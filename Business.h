#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
using namespace std;
#include "Flight.h"

class Business : public Flight
{
    public:
        virtual int priceCalculation(Airport departure, Airport arrival);
        virtual int speedCalculation(Airport departure, Airport arrival);


};
#endif
