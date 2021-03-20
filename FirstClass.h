#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flight.h"
class FirstClass : public Ticket
{
    public:
        FirstClass(string aFlightName, int aBasePrice);
        FirstClass(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice);
        virtual void setPrice();
};

#endif