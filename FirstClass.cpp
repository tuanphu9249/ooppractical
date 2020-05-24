#include<iostream>
#include "FirstClass.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 10; // coeffiecient for this flight type
using namespace std;

FirstClass::FirstClass(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "First Class";
    price = aBasePrice*COEF;
}

FirstClass::FirstClass(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "First Class";
    price = aBasePrice*COEF;
}

void FirstClass::setPrice()
{
    price = basePrice*COEF;
}