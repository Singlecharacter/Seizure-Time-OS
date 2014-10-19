#ifndef GLOBALS_H
#define GLOBALS_H

#include <QDate>
#include <QString>

#include "pcbcontrol.h"

class Globals
{
public:

    Globals();
    ~Globals();

    static QString mainDir;
    static PCBControl globalPCBControl;
    static QDate systemDate;
};

#endif // GLOBALS_H
