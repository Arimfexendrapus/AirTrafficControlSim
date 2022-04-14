#pragma once

#include "airspace.h"
#include <string>
#include <vector>

using namespace std;

class Airplane
{
private:
	string flightID;
	aircraft aircraft;
	int speed;
	int altitude;
	int heading;
	vector<int> flightCoordinates;
	vector<int> boundForCoordinates;
	vector<int> finalDestination;
	bool isCleared;
	bool departing;
	string runway;
public:
	bool land(string Runway);
	bool takeOff(vector<int> Coordinates);

	bool Set_Speed(int Speed);
	int Get_Speed();

	bool Set_Altitude(int Altitutde);
	int Get_Altitude();

	bool Set_Heading(int Heading);
	int Get_Heading();

	bool Set_Course(vector<int> Coordinates);
	vector<int> Get_Course();

	bool Set_Intention(bool boolean);
	bool Get_Intention();

	bool Set_Coordinates(vector<int> Coordinates);
	vector<int> Get_Coordinates();

	bool Set_Runway(string Runway);
	string Get_Runway();

	bool Set_FlightID(string FlightID);
	string Get_FlightID();


};

