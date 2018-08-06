#ifndef COLLISION_H
#define COLLISION_H

#include <allegro.h>
#include <string>
#include <algorithm>
#include <fstream>
#include "Global.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

using namespace std;

class Collision
{
public:
    Collision();
    ~Collision();
    void Update(BITMAP *Buffer,Player &player,Enemy &enemy, Map &m);
    void Draw(BITMAP *Buffer);
    void LoadCollisionMap(const char *fileName, int level);
    void PlatformCollision(BITMAP *Buffer, Player &player, Map &m);
    int LevelEnd(Player &player, Map &m);
    void EPCollision(Player &player, Enemy &enemy, Map &m);

protected:

private:
    int loadCounterX;
    int loadCounterY;
    int mapSizeX;
    int mapSizeY;
    int colMapFile[3][100][100];
    string line;

};


#endif //COLLISION_H
