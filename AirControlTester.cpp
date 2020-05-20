#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "AirControl.h"
#include "Flight.h"
#include "Ticket.h"
#include "Airport.h"



int main()
{
     {
        cout << "*** Testing output of AirControl::getAirports() *** \n";
        
        AirControl airSystem = AirControl("airports.txt", "flight.txt");
        vector<Airport*> airports = airSystem.getAirports();
        for (int i = 0; i < airSystem.getNumAirports(); i++)
        {
            cout << airports[i]->getName() << endl;
        }

    }

    
    {   cout << "\n*** Testing the availability of flights ***" << endl;
        AirControl airSystem = AirControl("airports.txt", "flight.txt");
        vector<Airport*> airports = airSystem.getAirports();

        for (int airportNum = 0; airportNum < airSystem.getNumAirports(); airportNum++)
        {
            cout << "Currently at " << airports[airportNum]->getName() << " airport:" <<
                            " There are " << airports[airportNum]->getNumFlights() << " available" << endl;

            if (airports[airportNum]->getNumFlights() > 0)
            {
                Flight* flights = airports[airportNum]->getFlights();
                for (int flightNum = 0; flightNum < airports[airportNum]->getNumFlights(); flightNum++)
                {
                    cout << flights[flightNum].getDeparture() << " " << flights[flightNum].getArrival() 
                                    << " " << flights[flightNum].getBasePrice() << " " << flights[flightNum].getDuration() << endl;
                }
            }
            
            cout << endl;

        }
    }


    {
        cout << "\n*** Testing output of AirControl::directFlightCheck() ***" << endl;

        AirControl airSystem = AirControl("airports.txt", "flight.txt");

        vector<Flight*> testFlight = airSystem.directFlightCheck("Adelaide", "Melbourne");
        if (!testFlight.empty())
        {
            cout << "Departure: " << testFlight.front()->getDeparture() << endl;
            cout << "Arrival: " << testFlight.front()->getArrival() << endl;
            cout << "Price: " << testFlight.front()->getBasePrice() << endl;
            cout << "Duration: " << testFlight.front()->getDuration() << endl;
        }
        else 
        {
            cout << "no flight available" << endl;
        }

    }



    return 0;

}

