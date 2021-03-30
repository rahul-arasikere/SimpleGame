#include <allegro.h>
#include "../include/ScreenManager.h"

volatile long counter = 0;

void Increment()
{
    counter ++;
}

int main()
{
    allegro_init ();
    install_keyboard ();
    install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, "A" );
    set_color_depth ( 32 );
    set_gfx_mode ( GFX_AUTODETECT_WINDOWED, ScreenWidth, ScreenHeight, 0, 0 );

    LOCK_VARIABLE ( counter );
    LOCK_FUNCTION ( Increment() );
    install_int_ex ( Increment, BPS_TO_TIMER( 100 ) );

    BITMAP *Buffer = create_bitmap ( 6000,6000 );
    srand(time(0));
    bool done=false;

    ScreenManager screenManager;

    while(!done)
    {
        while (counter > 0)
        {
            //Input
            if(key[KEY_ESC])
                done = true;
            //Update
            screenManager.Update(Buffer,done);
            counter --;
        }

        //Draw
        screenManager.Draw(Buffer);
        clear_bitmap(Buffer);
    }
    return 0;
}
END_OF_MAIN()
