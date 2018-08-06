#ifndef CAMERA_H
#define CAMERA_H


#include <allegro.h>
#include "Global.h"

class Camera
{
public:
    Camera();
    ~Camera();
    void Update(int x, int y);
    void Draw(BITMAP *Buffer);
    void SetPosition(int x, int y);

private:
    int cameraX, cameraY;
};


#endif //CAMERA_H
