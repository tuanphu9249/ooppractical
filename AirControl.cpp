#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include "AirControl.h"
#include "Airport.h"
#define POS_INF 10e7

void AirControl::readAirports(string airportText)
{
    string line;
    ifstream airportFile;
    airportFile.open(airportText);
    if (airportFile.is_open())
    {
        while (getline(airportFile, line))
        {
            airports.insert(pair<string, Airport*>(line, new Airport(line)));
            numAirports++;
        }

    }
    airportFile.close();

}


//TODO: fix readFlights() so that each airport is assigned with its flights.
void AirControl::readFlights(string flightText)
{
    string line;
    ifstream flightFile;
    flightFile.open(flightText);
    string name, departure, arrival;
    int baseCost, duration;

    if (flightFile.is_open())
    {
        while (getline(flightFile, line))
        {               
            istringstream tempStream(line);  // string stream for a line

            // tokenizing w.r.t space ' '
            tempStream >> name >> departure >> arrival >> baseCost >> duration;
            
            airports[departure]->addFlight(new Flight(name, departure, arrival,
                                            baseCost, duration));
        }
    }
    flightFile.close();
}


AirControl::AirControl(string airportText, string flightText)
{
    numAirports = 0;
    readAirports(airportText);
    readFlights(flightText);

    // initilise verticies and weight of the map
    for (int i = 0; i < numAirports; i++)
    {
        for (int j = 0; j < numAirports; j++)
        {
            if (i == j) costs[i][j] = 0;
            costs[i][j] = (int)POS_INF;
        }
        
    }

    //  fill in costs[][]
    map<string, Airport*>::iterator ite;    // iterator to loop through each airports and check for flights 
    for (ite = airports.begin(); ite != airports.end(); ite++)
    {
        Flight* flights = ite->second->getFlights();
        for (int i = 0; i < ite->second->getNumFlights(); i++)
        {
            string departure = flights[i].getDeparture();
            string arrival = flights[i].getArrival();
            int arrivalID = airports[arrival]->getID();
            int departureID = airports[departure]->getID();
            costs[departureID][arrivalID] = flights[i].getBasePrice();
        }

    }
}

vector<Airport*> AirControl::getAirports()
{
    vector<Airport*> allAirports;
    map<string, Airport*>::iterator ite;

    for (ite = airports.begin(); ite != airports.end(); ite++ )
    {
        allAirports.push_back(ite->second);

    }
    return allAirports;

}

int AirControl::getNumAirports()
{
    return numAirports;
    
}

vector<Flight*> AirControl::directFlightCheck(string departure, string arrival)
{
    Airport* departureAirport = airports[departure];
    Flight* flightsFromDeparture = departureAirport->getFlights();
    vector<Flight*> result;

    for (int i = 0; i < departureAirport->getNumFlights(); i++)
    {   
        if (flightsFromDeparture[i].getArrival() == arrival)
            result.push_back(&flightsFromDeparture[i]);
    }
    return result;
}

struct AirControl::compare
{
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const{
        return a.second > b.second;
    }
};

void AirControl::Dijkstra(int a, vector<int>* weight, int* path)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    pq.push(make_pair(a,0));
    (*weight)[a] = 0;
    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int p = top.first;
        int w = top.second;
        for(int i = 0; i < graph[p].size(); i++)
        {
            pair<int,int> neighbor = graph[p][i];
            if (w + neighbor.second < (*weight)[neighbor.first]){
                (*weight)[neighbor.first] = w + neighbor.second;
                pq.push(pair<int,int>(neighbor.first, (*weight)[neighbor.first]));
                path[neighbor.first] = p;
            }
        }
    }
}

int AirControl::getCheapestRoutePrice(string departure,string arrival)
{
    int depid = airports[departure]->getID();
    int arrid = airports[arrival]->getID();
    vector<int> dist(55,POS_INF);
    int path[55];
    graph = vector<vector<pair<int,int>>>(55,vector<pair<int,int>>());
    for(int i = 0; i < numAirports; i++)
    {
        for(int j = 0; j < numAirports; j++){
            graph[i].push_back(pair<int,int>(j,costs[i][j]));
        }
    }
    Dijkstra(depid,&dist,path);
    return dist[arrid];
}

vector<Airport*> AirControl::cheapeastRoute(string departure, string arrival)
{
    int depID = airports[departure]->getID();
    int arrID = airports[arrival]->getID();
    vector<Airport*> returnPath;
    vector<int> dist(55,POS_INF);
    int path[55] = {-1};
    graph = vector<vector<pair<int,int>>>(55,vector<pair<int,int>>());
    for(int i = 0; i < numAirports; i++)
    {
        for(int j = 0; j < numAirports; j++){
            graph[i].push_back(pair<int,int>(j,costs[i][j]));
        }
    }
    Dijkstra(depID,&dist,path);
    int n = arrID;
    while(path[n] != -1)
    {
        map<string,Airport*>::iterator it;
        for(it = airports.begin(); it != airports.end(); it++ )
        {
            if( it->second->getID() == n) break;
        }
        returnPath.push_back(airports[it->first]);
        n = path[n];
    }
    return returnPath;
}    // return the cheapeast route



AirControl::~AirControl()
{}