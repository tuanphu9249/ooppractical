#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;
#include "Ticket.h"

class Business : public Ticket
{
    public:
        virtual int priceCalculation();


};
#endif
