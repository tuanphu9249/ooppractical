#ifndef TICKET_H
#define TICKET_H
#include <iostream>
using namespace std;

class Ticket
{
    protected:
        string flightName;
        string arrival;
        string departure;
        string name;
        int basePrice;
        string DOB;
        int seatNumber;
        string type;
        int price;
    public:
        Ticket();
        Ticket(string aFlightName, int aBasePrice);
        Ticket(string aFlightName, string aName, string aDOB, int aSeatNumber, int aBasePrice);
        int getPrice();
        virtual void setPrice(int coef);
        string getFlightName();
        string getArrival();
        string getDeparture();
        string getName();
        string getType();
        string getDOB();
        int getSeatNumber();        

        void setFlightName(string aFlightName);
        void setArrival(string aArrival);
        void setDeparture(string aDeparture);
        void setName(string aName);
        void setDOB(string aDOB);
        void setType (string aType);
        void setSeatNumber(int aSeatNumber);
        

        ~Ticket();


};

#endif