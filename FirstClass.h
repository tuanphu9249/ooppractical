#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flight.h"
class FirstClass : public Ticket
{
    public:
        FirstClass(Flight* aFlight, string aName, string aDOB, string aSeatNumber);
        virtual void setPrice();
};

#endif