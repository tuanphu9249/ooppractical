#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Menu.h"
#include <stdio.h>
#include "AirControl.h"
#include "Flight.h"
#include "Airport.h"
#include "Ticket.h"
#include "Business.h"
#include "Economy.h"
#include "FirstClass.h"
#include <vector>
#define FIRST_MAX 1
#define BUSINESS_MAX 10
#define ECO_MAX 100
#define MAX_TICKET 111
#define POS_INF 10e7



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
    cout << " 4. Check All Flight From A Airport" << endl;
    cout << " 5. Exit" << endl << endl << endl << endl << endl;
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
    int count = 0;
    vector<Flight*> flights = airSystem.directFlightCheck(departureAirport, arrivalAirport);
    if (flights.size() == 0) cout << "There is no direct flight available from "
                                    << departureAirport << " to " << arrivalAirport << endl;
    else if(flights[0]->getName() == "")
    {

    }
    else
    { 
        cout << "There are " << flights.size() << " flights available..." << endl << endl << endl;
        for (int i = 0; i < flights.size(); i++)
        {
            cout << ++count << "." << endl;
            printFlightInfo(flights[i]);
        }
    }
    cout << endl << endl << endl;
    holdScreen();

}

void Menu::printFlightInfo(Flight* flight)
{
    cout << flight->getName() << " " << " From: " << flight->getDeparture() << "     To: " << flight->getArrival() << endl;
    cout << "Duration: " << flight->getDuration() << "h"; 
    cout << "   " << "Cost : $" << flight-> getBasePrice() << endl;
    cout << "Available Economy Seat: " << ECO_MAX - flight->getCurEcoSeat() << endl;
    cout << "Available Business Seat: " <<BUSINESS_MAX - flight->getCurBusinessSeat() << endl;
    cout << "Available First Class Seat: " << FIRST_MAX - flight->getCurFirstSeat() << endl;
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
    }
    else if (cheapeastCost == -1)
    {

    }
    else
    {
        vector<Airport*> route = airSystem.cheapeastRoute(departureAirport, arrivalAirport);
        cout << "The cheapest route is: " << endl;
        vector<Airport*>::iterator iter;
        for (iter = route.end() - 1; iter >= route.begin(); iter--)
        {
            if (iter != route.end()-1)
                cout << " -> " << (*iter)->getName();
            else
                cout << " " << (*iter)->getName();

        }
        cout << endl;
        cout << "The cost for this route is $" << cheapeastCost << endl << endl; 
        vector<Airport*>::iterator iter1;
        vector<Flight*>::iterator iter2;
        int i = 0;
        for (iter1 = route.end() - 1; iter1 > route.begin(); iter1--)
        {
            cout << "***"<< "Flight " << ++i <<": from " << (*iter1)->getName() << " to " << (*(iter1-1))->getName() << "***"<< endl;
            vector<Flight*> tempflight;
            tempflight = airSystem.directFlightCheck((*iter1)->getName(),(*(iter1-1))->getName());
            for(iter2 = tempflight.begin(); iter2 != tempflight.end(); iter2 ++){
                printFlightInfo(*iter2);
            }
            cout << endl;
        }
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
    cout << endl << endl;

    vector<Flight*> flights = airSystem.directFlightCheck(departureAirport, arrivalAirport);
    if (flights.size() == 0)
    {
        cout << "No flights available from " << departureAirport << " to " << arrivalAirport << endl << endl;
        holdScreen();
        return;
    }
    else if (flights[0]->getName() == "")
    {
        holdScreen();
        return;
    }
    else
    {
        cout << "There are " << flights.size() << " flights available..." << endl << endl << endl;
        for (int i = 0; i < flights.size(); i++)
        {
            cout << i+1 << ". " << endl;
            printFlightInfo(flights[i]);
        }
    }

    cout << endl;

    int flightChoosen;
    do {
        cout << "Enter your choice: ";
        cin >> flightChoosen;
        flightChoosen = flightChoosen-1;
        cin.ignore();
    } while (flightChoosen < 0 || flightChoosen >= flights.size());
    

    string DOB;
    string name;
    int type;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Date of Birth: ";
    cin >> DOB;
    cout << "Flight type:    1. Business      2. First Class     3. Economy" << endl;
    cout << "Enter your choice: ";

    cin >> type;
    
    int priceCoef;
    Ticket* ticket;
    Flight* tempflight = flights[flightChoosen];
    int curBusinessSeat, curFirstSeat, curEcoSeat;
    switch(type)
    {
        case (1):
            curBusinessSeat = tempflight->getCurBusinessSeat();
            if (curBusinessSeat >= BUSINESS_MAX)
            {
                cout << "Business ticket is full" << endl;
                holdScreen();
                return;
            }

            ticket = new Business(tempflight->getName(), name, DOB, curBusinessSeat, tempflight->getBasePrice());
            priceCoef = 2;

            break;
        case (2):
            curFirstSeat = tempflight->getCurFirstSeat();
            if (curFirstSeat >= FIRST_MAX)
            {
                cout << "First Class ticket is full" << endl;
                holdScreen();
                return;
            }
            ticket = new FirstClass(tempflight->getName(), name, DOB, curFirstSeat, tempflight->getBasePrice());
            priceCoef = 3;
            break;
        case (3):
            curEcoSeat = tempflight->getCurEcoSeat();
            if (curEcoSeat >= ECO_MAX)
            {
                cout << "Economy ticket is full" << endl;
                holdScreen();
                return;
            }
            ticket = new Economy(tempflight->getName(), name, DOB, curEcoSeat, tempflight->getBasePrice());
            priceCoef = 1;
            break;
        default:
            cout << "Sorry, something went wrong" << endl << endl;
            holdScreen(); 
            return;
    }

    ticket->setPrice(priceCoef);

    int money;

    cout << "The cost for this flight is $" << ticket->getPrice() << endl;
    cout << "Enter your money: ";
    cin >> money;
    if (money < ticket->getPrice())
    {
        cout << "You entered a insufficient amount." << endl << endl << endl;
        holdScreen();
    }

    else
    {
        if (!airSystem.buyTicket(flights[flightChoosen], ticket))
        {
            cout << "This flight is full" << endl << endl << endl;
            holdScreen();

        }
        else 
        {
            switch(type)
        {
            case (1):
                tempflight->setCurBusinessSeat(tempflight->getCurBusinessSeat() + 1);
                ticket->setSeatNumber(tempflight->getCurBusinessSeat());
                break;
            case (2):
                tempflight->setCurFirstSeat(tempflight->getCurFirstSeat() + 1);
                ticket->setSeatNumber(tempflight->getCurFirstSeat());
                break;
            case (3):
                tempflight->setCurEcoSeat(tempflight->getCurEcoSeat() + 1);
                ticket->setSeatNumber(tempflight->getCurEcoSeat());
                break;
            default:
                break;
        }

            cout << "Success, here is the information on your flight" << endl << endl;
            printTicketInfo(ticket);
            holdScreen();

        }
    }


}

void Menu::printTicketInfo(Ticket* ticket)
{   
    cout << ticket->getFlightName() << " " << ticket->getDeparture() << ticket->getArrival()  << endl;
    cout << "Passenger: " << ticket->getName() << "    " << "DOB: " << ticket->getDOB() << "    " << "Seat: " << ticket->getType()[0] <<  ticket->getSeatNumber() << endl;
    cout << "Class: " << ticket->getType() << "    " << "Price: $" << ticket->getPrice() << endl;
}

void Menu::CheckFlightFromMenu()
{

    string departureAirport;
    system("clear");
    cout << endl;
    cout << "==========================================================" << endl;
    cout << "                        Air Control                          " << endl;
    cout << "==========================================================" << endl;
    cout << endl;

    cout << "Departure Airport: ";
    cin >> departureAirport;
    vector<Flight*> flights = airSystem.getFlightsFromAirport(departureAirport);
    vector<Flight*>::iterator it;
    cout << endl;
    int count = 0;
    if(flights.size() == 0)
    {
        cout << "There is no flight from " << departureAirport << " airport" << endl;
    }
    else if(flights[0]->getName() == "")
    {
        
    }
    else
    {
        cout << "There are " << flights.size() <<" flights from "<< departureAirport << endl;
        for(it = flights.begin(); it != flights.end(); it++)
        {
            cout << ++count << "." << endl;
            printFlightInfo(*it);
            cout << endl;
        }
    }
    cout << endl << endl << endl;
    holdScreen();
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