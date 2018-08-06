#include "../include/ScreenManager.h"

ScreenManager::ScreenManager()
{
    gameState = Title;
    menuCounter = 0;
    keyPressed = false;
    lastKeyPressed = false;

    menuItem[0] = "Play Game";
    menuItem[1] = "End Game";
    titleBackgroundImage = load_bitmap("media/title.bmp", NULL);
    GameoverBackgroundImage = load_bitmap("media/gameover.bmp", NULL);
}

ScreenManager::~ScreenManager()
{
    //dtor
}

void ScreenManager::Update(BITMAP *Buffer, bool &done)
{
    switch(gameState)
    {
        case Title:
        ScreenManager::UpdateTitleScreen(done);
        break;

        case Game:
        ScreenManager::UpdateGameScreen(Buffer);
        break;

        case Gameover:
        ScreenManager::UpdateGameoverScreen();
        break;
    }
}

void ScreenManager::Draw(BITMAP *Buffer)
{
    switch(gameState)
    {
        case Title:
        ScreenManager::DrawTitleScreen(Buffer);
        break;

        case Game:
        ScreenManager::DrawGameScreen(Buffer);
        break;

        case Gameover:
        ScreenManager::DrawGameoverScreen(Buffer);
        break;
    }
}

void ScreenManager::UpdateTitleScreen(bool &done)
{
    if(key[KEY_DOWN])
        menuCounter++;
    else if(key[KEY_UP])
        menuCounter--;
    else if(key[KEY_Z])
    {
        if( menuCounter == 0 )
            gameState = Game;
        else
            done = true;
    }
    if(menuCounter > 1)
        menuCounter = 1;
    if(menuCounter < 0)
        menuCounter = 0;
}

void ScreenManager::DrawTitleScreen(BITMAP *Buffer)
{
    stretch_blit(titleBackgroundImage, Buffer,0,0,819,460,0,0,800,600);
    for(int i=0;i<2;i++)
    {
        textout_ex(Buffer, font, menuItem[i].c_str(),350,i*50+300,makecol(255,0,0), -1);
    }
    textout_ex(Buffer, font, menuItem[menuCounter].c_str(),350,menuCounter*50+300,makecol(255,255,0),-1);
    blit(Buffer,screen,0,0,0,0,800,600);
}

void ScreenManager::UpdateGameScreen(BITMAP *Buffer)
{
     m.Update();
     player.Update();
     enemy.Update(m.GetLevel());
     collision.Update(Buffer, player, enemy, m);
     camera.Update(player.GetX(), player.GetY());
}

void ScreenManager::DrawGameScreen(BITMAP *Buffer)
{
    m.Draw(Buffer);
    player.Draw(Buffer);
    enemy.Draw(Buffer,m.GetLevel());
    stringstream str;
    str<< player.GetLives();
    textout_ex(Buffer, font,str.str().c_str(), 10, 10, makecol(255, 0, 0), -1);
     if(player.GetLives()<=0)
     {
         gameState = Gameover;
         player.SetLives(5);
         player.SetX(player.GetOrigX());
         player.SetY(player.GetOrigY());
     }
    camera.Draw(Buffer);

}

void ScreenManager::UpdateGameoverScreen()
{
    if(key[KEY_Z])
        keyPressed = true;
    else if(keyPressed && !key[KEY_Z])
    {
        gameState = Title;
        keyPressed = false;
    }
}

void ScreenManager::DrawGameoverScreen(BITMAP *Buffer)
{
    stretch_blit(GameoverBackgroundImage,Buffer,0,0,852,558,0,0,800,600);
    blit(Buffer, screen,0,0,0,0,800,600);
}
