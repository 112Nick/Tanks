/*
Класс хранит все объекты игры и отвечает за их обновление и взаимодействие.
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "GameObject.h"
#include "Tank.h"
#include <vector>

class Tank;

class Controller
{	
public:
	Controller();
	void Tick();
	void Render();
	void AddLevelMapItem(GameObject& item);
	void AddEnemy(GameObject& enemy);
	void AddOther(GameObject& other);
	void SetPlayer(Tank* p);
	void Keyboard(unsigned char key);
	void SpecialKeyboard(int k);
	bool Check(int a, int b);
private:
	std::vector<GameObject*> levelMap;
	std::vector<GameObject*> enemies;
	std::vector<GameObject*> other;
	Tank* player;
	void RenderMap();
	void GetMapFromFile();
	bool field[40][30];
};
#endif
