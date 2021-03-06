#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "SDL/lib.x86/SDL2.lib")
#pragma comment(lib, "SDL/lib.x86/SDL2main.lib")
#pragma comment(lib, "SDL/lib.x86/SDL2_image.lib")
#define MAX_BULLETS 10
#define MAX_BACKGROUND 2


int main(int argc, char* argv[]) {


	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_INIT_PNG;
	SDL_RENDERER_PRESENTVSYNC;

	//int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window** window, SDL_Renderer** renderer);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* todd_surface;
	SDL_Surface* bullshit_surface;
	SDL_Surface* lies_surface;
	SDL_Texture* bullshit_texture;
	SDL_Texture* todd_texture;
	SDL_Texture* lies_texture;
	SDL_Rect rectangle { 0, 240, 123, 158 };	
	SDL_Rect unicorn { 0, 0, 200, 120 };
	SDL_Rect shot{ 0, 0, 350, 80 };
	SDL_Rect background_1 = { 0 ,0, 1024, 512};
	SDL_Rect background_2 = { 1024, 0, 1024, 512 };
	SDL_Rect bullet[MAX_BULLETS]; // = { -58, -19, 58, 19 };	
	for (int i = 0; i < MAX_BULLETS; ++i) {
		bullet[i].x = -58;
		bullet[i].y = -19;
		bullet[i].w = 58;
		bullet[i].h = 19;
	}	

	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer); //SCREEN SIZE

	//////////////////////TEXTURES AND SURFACES///////////////////////
	todd_surface = IMG_Load("unicorn_sprites.png");
//	standby_surface = SDL_LoadBMP("standby.bmp");
	bullshit_surface = SDL_LoadBMP("bullshit.bmp");
	lies_surface = SDL_LoadBMP("lies.bmp");
	todd_texture = SDL_CreateTextureFromSurface(renderer, todd_surface);
	bullshit_texture = SDL_CreateTextureFromSurface(renderer, bullshit_surface);
	lies_texture = SDL_CreateTextureFromSurface(renderer, lies_surface);
   	SDL_FreeSurface(todd_surface);
	SDL_FreeSurface(bullshit_surface);
	SDL_FreeSurface(lies_surface);

	bool quit = false;
	bool shoot = false;
	int i = 0;
	int counter = 0;
	int animations = 0;

	while(quit == false) //SCREEN COLORS AND RECTANGLE
	{
		/////////////////RENDERING////////////////////////
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bullshit_texture, NULL, &background_1);
		SDL_RenderCopy(renderer, bullshit_texture, NULL, &background_2);
		SDL_RenderCopy(renderer, todd_texture, &unicorn, &rectangle);		
		for (i = 0; i < MAX_BULLETS; ++i) {
			SDL_RenderCopy(renderer, todd_texture, &shot, &bullet[i]);		
			bullet[i].x++;
		}	
	
		SDL_Event event;

		if (shoot) {
			
			bullet[counter].x = rectangle.x + 50;
			bullet[counter].y = rectangle.y + 50;
			shoot = false;
		}

		//////////////BACKGROUND MOVEMENT///////////////////////////

		background_1.x--;
		background_2.x--;

		if (background_1.x == -1024)
		{
			background_1.x = 1024;
		}
		if (background_2.x == -1024)
		{
			background_2.x = 1024;
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
							unicorn.x = 845;
							unicorn.y = 750;
							break;
						case(SDLK_s):
							rectangle.y += 5;
							unicorn.x = 1720;
							unicorn.y = 740;
							break;
						case(SDLK_a):
							rectangle.x -= 5;
							break;
						case(SDLK_d):
							rectangle.x += 5;
							break;
						case(SDLK_SPACE):
							++counter;
							shot.y = 1680;
							if (counter == MAX_BULLETS) {
								counter = 0;
							}							
							shoot = true;
							break;

				}
				break;		
			}
		}
		/////////////////Movement////////////////
		SDL_RenderPresent(renderer);
		SDL_Delay(3);
		
	}

	SDL_DestroyTexture(todd_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return(EXIT_SUCCESS);
}