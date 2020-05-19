#include <iostream>
using namespace std;
#include "Ticket.h"
#include "FirstClass.h"
#include "Business.h"
#include "Flight.h"


int main()
{
    int numTests = 0;
    int numFailTests = 0;
    // unit tests

    // testing Airport::addFlight;
    {
        Flight* flight1 = new Flight();
        Ticket* ticket1 = new Ticket(flight1,"Antoine","17/11/1999","11E");
        Business* business = new Business(flight1,"AndrewNgo","11/11/1999","19A");
        FirstClass* firstclass = new FirstClass(flight1,"Long","12/12/1999","22A");
        cout << firstclass->getName() << endl;
        numTests++;
    }

    //  // testing Airport::getNumFlights();
    // {
    //     Airport* adelaide = new Airport("Adelaide");
    //     Flight flight1 = Flight();
    //     Flight flight2 = Flight();

    //     adelaide->addFlight(flight1);
    //     adelaide->addFlight(flight2);

    //     if (adelaide->getNumFlights() != 2)
    //     {
    //         cout << "An error occurred with Airport::getNumFlights()" << endl;
    //         numFailTests++;
    //     }
    //     numTests++;
    // }



    // // testing Airport::getFlights();
    // {
    //     Airport* adelaide = new Airport("Adelaide");
    //     Flight flight1 = Flight();
    //     Flight flight2 = Flight();
    //     Flight flight3 = Flight();
    //     adelaide->addFlight(flight1);
    //     adelaide->addFlight(flight2);
    //     adelaide->addFlight(flight3);

    //     for (int i = 0; i < 3; i++)
    //     {
    //         if (adelaide->getFlights()[i].getName() != "") 
    //         {
    //             cout << "An error occurrent with Airport::getFlights()" << endl;
    //             numFailTests++;
    //             break;
    //         }
    //     }

    //     numTests++;
    // }

    // cout << numTests << " tests ran, " << numFailTests << " failed." << endl;



}

    