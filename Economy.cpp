#include<iostream>
#include "Economy.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 1; // coeffiecient for this flight type
using namespace std;
Economy::Economy(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "Economy";
    price = aBasePrice*COEF;
}


Economy::Economy(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "Economy";
    price = aBasePrice*COEF;
}

void Economy::setPrice()
{
    price = basePrice*COEF;
}