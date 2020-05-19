#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "AirControl.h"
#include "Airport.h"
#define POS_INF 10e9

void AirControl::readAirports()
{
    string line;
    ifstream airportFile;
    airportFile.open("airports.txt");
    if (airportFile.is_open())
    {
        while (getline(airportFile, line))
            airports.insert(pair<string, Airport*>(line, new Airport(line));

    }
    airportFile.close();

}


//TODO: fix readFlights() so that each airport is assigned with its flights.
void AirControl::readFlights()
{
    string line;
    ifstream flightFile;
    flightFile.open("filghts.txt");
    vector<string> tokens;
    stringstream tempStream(line);      // string stream for a line
    string intermediate;                // temporary place for each individual word

    if (flightFile.is_open())
    {
        while (getline(flightFile, line))
        {               
            // tokenizing w.r.t space ' '
            while (getline(tempStream, intermediate, ' '))
            {
                tokens.push_back(intermidiate);
            }

            airports[tokens[1]]->addFlight(Flight(tokens[0], tokens[1], tokens[2],
                                            stoi(tokens[4]), stoi(tokens[5])));
        }
    }
}


AirControl::AirControl()
{
    numAirports = 0;
    for(int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            costs[i][j] = POS_INF;
        }
        
    }
    readAirports();
    readFlights();

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

vector<Flight*> AirControl::directFlightCheck(string departure, string arrival)
{
    Airport departureAirport = airports[departure];
    Flight* flightsFromDeparture = departureAirport.getFlights();
    vector<Flight*> result;

    for (int i = 0; i < departureAirport.getNumFlights(); i++)
    {   
        if (flightsFromDeparture[i].getArrival() == arrival)
            result.push_back(flightsFromDeparture[i]);
    }
    return result;
}
 