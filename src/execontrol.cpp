#include "execontrol.h"

exeControl::~exeControl(){}
void exeControl::Update()
{
    if(engine->key[_esc] || engine->key[_close_window])
    {
        engine->isRunning(false);
    }
}
