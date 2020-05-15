#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include<vector>
using namespace std;


class Airport
{
    private:
        string name;
        Flight* flights;
        int numFlights;

    public:
        Airport(string name);
        void addFlight(Flight aFlight);
        void setName(string name);

        string getName();
        Flight* getFlights();
        int getNumFlights();


        ~Airport();



};

#endif