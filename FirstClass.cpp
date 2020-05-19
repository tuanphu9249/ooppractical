#include<iostream>
#include "FirstClass.h"
#include "Flight.h"
#include "Ticket.h"
#define COEF 10; // coeffiecient for this flight type
using namespace std;
FirstClass::FirstClass(Flight* aFlight, string aName, string aDOB, string aSeatNumber) : Ticket(aFlight, aName, aDOB, aSeatNumber)
{
    flight = aFlight;
    name = aName;
    DOB = aDOB;
    seatNumber = aSeatNumber;
    type = "First Class";
    price = flight->getBasePrice()*COEF;
}

void FirstClass::setPrice()
{
    price = flight->getBasePrice()*COEF;
}