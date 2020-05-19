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
    /*
    {   // reading files testing
        AirControl airSystem = AirControl();
        map<string, Airport*>::iterator ite;    // iterator to loop through each airports and check for flights 
        for (ite = airSystem.airports.begin(); ite != airSystem.airports.end(); ite++ )
        {
            Airport* airport = ite->second;
            cout << "Currently at " << airport->getName() << " airport:" <<
                            " There are " << airport->getNumFlights() << " available" << endl;

            Flight* flights = airport->getFlights();
            for (int i = 0; i < airport->getNumFlights(); i++)
            {
                cout << flights[i].getDeparture() << " " << flights[i].getArrival() 
                                << " " << flights[i].getBasePrice() << " " << flights[i].getDuration() << endl;
            }
            
            cout << endl;

        }
    }
*/
    
    {
        cout << "Testing output of AirControl::getAirports() \n";
        AirControl airSystem = AirControl();
        vector<Airport*> airports = airSystem.getAirports();
        for (int i = 0; i < airSystem.getNumAirports(); i++)
        {
            cout << airports[i]->getName() << endl;
        }

    }


    {
        cout << "\nTesting output of AirControl::directFlightCheck()" << endl;

        AirControl airSystem = AirControl();

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

