#include "../include/Map.h"

Map::Map()
{
    loadCounterX = loadCounterY = 0;
    level = 0;
    Map::LoadMap("levels/Map1.txt", 0);
    Map::LoadMap("levels/Map2.txt", 1);
    Map::LoadMap("levels/Map3.txt", 2);
    Ground = load_bitmap("media/ground.bmp", NULL);
    Stone = load_bitmap("media/stone.bmp", NULL);
}

Map::~Map()
{

}

void Map::Draw(BITMAP *Buffer)
{
    for(int i =0; i< mapSizeX; i++)
    {
        for(int j =0 ; j < mapSizeY; j++)
        {
            if(mapFile[level][i][j]==0)
            {
                rectfill ( Buffer, i*BlockSize, j*BlockSize, i*BlockSize+BlockSize, j*BlockSize+BlockSize, makecol(255,255, 255));
            }
            if(mapFile[level][i][j]==1)
            {
                rectfill ( Buffer, i*BlockSize, j*BlockSize, i*BlockSize+BlockSize, j*BlockSize+BlockSize, makecol(0,255, 255));
            }
            if(mapFile[level][i][j]==2)
            {
                stretch_blit(Ground, Buffer, 0, 0, 128, 128, i*BlockSize, j*BlockSize, BlockSize, BlockSize);
            }
            if(mapFile[level][i][j]==3)
            {
                stretch_blit(Stone, Buffer, 0, 0, 128, 128, i*BlockSize, j*BlockSize, BlockSize, BlockSize);
            }
            if(mapFile[level][i][j]==4)
            {
                rectfill ( Buffer, i*BlockSize, j*BlockSize, i*BlockSize+BlockSize, j*BlockSize+BlockSize, makecol(0,255, 0));
            }
        }
    }
}

void Map::Update()
{

}

void Map::LoadMap(const char *fileName, int level)
{
    ifstream openfile(fileName);
    if(openfile.is_open())
    {
        getline(openfile, line);
        line.erase(remove(line.begin(),line.end(),' '),line.end());
        mapSizeX = line.length();
        mapSizeY = 0;
        openfile.seekg(0,ios::beg);
        while(!openfile.eof())
        {
            openfile >> mapFile[level][loadCounterX][loadCounterY];
            loadCounterX ++;
            if(loadCounterX >= mapSizeX)
            {
                loadCounterX = 0;
                loadCounterY ++;
                mapSizeY ++;
            }
        }
        loadCounterX = loadCounterY = 0;
    }
    else
    {
        allegro_message("Cannot find the map file !");
    }
}

int Map::GetLevel()
{
    return level;
}

void Map::SetLevel(int value)
{
    level = value;
}

