#ifndef FLIGHT_H
#define FLIGHT_H
#define FIRST_MAX 5;
#define BUSINESS_MAX 10;
#define ECO_MAX 100;
#include <iostream>
#include "Airport.h"
#include <ctime>
using namespace std;


class Flight
{
    protected:
    // time
        time_t departuretime;
        time_t arivaltime;
    // 
        Airport departure; // departure destination
        Airport arrival;   // arrival destination
        string flightName; // VJ-696
        
        int basePrice;
        int flightID;        // ID of flight
        static int totalFlightID; // increase whenever instantiate a new flight 
        int curBusinesSeat = 0;
        int curEcoSeat = 0;
        int curFirstSeat = 0;

    public:
        Flight();
        Flight(string name, Airport departure, Airport arrival, int aPrice, time_t deptime, time_t arritime);

        string getName();        
        time_t getDepartureTime();
        time_t getArrivalTime();
        string getDeparture();
        string getArrival();
        int getID();
        int getCurBusinessSeat();
        int getCurEcoSeat();
        int getCurFirstSeat();  
        int getBasePrice(); 

        void setName(string name);
        void setDepartureTime(time_t aDeparturetime);
        void setArrivalTime(time_t aArrivaltime);
        void setDeparture(Airport aDeparture);
        void setArrival(Airport aArrival);
        void setCurBusinessSeat(int num);
        void setCurEcoSeat(int num); 
        void setCurFirstSeat(int num);
        
        ~Flight();




};

#endif




