#include<iostream>
#include "FirstClass.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 10; // coeffiecient for this flight type

FirstClass::FirstClass(Flight aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFlight, aName, aDOB, aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    SeatNumber = aSeatNumber;
    type = "First Class";
}

int FirstClass::priceCalculation()
{
    return flight.getBasePrice()*COEF;
}