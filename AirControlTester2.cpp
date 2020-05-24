#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "AirControl.h"
#include "Flight.h"
#include "Ticket.h"
#include "Airport.h"



int main(int argc, char *argv[])        // argv[1] holds airports.txt, argv[2] holds flight.txt
{
    {
        vector<Airport*>::iterator it;
        cout << "\n*** Testing output of Aircontrol::cheapestRoute***" << endl;
        AirControl airSystem = AirControl(argv[1], argv[2]);

        cout << "Cheapest Route from Adelaide to Sydney" << endl;
        cout << airSystem.getCheapestRoutePrice("Adelaide","Sydney") << endl;
        vector<Airport*> cheapPath1 = airSystem.cheapeastRoute("Adelaide","Sydney");

        for(it = cheapPath1.end()-1; it >= cheapPath1.begin(); it-- ){
            cout << "->" << (*it)->getName(); 
        }
        cout << endl;

        cout << "Cheapest Route from Adelaide to Monaco" << endl;
        cout << airSystem.getCheapestRoutePrice("Adelaide","Monaco") << endl;
        vector<Airport*> cheapPath2 = airSystem.cheapeastRoute("Adelaide","Monaco");

        for(it = cheapPath2.end()-1; it >= cheapPath2.begin(); it--){
            cout << "->" <<(*it)->getName(); 
        }
        cout << endl;
        cout << "Cheapest Route from Adelaide to HoChiMinh" << endl;
        cout << airSystem.getCheapestRoutePrice("Adelaide","HoChiMinh") <<endl;
        vector<Airport*> cheapPath3 = airSystem.cheapeastRoute("Adelaide","HoChiMinh");

        for(it = cheapPath3.end()-1; it >= cheapPath3.begin(); it--){
            cout << "->" <<(*it)->getName(); 
        }

        cout << endl;
    }
}
