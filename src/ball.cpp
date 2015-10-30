#include "ball.h"
#include "rf_process.h"
#include "block.h";
#include <stdlib.h>

Ball::~Ball(){}

void Ball::Start()
{
    graph=engine->loadPNG("resources/Ball.png");
    transform.position=Vector2<float>(640,650);
    velocity=Vector2<float>(100,100);
}

void Ball::Update()
{
    RF_Process *col=engine->collision("block",this);
    if(col>0)
    {
        if(!interact)
        {
            Block *b=dynamic_cast<Block*>(col);
            b->Die();

            velocity.y=-velocity.y;
            interact=true;
        }
    }

    col=engine->collision("player",this);
    if(col>0)
    {
        if(!interact)
        {
            if(velocity.x<0) velocity.x-=abs((int)(col->transform.position.x+50-transform.position.x));
            else velocity.x+=abs((int)(col->transform.position.x+50-transform.position.x));

            if(velocity.x>500) velocity.x=500;
            if(velocity.x<-500) velocity.x=-500;

            velocity.y=-(velocity.y+rand()%200-(col->transform.position.x+50-transform.position.x))*5;
            if(velocity.y>-50) velocity.y=-50;
            if(velocity.y<-200) velocity.y=-200;

            engine->Debug(velocity.y);
            interact=true;
        }
    }
    if(transform.position.x<50 || transform.position.x>1210)
    {
        if(!interact)
        {
            velocity.x=-velocity.x;
            interact=true;
        }
    }
    else if(transform.position.y<20)
    {
        if(!interact)
        {
            velocity.y=-velocity.y;
            interact=true;
        }
    }
    else
    {
        interact=false;
    }

    transform.position.x+=velocity.x*engine->time->deltaTime;
    transform.position.y+=velocity.y*engine->time->deltaTime;
}
