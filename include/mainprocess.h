#ifndef MAINPROCESS_H
#define MAINPROCESS_H

#include "rf_process.h"

class mainProcess : public RF_Process
{
    public:
        mainProcess():RF_Process("mainprocess"){}
        virtual ~mainProcess();

        virtual void Start();
        virtual void Update();

        void setState(int state);

    private:
        int stateMachine=0; /// 0 = Main Menu; 1 = Prepare Game; 2 = Game Loop; 3 = Win & prepare next level; 4 = Fail & return to 0
        int scene,ball,level=0;
};

#endif // MAINPROCESS_H
