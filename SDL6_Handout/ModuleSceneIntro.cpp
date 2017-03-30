#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"



ModuleSceneIntro::ModuleSceneIntro()
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{
}


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA


// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading intro scene");

	background = App->textures->Load("rtype/intro.png");
	
	App->player->Disable();

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(background);
	

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	// Fade -----------------------------------------

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_space, 1.5f);
		fading == true;
	
	}
	return UPDATE_CONTINUE;
}


