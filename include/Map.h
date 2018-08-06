#ifndef MAP_H
#define MAP_H

#include <allegro.h>
#include <fstream>
#include <algorithm>
#include <string>
#include "Global.h"
using namespace std;
class Map
{
public:
    Map();
    ~Map();

    void Update();
    void Draw(BITMAP *Buffer);
    void LoadMap(const char *fileName, int level);
    int GetLevel();
    void SetLevel(int value);


protected:

private:
    int loadCounterX, loadCounterY;
    int mapSizeX, mapSizeY;
    int mapFile[3][100][100];
    int level;
    string line;
    BITMAP *Ground, *Stone, *Apple;
};


#endif //MAP_H
