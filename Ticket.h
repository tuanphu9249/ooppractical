#ifndef TICKET_H
#define TICKET_H
#include "Flight.h"
#include <iostream>
using namespace std;

class Ticket
{
    private:
        Flight flight;
        string name;
        string DOB;
        string seatNumber;
        string type;

    public:
        Ticket();
        Ticket(Flight aFlight, string aName, string aDOB, string aSeatNumber);
        virtual int priceCalculation(Airport departure, Airport arrival) = 0;

        Flight getFlight();
        string getName();
        string getDOB();
        string getSeatNumber();        
        int getPrice();

        void setFlight();
        void setName();
        void setDOB();
        void setSeatNumber();
        

        ~Ticket();


};

#endif