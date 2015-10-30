#include "block.h"

Block::~Block(){}

void Block::Start()
{
    graph=engine->loadPNG("resources/Block.png");
}
