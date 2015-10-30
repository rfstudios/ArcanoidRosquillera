#include "mainmenu.h"
#include "mainprocess.h"

mainMenu::~mainMenu(){}

void mainMenu::Start()
{
    graph=engine->loadPNG("resources/MainMenu.png");
    transform.position=Vector2<float>(271,77.5);
}

void mainMenu::Update()
{
    if(engine->key[_space])
    {
        mainProcess *padre = dynamic_cast<mainProcess*> (engine->taskManager[father]);
        padre->setState(1);
    }
}
