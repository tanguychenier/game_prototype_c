#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Impossible d'initialiser la SDL\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL TEST - TCHENIER",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            640,
                                            480,
                                            SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("Impossible de creer la fenetre: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)
    {
        printf("Impossible de creer le renderer: %s\n", SDL_GetError());
        return -1;
    }


    int primary_color = 1;
    int max_color = 1;

    while (true)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, primary_color, 0, 0, 255);
        
        if (primary_color >= 255 || primary_color <= 0)
        {
            max_color = -max_color;
        }

        primary_color += max_color;

        printf("%i\n", primary_color);


        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}