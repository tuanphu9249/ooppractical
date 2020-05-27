#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flight.h"
class Economy : public Ticket
{
    public:
        Economy(string aFlightName, int aBasePrice);
        Economy(string aFlightName, string aName, string aDOB, int aSeatNumber, int basePrice);
        virtual void setPrice();

};

#endif
