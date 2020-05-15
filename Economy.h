#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;
#include "Ticket.h"

class Economy : public Ticket
{
    public:
        Economy(Flight aFlight, string aName, string aDOB, string aSeatNumber);
        virtual int priceCalculation();

};

#endif
