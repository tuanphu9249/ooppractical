#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include "Flight.h"

using namespace std;


class Airport
{
    private:
        string name;
        Flight* flights;
        int numFlights;

    public:
        Airport();
        Airport(string aName);
        void addFlight(Flight aFlight);
        void setName(string aName);

        string getName();
        Flight* getFlights();
        int getNumFlights();


        ~Airport();



};

#endif