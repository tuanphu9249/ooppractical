#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flight.h"
class Economy : public Ticket
{
    public:
        Economy(Flight* aFlight, string aName, string aDOB, string aSeatNumber);
        virtual void setPrice();

};

#endif
