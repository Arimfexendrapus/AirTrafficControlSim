#ifndef AIRPLANE
#define AIRPLANE

//#include "airspace.h"
#include "aircraft.h"
#include "runway.h"
#include "airport.h"
#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class airplane
{
private:
	string flightID;
	aircraft Aircraft;
	int speed;
	int altitude;
	int heading;
	vector<int> flightCoordinates;
	vector<int> boundForCoordinates;
	vector<int> finalDestination;
	bool isCleared;
	bool departing;
	runway *Runway;
public:
	bool land(airport Airport);
	bool takeOff(vector<int> Coordinates);

	bool set_speed(int Speed);
	int get_speed();

	bool set_altitude(int Altitutde);
	int get_altitude();

	bool set_heading(int Heading);
	bool set_heading(int Heading, char direction);
	int get_heading();

	bool set_course(vector<int> Coordinates);
	vector<int> get_course();

	bool set_intention(bool boolean);  //true is departing, false is arriving
	bool get_intention();

	bool set_coordinates(vector<int> Coordinates);
	vector<int> get_coordinates();

	bool set_runway(int runwayID, airport Airport);
	int get_runway();

	bool set_flightID(string FlightID);
	string get_flightID();

	bool set_clearance(bool clear);
	bool get_clearance();


	//contructor
	airplane();

};

#endif


#define takeoffSpeed 160
#define takeoffAltitude 5000

bool airplane::land(airport Airport)
{
	if (altitude <= 3000 && Airport.degree_clearance(heading, Runway->runwayID)==1)
	{
		int distance = 0;/*(distance between aircraft and runway)*/
		int howLong = 0; /*distance / speed */
		int toDecel = 0; /*distance / aircraft.acceleration[1]*/
		if (howLong < toDecel) set_speed(0);
		
		set_course(Runway->endlocation);
	}
}

bool airplane::takeOff(vector<int> Coordinates)
{
	if (/*requirements for takeoff are met*/)
	{
		set_course(Coordinates);
		set_speed(takeoffSpeed);
		set_altitude(takeoffAltitude);
	}
	if (boundForCoordinates == Coordinates) return true;
	else return false;
}

bool airplane::set_speed(int givenSpeed)
{
	if (givenSpeed > Aircraft.aircraft_max_speed) return false;

	while (speed != givenSpeed)
	{
		if (speed > givenSpeed)
		{
			if (speed - Aircraft.aircraft_acceleration[1] < givenSpeed) speed = givenSpeed;
			else speed -= Aircraft.aircraft_acceleration[1];
		}

		else if (speed < givenSpeed)
		{
			if (speed + Aircraft.aircraft_acceleration[0] > givenSpeed) speed = givenSpeed;
			else speed += Aircraft.aircraft_acceleration[0];
		}
		Sleep(1000);
	}
	return true;
}

int airplane::get_speed()
{
	return speed;
}

bool airplane::set_altitude(int givenAltitude)
{
	while (altitude != givenAltitude)
	{
		if (altitude > givenAltitude)
		{
			if (altitude - Aircraft.aircraft_elevation_rate < givenAltitude) altitude = givenAltitude;
			else altitude -= Aircraft.aircraft_elevation_rate;
		}

		else if (altitude < givenAltitude)
		{
			if (altitude + Aircraft.aircraft_elevation_rate > givenAltitude) altitude = givenAltitude;
			else altitude += Aircraft.aircraft_elevation_rate;
		}
		Sleep(1000);
	}
	return true;
}

int airplane::get_altitude()
{
	return altitude;
}

bool airplane::set_heading(int Heading)
{
	heading = Heading;
	if (heading == Heading) return true;
	else return false;
}

bool airplane::set_heading(int Heading, char direction)
{
	//Need to ask for clarification


	return true;
}

int airplane::get_heading()
{
	return heading;
}

bool airplane::set_course(vector<int> Coordinates)
{
	boundForCoordinates[0] = Coordinates[0];
	boundForCoordinates[1] = Coordinates[1];
	boundForCoordinates[2] = Coordinates[2];

	if (Coordinates == boundForCoordinates) return true;
	else return false;
}

vector<int> airplane::get_course()
{
	vector<int> Course;
	Course.push_back(boundForCoordinates[0]);
	Course.push_back(boundForCoordinates[1]);
	Course.push_back(boundForCoordinates[2]);

	return Course;
}

bool airplane::set_intention(bool boolean)
{
	//true is departing, false is arriving

	departing = boolean;
	if (departing == boolean) return true;
	else return false;
}

bool airplane::get_intention()
{
	return departing;
}

bool airplane::set_coordinates(vector<int> Coordinates)
{
	flightCoordinates[0] = Coordinates[0];
	flightCoordinates[1] = Coordinates[1];
	flightCoordinates[2] = Coordinates[2];

	if (Coordinates == flightCoordinates) return true;
	else return false;
}

vector<int> airplane::get_coordinates()
{
	vector<int> Coordinates;
	Coordinates.push_back(flightCoordinates[0]);
	Coordinates.push_back(flightCoordinates[1]);
	Coordinates.push_back(flightCoordinates[2]);

	return Coordinates;
}

bool airplane::set_runway(int runwayID, airport Airport)
{
	Runway = &Airport.get_runway(runwayID);
	if (Runway->runwayID == runwayID) return true;
	else return false;
}

int airplane::get_runway()
{
	return Runway->runwayID;
}

bool airplane::set_flightID(string FlightID)
{
	flightID = FlightID;
	if (flightID == FlightID) return true;
	else return false;
}

string airplane::get_flightID()
{
	return flightID;
}

bool airplane::set_clearance(bool clear)
{
	isCleared = clear;
	if (isCleared == clear) return true;
	else return false;
}

bool airplane::get_clearance()
{
	return isCleared;
}


airplane::airplane()
{
	aircraft a;
	runway b;
	flightID = "default";
	Aircraft = a;
	speed = 0;
	altitude = 0;
	heading = 0;
	flightCoordinates = { 0,0,0 };
	boundForCoordinates = { 0,0,0 };
	finalDestination = { 0,0,0 };
	isCleared = false;
	departing = false;
	Runway = b;
}