#include <SDL2/SDL.h>
#include "rf_declares.h"
#include "rf_engine.h"

#include "execontrol.h"
#include "mainprocess.h"

int main()
{
    RF_Engine *e = new RF_Engine(true);
    e->newWindow("Arcanoid (con Rosquillera)", SDL_WINDOW_OPENGL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_RENDERER_ACCELERATED);
    e->newTask(new exeControl());
    e->newTask(new mainProcess());

    do
    {
        e->run();
        SDL_Delay(1);
    }while(e->isRunning());

    e->destroyWindow();

    return 0;
}

