#include<iostream>
#include "Business.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 5; // coeffiecient for this flight type
using namespace std;
Business::Business(Flight* aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFlight, aName, aDOB, aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "Business";
    price = flight->getBasePrice()*COEF;
}

void Business::setPrice()
{
    price = flight->getBasePrice()*COEF;
}