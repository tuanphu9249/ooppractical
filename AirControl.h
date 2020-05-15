#ifndef AIRCONTROL_H
#define AIRCONTROL_H

#include <iostream>
#include "FlightType.h"
#include "Airport.h"
using namespace std;


class AirControl
{
    private:
        Airport[] airports;
        int numAirports;

    public:
        AirControl();

        FlightType[] flightCheck(string arrival, string destination); // show flight ID, name, # of passengers,
                                                                    // price, speed, time of all flights available
        bool buyTicket(string arrival, string destination);         


        ~AirControl();
};

#endif
