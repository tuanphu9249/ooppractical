#include <iostream>
#include "Ticket.h"
#include "Flight.h"


Ticket::Ticket()
{

}
Ticket::Ticket(Flight* aFlight, string aName, string aDOB, int aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;

}
void Ticket::setPrice()
{
    price = 0;
}
Flight* Ticket::getFlight()
{
    return flight;
}
string Ticket::getName()
{
    return name;
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

void Ticket::setFlight(Flight* aFlight)
{
    flight = aFlight;
}
void Ticket::setName(string aName)
{
    name = aName;
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