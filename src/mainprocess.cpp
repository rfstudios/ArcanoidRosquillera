#include "mainprocess.h"
#include "mainmenu.h"
#include "block.h"
#include "ball.h"
#include "player.h"
#include "losescene.h"
#include "winscene.h"

mainProcess::~mainProcess(){}

void mainProcess::Start()
{
    scene=engine->newTask(new mainMenu(),id);
    graph=engine->loadPNG("resources/Background.png");
}

void mainProcess::Update()
{
    switch(stateMachine)
    {
        case 0:
            if(!engine->taskManager[scene])
            {
                scene=engine->newTask(new mainMenu(),id);
            }
            break;
        case 1:
            for(int j=0;j<1+level;j++)
            {
                for(int i=0;i<10;i++)
                {
                    int b=engine->newTask(new Block(),id);
                    engine->taskManager[b]->transform.position=Vector2<float>(125+100*i,15+33*j);
                }
            }
            ball=engine->newTask(new Ball(),id);
            engine->newTask(new Player(),id);
            setState(2);
            break;
        case 2:
            if(!engine->exists("block")){ setState(3); level++;}///Win
            if(engine->taskManager[ball]->transform.position.y>950) setState(4); ///Lose

            if(engine->key[_e]) engine->sendSignal("block",S_KILL);
            break;
        case 3:
            if(!engine->taskManager[scene])
            {
                scene=engine->newTask(new winScene(),id);
            }
            break;
        case 4:
            if(!engine->taskManager[scene])
            {
                scene=engine->newTask(new loseScene(),id);
            }
            break;
    }
}

void mainProcess::setState(int state)
{
    if(engine->taskManager[scene])
    {
        engine->sendSignal(scene,S_KILL);
    }

    if(stateMachine==2)
    {
        engine->sendSignal("block", S_KILL);
        engine->sendSignal(ball, S_KILL);
        engine->sendSignal("player", S_KILL);
    }

    stateMachine=state;
}
