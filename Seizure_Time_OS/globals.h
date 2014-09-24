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
};

#endif // GLOBALS_H
