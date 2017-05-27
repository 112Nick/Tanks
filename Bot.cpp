#include "Bot.h"

#include <chrono>
#include <iostream>
#include <GL/glut.h>

Bot::Bot(Tank t): tank(t) 
{  
    keys.push_back(GLUT_KEY_LEFT);
    keys.push_back(GLUT_KEY_UP);
    keys.push_back(GLUT_KEY_RIGHT);
    keys.push_back(GLUT_KEY_DOWN);
    keys.push_back(32);
    opDelay = 430;
    perfDelay = 200;
    shootKey = 32;

    prevOp = std::chrono::system_clock::now();
    prevPerf = std::chrono::system_clock::now();
}

void Bot::Tick()
{
    tank.Tick();
    EmulateKeyboard();
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - prevPerf).count();
    if(delta > perfDelay)
    {
        if(operationQueue.size() > 0)
        {
            int operation = operationQueue.front();
            operationQueue.pop_front();
            if(operation == shootKey)
            {
                tank.Keyboard(operation);
            }
            else
            {
                tank.SpecialKeyboard(operation);
            }
            prevPerf = now;
            }
    }
}

void Bot::Render()
{
    tank.Render();
}

void Bot::EmulateKeyboard()
{
    //проверить, прошло ли достаточно времени
    //сгенерировать случайную длину цепочки
    //добавить элементы цепочки в стек
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - prevOp).count();
    if(delta > opDelay)
    {
        int length = rand() % 3 + 1; //генерируем цепочки длиной 1..4
        int operation = rand() % 5; //генерируем случайную операцию
        for(int i = 0;i<length;i++)
        {
            operationQueue.push_back(keys[operation]);
        }

        prevOp = now;
    }
}

void Bot::SetOpDelay(int delay)
{
    opDelay = delay;
}

void Bot::SetPerfDelay(int delay)
{
    perfDelay = delay;
}

int Bot::GetOpDelay()
{
    return opDelay;
}

int Bot::GetPerfDelay()
{
    return perfDelay;
}

Tank& Bot::GetTank()
{
    return tank;
}