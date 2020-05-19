#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
#include "Flight.h"
#include "Airport.h"

int Flight::totalFlightID = 0;

Flight::Flight()
{
    departure = "";
    arrival = "";
    flightName = "";
    basePrice = 0;

    duration = 0;
    flightID = totalFlightID++;
    curBusinessSeat = 0;
    curEcoSeat = 0;
    curFirstSeat = 0;
}

Flight::Flight(string aName, string aDeparture, string aArrival, int aBasePrice, int aDuration)
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


int Flight::getDuration()
{
    return duration;
}

string Flight::getDeparture()
{
    return departure;
}

string Flight::getArrival()
{
    return arrival;
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

void Flight::setDuration(int aDuration)
{
    duration = aDuration;
}


void Flight::setDeparture(string aDeparture)
{
    departure = aDeparture;
}

void Flight::setArrival(string aArrival)
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