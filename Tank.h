#ifndef TANK_H
#define TANK_H
#include <vector>
#include <chrono>
#include <string>
#include "Rectangle.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"
#include "Map.h"

class Controller;

extern const int SCALE;

class Tank: public GameObject, public Rectangle
{
public:
    Tank();
    Tank(float _x, float _y, std::string texfolder, Controller& _c, bool enemy, int hp);
    Tank(const Tank& other);
    Tank& operator=(const Tank&);
    Map& GetCollisionMap();
    void Render();
    void SpecialKeyboard(int key);
    void Keyboard(int key);
    void Restore();
    void Shoot();
    void Tick();
    void Hit();
    bool IsEnemy();
    int GetHp();

 private:
  void Move(Direction d, float dx, float dy);
  void Copy(const Tank& t);
  int hp;
  const double STEP_TIME = 0.1;
  const double RELOAD_TIME = 0.3;
  float restoreX, restoreY;
  bool isEnemy;
  Direction prevDir;
  Direction dir;
  Controller* c;
  std::vector<Map> collisionMaps;
  std::chrono::high_resolution_clock::time_point prevStepTime;
  std::chrono::high_resolution_clock::time_point prevShootTime;
}; 
#endif