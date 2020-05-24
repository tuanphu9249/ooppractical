# Course: Object Oriented Programming
# Practical 9-11
# Description: Makefile for AirControl

# default target is all
all: driver

driver: AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o
	g++ AirControl.o Airport.o Ticket.o Business.o Economy.o FirstClass.o Flight.o Menu.o -o driver
AirControl.o: AirControl.cpp AirControl.h
	g++ -c AirControl.cpp -o AirControl.o
Airport.o: Airport.cpp Airport.h
	g++ -c Airport.cpp -o Airport.o
Ticket.o: Ticket.cpp Ticket.h
	g++ -c Ticket.cpp -o Ticket.o
Business.o: Business.cpp Business.h
	g++ -c Business.cpp -o Business.o
Economy.o: Economy.cpp Economy.h
	g++ -c Economy.cpp -o Economy.o
FirstClass.o: FirstClass.cpp FirstClass.h
	g++ -c FirstClass.cpp -o FirstClass.o
Flight.o: Flight.cpp Flight.h
	g++ -c Flight.cpp -o Flight.o
Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp -o Menu.o
# remove all object files and the compiled executable
clean:
	rm -f *.o driver