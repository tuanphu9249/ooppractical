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
        map<string, Airport*> airports;     // input string whill return airport
        int numAirports;
        int costs[50][50];
        vector<vector<pair<int,int>>> graph;
        struct compare;
    public:
        AirControl();               // default constructor, do nothing
        AirControl(string airportFile, string flightFile);  // constructor that reads from files
        
        vector<Airport*> getAirports();                     // return list of airports that the system manage
        int getNumAirports();                      // return number of airports that the system manage

        vector<Flight*> directFlightCheck(string departure, string arrival); // check if there is a direct
                                                                            // flight between departure and arrival, return the actual flight
                                                                            // if no return null
        bool buyTicket(Flight* flight, Ticket* ticket);    

        vector<Airport*> cheapeastRoute(string departure, string arrival);    // return the cheapeast route
                                                                        // between arrival and destination as an array of airports

        int getCheapestRoutePrice(string departure, string arrival);              // return the cheapeast cost between arrival and destination

        vector<Flight*> getFlightsFromAirport(string airportName);

        ~AirControl();
    private:
        void readAirports(string airportText);              // read airports data from airports.txt
        void readFlights(string flightText);                 // read flights data from flights.txt
        void Dijkstra(int a,vector<int>* weight,int* path);
};

#endif
