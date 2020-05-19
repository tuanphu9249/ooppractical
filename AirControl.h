#ifndef AIRCONTROL_H
#define AIRCONTROL_H

#include <iostream>
#include "Flight.h"
#include "Airport.h"
using namespace std;


class AirControl
{
    private:
        map<string, Airport*> airports;
        int numAirports;
        int numFlights;
        int[50][50] costs;
    public:
        AirControl();


        vector<Flight*> directFlightCheck(string departure, string arrival); // check if there is a direct
                                                                            // flight between departure and arrival, return the actual flight
                                                                            // if no return null
        bool buyTicket(string departure, string arrival, Ticket* ticket);    

        Airport* cheapeastRoute(string departure, string arrival);    // return the cheapeast route
                                                                        // between arrival and destination as an array of airports

        int bestRoute(string departure, string arrival);              // return the cheapeast cost between arrival and destination


        ~AirControl();
    private:
        void readAirports();              // read airports data from airports.txt
        void readFlights();                 // read flights data from flights.txt
};

#endif
