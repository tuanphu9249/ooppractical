#ifndef TICKET_H
#define TICKET_H
#include "Flight.h"
#include <iostream>
using namespace std;

class Ticket
{
    protected:
        Flight* flight;
        string name;
        string DOB;
        int seatNumber;
        string type;
        int price;
    public:
        Ticket();
        Ticket(Flight* aFlight, string aName, string aDOB, int aSeatNumber);
        int getPrice();
        virtual void setPrice();
        Flight* getFlight();
        string getName();
        string getType();
        string getDOB();
        int getSeatNumber();        

        void setFlight(Flight* aFlight);
        void setName(string aName);
        void setDOB(string aDOB);
        void setType (string aType);
        void setSeatNumber(int aSeatNumber);
        

        ~Ticket();


};

#endif