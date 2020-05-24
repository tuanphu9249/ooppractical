#include <iostream>
using namespace std;
#include "Airport.h"
#include "Flight.h"


Airport::Airport()
{
    name = "";
    ID = Airport::totalID++;
    numFlights = 0;
    flights = new Flight[100];

}
int Airport::totalID = 0;
Airport::Airport(string aName)
{
    ID = Airport::totalID++;
    name = aName;
    numFlights = 0;
    flights = new Flight[100];
}

void Airport::setName(string aName)
{
    name = aName;
}

void Airport::addFlight(Flight* aFlight)
{
    flights[numFlights++] = *aFlight;
}


string Airport::getName()
{
    return name;
}

int Airport::getID()
{
    return ID; 
}

Flight* Airport::getFlights()
{
    return flights;
}

int Airport::getNumFlights()
{
    return numFlights;
}

Airport::~Airport()
{}



