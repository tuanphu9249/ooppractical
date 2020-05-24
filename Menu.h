#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;
#include "AirControl.h"
#include "Flight.h"
#include "Ticket.h"



class Menu
{
    private:
        AirControl airSystem;
    public:
        Menu(string airportFile, string flightFile);
        void mainMenu();
        void directFlightCheckMenu();    // 1
        void findCheapestFlightMenu();   // 2
        void buyTicketMenu();    // 3
        void holdScreen();
        void CheckAllflight();
        ~Menu();

    private:
        void printFlightInfo(Flight* aFlight);
        void printTicketInfo(Ticket* aTicket);
        

};

#endif

