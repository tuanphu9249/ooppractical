#include <iostream>
#include "Ticket.h"
#include "Flight.h"


Ticket::Ticket()
{

}
Ticket::Ticket(string aFlightName, int aBasePrice)
{
    flightName = aFlightName;
    basePrice = aBasePrice;

}
Ticket::Ticket(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    basePrice = aBasePrice;

}
void Ticket::setPrice()
{
    price = basePrice;
}
string Ticket::getFlightName()
{
    return flightName;
}
string Ticket::getName()
{
    return name;
}

string Ticket::getArrival()
{
    return arrival;
}

string Ticket::getDeparture()
{
    return departure;
}

string Ticket::getDOB()
{
    return DOB;
}
int Ticket::getSeatNumber()
{
    return seatNumber;
}        

string Ticket::getType()
{
    return type;
}

int Ticket::getPrice()
{
    return price;
}

void Ticket::setFlightName(string aFlightName)
{
    flightName = aFlightName;
}

void Ticket::setName(string aName)
{
    name = aName;
}

void Ticket::setDeparture(string aDeparture)
{
    departure = aDeparture;
}

void Ticket::setArrival(string aArrival)
{
    arrival = aArrival;
}
void Ticket::setDOB(string aDOB)
{
    DOB = aDOB;
}
void Ticket::setSeatNumber(int aSeatNumber)
{
    seatNumber = aSeatNumber;
}

void Ticket::setType(string aType)
{  
    type = aType;

}


Ticket::~Ticket()
{
    
}