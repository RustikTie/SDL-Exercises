#include "SDL/include/SDL.h"
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "SDL/lib.x86/SDL2.lib")
#pragma comment(lib, "SDL/lib.x86/SDL2main.lib")
#define MAX_BULLETS 2


int main(int argc, char* argv[]) {


	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_RENDERER_PRESENTVSYNC;

	//int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window** window, SDL_Renderer** renderer);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* todd_surface;
	SDL_Surface* standby_surface;
	SDL_Surface* lies_surface;
	SDL_Texture* standby_texture;
	SDL_Texture* todd_texture;
	SDL_Texture* lies_texture;
	SDL_Rect rectangle{ 0, 240, 123, 158 };	
	SDL_Rect background{ 0 ,0, 640, 480};
	
	SDL_Rect bullet[MAX_BULLETS] = { -58, -19, 58, 19 };


	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer); //SCREEN SIZE

	todd_surface = SDL_LoadBMP("Todd.bmp");
	standby_surface = SDL_LoadBMP("standby.bmp");
	lies_surface = SDL_LoadBMP("lies.bmp");
	todd_texture = SDL_CreateTextureFromSurface(renderer, todd_surface);
	standby_texture = SDL_CreateTextureFromSurface(renderer, standby_surface);
	lies_texture = SDL_CreateTextureFromSurface(renderer, lies_surface);
   	SDL_FreeSurface(todd_surface);
	SDL_FreeSurface(standby_surface);
	SDL_FreeSurface(lies_surface);

	bool quit = false;
	bool shoot = false;
	int i = 0;
	int counter = 0;

	while(quit == false) //SCREEN COLORS AND RECTANGLE
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, standby_texture, NULL, &background);
		SDL_RenderCopy(renderer, todd_texture, NULL, &rectangle);		
		for (i = 0; i < MAX_BULLETS; ++i) {
			SDL_RenderCopy(renderer, lies_texture, NULL, &bullet[i]);		
			bullet[i].x++;

		}		

		SDL_Event event;

		if (shoot) {
			
			bullet[counter].x = rectangle.x + 50;
			bullet[counter].y = rectangle.y + 120;
			shoot = false;
		}

		///////////////////Events/////////////////////
		while (SDL_PollEvent(&event)) 
		{			
			
			switch (event.type) {
				case SDL_KEYDOWN:

					switch (event.key.keysym.sym) {
						case (SDLK_ESCAPE): //QUIT WHEN HIT ESCAPE
							quit = true;
							break;
						case(SDLK_w):
							rectangle.y -= 5;							
							break;
						case(SDLK_s):
							rectangle.y += 5;
							break;
						case(SDLK_a):
							rectangle.x -= 5;
							break;
						case(SDLK_d):
							rectangle.x += 5;
							break;
						case(SDLK_SPACE):
							++counter;
							if (counter == MAX_BULLETS) {
								counter = 0;
							}							
							shoot = true;
							break;

				}
				break;		
			}
		}
		/////////////////Movement
		SDL_RenderPresent(renderer);
		SDL_Delay(3);
		
	}

	SDL_DestroyTexture(todd_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return(EXIT_SUCCESS);
}