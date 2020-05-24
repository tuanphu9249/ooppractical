#include <iostream>
using namespace std;
#include "Flight.h"
#include "Airport.h"
#include "Ticket.h"
#include <vector>

int main()
{
    //  unit testing
    {
        vector<Flight*> gate1; 
        vector<Flight*>::iterator it;
        Flight* flight1 = new Flight("JS-110","Adelaide","Sydney",10,8);
        Flight* flight2 = new Flight("DS-112", "Darwin","Kuala Lumpur",9,10);
        Flight* flight3 = new Flight("VJ-303", "Melbourne", "Budapest",20,11);
        Flight* flight4 = new Flight("MH-370","Kuala Lampur","Beijing",23,15);
        gate1.push_back(flight1);
        gate1.push_back(flight2);
        gate1.push_back(flight3);
        gate1.push_back(flight4);
        for(it = gate1.begin(); it < gate1.end(); it++)
        {
            cout << (*it)->getName() << " " << (*it)->getDeparture() << " " 
            << (*it)->getArrival() << " " << (*it)->getBasePrice() << " " << (*it)->getDuration() << endl;
        }
        flight1->setArrival("Melbourne");
        flight2->setName("VL-091");
        for(it = gate1.begin(); it < gate1.end(); it++)
        {
            cout << (*it)->getName() << " " << (*it)->getDeparture() << " " 
            << (*it)->getArrival() << " " << (*it)->getBasePrice() << " " << (*it)->getDuration() << endl;
        }
        flight3->setCurBusinessSeat(10);
        flight3->setCurEcoSeat(5);
        cout << flight3->getCurBusinessSeat() << " " << flight3->getCurEcoSeat() <<endl;

    }

    {
        Flight* flight = new Flight();
        for (int i = 0; i < 115; i++)
            flight->addTicket(new Ticket(flight, "Anh Tuan Phu", "14/08/99", i ));

        Ticket* tickets = flight->getTickets();

        if (flight->getNumTicket() != 115)
            cout << "Error with Flight::addTicket()" << endl;


        if (flight->addTicket(new Ticket()))
            cout << "Ticket still adding although limit is exceeded" << endl;
        else cout <<"Flight::addTicket() no error" << endl;
            
            

        
    }   
    
}