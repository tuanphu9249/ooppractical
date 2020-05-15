#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include <iostream>
using namespace std;
#include "FlightType.h"

class FirstClass : public FlightType
{
    public:
        virtual int priceCalculation(Airport departure, Airport arrival);
        virtual int speedCalculation(Airport departure, Airport arrival);

}

#endif