#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

int main()
{
    bool done = false;
    int width = 640;
    int height = 480;
    /***
    * define the sprite locations
    ***/
    int WallWidth = 80;
    int WallHeight = 80;
    al_init();
    al_install_keyboard();
    al_init_image_addon();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* disp = al_create_display(width, height);
    ALLEGRO_BITMAP* image;
    image = al_load_bitmap("D:\\GameArt\\Bitmaps\\dungeon_tiles_0.bmp");
    
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    

    al_start_timer(timer);
    while (!done)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }
        al_clear_to_color(al_map_rgb(62, 65, 78));

        int xpos = 0;
        int ypos = 0;

        

        al_draw_bitmap_region(image, 32, 32, WallWidth, WallHeight, 32, 32, 0);
        al_flip_display();
    }

    al_destroy_bitmap(image);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}