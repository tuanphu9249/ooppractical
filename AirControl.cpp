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
            while(getline(tempStream, intermediate, ' '))
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
    airports = new Airport[50];
    numAirports = 0;
    costs = {POS_INF};

    readAirports(airports);
    readFlights(flights);

    //  fill in costs[][]













}