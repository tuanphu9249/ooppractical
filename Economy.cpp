#include<iostream>
#include "Economy.h"
#include "Flight.h"
#include "Ticket.h"
using namespace std;
Economy::Economy(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "Economy";
}


Economy::Economy(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "Economy";
}

void Economy::setPrice(int coef)
{
    price = basePrice*coef;
}