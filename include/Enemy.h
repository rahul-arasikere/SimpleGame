#ifndef ENEMY_H
#define ENEMY_H
#include <allegro.h>
#include <fstream>
#include <cmath>

using namespace std;

class Enemy
{
public:
    Enemy();
    ~Enemy();
    void Update(int level);
    void Draw(BITMAP *Buffer, int level);
    void LoadEnemies(const char *fileName);
    void Move(int level);
    int GetAmountOfEnemies();
    int GetX(int index);
    int GetY(int index);
    int GetX2(int index);
    int GetY2(int index);
    int GetLevel(int index);
protected:

private:
    int x[10], y[10];
    int speed[10];
    int rangeCounter[10];
    int range[10];
    int dir[10];
    int level[10];
    int width[10], height[10];
    bool Increase[10];
    int loadCounter;
    int amountOfEnemies;
};

#endif // ENEMY_H
