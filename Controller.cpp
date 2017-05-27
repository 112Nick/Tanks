#include <iostream>
#include <cstdlib>
#include "Controller.h"
#include "Tank.h"
#include "Map.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "LoseMenu.h"
#include "Bot.h"


Controller::Controller(): start(false), pause(false), lose(false)
{
	score = 0;
}

bool Controller::CollidesBlocks(const Rectangle& r)
{
	for(Block& b: map->GetBlocks())
	{
		if(b.Intersects(r))
		return true;
	}
	return false;
}

void Controller::HandleBullets()
{
		auto itr = enemyBullets.begin();
		while (itr != enemyBullets.end()) 
		{				
	    	if (player->Intersects(*itr)) 
			{
	      		itr = enemyBullets.erase(itr);
	      		player->Hit();
	    	} 
	    	else 
	    	{
	      		++itr;
	    	}
  		}
		  bool flag = false;
		itr = playerBullets.begin();
			////for(Bot& b: enemies)
			////{
				while (itr != playerBullets.end()) 
				{		
					flag = false;
					for(Bot& b: enemies)
					{	
						if(itr->Intersects(b.GetTank()))
						{
							b.GetTank().Hit();
							itr = playerBullets.erase(itr);
							flag = true;
						}
					}
					//else 
					//{
						if(!flag)
							++itr;
					//}
				}
			////}

}
void Controller::HandleEnemies()
{
for(Bot& bot: enemies)
		{
			if(player->Intersects(bot.GetTank()))
			{
				player->Restore();
			}
		}
	for(int i = 0;i<enemies.size();i++)
	{
		for(int j = 0;j<enemies.size();j++)
		{
			if(i != j)
			{
				if(enemies[i].GetTank().Intersects(enemies[j].GetTank()))
				{
					enemies[i].GetTank().Restore();
				}
			}
		}
	}
}

void Controller::HandleBlocks()
{
	for(Block& b: map->GetBlocks())
	{
		if(player->Intersects(b))
		{
			player->Restore();
		}

		for(Bot& bot: enemies)
		{
			if(bot.GetTank().Intersects(b))
			{
				bot.GetTank().Restore();
			}
		}

		auto itr = playerBullets.begin();
		while (itr != playerBullets.end()) 
		{
    		if (itr->Intersects(b)) 
			{
      			itr = playerBullets.erase(itr);
      			if(b.IsDestructible())
				{
      				b.SetHp(b.GetHp()-1);
      			}
    		}	 
    		else 
    		{
      			++itr;
    		}
  		}

		itr = enemyBullets.begin();
		while (itr != enemyBullets.end()) 
		{
	    	if (itr->Intersects(b)) 
			{
	      		itr = enemyBullets.erase(itr);
	      		if(b.IsDestructible())
				{
	      			b.SetHp(b.GetHp()-1);
	      		}
	    	} 
	    	else 
	    	{
	      		++itr;
	    	}
  		}
	}
}

void Controller::Tick()
{
	if(start)
	{
		if(!pause)
		{
			player->Tick();
			if(player->IsDead())
			{
				lose = true;
				pause = true;
				lmenu->SetScore(score);
			}
			map->Tick();

			for (Bullet& bul: playerBullets) 
			{
				bul.Tick();
			}

			for (Bullet& bul: enemyBullets) 
			{
				bul.Tick();
			}

			HandleBlocks();
			HandleEnemies();
			HandleBullets();

			int i = 0;
			auto itr = map->GetBlocks().begin();
			while (itr != map->GetBlocks().end()) { 
	    		if (itr->IsDestructible() && itr->GetHp() <= 0) {
	      			itr = map->GetBlocks().erase(itr);
	    		} 
	    		else 
	    		{
	      			++itr;
	    		}
  			}

			auto itr2 = enemies.begin();
			while (itr2 != enemies.end()) { 
				//std::cout << itr2->GetTank().GetHp() << std::endl;
	    		if (itr2->GetTank().IsDead()) {
	      			itr2 = enemies.erase(itr2);
	    		} 
	    		else 
	    		{
	      			++itr2;
	    		}
  			}
			if(enemies.size() <= 2)
			{
				srand(time(0));
				Bot g = Bot(Tank(rand()%70+5, rand()%50+5, "Enemy", *this, true, 3));
				while(CollidesBlocks(g.GetTank()))
				{
					g = Bot(Tank(rand()%70+5, rand()%50+5, "Enemy", *this, true, 3));
				}
				int newOpDelay = (g.GetOpDelay() - score*10) < 0 ? 50 : g.GetOpDelay() - score*7;
				int newPerfDelay = (g.GetPerfDelay() - score*10) < 0 ? 25 : g.GetPerfDelay() - score*4;
				g.SetOpDelay(newOpDelay);
				g.SetPerfDelay(newPerfDelay);
				AddBot(g);
				score++;
			}
			for(Bot& b: enemies)
			{
				b.Tick();
			}
		}
	}
}
void Controller::RenderScore()
{
	glColor3ub( 0, 222, 18);
	glRasterPos3d(WIDTH-120, HEIGHT+1, 0);
	std::string s = "Score: " + std::to_string(score);
   	glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)s.c_str());
	glRasterPos3d(WIDTH-200, HEIGHT+1, 0);
	s = "HP: " + std::to_string(player->GetHp());
   	glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)s.c_str());
}

void Controller::Render()
{
	if(!start)
		menu->Render();
	else
	{
		if(lose)
		{
			lmenu->Render();
		}
		else if(!pause)
		{
			player->Render();
			map->Render();
			RenderScore();
			for (Bullet& b: playerBullets) 
			{
				b.Render();
			}

			for (Bullet& b: enemyBullets) 
			{
				b.Render();
			}

			for(Bot& b: enemies)
			{
				b.Render();
			}
		}
		else
		{
			pmenu->Render();
		}
	}
	
}

void Controller::NewGame()
{
	ResetGame();
	score = 0;
	pause = false;
	start = true;
	lose = false;
}

void Controller::Continue()
{
	pause = !pause;
}

void Controller::StopGame()
{
	pause = false;
	start = false;
}

void Controller::ResetGame()
{
	enemies.clear();
	delete map;
	delete player;
	SetPlayer(new Tank(10, 10, "Tank", *this, false, 3));
   	SetMap(new Map("map", 0, 1));
	AddBot(Bot(Tank(40, 40, "Enemy", *this, true, 3)));
	AddBot(Bot(Tank(50, 40, "Enemy", *this, true, 3)));
	AddBot(Bot(Tank(60, 40, "Enemy", *this, true, 3)));
	playerBullets.clear();
	enemyBullets.clear();
}

void Controller::SetPlayer(Tank* player)
{
	this->player = player;
}

void Controller::SetMap(Map* map)
{
	this->map = map;
}

void Controller::SetMenu(Menu* menu)
{
	this->menu = menu;
}

void Controller::SetPauseMenu(PauseMenu* menu)
{
	pmenu = menu;
}

void Controller::SetLoseMenu(LoseMenu* menu)
{
	this->lmenu = menu;
}

void Controller::AddPlayerBullet(Bullet b)
{
	playerBullets.push_back(b);
}

void Controller::AddEnemyBullet(Bullet b)
{
	enemyBullets.push_back(b);
}

void Controller::AddBot(Bot b)
{
	enemies.push_back(b);
}

void Controller::Keyboard(unsigned char key)
{
	if(start)
	{
		if(lose)
		{
			lmenu->Keyboard(key);
		}
		else
		{
			switch(key) {
			case 27:
				pause = !pause;
				break;
  			}
			if(pause)
				pmenu->Keyboard(key);
			else
				player->Keyboard(key);
			}
	}
	else
	{
		menu->Keyboard(key);
	}
}
void Controller::SpecialKeyboard(int key)
{
	if(start)
	{
		if(lose)
		{
			lmenu->SpecialKeyboard(key);
		}
		else
		{
			if(pause)
				pmenu->SpecialKeyboard(key);
			else
				player->SpecialKeyboard(key);
		}
	}
	else
	{
		menu->SpecialKeyboard(key);
	}
}

Controller::~Controller()
{
	delete menu;
	delete pmenu;
	delete player;
	delete map;
}