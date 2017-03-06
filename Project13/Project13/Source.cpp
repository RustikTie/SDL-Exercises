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
	SDL_Surface* todd_surface;
	SDL_Texture* todd_texture;
	SDL_Rect rectangle{ 196, 81, 247, 317 };	

	
	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer); //SCREEN SIZE

	todd_surface = SDL_LoadBMP("Todd.bmp");
	todd_texture = SDL_CreateTextureFromSurface(renderer, todd_surface);

	bool quit = false;

	while(quit == false) //SCREEN COLORS AND RECTANGLE
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) 
		{
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderClear(renderer);			
			SDL_RenderCopy(renderer, todd_texture, NULL, &rectangle);
			SDL_RenderPresent(renderer);

			switch (event.type) {
				case SDL_KEYDOWN:

					switch (event.key.keysym.sym) {
						case (SDLK_ESCAPE): //QUIT WHEN HIT ESCAPE
							quit = true;
							break;
						case(SDLK_w):
							--rectangle.y;
							if (rectangle.y < -398) {
								rectangle.y = 438;
							}
							break;
						case(SDLK_s):
							++rectangle.y;
							if (rectangle.y > 397) {
								rectangle.y = -637;
							}
							break;
						case(SDLK_a):
							--rectangle.x;
							if (rectangle.x < -443) {
								rectangle.x = 640;
							}
							break;
						case(SDLK_d):
							++rectangle.x;
							if (rectangle.x > -443) {
								rectangle.x = -246;
							}
							break;

				}
				break;
			}
		}
	}

	SDL_DestroyTexture(todd_texture);
	SDL_FreeSurface(todd_surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(todd_texture);
	SDL_FreeSurface(todd_surface);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return(EXIT_SUCCESS);
}