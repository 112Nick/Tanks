/*
Базовый абстрактный класс для любого объекта в игровом мире.
Содержит общие для всех объектов элементы: методы Tick и Render, координаты, Getters/Setters.
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point.h"
class GameObject: public virtual Point
{
public:
	GameObject();
	GameObject(float _x, float _y);
	virtual void Tick() = 0;
	virtual void Render() = 0;
	virtual void Keyboard(int key) = 0;
	virtual void SpecialKeyboard(int key) = 0;
	bool IsDead();
protected:
	bool dead;
};
#endif