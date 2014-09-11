#ifndef GLOBALS_H
#define GLOBALS_H

#include <QDate>

#include "pcbcontrol.h"

class Globals
{
public:

    Globals();
    ~Globals();

    static PCBControl globalPCBControl;
    static QDate systemDate;
    static int test;
};

#endif // GLOBALS_H
