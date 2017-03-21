#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	//ship
	ship.x = 10;
	ship.y = 24;
	ship.w = 521;
	ship.h = 182;	 

	//ship animation
	shipMovement.PushBack({ 10, 24, 521, 182 });
	shipMovement.PushBack({ 10, 25, 521, 182 });
	shipMovement.PushBack({ 10, 26, 521, 182 });
	shipMovement.PushBack({ 10, 27, 521, 182 });
	shipMovement.PushBack({ 10, 26, 521, 182 });
	shipMovement.PushBack({ 10, 25, 521, 182 });
	shipMovement.speed = 0.08f;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	// girl animation
	girl.PushBack({ 624, 16, 32, 56 });
	girl.PushBack({ 624, 17, 32, 56 });
	girl.PushBack({ 624, 82, 32, 56 });
	girl.PushBack({ 624, 83, 32, 56 });
	girl.PushBack({ 624, 146, 32, 56 });
	girl.PushBack({ 624, 145, 32, 56 });

	girl.speed = 0.08f;
}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	//App->render->Blit(graphics, 0, 0, &ship, 0.75f);
	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	App->render->Blit(graphics, 0, 0, &(shipMovement.GetCurrentFrame()), 0.75f);
	App->render->Blit(graphics, 190, 104, &(girl.GetCurrentFrame()), 0.75f);

	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}