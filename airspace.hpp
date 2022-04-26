#ifndef AIRSPACE
#define AIRSPACE

// airspace class pseudo code
#include <vector>
#include <string>
#include <random>

#include "airport.hpp"
#include "airplane.hpp"
#include "aircraft.hpp"
#include "nav_aid.hpp"
using namespace std;

class airspace
{
private:
    vector<string> FlightIDs;
    vector<airplane *> AirplaneVec;
    vector<aircraft> AircraftInfo;
    vector<nav_aid> NavAids; // vector of navaid structs
    airport *Airport_Object;
    string ReturnMessage;

public:
    airspace(vector<airplane *> apVector, airport *aPort);
    void generate_airplane();
    void simulator();
    string clear_aircraft(string FlightID, string NavPoint, char Directrion);
    string clear_aircraft(string FlightID, int heading, char Directrion);
    string clear_aircraft(string FlightID, int altitude);
    string land_aircraft(string FlightID, string runway);
    string takeoff_aircraft(string FlightID);
    string hold_aircraft(string FlightID, string NavPoint);
    string set_aircraft_speed(string FlightID, int Speed);
    string wait_aircraft(string FlightID);
    string abort_aircraft(string FlightID);
    int identify_flight(string FlightID);
};

airspace::airspace(vector<airplane *> apVector, airport *aPort)
{

    AirplaneVec = apVector; // holds pointers to the airplane
    Airport_Object = aPort; // get the pointer to airport object
    FlightIDs.clear();
    AircraftInfo = GetAircraftInfo(); // called from aircraft info header file
    NavAids = getNavAids();
    ReturnMessage = "";
    this->generate_airplane(); // NOT CORRECT YET
}

void airspace::generate_airplane()
{
    string flightID = ""; // hold the flightID string
    string Airlines[3] = {"AAL", "DAL", "NKS"};
    aircraft TempCraft;
    int rdom = 0;
    bool taken = false;
    /* https://stackoverflow.com/questions/41875884/how-to-generate-random-numbers-in-c-without-using-time-as-a-seed */
    // Setup ONCE
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 999);
    rdom = dis(gen);
    flightID += Airlines[rdom % 3];
    while (taken)
    {
        taken = false;
        flightID += Airlines[rdom % 3];
        if (rdom / 10 == 0) // if its a single digit number
        {
            flightID += "00" + to_string(rdom);
        }
        else if (rdom / 100 == 0) // if its double digit
        {
            flightID += "0" + to_string(rdom);
        }
        else
        {
            flightID += to_string(rdom);
        }
        // make sure that there isnt already something with this flight id
        for (int x = 0; x < (int)FlightIDs.size(); x++)
        {
            if (flightID == FlightIDs[x])
            {
                taken = true;
                break;
            }
        }
    }
    // choose a random aircraft type
    TempCraft = AircraftInfo[rdom % 5];
}

int airspace::identify_flight(string FlightID)
{
    for (int i = 0; i < AirplaneVec.size(); i++)
    {
        if (FlightID == AirplaneVec[i]->get_flightID())
        {
            return i;
        }
    }
    return -1;
}

string airspace::abort_aircraft(string FlightID)
{
    int aircraftLoc = identify_flight(FlightID);
    if (aircraftLoc != -1)
    {
        AirplaneVec[aircraftLoc]->abort();
        return "abort started";
    }
    else
        return "invalid ID";
}

#endif