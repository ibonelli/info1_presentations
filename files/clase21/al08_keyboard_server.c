/*
 * Basic Keyboard Example
 * https://wiki.allegro.cc/index.php?title=Basic_Keyboard_Example
 */

#include <string.h>
#include <stdio.h>
#include <allegro5/allegro.h>
 
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define PUERTO 9123

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_EXIT
};

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int get_network_data(int sockfd, char *buffer, int *s, int *k) {
	int n;
	char *key, *status;
	
	// Me fijo si llegó via red
	memset((void *) buffer, '\0', 256);
	n = recv(sockfd,buffer,255,MSG_DONTWAIT);
	//DBG - printf("Buffer: %s / n: %d",buffer,n);
	
	if(n>0) {
		key = strtok(buffer,";");
		status = strtok(NULL,";");
		//DBG - printf("key: %s / status: %s\n",key,status);
		
		if(!strcmp(status,"TRUE")) {
			*s=1;
		} else if(!strcmp(status,"FALSE")) {
			*s=0;
		} else {
			printf("Error recepción. Buffer: %s",buffer);
			return 0;
		}

		if(!strcmp(key,"KEY_UP")) {
			*k=KEY_UP;
		} else if(!strcmp(key,"KEY_DOWN")) {
			*k=KEY_DOWN;
		} else if(!strcmp(key,"KEY_LEFT")) {
			*k=KEY_LEFT;
		} else if(!strcmp(key,"KEY_RIGHT")) {
			*k=KEY_RIGHT;
		} else if(!strcmp(key,"KEY_EXIT")) {
			*k=KEY_EXIT;
		} else {
			printf("Error recepción. Buffer: %s",buffer);
			return 0;
		}

		// Data saved (s+k), can return
		//DBG - printf("key: %d / status: %d\n",*k,*s);
		return 1;

	} else {
		return 0;
	}
}

int main(int argc, char **argv)
{
	/*************************
	 * Variables de Allegro
	 */

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   bool redraw = true;
   bool doexit = false;
 
	/*************************
	 * Variables de Server TCP
	 */

	int sockfd, newsockfd;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int net, status, sentkey;

	/*************************
	 * Inicializacion Server TCP
	 */

	// Inicializo sockets
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) 
		error("ERROR opening socket");

	// Armando la estructura "sockaddr_in"
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PUERTO);
	memset((void *) &(serv_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR on binding");

	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	printf("Esperando jugador en red...\n");
	// Llamado bloqueante a accept()
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) error("ERROR on accept");
	printf("Conexion jugador aceptada!\n");

	/*************************
	 * Inicialiación y configuración Allegro
	 */

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
 
   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
 
   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      return -1;
   }
 
   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(255, 0, 255));
 
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      return -1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
 	/*************************
	 * Listos para empezar el juego!
	 */

   while(!doexit)
   {
	  net = get_network_data(newsockfd, buffer, &status, &sentkey);
	  //DBG - if(net) printf("key: %d / status: %d\n",sentkey,status);

      if(net == 1) {
         switch(sentkey) {
            case KEY_UP:
			   if(status && bouncer_y >= 4.0)
			      bouncer_y -= 4.0;
			   redraw = true;
               break;

            case KEY_DOWN:
               if(status && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0)
                  bouncer_y += 4.0;
			   redraw = true;
               break;

            case KEY_LEFT: 
               if(status && bouncer_x >= 4.0)
                  bouncer_x -= 4.0;
			   redraw = true;
               break;
 
            case KEY_RIGHT:
               if(status && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0)
			      bouncer_x += 4.0;
			   redraw = true;
               break;

            case KEY_EXIT:
               doexit = true;
               break;
         }
      }
 
      if(redraw) {
         redraw = false;
 
         al_clear_to_color(al_map_rgb(0,0,0));
 
         al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
 
         al_flip_display();
      }
   }
 
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   close(sockfd);
 
   return 0;
}
