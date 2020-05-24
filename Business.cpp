#include<iostream>
#include "Business.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 5; // coeffiecient for this flight type


using namespace std;
Business::Business(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "Business";
    price = aBasePrice*COEF;
}


Business::Business(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "Business";
    price = aBasePrice*COEF;
}

void Business::setPrice()
{
    price = basePrice*COEF;
}