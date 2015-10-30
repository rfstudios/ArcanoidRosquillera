#ifndef BLOCK_H
#define BLOCK_H

#include "rf_process.h"


class Block : public RF_Process
{
    public:
        Block():RF_Process("block"){}
        virtual ~Block();

        virtual void Start();

        void Die(){engine->sendSignal(id,S_KILL);}
};

#endif // BLOCK_H
