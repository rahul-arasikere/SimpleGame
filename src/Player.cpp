#include "../include/Player.h"

Player::Player()
{
    width = 10;
    height = 10;
    x = (ScreenWidth - width)/2;
    y = (ScreenHeight - height)/2;
    x2 = x + width;
    y2 = y + height;
    origX = x;
    origY = y;
    velx = vely = 0;
    speed = 2;
    jumpspeed = -15;
    gravity = 1;
    Jump = Platform = false;
    hDir = 0;
    vDir = 2;
    lives = 5;
    Character = load_bitmap("media/character.bmp", NULL);
    frame = 1;
}

Player::~Player()
{

}

void Player::Update()
{
    Player::Controls();
    Player::SetPosition();
}

void Player::Draw(BITMAP *Buffer)
{
    rectfill ( Buffer, x, y, x+10, y+10, makecol(255,0,0));
}


void Player::Controls()
{
    if (key[KEY_RIGHT])
    {
        velx=speed;
        hDir=1;
    }
    else if (key[KEY_LEFT])
    {
        velx=-speed;
        hDir=2;
    }
    else if (key[KEY_UP] && Jump)
    {
        vely = jumpspeed;
        vDir = 1;
        Platform = false;
        Jump = false;
    }
    else
    {
        velx=0;
        hDir=0;
    }
}

void Player::SetPosition()
{
    if (vely >= 0)
    {
        vDir = 2;
    }

    if (!Platform)
    {
        vely += gravity;
    }
    else
    {
        vely = 0;
    }

    x+=velx;
    y+=vely;
    x2 = x+width;
    y2 = y+height;
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

int Player::GetX2()
{
    return x2;
}

int Player::GetY2()
{
    return y2;
}

int Player::GetSpeed()
{
    return speed;
}

int Player::GetGravity()
{
    return gravity;
}

int Player::GetOrigX()
{
    return origX;
}

int Player::GetOrigY()
{
    return origY;
}

bool Player::GetPlatform()
{
    return Platform;
}

void Player::SetPlatform(bool value)
{
    Platform = value;
}

bool Player::GetJump()
{
    return Jump;
}

void Player::SetJump(bool value)
{
    Jump = value;
}

int Player::GetVelX()
{
    return velx;
}

int Player::GetVelY()
{
    return vely;
}

int Player::GetHDir()
{
    return hDir;
}

int Player::GetVDir()
{
    return vDir;
}

void Player::SetX(int value)
{
    x=value;
}

void Player::SetY(int value)
{
    y=value;
}

void Player::SetX2(int value)
{
    x2=value;
}

void Player::SetY2(int value)
{
    y2=value;
}

void Player::SetVelY(int value)
{
    vely=value;
}

int Player::GetLives()
{
    return lives;
}

void Player::SetLives(int value)
{
    lives = value;
}
