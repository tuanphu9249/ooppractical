#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
#include "Flight.h"
#include "Airport.h"

int Flight::totalFlightID = 0;

Flight::Flight()
{
    departureTime = time(0);
    arrivalTime = time(0);

    departure = NULL;
    arrival = NULL;
    flightName = "";
    basePrice = 0;

    flightID = totalFlightID++;
    curBusinessSeat = 0;
    curEcoSeat = 0;
    curFirstSeat = 0;
}

Flight::Flight(string aName, Airport* aDeparture, Airport* aArrival, int aBasePrice, time_t aDepartureTime, time_t aArrivalTime)
{
    departureTime = aDepartureTime;
    arrivalTime = aArrivalTime;

    departure = aDeparture;
    arrival = aArrival;
    flightName = aName;
    basePrice = aBasePrice;

    flightID = totalFlightID++;
    curBusinessSeat = 0;
    curEcoSeat = 0;
    curFirstSeat = 0;

}

string Flight::getName()
{
    return flightName;
}

time_t Flight::getDepartureTime()
{
    return departureTime;
}

time_t Flight::getArrivalTime()
{
    return arrivalTime;
}

string Flight::getDeparture()
{
    return departure->getName();
}

string Flight::getArrival()
{
    return arrival->getName();
}

int Flight::getID()
{
    return flightID;
}

int Flight::getCurBusinessSeat()
{
    return curBusinessSeat;
}

int Flight::getCurEcoSeat()
{
    return curEcoSeat;
}

int Flight::getCurFirstSeat()
{
    return curFirstSeat;
}

int Flight::getBasePrice()
{
    return basePrice;
}

void Flight::setName(string aName)
{
    flightName = aName;
}

void Flight::setDepartureTime(time_t aDepartureTime)
{
    departureTime = aDepartureTime;
}

void Flight::setArrivalTime(time_t aArrivalTime)
{
    arrivalTime = aArrivalTime;
}


void Flight::setDeparture(Airport* aDeparture)
{
    departure = aDeparture;
}

void Flight::setArrival(Airport* aArrival)
{
    arrival = aArrival;
}

void Flight::setCurBusinessSeat(int num)
{
    curBusinessSeat = num;
}

void Flight::setCurEcoSeat(int num)
{
    curEcoSeat = num;
}

void Flight::setCurFirstSeat(int num)
{
    curFirstSeat = num;
}

Flight::~Flight()
{}