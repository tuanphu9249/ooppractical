#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "AirControl.h"
#include "Airport.h"
#define POS_INF 10e9

void AirControl::readAirports(string airportText)
{
    string line;
    ifstream airportFile;
    airportFile.open(airportText);
    if (airportFile.is_open())
    {
        while (getline(airportFile, line))
        {
            airports.insert(pair<string, Airport*>(line, new Airport(line)));
            numAirports++;
        }

    }
    airportFile.close();

}


//TODO: fix readFlights() so that each airport is assigned with its flights.
void AirControl::readFlights(string flightText)
{
    string line;
    ifstream flightFile;
    flightFile.open(flightText);
    string name, departure, arrival;
    int baseCost, duration;

    if (flightFile.is_open())
    {
        while (getline(flightFile, line))
        {               
            istringstream tempStream(line);  // string stream for a line

            // tokenizing w.r.t space ' '
            tempStream >> name >> departure >> arrival >> baseCost >> duration;
            
            airports[departure]->addFlight(new Flight(name, departure, arrival,
                                            baseCost, duration));
        }
    }
    flightFile.close();
}


AirControl::AirControl(string airportText, string flightText)
{
    numAirports = 0;
    readAirports(airportText);
    readFlights(flightText);

    // initilise verticies and weight of the map
    for (int i = 0; i < numAirports; i++)
    {
        for (int j = 0; j < numAirports; j++)
        {
            if (i == j) costs[i][j] = 0;
            costs[i][j] = (int)POS_INF;
        }
        
    }

    //  fill in costs[][]
    map<string, Airport*>::iterator ite;    // iterator to loop through each airports and check for flights 
    for (ite = airports.begin(); ite != airports.end(); ite++)
    {
        Flight* flights = ite->second->getFlights();
        for (int i = 0; i < ite->second->getNumFlights(); i++)
        {
            string departure = flights[i].getDeparture();
            string arrival = flights[i].getArrival();
            int arrivalID = airports[arrival]->getID();
            int departureID = airports[departure]->getID();
            costs[departureID][arrivalID] = flights[i].getBasePrice();
        }

    }
}

vector<Airport*> AirControl::getAirports()
{
    vector<Airport*> allAirports;
    map<string, Airport*>::iterator ite;

    for (ite = airports.begin(); ite != airports.end(); ite++ )
    {
        allAirports.push_back(ite->second);

    }
    return allAirports;

}

int AirControl::getNumAirports()
{
    return numAirports;
    
}

vector<Flight*> AirControl::directFlightCheck(string departure, string arrival)
{
    Airport* departureAirport = airports[departure];
    Flight* flightsFromDeparture = departureAirport->getFlights();
    vector<Flight*> result;

    for (int i = 0; i < departureAirport->getNumFlights(); i++)
    {   
        if (flightsFromDeparture[i].getArrival() == arrival)
            result.push_back(&flightsFromDeparture[i]);
    }
    return result;
}














AirControl::~AirControl()
{}