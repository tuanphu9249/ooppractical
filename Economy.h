#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;
#include "Flight.h"

class Economy : public Flight
{
    public:
        virtual int priceCalculation(Airport departure, Airport arrival);
        virtual int speedCalculation(Airport departure, Airport arrival);

};

#endif
