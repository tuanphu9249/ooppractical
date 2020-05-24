# Course: Object Oriented Programming
# Practical 9-11
# Makefile for the practical

# default target is all
all: main

main: AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o main.o
	g++ AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o main.o -o main
AirControl.o: AirControl.cpp AirControl.h Airport.h Ticket.h Business.h Economy.h FirstClass.h
	g++ -c AirControl.cpp -o AirControl.o
Airport.o: Airport.cpp Airport.h Flight.h
	g++ -c Airport.cpp -o Airport.o
Ticket.o: Ticket.cpp Ticket.h Flight.h
	g++ -c Ticket.cpp -o Ticket.o
Business.o: Business.cpp Business.h Flight.h Ticket.h
	g++ -c Business.cpp -o Business.o
Economy.o: Economy.cpp Economy.h Flight.h Ticket.h
	g++ -c Economy.cpp -o Economy.o
FirstClass.o: FirstClass.cpp FirstClass.h Flight.h Ticket.h
	g++ -c FirstClass.cpp -o FirstClass.o
Flight.o: Flight.cpp Flight.h Ticket.h Airport.h
	g++ -c Flight.cpp -o Flight.o
Menu.o: Menu.cpp Menu.h AirControl.h Flight.h Airport.h Ticket.h Business.h Economy.h FirstClass.h
	g++ -c Menu.cpp -o Menu.o
main.o: main.cpp AirControl.h Airport.h Ticket.h Flight.h Menu.h
	g++ -c main.cpp -o main.o
# remove all object files and the compiled executable
clean:
	rm -f *.o main