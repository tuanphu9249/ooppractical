#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include <stdio.h>
#include "AirControl.h"
#include "Flight.h"
#include "Airport.h"
#include "Ticket.h"
#include <vector>
#define POS_INF 10e7
using namespace std;


Menu::Menu(string airportFile, string flightFile)
{
    airSystem = AirControl(airportFile, flightFile);
}

void Menu::mainMenu()
{
    system("clear");
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                        Air Control                          " << endl;
    cout << "==========================================================" << endl;
    cout << endl;

    cout << " 1. Check Direct Flight" << endl;
    cout << " 2. Find Cheapest Flight" << endl;
    cout << " 3. Buy Ticket" << endl;
    cout << " 4. Exit" << endl << endl << endl << endl << endl;
    cout << "   Enter your options: ";
}

void Menu::directFlightCheckMenu()
{
    string departureAirport, arrivalAirport;
    system("clear");

    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                        Air Control                          " << endl;
    cout << "==========================================================" << endl;
    cout << endl;

    cout << "Departure Airport: ";
    cin >> departureAirport;
    cout << endl;
    cout << "Arrival Airport: ";
    cin >> arrivalAirport;
    cout << endl;
    vector<Flight*> flights = airSystem.directFlightCheck(departureAirport, arrivalAirport);
    if (flights.size() == 0) cout << "There is no direct flight available from "
                                     << departureAirport << " to " << arrivalAirport << endl;
    else
    {
        cout << "There are " << flights.size() << " flights available..." << endl << endl << endl;
        for (int i = 0; i < flights.size(); i++)
        {
            // TODO: add flight not available condition here
            printFlightInfo(flights[i]);
        }
    }
    cout << endl << endl << endl;
    holdScreen();

}

  

void Menu::printFlightInfo(Flight* flight)
{
    cout << flight->getName() << " " << " From: " << flight->getDeparture() << "     To: " << flight->getArrival() << endl;
    cout << "Duration: " << flight->getDuration() << "h" << endl; 
}

void Menu::findCheapestFlightMenu()
{
    string departureAirport, arrivalAirport;
    system("clear");
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                        Air Control                          " << endl;
    cout << "==========================================================" << endl;
    cout << endl;

    cout << "Departure Airport: ";
    cin >> departureAirport;
    cout << endl;
    cout << "Arrival Airport: ";
    cin >> arrivalAirport;
    cout << endl;
    int cheapeastCost = airSystem.getCheapestRoutePrice(departureAirport, arrivalAirport);
    if (cheapeastCost == POS_INF)
    {
        cout << "There is currently no route from " << departureAirport << " to " << arrivalAirport;
        return;
    }

    else
    {
        vector<Airport*> route = airSystem.cheapeastRoute(departureAirport, arrivalAirport);
        cout << "The cheapest route available is: " << endl;
        vector<Airport*>::iterator iter;
        for (iter = route.end() - 1; iter >= route.begin(); iter--)
        {
            if (iter != route.begin())
                 cout << "->" << (*iter)->getName();
            else
                 cout << " " << (*iter)->getName();

        }
        cout << endl;

        cout << "The cost for this route is $" << cheapeastCost << endl; 

    }
    cout << endl << endl << endl;

    holdScreen();

}
void Menu::buyTicketMenu()
{
    string departureAirport, arrivalAirport;
    system("clear");
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                        Air Control                          " << endl;
    cout << "==========================================================" << endl;
    cout << endl;

    cout << "Departure Airport: ";
    cin >> departureAirport;
    cout << endl;
    cout << "Arrival Airport: ";
    cin >> arrivalAirport;
    cout << endl;

}


void Menu::holdScreen()
{

    cin.ignore(1024, '\n');
    do 
    {
    cout << '\n' << "Press enter to return to main menu...";
    } while (cin.get() != '\n');
}

Menu::~Menu()
{}