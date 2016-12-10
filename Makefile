TanksElite: main.o liblist.a libin.a
	g++ -g TanksElite.o Tank.o Controller.o Point.o GameObject.o Bullet.o Rectangle.o -lglut -lGL -lGLU -lGLEW

TanksElite.o: TanksElite.cpp
	g++ -c TanksElite.cpp

Tank.o: Tank.cpp
	g++ -c Tank.cpp

Controller.o: Controller.cpp
	g++ -c Controller.cpp

Point.o: Tank.cpp
	g++ -c Tank.cpp

GameObject.o: Tank.cpp
	g++ -c Tank.cpp

Bullet.o: Tank.cpp
	g++ -c Tank.cpp

Rectangle.o: Tank.cpp
	g++ -c Tank.cpp

clean:
	rm -f *.o *.a *.out binary
