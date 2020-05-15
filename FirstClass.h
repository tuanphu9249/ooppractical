#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;
#include "Ticket.h"

class FirstClass : public Ticket
{
    public:
        FirstClass(Flight aFlight, string aName, string aDOB, string aSeatNumber);
        virtual int priceCalculation();

}

#endif