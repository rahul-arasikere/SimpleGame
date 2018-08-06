#include "../include/Collision.h"

Collision::Collision()
{
    loadCounterX = loadCounterY = 0;
    Collision::LoadCollisionMap("levels/ColMap1.txt", 0);
    Collision::LoadCollisionMap("levels/ColMap2.txt", 1);
    Collision::LoadCollisionMap("levels/ColMap3.txt", 2);
}

Collision::~Collision()
{
    //dtor
}

void Collision::Update(BITMAP *Buffer, Player &player,Enemy &enemy, Map &m)
{
    Collision::PlatformCollision(Buffer, player, m);
    Collision::EPCollision(player, enemy, m);
    Collision::LevelEnd(player, m);
}

void Collision::Draw(BITMAP *Buffer)
{

}

void Collision::LoadCollisionMap(const char *fileName, int level)
{
    ifstream openfile(fileName);
    getline(openfile, line);
    line.erase(remove(line.begin(),line.end(),' '),line.end());
    mapSizeX = line.length();
    mapSizeY = 0;
    openfile.seekg(0,ios::beg);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            openfile >> colMapFile[level][loadCounterX][loadCounterY];
            loadCounterX ++;
            if(loadCounterX >= mapSizeX)
            {
                loadCounterX = 0;
                loadCounterY ++;
                mapSizeY++;
            }
        }
        loadCounterX = loadCounterY = 0;
    }
    else
    {
        allegro_message("Cannot find the collision map file !");
    }
}

void Collision::PlatformCollision(BITMAP *Buffer, Player &player, Map &m)
{
    for (int i =0; i< mapSizeX; i++)
    {
        for (int j=0; j < mapSizeY; j++)
        {
            if(colMapFile[m.GetLevel()][i][j]==1)
            {
                if(player.GetX()>i*BlockSize+BlockSize || player.GetY()>j*BlockSize+BlockSize|| player.GetX2()<i*BlockSize || player.GetY2()<j*BlockSize)
                {
                    //No Collision
                    player.SetPlatform(false);
                }
                else
                {
                    if(player.GetVDir() == 2&&player.GetY()-player.GetVelY()<=j*BlockSize)
                    {
                        player.SetY(j*BlockSize - 10);
                        player.SetY2(player.GetY() + 10);
                        player.SetPlatform(true);
                        player.SetJump(true);
                        player.SetVelY(0);
                    }
                    else if(player.GetVDir() == 1)
                    {
                        player.SetY(player.GetY()+player.GetSpeed()*2);
                        player.SetY2(player.GetY() + 10);
                        player.SetVelY(0);
                        player.SetPlatform(false);
                        player.SetJump(false);
                    }
                    if(player.GetHDir() == 1&& !player.GetPlatform())
                    {
                        player.SetX(player.GetX()-player.GetSpeed());
                        player.SetX2(player.GetX()+10);
                    }
                    else if(player.GetHDir() == 2 && !player.GetPlatform())
                    {
                        player.SetX(player.GetX()+player.GetSpeed());
                        player.SetX2(player.GetX()+10);
                    }
                }
            }
            else if(colMapFile[m.GetLevel()][i][j]==3)
            {
                if(player.GetX()>i*BlockSize+BlockSize || player.GetY()>j*BlockSize+BlockSize|| player.GetX2()<i*BlockSize || player.GetY2()<j*BlockSize)
                {
                    //No Collision
                    player.SetPlatform(false);
                }
                else
                {
                    player.SetLives(0);
                }
            }
        }
    }
}

int Collision::LevelEnd(Player &player, Map &m)
{
    for (int i =0; i< mapSizeX; i++)
    {
        for (int j=0; j < mapSizeY; j++)
        {
            if(colMapFile[m.GetLevel()][i][j]==2)
            {
                if(player.GetX()>i*BlockSize+BlockSize || player.GetY()>j*BlockSize+BlockSize|| player.GetX2()<i*BlockSize || player.GetY2()<j*BlockSize)
                {
                    //No Collision
                }
                else
                {
                    int level = m.GetLevel();
                    level++;
                    m.SetLevel(level);
                    if(level>2)
                    {
                        m.SetLevel(0);
                    }
                    player.SetX(player.GetOrigX());
                    player.SetY(player.GetOrigY());
                    clear_to_color(screen,makecol(0,0,0));
                    rest(1000);
                }
            }
        }
    }
}

void Collision::EPCollision(Player &player, Enemy &enemy, Map &m)
{
    for(int i=0; i<enemy.GetAmountOfEnemies(); i++)
    {
        if(enemy.GetLevel(i)==m.GetLevel())
        {
            if(player.GetX() > enemy.GetX2(i) || player.GetY() > enemy.GetY2(i) || player.GetX2() < enemy.GetX(i) || player.GetY2() < enemy.GetY(i))
            {
                //No collision;
            }
            else
            {
                player.SetLives(player.GetLives()-1);
            }
        }
    }
}
