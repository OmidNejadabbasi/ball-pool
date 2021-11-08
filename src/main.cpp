#include "include/olcConsoleGameEngineSDL.h"
#include <iostream>
#include <vector>
using namespace std;

struct sBall
{
    float px, py;
    float radius;
    float vx, vy;
    float ax, ay;

    int id;
};

class BallPool : public olcConsoleGameEngine
{
private:
    vector<pair<float, float>> modelCircle;
    vector<sBall> balls;

    void AddBall(float x, float y, float r = 8.0f)
    {
        sBall ball;
        ball.px = x;
        ball.py = y;
        ball.vx = 0;
        ball.vy = 0;
        ball.ax = 0;
        ball.ay = 0;

        ball.radius = r;
        ball.id = balls.size();
    }

public:
    bool OnUserCreate()

    {

        modelCircle.push_back({0.0f, 0.0f});
        int iPoints = 20;
        for (int i = 0; i < iPoints; i++)
        {
            modelCircle.push_back({cosf((float)(iPoints - 1) * 2.0f * 3.1415f), sinf((float)(iPoints - 1) * 2.0f * 3.1415f)});
        }

        AddBall(ScreenWidth() * 0.25f, ScreenHeight() * 0.5f);
        AddBall(ScreenWidth() * 0.75f, ScreenHeight() * 0.5f);
        return true;
    }

    bool OnUserUpdate(float elapsedTime)
    {

        // clear the screen
        Fill(0, 0, ScreenWidth(), ScreenHeight(), ' ');

        // draw the balls
        for (auto &b : balls)
        {
            DrawWireFrameModel(modelCircle, b.px, b.py, atan2f(b.vx, b.vy), b.radius, FG_WHITE);
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    BallPool ballPool;
    if (ballPool.ConstructConsole(80, 40, 6, 6))
        ballPool.Start();
    else
        cout << "The game could not start ! :(";

    return 0;
}
