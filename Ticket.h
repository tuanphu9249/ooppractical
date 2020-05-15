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

    public:
        Ticket();
        Ticket(Flight aFlight, string name, string DOB, string seatNumber);
        Flight getFlight();
        string getName();
        string getDOB();
        string getSeatNumber();

        void setFlight();
        void setName();
        void setDOB();
        void setSeatNumber();

        ~Ticket();




};

#endif