#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{


    /* An SDL_Event struct */
    SDL_Event event;

    /* A bool to check if the program has exited */
    int quit = 0;

    /* While the program is running */
    while (!quit)
    {
        /* Check for new events */
        while(SDL_PollEvent(&event))
        {
            /* If a quit event has been sent */
            if (event.type == SDL_QUIT)
            {
                /* Quit the application */
                quit = 1;
            }

            /* If the mouse is moving */
            if (event.type == SDL_MOUSEMOTION)
            {
                //SDL_PixelFormat* fmt = screen->format;
                /* If the mouse is moving to the left */
                if (event.motion.xrel < 0)
                    SDL_FillRect(screen, NULL, SDL_MapRGB(fmt, 255, 0, 0));
                /* If the mouse is moving to the right */
                else if (event.motion.xrel > 0)
                    SDL_FillRect(screen, NULL, SDL_MapRGB(fmt, 0, 255, 0));
                /* If the mouse is moving up */
                else if (event.motion.yrel < 0)
                    SDL_FillRect(screen, NULL, SDL_MapRGB(fmt, 0, 0, 255));
                /* If the mouse is moving down */
                else if (event.motion.yrel > 0)
                    SDL_FillRect(screen, NULL, SDL_MapRGB(fmt, 0, 255, 255));
            }
        }

        SDL_Flip(screen);
    }

}
