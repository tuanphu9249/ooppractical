#include<iostream>
#include "Business.h"
#include "Flight.h"
#include "Ticket.h"
#define coef 10

using namespace std;
Business::Business(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "Business";
}


Business::Business(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "Business";
}

void Business::setPrice()
{
    price = basePrice*coef;
}