#ifndef FLIGHTTYPE_H
#define FLIGHTTYPE_H
#include <iostream>
#include "Airport.h"
using namespace std;


class FlightType
{
    protected:
        string type;
        Airport departure;
        Airport arrival;
        string flightName;
        static int flightID;
        int num_passengers;
        int price;
    public:
        FlightType(string type);
        virtual int priceCalculation(Airport departure, Airport arrival) = 0;
        virtual int speedCalculation(Airport departure, Airport arrival) = 0;

        int getNumPassenger();
        string getDeparture();
        string getArrival();
        void getType();
        int getID();
        string getName();

        void setName();
        void setDeparture();
        void setArrival();



        ~FlightType();




};

#endif