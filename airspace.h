// Airspace Class Pseudo Code
#include <vector>
#include <string>
#include "aircraft.h"

class Airspace
{
private:
    vector<string> FlightIDs;
    vector<aircraft*> Aircraft;
    vector<nav_aid> NavAids; // vector of NavAid Structs
    Airport* Airport_Object;
    string ReturnMessage;

public:
    Airspace(vector<Airplane*> apVector, Airport* aPort);
    void Generate_Airplane();
    string Clear_Aircraft(string FlightID, string NavPoint, char Directrion);
    string Clear_Aircraft(string FlightID, int heading, char Directrion);
    string Clear_Aircraft(string FlightID, int altitude);
    string Land_Aircraft(string FlightID, string runway);
    string Takeoff_Aircraft(string FlightID);
    string Hold_Aircraft(string FlightID, string NavPoint);
    Set_Aircraft_Speed(FlightID : string, Speed : int);
    Wait_Aircraft(FlightID : string);
    Abort_Aircraft(FlightID : string);