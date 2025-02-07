#include "graphics.h"
#include "Game.h"
#include "config.h"
#include "menu.h"



void update(float ms)
{
    Game * game = reinterpret_cast<Game *>(graphics::getUserData());
    game->update();

}
//Draw the base of the app (background and arrows, menu button, etc...)
void draw()
{
    Game* game = reinterpret_cast<Game *>(graphics::getUserData());
    game->draw();
}
//Initialization of the application window
int main()
{

    Game mygame;
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Movie Browser");

    

    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    mygame.init();
    graphics::startMessageLoop();

    return 0;
}