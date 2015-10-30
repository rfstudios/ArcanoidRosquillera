#ifndef WINSCENE_H
#define WINSCENE_H

#include "rf_process.h"

class winScene : public RF_Process
{
    public:
        winScene():RF_Process("lose"){}
        virtual ~winScene();

        virtual void Start();
        virtual void Update();
};

#endif // WINSCENE_H
