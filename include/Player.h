#ifndef PLAYER_H
#define PLAYER_H
#include "Global.h"
#include <allegro.h>
class Player
{
public:
    Player();
    ~Player();

    void Update();
    void Draw(BITMAP *Buffer);
    void SetPosition();
    void Controls();

    /*
                GET FUNCTIONS
    */
    int GetX();
    int GetY();
    int GetX2();
    int GetY2();
    int GetSpeed();
    int GetGravity();
    int GetOrigX();
    int GetOrigY();
    bool GetPlatform();
    bool GetJump();
    int GetVelX();
    int GetVelY();
    int GetHDir();
    int GetVDir();
    int GetLives();

    /*
            SET FUNCTIONS
    */
    void SetX(int value);
    void SetY(int value);
    void SetX2(int value);
    void SetY2(int value);
    void SetVelY(int value);
    void SetPlatform(bool value);
    void SetJump(bool value);
    void SetLives(int value);

private:
    int x, y;
    int origX, origY;
    int velx, vely;
    int width, height;
    int hDir, vDir;
    int x2, y2;
    int speed, gravity, jumpspeed;
    bool Jump, Platform;
    int lives;
    int frame;
    BITMAP *Character;
};

#endif //PLAYER_H
