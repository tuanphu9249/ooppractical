#include <iostream>
#include "Ticket.h"
#include "Flight.h"


Ticket::Ticket()
{

}
Ticket::Ticket(Flight* aFlight, string aName, string aDOB, string aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;

}
int Ticket::priceCalculation()
{
    return 0;
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
string Ticket::getSeatNumber()
{
    return seatNumber;
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
void Ticket::setSeatNumber(string aSeatNumber)
{
    seatNumber = aSeatNumber;
}


Ticket::~Ticket()
{
    
}