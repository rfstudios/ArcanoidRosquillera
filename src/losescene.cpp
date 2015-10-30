#include "losescene.h"
#include "mainprocess.h"

loseScene::~loseScene(){}

void loseScene::Start()
{
    graph=engine->loadPNG("resources/Lose.png");
    transform.position=Vector2<float>(271,77.5);
}

void loseScene::Update()
{
    if(engine->key[_space])
    {
        mainProcess *padre = dynamic_cast<mainProcess*> (engine->taskManager[father]);
        padre->setState(1);
    }
}
