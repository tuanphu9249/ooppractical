#include<iostream>
#include "FirstClass.h"
#include "Flight.h"
#include "Ticket.h"
using namespace std;

FirstClass::FirstClass(string aFlightName, int aBasePrice) : Ticket(aFlightName, aBasePrice)
{
    flightName = aFlightName;
    type = "First Class";
}

FirstClass::FirstClass(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice) : Ticket(aFlightName, aName, aDOB, aSeatNumber, aBasePrice)
{
    flightName = aFlightName;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "First Class";
}

void FirstClass::setPrice(int coef)
{
    price = basePrice*coef;
}