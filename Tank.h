#ifndef TANK_H
#define TANK_H
#include "Rectangle.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"

class Controller;

const int SCALE = 20;

class Tank: public GameObject, public Rectangle 
{
public:
    Tank();
    Tank(float _x, float _y, Controller& _c);
    void Render();
    void SpecialKeyboard(int key);
    void Keyboard(int key);
    void Shoot();
    void Tick();

 private:
  int x, y;
  Direction dir;
  Controller* c;

}; 
#endif