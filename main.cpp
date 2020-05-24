#include <iostream>
#include <stdlib.h>
#include "AirControl.h"
#include "Flight.h"
#include "Ticket.h"
#include "Menu.h"
#include "Airport.h"
using namespace std;


int main(int argc, char *argv[])        // argv[1] holds airports.txt, argv[2] holds flight.txt
{
    Menu menu = Menu(argv[1], argv[2]);   // init
    int option;
    while (true)
    {
        menu.mainMenu();
        cin >> option;
      // printf("\033[2J\033[1;1H");


        switch (option)
        {
            case 1:
                menu.directFlightCheckMenu();
                break;
            case 2:
                menu.findCheapestFlightMenu();
                break;
            case 3:
                menu.buyTicketMenu();
                break;
            case 4:
                menu.CheckAllflight();
                break;
            case 5:
                return 0 ;
            default:
                system("clear");
                cout << "Wrong option, try again.";
                system("clear");
                menu.holdScreen();

        }
    }






    





}