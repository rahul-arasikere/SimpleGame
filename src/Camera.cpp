#include "../include/Camera.h"

Camera::Camera()
{
    cameraX=0;
    cameraY=0;
}

Camera::~Camera()
{
    //dtor
}

void Camera::Update(int x, int y)
{
    Camera::SetPosition(x, y);
}

void Camera::Draw(BITMAP *Buffer)
{
    blit(Buffer, screen, cameraX, cameraY, 0, 0, ScreenWidth, ScreenHeight);
}

void Camera::SetPosition(int x, int y)
{
    cameraX = x - ScreenWidth/2;
    cameraY = y - ScreenHeight/2;
    if (cameraX < 0)
    {
        cameraX = 0;
    }
    if (cameraY < 0)
    {
        cameraY = 0;
    }
}
