#ifndef __ENEMY_BROWNCOOKIES_H__
#define __ENEMY_BROWNCOOKIES_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_BrownCookies : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Path path;

public:

	Enemy_BrownCookies(int x, int y);

	void Move();
};

#endif
