#
#  Makefile
#  Ejemplos de: 
#      https://wiki.allegro.cc/index.php?title=Allegro_5_API_Tutorials
#

LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_dialog
CFLAGS = -Wall

all: al01_display al02_screenres al03_events al04_timers al04_timers2 al05_bitmaps al06_bitmapload al07_mouse al08_keyboard al09_keyboard_client al09_keyboard_server al21_user_events

al09_keyboard_client: al09_keyboard_client.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

al09_keyboard_server: al09_keyboard_server.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f al01_display al02_screenres al03_events al04_timers al04_timers2 al05_bitmaps al06_bitmapload al07_mouse al08_keyboard al09_keyboard_client al09_keyboard_server al21_user_events
