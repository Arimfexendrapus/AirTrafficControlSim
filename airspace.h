// airspace class pseudo code
#include <vector>
#include <string>
#include "aircraft.h"
#include "nav_aid.h"
#include "airport.h"




class airspace
{
private:
    vector<string> flightids;
    vector<aircraft*> Aircraft;
    vector<nav_aid> navaids; // vector of navaid structs
    airport* airport_object;
    string returnmessage;

public:
    Airspace(vector<aircraft*> apvector, airport* aport);
    void generate_airplane();
    string clear_aircraft(string flightID, string navpoint, char directrion);
    string clear_aircraft(string flightID, int heading, char directrion);
    string clear_aircraft(string flightID, int altitude);
    string land_aircraft(string flightID, string runway);
    string takeoff_aircraft(string flightid);
    string hold_aircraft(string flightid, string navpoint);
    set_aircraft_speed(string flightID, int speed);
    wait_aircraft(string flightID);
    abort_aircraft(string flightID);
}

