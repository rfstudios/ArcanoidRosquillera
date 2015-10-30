#ifndef LOSESCENE_H
#define LOSESCENE_H

#include "rf_process.h"


class loseScene : public RF_Process
{
    public:
        loseScene():RF_Process("lose"){}
        virtual ~loseScene();

        virtual void Start();
        virtual void Update();
};

#endif // LOSESCENE_H
