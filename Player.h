#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"
class Player : public GameObject, public Rectangle
{
public:
	void Tick();
	void Render();
};
#endif