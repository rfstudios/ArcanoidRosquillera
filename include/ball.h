#ifndef BALL_H
#define BALL_H

#include "rf_process.h"


class Ball : public RF_Process
{
    public:
        Ball():RF_Process("ball"){}
        virtual ~Ball();

        virtual void Start();
        virtual void Update();

    private:
        Vector2<float> velocity;
        bool interact=false;
};

#endif // BALL_H
