#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;
#include "Ticket.h"
#include "Flight.h"
class Business : public Ticket
{
    public:
        Business(string aFlightName, int aBasePrice);
        Business(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice);
        virtual void setPrice(int coef);

};
#endif
