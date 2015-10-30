#ifndef MAINMENU_H
#define MAINMENU_H

#include "rf_process.h"


class mainMenu : public RF_Process
{
    public:
        mainMenu():RF_Process("mainmenu"){}
        virtual ~mainMenu();

        virtual void Start();
        virtual void Update();
};

#endif // MAINMENU_H
