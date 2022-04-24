#ifndef AIRSPACE
#define AIRSPACE

// airspace class pseudo code
#include <vector>
#include <string>

#include "airport.hpp"
#include "aircraft.hpp"
#include "nav_aid.hpp"

class airspace
{
private:
    vector<string> FlightIDs;
    vector<airplane *> Airplane;
    vector<aircraft> AircraftInfo;
    vector<nav_aid> NavAids; // vector of navaid structs
    airport *Airport_Object;
    string ReturnMessage;

public:
    airspace(vector<airplane *> apVector, airport *aPort);
    void generate_airplane();
    string clear_aircraft(string FlightID, string NavPoint, char Directrion);
    string clear_aircraft(string FlightID, int heading, char Directrion);
    string clear_aircraft(string FlightID, int altitude);
    string land_aircraft(string FlightID, string runway);
    string takeoff_aircraft(string FlightID);
    string hold_aircraft(string FlightID, string NavPoint);
    bool set_aircraft_speed(string FlightID, int Speed);
    bool wait_aircraft(string FlightID);
    bool abort_aircraft(string FlightID);
};
#endif

airspace::airspace(vector<airplane *> apVector, airport *aPort)
{
    Airplane = apVector;
    Airport_Object = aPort;
    ReturnMessage = "";
    NavAids = /*GENERATE ALL NAVAIDS STRUCTURES AND PUSH INTO THIS VARIABLE*/;
}
