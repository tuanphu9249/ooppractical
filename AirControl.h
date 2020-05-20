#ifndef AIRCONTROL_H
#define AIRCONTROL_H

#include <iostream>
#include "Flight.h"
#include "Airport.h"
#include "Ticket.h"
#include <map>
#include <vector>
using namespace std;


class AirControl
{
    private:
        map<string, Airport*> airports;
        int numAirports;
        int costs[50][50];
    public:
        AirControl(string airportFile, string flightFile);
        
        vector<Airport*> getAirports();                     // return list of airports that the system manage
        int getNumAirports();                      // return number of airports that the system manage

        vector<Flight*> directFlightCheck(string departure, string arrival); // check if there is a direct
                                                                            // flight between departure and arrival, return the actual flight
                                                                            // if no return null
        bool buyTicket(string departure, string arrival, Ticket* ticket);    

        Airport* cheapeastRoute(string departure, string arrival);    // return the cheapeast route
                                                                        // between arrival and destination as an array of airports

        int bestRoute(string departure, string arrival);              // return the cheapeast cost between arrival and destination


        ~AirControl();
    private:
        void readAirports(string airportText);              // read airports data from airports.txt
        void readFlights(string flightText);                 // read flights data from flights.txt
};

#endif
