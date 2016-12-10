#include "Controller.h"
#include "Tank.h"
#include "Block.h"
#include <fstream>


Controller::Controller()
{
	GetMapFromFile();
}

bool Controller::Check(int a, int b)
{
 return field[a][b];
}
void Controller::GetMapFromFile()
{
	std::ifstream fin("map.txt");
	char buf;
	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 41; j++)
		{
			buf = fin.get();
			//std::cout << buf ;
			if(buf == '1')
			{
				field[j][i] = true;
			}
		}
		//std::cout << std::endl;
	}


}
void Controller::RenderMap()
{
	for(int i = 0; i < 40; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			if(field[i][j])
			{
				Block b(i,j);
				b.Render();
			}
		}
	}
}
void Controller::Tick()
{
	player->Tick();
	for (int i=0; i<other.size(); ++i) 
	{
		other[i]->Tick();
	}
	
}

void Controller::Render()
{
	player->Render();
	RenderMap();
	for (int i=0; i<other.size(); ++i) 
	{
		other[i]->Render();
	}
}

void Controller::AddLevelMapItem(GameObject& item)
{
	levelMap.push_back(&item);
}

void Controller::AddEnemy(GameObject& enemy)
{
	enemies.push_back(&enemy);
}

void Controller::SetPlayer(Tank* player)
{
	this->player = player;
}

void Controller::AddOther(GameObject& o)
{
	other.push_back(&o);
}
void Controller::Keyboard(unsigned char key)
{
	player->Keyboard(key);
}
void Controller::SpecialKeyboard(int key)
{
	player->SpecialKeyboard(key);
}

