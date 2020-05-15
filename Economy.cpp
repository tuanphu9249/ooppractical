#include<iostream>
#include "Economy.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 1; // coeffiecient for this flight type

Economy::Economy(Flight aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFlight, aName, aDOB, aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    SeatNumber = aSeatNumber;
    type = "Economy";
}

int Economy::priceCalculation()
{
    return flight.getPrice()*COEF
}