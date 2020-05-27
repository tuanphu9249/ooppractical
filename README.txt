// 


## RUN CONSOLE ## 
> make main && ./main airports.txt DijkstraFlight.txt


## test Airport.cpp module ##
> make AirportTester && ./AirportTester


## test Flight.cpp module ##
> make FlightTester && ./FlightTester > output.txt && diff output.txt ExpectedOutput.txt
> ./FlightTester

## test AirControl.cpp module ##
> make AirControlTester && ./AirControlTester airports.txt flight.txt

## test Ticket.cpp module ##
> make TicketTester && ./TicketTester


