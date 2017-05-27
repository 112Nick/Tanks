#ifndef BOT_H
#define BOT_H
#include "Tank.h"
#include <vector>
#include <chrono>

class Bot
{
public:
    Bot(Tank t);
    void Tick();
    void Render();
    void EmulateKeyboard(); //через определённые промежутки времени вызывает Keyboard у tank
    Tank& GetTank();
    void SetOpDelay(int delay);
    void SetPerfDelay(int delay);
    int GetOpDelay();
    int GetPerfDelay();
private:
    Tank tank;
    std::vector<int> keys;
    int shootKey;
    std::list<int> operationQueue;
    int opDelay, perfDelay; //opDelay - задержка добавления операций в очередь
                            //perfDelay - задержка выполнения операций из очереди
    std::chrono::system_clock::time_point prevOp; //prevOp - время предыдущего добавления операций
    std::chrono::system_clock::time_point prevPerf; //prevPerf - время предыдущего выполнения операций
};

#endif