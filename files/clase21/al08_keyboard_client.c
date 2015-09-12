/*
 * Basic Keyboard Example
 * https://wiki.allegro.cc/index.php?title=Basic_Keyboard_Example
 */

#include <stdio.h>
#include <allegro5/allegro.h>
 
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define PUERTO 9123
#define MY_EVENT_TYPE ALLEGRO_GET_EVENT_TYPE('S','O','C','K')

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

void error(const char *msg)
{
    perror(msg);
    exit(0);
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
   bool key[4] = { false, false, false, false };
   bool redraw = true;
   bool doexit = false;
 
	/*************************
	 * Variables de Server TCP
	 */

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

	/*************************
	 * Inicializacion Server TCP
	 */

    if (argc < 2) {
       fprintf(stderr,"usage %s hostname\n", argv[0]);
       exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((void *) &serv_addr, '\0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(PUERTO);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

	/*************************
	 * Inicialiación y configuración Allegro
	 */

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
 
   if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
   }
 
   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
 
   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }
 
   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_set_target_bitmap(bouncer);
 
   al_clear_to_color(al_map_rgb(255, 0, 255));
 
   al_set_target_bitmap(al_get_backbuffer(display));
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_register_event_source(event_queue, al_get_keyboard_event_source());
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(timer);
 
 	/*************************
	 * Listos para empezar el juego!
	 */

   while(!doexit)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         if(key[KEY_UP] && bouncer_y >= 4.0) {
            bouncer_y -= 4.0;
         }
 
         if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
            bouncer_y += 4.0;
         }
 
         if(key[KEY_LEFT] && bouncer_x >= 4.0) {
            bouncer_x -= 4.0;
         }
 
         if(key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
            bouncer_x += 4.0;
         }
 
         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = true;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_UP;TRUE"); buffer[11] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = true;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_DOWN;TRUE"); buffer[13] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_LEFT: 
               key[KEY_LEFT] = true;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_LEFT;TRUE"); buffer[13] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = true;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_RIGHT;TRUE"); buffer[14] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
         }
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = false;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_UP;FALSE"); buffer[12] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = false;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_DOWN;FALSE"); buffer[14] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_LEFT: 
               key[KEY_LEFT] = false;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_LEFT;FALSE"); buffer[14] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = false;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_RIGHT;FALSE"); buffer[15] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
 
            case ALLEGRO_KEY_ESCAPE:
               doexit = true;
				memset((void *) buffer, '\0', 256);
				strcpy(buffer,"KEY_EXIT;TRUE"); buffer[13] = '\0';
				n = write(sockfd,buffer,strlen(buffer));
				if (n < 0) error("ERROR writing to socket");
               break;
         }
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
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
