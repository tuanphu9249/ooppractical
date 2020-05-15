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
        time_t departureTime;
        time_t arrivalTime;
    // 
<<<<<<< HEAD
        Airport departure; // departure destination
        
        Airport arrival;   // arrival destination
=======
        Airport* departure; // departure destination
        Airport* arrival;   // arrival destination
>>>>>>> 74b3a9be855d958bc38aadb6533d53729b5cd51a
        string flightName; // VJ-696
        
        int basePrice;
        int flightID;        // ID of flight
        static int totalFlightID; // increase whenever instantiate a new flight 
        int curBusinessSeat;
        int curEcoSeat;
        int curFirstSeat;

    public: 
        Flight();
        Flight(string aName, Airport* aDeparture, Airport* aArrival, int aPrice, time_t aDepartureTime, time_t aArrivalTime);

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

        void setName(string aName);
        void setDepartureTime(time_t aDeparturetime);
        void setArrivalTime(time_t aArrivaltime);
        void setDeparture(Airport* aDeparture);
        void setArrival(Airport* aArrival);
        void setCurBusinessSeat(int num);
        void setCurEcoSeat(int num); 
        void setCurFirstSeat(int num);

        ~Flight();




};

#endif




