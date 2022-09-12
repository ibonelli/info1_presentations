#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MAXBUFLEN 256
#define MYPORT 4321 // puerto escucha UDP

int main(void)
{
  int sockfd; //para el socket
  char buf[MAXBUFLEN];

  int infilefd; //para el archivo
  char filebuf[MAXBUFLEN];

  int fiffd; //para el pipe
  char fifbuf[MAXBUFLEN];

  int num,selret,salir =0;
  int n; //valor para select

  fd_set rfds; //conjunto de descriptores de lectura a ser watcheados
  struct timeval tv; //para el time out si se quiere

  struct sockaddr_in my_addr; // mi dirección
  struct sockaddr_in their_addr; // socket address information
  int addr_len, numbytes;

  //preparo socket
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }
  
  my_addr.sin_family = AF_INET; /* host byte order */
  my_addr.sin_port = htons(MYPORT); /* short, network byte order */
  my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
  bzero(&(my_addr.sin_zero), 8); /* zero the rest of the struct */
  if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) 
  {
    perror("bind");
    exit(1);
  }
  addr_len = sizeof(struct sockaddr);
// ********************************************************
// hasta acá esta listo para escuchar el socket
// ********************************************************

  fiffd = open("fifo1", O_RDWR);
// ********************************************************
// hasta acá esta listo para escuchar el fifo
// ********************************************************

  infilefd = open ("archtest.dat",O_RDWR); // debe usarse así, sino bloquea en open
  
// ********************************************************
// hasta aca esta listo para escuchar el archivo (segundo fifo)
// ********************************************************

//antes de llamar a select debo determinal el mayor numero de fd
  n=fiffd;
  if (sockfd>fiffd) n=sockfd;
  if (infilefd>n) n=infilefd;

  while (!salir) // loop principal
  {

    FD_ZERO(&rfds); //limpio el conjunto y cargo descriptores a monitorear
    FD_SET(fiffd, &rfds);
    FD_SET(infilefd, &rfds);
    FD_SET(sockfd, &rfds);

    tv.tv_sec = 20; // time out en 20 segundos
    tv.tv_usec = 0;

//**************************************
//aca se bloquea en espera de algun evento o del time out en tv
    selret = select(n+1, &rfds, NULL, NULL, &tv);
//al seguir debo ver por cual de todos fue el desbloqueo
//**************************************
    if (selret == -1) 
    {
      printf("erorr de select!\n");
      exit(1);
    }

//**************************************
    if (FD_ISSET(infilefd,&rfds) )
    { //si fue por el archivo
      if ((num = read(infilefd, filebuf, MAXBUFLEN)) == -1)
	perror("read");
      else 
      {
	filebuf[num] = '\0';
	printf("ARCH1 : %s", filebuf);
      }
    }

//**************************************
    if (FD_ISSET(sockfd,&rfds)) 
    { // si fue el socket
      if ((numbytes=recvfrom(sockfd, buf, MAXBUFLEN, 0, (struct sockaddr *)&their_addr, &addr_len)) == -1) 
      {
	perror("recvfrom");
	exit(1);
      }
      buf[numbytes] = '\0';
      printf("SOCKET: %s",buf);
    }
  
//**************************************
    if (FD_ISSET(fiffd,&rfds))
    { // si fue el fifo
      if ((num = read(fiffd, fifbuf, MAXBUFLEN)) == -1)
	perror("read");
      else 
      {
	fifbuf[num] = '\0';
	printf("FIFO1 : %s", fifbuf);
      }
    }

//**************************************
    if (!selret)
    { //o fue por time out
      printf("\nTime out esperando datos desde cualquier file descriptor...\n");
      salir =1;
    }
  } // del while

  close(sockfd);
  close(infilefd);
  close(fiffd);
  return 0;
}