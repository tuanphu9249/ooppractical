#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;
#include "Ticket.h"

class Business : public Ticket
{
    public:
        Business(Flight* aFlight, string aName, string aDOB, string aSeatNumber);
        virtual int priceCalculation();

};
#endif
