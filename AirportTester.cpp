#include <iostream>
using namespace std;
#include "Airport.h"
#include "Flight.h"


int main()
{
    int numTests = 0;
    int numFailTests = 0;
    // unit tests

    // testing Airport::addFlight;
    {
        Airport* adelaide = new Airport("Adelaide");
        Flight* flight1 = new Flight();
        adelaide->addFlight(flight1);
        if (adelaide->getFlights()[0].getName() != "")
        {
            cout << "An error occurred with Airport::addFlight()" << endl;
            cout << adelaide->getFlights()[0].getName() << " was printed" << endl;
            numFailTests++;
        }

        numTests++;
    }

     // testing Airport::getNumFlights();
    {
        Airport* adelaide = new Airport("Adelaide");
        Flight* flight1 = new Flight();
        Flight* flight2 = new Flight();

        adelaide->addFlight(flight1);
        adelaide->addFlight(flight2);

        if (adelaide->getNumFlights() != 2)
        {
            cout << "An error occurred with Airport::getNumFlights()" << endl;
            numFailTests++;
        }
        numTests++;
    }



    // testing Airport::getFlights();
    {
        Airport* adelaide = new Airport("Adelaide");
        Flight* flight1 = new Flight();
        Flight* flight2 = new Flight();
        Flight* flight3 = new Flight();
        adelaide->addFlight(flight1);
        adelaide->addFlight(flight2);
        adelaide->addFlight(flight3);

        for (int i = 0; i < 3; i++)
        {
            if (adelaide->getFlights()[i].getName() != "") 
            {
                cout << "An error occurrent with Airport::getFlights()" << endl;
                numFailTests++;
                break;
            }
        }

        numTests++;
    }

    cout << numTests << " tests ran, " << numFailTests << " failed." << endl;



}

    