/*
 * Basic Keyboard Example
 * https://wiki.allegro.cc/index.php?title=Basic_Keyboard_Example
 *         Basado en el de pooling de la v1
 */

#include <stdio.h>
#include <allegro5/allegro.h>
 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "al09_keyboard.h"

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

      net = get_network_data(newsockfd, buffer, &status, &sentkey);
      //DBG - if(net) printf("key: %d / status: %d\n",sentkey,status);

      if(net == 1) {
         if(sentkey == KEY_EXIT) {
            doexit = true;
            //DBG - printf("Received exit!\n");
         } else {
            key[sentkey] = status;
         }
      }

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
      } else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
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
