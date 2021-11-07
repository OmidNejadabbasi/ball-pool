#include "include/olcConsoleGameEngineSDL.h"

class BallPool : public olcConsoleGameEngine
{
private:
    /* data */
public:
    bool OnUserCreate()
    {

        return true;
    }

    bool OnUserUpdate(float elapsedTime)
    {

        return true;
    }
};

int main(int argc, char const *argv[])
{
    BallPool ballPool;
    ballPool.ConstructConsole(80, 40, 8, 8);
    ballPool.Start();
    return 0;
}
