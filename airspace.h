// Airspace Class Pseudo Code
#include <vector>
#include <string>
#include "aircraft.h"
#include "nav_aid.h"
#include "airport.h"




class airspace
{
private:
    vector<string> FlightIDs;
    vector<aircraft*> Aircraft;
    vector<nav_aid> NavAids; // vector of NavAid Structs
    airport* Airport_Object;
    string ReturnMessage;

public:
    Airspace(vector<aircraft*> apVector, airport* aPort);
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
}
