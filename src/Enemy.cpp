#include "../include/Enemy.h"

Enemy::Enemy()
{
    loadCounter = 0;
    amountOfEnemies = 0;
    Enemy::LoadEnemies("enemy/Enemy.txt");
    for(int i=0; i<amountOfEnemies; i++)
    {
        rangeCounter[i]=0;
        int Rand = rand()%2 + 1;
        if(Rand == 1)
            Increase[i] = true;
        else
            Increase[i] = false;
    }
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::LoadEnemies(const char *fileName)
{
    ifstream openfile(fileName);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            openfile >> x[loadCounter] >> y[loadCounter] >> speed[loadCounter] >> dir[loadCounter] >> range[loadCounter] >> level[loadCounter] >> width[loadCounter] >> height[loadCounter];
            loadCounter++;
            amountOfEnemies++;
        }
        loadCounter = 0;
    }
    else
    {
        allegro_message("Enemy file could not be found!");
    }
}

void Enemy::Move(int level)
{
    for(int i=0; i<amountOfEnemies; i++)
    {
        if(this->level[i] == level)
        {
            if(Increase[i])
            {
                rangeCounter[i]++;
            }
            else
            {
                rangeCounter[i]--;
            }
            if(labs(rangeCounter[i])==range[i])
            {
                if(dir[i]==1)
                {
                    dir[i]=2;
                }
                else if(dir[i]==2)
                {
                    dir[i]=1;
                }
                else if(dir[i]==3)
                {
                    dir[i]=4;
                }
                else if(dir[i]==4)
                {
                    dir[i]=3;
                }
                if(Increase[i])
                {
                    Increase[i]=false;
                }
                else
                {
                    Increase[i]=true;
                }
            }
            if(dir[i]==1)
            {
                x[i]+=speed[i];
            }
            else if(dir[i]==2)
            {
                x[i]-=speed[i];
            }
            else if(dir[i]==3)
            {
                y[i]-=speed[i];
            }
            else if(dir[i]==4)
            {
                y[i]+=speed[i];
            }
        }
    }
}

void Enemy::Update(int level)
{
    Enemy::Move(level);
}

void Enemy::Draw(BITMAP *Buffer, int level)
{
    for(int i=0; i<amountOfEnemies; i++)
    {
        if(this->level[i]==level)
        {
            rectfill(Buffer, x[i], y[i], x[i]+width[i], y[i]+height[i], makecol(0,0, 255));
        }
    }
}

int Enemy::GetAmountOfEnemies()
{
    return amountOfEnemies;
}

int Enemy::GetX(int index)
{
    return x[index];
}

int Enemy::GetY(int index)
{
    return y[index];
}

int Enemy::GetX2(int index)
{
    return x[index] + width[index];
}

int Enemy::GetY2(int index)
{
    return y[index] + height[index];
}

int Enemy::GetLevel(int index)
{
    return level[index];
}
