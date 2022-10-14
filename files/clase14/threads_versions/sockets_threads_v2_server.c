#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <pthread.h>    /* multithreading the clients! */

#define MAXMSGSIZE 150
#define MAXCLIENTS 5
#define TOO_MANY_CD 0
#define ALL_GOOD_CD 1
#define OTHER_BAD_CD 2

struct client {
    char* username;
    char** subs;
    int socket;
    char temp_msg[MAXMSGSIZE*2];
};

void DieWithError(char* errorMessage);  /* Error handling function */
void handle_client(void* new_socket); /* Client handling function */

static struct client** clients;
static pthread_t* threads;
static pthread_mutex_t clients_mutex;
static pthread_mutex_t threads_mutex;

int main(int argc, char *argv[])
{
    int server_sock;                /* Server socket descriptor */
    unsigned short server_port;     /* Echo server port */
    struct sockaddr_in server_addr; /* sockaddr_in struct to hold information about the server */
    int server_addr_size;           /* Size of server_addr struct in bytes */
    int client_sock;
    int empty_thread;
    pthread_attr_t thread_attr;

    if (argc != 2) {  /* Test for correct number of arguments */
        fprintf(stderr, "Usage: %s <server_port>\n", argv[0]);
        exit(1);
    }

    clients = (struct client**) calloc(1, sizeof(struct client*) * MAXCLIENTS);
    if (clients == NULL)
        DieWithError("calloc() for clients failed");
    threads = (pthread_t*) calloc(1, sizeof(pthread_t) * MAXCLIENTS);
    if (clients == NULL)
        DieWithError("calloc() for clients failed");

    pthread_mutex_init(&clients_mutex, NULL);
    pthread_mutex_init(&threads_mutex, NULL);
    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);

    server_port = atoi(argv[1]);

    /* Create a reliable, stream socket using TCP */
    if ((server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket() failed");

    // Zero out server_addr var and fill with information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);

    // Bind server with sock, IP, and port so that the clients can connect to us
    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
        DieWithError("bind() failed");

    // Allow this server to accept 5 clients at a time (queue has 0 capacity because we multithread)
    if (listen(server_sock, 0) < 0)
        DieWithError("listen() failed");

    // Display some information so we can connect with client
    printf("Using\n\tport: %d\n\tIP: %s\n", server_port, inet_ntoa(server_addr.sin_addr));
    server_addr_size = sizeof(server_addr);
  for (;;) {
    int* new_socket = (int*)malloc(sizeof(int));
    if ((*new_socket = accept(server_sock, 
        (struct sockaddr*) &server_addr, &server_addr_size)) < 0) {
      printf("accept() failed");
      continue;
    }
    int free_spot = -1;
    for (int i = 0; i < MAXCLIENTS; i++)
        if (!threads[i]) free_spot = i;
    if (free_spot == -1) {
        printf("no empty threads (max clients handled currently)");
        send(*new_socket,(void*) OTHER_BAD_CD, sizeof(OTHER_BAD_CD), 0);
        close(*new_socket);
        continue;
    }

    if (pthread_create(&threads[free_spot], &thread_attr,
        (void*) &handle_client, (void*) new_socket)) {
      printf("pthread_create failed");
      close(*new_socket);
      continue;
    }
    printf("sent new client %d to handle_client()\n", *new_socket);
  }
}

void handle_client(void* new_socket) {
    int socket = *(int*)new_socket;
    free(new_socket);
    printf("handling new client %d\n", socket);
    struct client* curr_cl;
    pthread_mutex_lock(&clients_mutex);
    printf("locked mutex?\n");
    if (send(socket, (void*)ALL_GOOD_CD, sizeof(ALL_GOOD_CD), 0) < 0) {
        printf("inital all good resp failed");
        send(socket, (void*)OTHER_BAD_CD, sizeof(OTHER_BAD_CD), 0);
        return;
    }
    printf("sent stuff\n");
    int free_spot = -1;
    for (int i = 0; i < MAXCLIENTS; i++)
        if (!clients[i]) free_spot = i;

    printf("filtered through clients and got free spot %d\n", free_spot);
    if (free_spot == -1) {
        printf("didn't find free spot :(\n");
        send(socket, (void*)TOO_MANY_CD, sizeof(TOO_MANY_CD), 0);
        pthread_mutex_unlock(&clients_mutex);
        return;
    }
    printf("found free spot %d for client %d", free_spot, socket);
    clients[free_spot] = (struct client*) calloc(1, sizeof(struct client));
    if (clients[free_spot] == NULL) {
        send(socket, (void*)OTHER_BAD_CD, sizeof(OTHER_BAD_CD), 0);
        pthread_mutex_unlock(&clients_mutex);
        return;
    }
    curr_cl = clients[free_spot];

    if (recv(socket, curr_cl->username, sizeof(curr_cl->username), 0) < 0) {
        send(socket, (void*)OTHER_BAD_CD, sizeof(OTHER_BAD_CD), 0);
        pthread_mutex_unlock(&clients_mutex);
        return;
    }

    // Subscribe client to #ALL automatically
    curr_cl->subs[0] = "#ALL";

    if (send(socket, (void*)ALL_GOOD_CD, sizeof(ALL_GOOD_CD), 0) < 0) {
        printf("send() for final all good failed\n");
        send(socket, (void*)OTHER_BAD_CD, sizeof(OTHER_BAD_CD), 0);
        pthread_mutex_unlock(&clients_mutex);
        return;
    }
    printf("\taccepted new client %s and now listening\n", curr_cl->username);
    pthread_mutex_unlock(&clients_mutex);
    return;
}

void DieWithError(char* errorMessage) {
    fprintf(stderr, "Dying with error sadface: %s\n", errorMessage);
    exit(1);
} 
