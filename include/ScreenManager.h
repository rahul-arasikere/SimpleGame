#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <allegro.h>
#include <string>
#include <ctime>
#include <sstream>
#include "Enemy.h"
#include "Player.h"
#include "Camera.h"
#include "Global.h"
#include "Map.h"
#include "Collision.h"


class ScreenManager
{
    public:
        ScreenManager();
        ~ScreenManager();
        enum ScreenState
        {
            Title,
            Game,
            Gameover
        };
        ScreenState gameState;
        void Update(BITMAP *Buffer, bool &done);
        void Draw(BITMAP *Buffer);

    protected:

    private:
        void UpdateTitleScreen(bool &done);
        void DrawTitleScreen(BITMAP *Buffer);

        void UpdateGameScreen(BITMAP *Buffer);
        void DrawGameScreen(BITMAP *Buffer);

        void UpdateGameoverScreen();
        void DrawGameoverScreen(BITMAP *Buffer);

        int menuCounter;
        string menuItem[2];
        BITMAP *titleBackgroundImage;
        BITMAP *GameoverBackgroundImage;

        Player player;
        Camera camera;
        Map m;
        Enemy enemy;
        Collision collision;

        bool keyPressed;
        bool lastKeyPressed;
};

#endif // SCREENMANAGER_H
