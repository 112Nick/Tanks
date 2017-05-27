#ifndef MAP_H
#define MAP_H
#include "GameObject.h"
#include "Block.h"
#include "Rectangle.h"
#include <string>
#include <list>

class Map : public GameObject
{
public:
	Map(const std::string& filename, float, float);
	bool Intersects(const Rectangle& r);
	std::list<Block>& GetBlocks();
	void Tick();
	void Render();
	void Keyboard(int);
	void Translate(float, float);
	void SpecialKeyboard(int);
private:
	void ReadMapFromFile(const std::string& filename);
	std::list<Block> blocks; 
};
#endif