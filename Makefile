# Course: Object Oriented Programming
# Practical 9-11
# Makefile for the practical

# default target is all
all: main

AirControlTester: AirControlTester.o AirControl.o Flight.o Ticket.o Airport.o
	g++ AirControlTester.o AirControl.o Flight.o Ticket.o Airport.o -o AirControlTester
AirportTester: AirportTester.o Airport.o Flight.o Ticket.o
	g++ AirportTester.o Airport.o Flight.o Ticket.o -o AirportTester
FlightTester: FlightTester.o Airport.o Flight.o Ticket.o
	g++ FlightTester.o Airport.o Flight.o Ticket.o -o FlightTester
TicketTester: TicketTester.o Ticket.o FirstClass.o Business.o Economy.o Flight.o
	g++ TicketTester.o Ticket.o FirstClass.o Business.o Economy.o Flight.o -o TicketTester
main: AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o main.o
	g++ AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o main.o -o main


AirControl.o: AirControl.cpp AirControl.h Airport.h Ticket.h Business.h Economy.h FirstClass.h
	g++ -c AirControl.cpp -o AirControl.o
Airport.o: Airport.cpp Airport.h Flight.h
	g++ -c Airport.cpp -o Airport.o
Ticket.o: Ticket.cpp Ticket.h Flight.h
	g++ -c Ticket.cpp -o Ticket.o
Menu.o: Menu.cpp Menu.h AirControl.h Flight.h Airport.h Ticket.h Business.h Economy.h FirstClass.h
	g++ -c Menu.cpp -o Menu.o
main.o: main.cpp AirControl.h Airport.h Ticket.h Flight.h Menu.h
	g++ -c main.cpp -o main.o
# remove all object files and the compiled executable
AirportTester.o: AirportTester.cpp Airport.h Flight.h Ticket.h
	g++ -c AirportTester.cpp -o AirportTester.o
FlightTester.o: FlightTester.cpp Airport.h Flight.h Ticket.h
	g++ -c FlightTester.cpp -o FlightTester.o
AirControlTester.o: AirControlTester.cpp AirControl.h Flight.h Ticket.h Airport.h
	g++ -c AirControlTester.cpp -o AirControlTester.o
TicketTester.o: TicketTester.cpp Ticket.h FirstClass.h Business.h Economy.h Flight.h
	g++ -c TicketTester.cpp -o TicketTester.o
clean:
	rm -f *.o main AirportTester FlightTester
