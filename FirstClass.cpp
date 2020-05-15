#include<iostream>
#include "FirstClass.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 10;

FirstClass::FirstClass(Flight aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFight,name,DOB,seatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    SeatNumber = aSeatNumber;
    type = "First Class";
}

int FirstClass::priceCalculation()
{
    return 
}