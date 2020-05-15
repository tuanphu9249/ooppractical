#include<iostream>
#include "Business.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 5; // coeffiecient for this flight type

Business::Business(Flight aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFlight, aName, aDOB, aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    SeatNumber = aSeatNumber;
    type = "Business";
}

int Business::priceCalculation()
{
    return flight.getBasePrice()*COEF;
}