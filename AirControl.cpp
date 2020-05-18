#include <iostream>
using namespace std;
#include <fstream>
#include <string>
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
            airports[numAirports++] = new Airport(line);

    }
    airportFile.close();

}


//TODO: fix readFlights() so that each airport is assigned with its flights.
void AirControl::readFlights()
{
    string line;
    ifstream flightFile;
    flightFile.open("filghts.txt");
    if (flightFile.is_open())
    {
        while (getline(flightFile, line))
        {   
            vector<string> tokens;
            stringstream tempStream(line); // string stream for line
            string intermediate;
            
            // tokenizing w.r.t space ' '
            while(getline(tempStream, intermediate, ' '))
            {
                tokens.push_back(intermidiate);
            }

            flights[numFlights++] = Flight(tokens[0], tokens[1], tokens[2], tokens[3],
                                             stoi(tokens[4]), tokens[5], tokens[6]);

        }
    }
}


AirControl::AirControl()
{
    airports = new Airport[50];
    numAirports = 0;
    costs = {POS_INF};

    readAirports(airports);
    readFlights(flights);

    //  fill in costs[][]











}