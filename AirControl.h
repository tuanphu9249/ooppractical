#ifndef AIRCONTROL_H
#define AIRCONTROL_H

#include <iostream>
#include "Flight.h"
#include "Airport.h"
using namespace std;


class AirControl
{
    private:
        Airport* airports;
        Flight* flights;
        int numAirports;
        int numFlights;
        int[50][50] costs;
    public:
        AirControl();


        Flight* flightCheck(string arrival, string destination); // show flight ID, name, # of passengers,
                                                                    // price, speed, time of all flights available
        bool buyTicket(string arrival, string destination, Ticket* ticket);    

        Airport* cheapeastRoute(string arrival, string destination);    // return the cheapeast route
                                                                        // between arrival and destination as an array of airports

        int bestRoute(string arrival, string destination);              // return the cheapeast cost between arrival and destination


        ~AirControl();
    private:
        void readAirports();              // read airports data from airports.txt
        void readFlights();                 // read flights data from flights.txt
};

#endif
