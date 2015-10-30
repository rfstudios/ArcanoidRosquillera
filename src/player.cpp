#include "player.h"

Player::~Player(){}

void Player::Start()
{
    graph=engine->loadPNG("resources/Player.png");
    transform.position=Vector2<float>(590,695);
}
void Player::Update()
{
    if(engine->key[_a] && transform.position.x>5) transform.position.x-=750*engine->time->deltaTime;
    if(engine->key[_d] && transform.position.x<1175) transform.position.x+=750*engine->time->deltaTime;
}
