#include "includes/tga_reader.h"
#include "includes/SDL2/SDL.h"

int		main(int argc, char **argv)
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	SDL_Texture	*texture;
	SDL_Renderer *rend;
	t_tga		*tga;
	SDL_Event	ev;
	
	if (argc < 2)
		return (0);
	if ((tga = load_tga(argv[1])) == NULL || tga->data == NULL)
		return (0);
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Show tga file", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	surface = SDL_CreateRGBSurfaceWithFormatFrom(tga->data, tga->w, tga->h, 32, tga->w * 4, SDL_PIXELFORMAT_ARGB32);
	texture = SDL_CreateTextureFromSurface(rend, surface);
	SDL_RenderCopy(rend, texture, NULL, NULL);
	SDL_RenderPresent(rend);
	SDL_UpdateWindowSurface(window);
	SDL_PollEvent(&ev);
	SDL_Delay(1000);
	free_tga(tga);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}
