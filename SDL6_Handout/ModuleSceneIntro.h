#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

	~ModuleSceneIntro();

public:
	SDL_Texture* background = nullptr;
	bool fading;

};

#endif