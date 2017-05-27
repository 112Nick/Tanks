TanksElite: TanksElite.o Tank.o Controller.o Map.o Menu.o Point.o GameObject.o Bullet.o Rectangle.o Block.o MenuBase.o PauseMenu.o Bot.o LoseMenu.o
	g++ -g Bot.o TanksElite.o Tank.o Controller.o Map.o Menu.o Point.o GameObject.o Bullet.o Rectangle.o Block.o MenuBase.o PauseMenu.o LoseMenu.o -o TanksElite -lglut -lGL -lGLU -lGLEW

TanksElite.o: TanksElite.cpp
	g++ -c -g TanksElite.cpp -std=c++11

Tank.o: Tank.cpp
	g++ -c -g Tank.cpp -std=c++11

Controller.o: Controller.cpp
	g++ -c -g Controller.cpp -std=c++11

Point.o: Point.cpp
	g++ -c -g Point.cpp -std=c++11

GameObject.o: GameObject.cpp
	g++ -c -g GameObject.cpp -std=c++11

Bullet.o: Bullet.cpp
	g++ -c -g Bullet.cpp -std=c++11

Rectangle.o: Rectangle.cpp
	g++ -c -g Rectangle.cpp -std=c++11

Map.o: Map.cpp
	g++ -c -g Map.cpp -std=c++11

Block.o: Block.cpp
	g++ -c -g Block.cpp -std=c++11

MenuBase.o: MenuBase.cpp
	g++ -c -g MenuBase.cpp -std=c++11

Menu.o: Menu.cpp
	g++ -c -g Menu.cpp -std=c++11

PauseMenu.o: PauseMenu.cpp
	g++ -c -g PauseMenu.cpp -std=c++11

Bot.o: Bot.cpp
	g++ -c -g Bot.cpp -std=c++11

LoseMenu.o: LoseMenu.cpp
	g++ -c -g LoseMenu.cpp -std=c++11

clean:
	rm -f *.o *.a *.out binary
