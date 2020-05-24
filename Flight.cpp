#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
#include "Flight.h"
#include "Ticket.h"
#include "Airport.h"
#define FIRST_MAX 5
#define BUSINESS_MAX 10
#define ECO_MAX 100
#define MAX_TICKET 115

int Flight::totalFlightID = 0;

Flight::Flight()
{
    departure = "";
    arrival = "";
    flightName = "";
    basePrice = 0;
    tickets = new Ticket[MAX_TICKET];
    duration = 0;
    flightID = totalFlightID++;
    curBusinessSeat = 0;
    curEcoSeat = 0;
    numTicket = 0;
}

Flight::Flight(string aName, string aDeparture, string aArrival, int aBasePrice, int aDuration)
{
    departure = aDeparture;
    arrival = aArrival;
    flightName = aName;
    basePrice = aBasePrice;
    tickets = new Ticket[MAX_TICKET];

    duration = aDuration;
    flightID = totalFlightID++;
    curBusinessSeat = 0;
    curEcoSeat = 0;
    curFirstSeat = 0;
    numTicket = 0;

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

int Flight::getNumTicket()
{
    return numTicket;
}

Ticket* Flight::getTickets()
{
    return tickets;
}

bool Flight::isAvailable()
{
    return numTicket < MAX_TICKET;
}

int Flight::getBasePrice()
{
    return basePrice;
}

void Flight::setName(string aName)
{
    flightName = aName;
}

bool Flight::addTicket(Ticket* aTicket)
{
    if (!isAvailable()) return false;
    tickets[numTicket++] = *aTicket;
    return true; 
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