#include <iostream>
using namespace std;
#include "Ticket.h"
#include "FirstClass.h"
#include "Business.h"
#include "Flight.h"
#include "Economy.h"

int main()
{
    int numTests = 0;
    int numFailTests = 0;
    // unit tests

    // testing Airport::addFlight;
    {
        Flight* flight1 = new Flight("VJ-110","Adelaide","Sydney",10,8);
        Economy* ticket1 = new Economy(flight1->getName(),"Antoine","17/11/1999",11, 1);
        Business* business = new Business(flight1->getName(),"AndrewNgo","11/11/1999", 19, 1);
        FirstClass* firstclass = new FirstClass(flight1->getName(),"Long Nguyen","12/12/1999",22, 1);
        
        cout << "Base price:" << flight1->getBasePrice() << endl;
        cout << "First Class customer:"<< firstclass->getName() <<", DOB: "<< firstclass->getDOB()<< ", seat number: "<< firstclass->getSeatNumber() << endl;
        cout << "price First Class: " << firstclass->getPrice() << endl;
        cout << "Price Business Class: " << business->getPrice() << endl;
        cout << "Price Economy Class: " << ticket1->getPrice() <<endl;
        numTests++;
    }



}

    