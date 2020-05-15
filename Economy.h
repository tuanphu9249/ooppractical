#ifndef ECONOMY_H
#define ECONOMY_H
#include <iostream>
using namespace std;
#include "FlightType.h"

class Economy : public FlightType
{
    public:
        virtual int priceCalculation(Airport departure, Airport arrival);
        virtual int speedCalculation(Airport departure, Airport arrival);

}