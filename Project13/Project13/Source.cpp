#include "SDL/include/SDL.h"
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "SDL/lib.x86/SDL2.lib")
#pragma comment(lib, "SDL/lib.x86/SDL2main.lib")


int main(int argc, char* argv[]) {


	SDL_Init(SDL_INIT_EVERYTHING);

	//int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window** window, SDL_Renderer** renderer);

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer); //all red with a box in the middle blue
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
		
	SDL_Rect rectangle{ 160, 120, 320, 240 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &rectangle);
	
	SDL_RenderFillRect(renderer, &rectangle);
	SDL_RenderPresent(renderer);


	for (;;) 
	{

	}

	SDL_Quit();

	return(EXIT_SUCCESS);
}