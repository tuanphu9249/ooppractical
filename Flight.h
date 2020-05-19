#ifndef FLIGHT_H
#define FLIGHT_H
#define FIRST_MAX 5;
#define BUSINESS_MAX 10;
#define ECO_MAX 100;
#include <iostream>
#include <ctime>
using namespace std;

class Airport;  // foward declarations to avoid dependency loop

class Flight
{
    protected:
        string departure; // departure airport
        string arrival;   // arrival airport
        string flightName; // VJ-696
        
        int duration;
        int basePrice;
        int flightID;        // ID of flight
        static int totalFlightID; // increase whenever instantiate a new flight 
        int curBusinessSeat;
        int curEcoSeat;
        int curFirstSeat;

    public: 
        Flight();
        Flight(string aName, string aDeparture, string aArrival, int aBasePrice, int aDuration);

        string getName();        
        string getDeparture();
        string getArrival();
        int getID();
        int getDuration();
        int getCurBusinessSeat();
        int getCurEcoSeat();
        int getCurFirstSeat();  
        int getBasePrice(); 

        void setName(string aName);
        void setDuration(int aDuration);
        void setDeparture(string aDeparture);
        void setArrival(string aArrival);
        void setCurBusinessSeat(int num);
        void setCurEcoSeat(int num); 
        void setCurFirstSeat(int num);

        ~Flight();




};

#endif




