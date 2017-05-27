#include "GameObject.h"
GameObject::GameObject(): Point(0, 0) {}

GameObject::GameObject(float _x, float _y): Point(_x, _y){}

bool GameObject::IsDead()
{
	return dead;
}