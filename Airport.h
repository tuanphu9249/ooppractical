#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
using namespace std;


class Airport
{
    private:
        string name;
        FlightType* flights;
        int numFlights;

    public:
        Airport(string name);
        void addFlight(string departure, string arrival);
        void setName(string name);

        string getName();
        string* getFlights();
        int getNumFlights();

        ~Airport();



};

#endif