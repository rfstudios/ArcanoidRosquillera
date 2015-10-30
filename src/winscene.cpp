#include "winscene.h"
#include "mainprocess.h"

winScene::~winScene(){}

void winScene::Start()
{
    graph=engine->loadPNG("resources/Win.png");
    transform.position=Vector2<float>(271,77.5);
}

void winScene::Update()
{
    if(engine->key[_space])
    {
        mainProcess *padre = dynamic_cast<mainProcess*> (engine->taskManager[father]);
        padre->setState(1);
    }
}
