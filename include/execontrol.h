#ifndef EXECONTROL_H
#define EXECONTROL_H

#include "rf_process.h"


class exeControl : public RF_Process
{
    public:
        exeControl():RF_Process("execontrol"){}
        virtual ~exeControl();

        virtual void Update();
};

#endif // EXECONTROL_H
