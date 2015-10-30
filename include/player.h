#ifndef PLAYER_H
#define PLAYER_H

#include "rf_process.h"


class Player : public RF_Process
{
    public:
        Player():RF_Process("player"){}
        virtual ~Player();

        virtual void Start();
        virtual void Update();
};

#endif // PLAYER_H
