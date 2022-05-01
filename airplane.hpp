#ifndef AIRPLANE
#define AIRPLANE

#define takeoffSpeed 160
#define takeoffAltitude 5000
vector<int> takeoffCoords = {4000, 4000, 4000};

//#include "airspace.h"
#include "aircraft.hpp"
#include "runway.hpp"
#include "airport.hpp"
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

	double speed;
	double altitude;
	int heading;
	vector<int> flightCoordinates;
	vector<int> boundForCoordinates;
	vector<int> finalDestination;
	bool isCleared;
	bool departing;
	bool isAborted;
	runway_ends *Runway;

public:
	aircraft Aircraft;

	bool land();
	bool takeOff();

	bool set_speed(double Speed);
	double get_speed();

	bool set_altitude(double Altitude);
	double get_altitude();

	bool set_heading(int Heading);
	bool set_heading(int Heading, char direction);
	int get_heading();

	bool set_course(vector<int> Coordinates);
	vector<int> get_course();

	bool set_intention(bool boolean); // true is departing, false is arriving
	bool get_intention();

	bool set_coordinates(vector<int> Coordinates);
	vector<int> get_coordinates();

	bool set_runway(string runwayID, airport *Airport);
	runway_ends *get_runway();

	bool set_flightID(string FlightID);
	string get_flightID();

	bool set_clearance(bool clear);
	bool get_clearance();

	bool abort();

	// contructor
	airplane();
	airplane(string fID, aircraft type); // constructor passed flight id
};

bool airplane::abort()
{
	isAborted = true;
	return true;
}

bool airplane::land()
{
	set_course(Runway->coordinates);
	while (1)
	{
		double distance = sqrt(pow((flightCoordinates[0] - Runway->coordinates[0]), 2) +
			pow((flightCoordinates[1] - Runway->coordinates[1]), 2) + pow((flightCoordinates[2] - Runway->coordinates[0]), 2));
		/*(distance between aircraft and runway)*/
		double howLong = distance / speed;  /*distance / speed */
		double toDecel = distance / Aircraft.aircraft_acceleration[1];  /*distance / aircraft.acceleration[1]*/
		if (howLong < toDecel)
		{
			set_speed(0);
			break;
		}
		Sleep(1000);
	}
	

	
	if (boundForCoordinates == flightCoordinates)
		return true;
	else
		return false;
}

bool airplane::takeOff()
{
	set_course(takeoffCoords);
	set_speed(takeoffSpeed);
	set_altitude(takeoffAltitude);

	if (boundForCoordinates == takeoffCoords)
		return true;
	else
		return false;
}

bool airplane::set_speed(double givenSpeed)
{
	if (givenSpeed > Aircraft.aircraft_max_speed)
		return false;
	while (speed != givenSpeed && isAborted == false)
	{
		if (speed > givenSpeed)
		{
			if (speed - Aircraft.aircraft_acceleration[1] < givenSpeed)
				speed = givenSpeed;
			else
				speed -= Aircraft.aircraft_acceleration[1];
		}
		else if (speed < givenSpeed)
		{
			if (speed + Aircraft.aircraft_acceleration[0] > givenSpeed)
				speed = givenSpeed;
			else
				speed += Aircraft.aircraft_acceleration[0];
		}
		Sleep(1000);
	}
	return true;
}

double airplane::get_speed()
{
	return speed;
}

bool airplane::set_altitude(double givenAltitude)
{

	while (altitude != givenAltitude && isAborted == false)
	{
		if (altitude > givenAltitude)
		{
			if (altitude - Aircraft.aircraft_elevation_rate[0] < givenAltitude)
				altitude = givenAltitude;
			else
				altitude -= Aircraft.aircraft_elevation_rate[0];
		}
		else if (altitude < givenAltitude)
		{
			if (altitude + Aircraft.aircraft_elevation_rate[1] > givenAltitude)
				altitude = givenAltitude;
			else
				altitude += Aircraft.aircraft_elevation_rate[1];
		}
		Sleep(1000);
	}
	return true;
}

double airplane::get_altitude()
{
	return altitude;
}

bool airplane::set_heading(int Heading)
{
	heading = Heading;
	if (heading == Heading)
		return true;
	else
		return false;
}

bool airplane::set_heading(int Heading, char direction)
{
	// Need to ask for clarification
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
	if (Coordinates == boundForCoordinates)
		return true;
	else
		return false;
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
	// true is departing, false is arriving
	departing = boolean;
	if (departing == boolean)
		return true;
	else
		return false;
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
	if (Coordinates == flightCoordinates)
		return true;
	else
		return false;
}

vector<int> airplane::get_coordinates()
{
	vector<int> Coordinates;
	Coordinates.push_back(flightCoordinates[0]);
	Coordinates.push_back(flightCoordinates[1]);
	Coordinates.push_back(flightCoordinates[2]);
	return Coordinates;
}

bool airplane::set_runway(string runwayID, airport *Airport)
{
	Runway = Airport->get_runway(runwayID);

	if (Runway->runwayID == runwayID)
		return true;
	else
		return false;
}

runway_ends *airplane::get_runway()
{
	return Runway;
}

bool airplane::set_flightID(string FlightID)
{
	flightID = FlightID;
	if (flightID == FlightID)
		return true;
	else
		return false;
}

string airplane::get_flightID()
{
	return flightID;
}

bool airplane::set_clearance(bool clear)
{
	isCleared = clear;
	if (isCleared == clear)
		return true;
	else
		return false;
}

bool airplane::get_clearance()
{
	return isCleared;
}

airplane::airplane()
{
	Runway = NULL;
	aircraft a;
	flightID = "default";
	Aircraft = a;
	speed = 0;
	altitude = 0;
	heading = 0;
	flightCoordinates = {0, 0, 0};
	boundForCoordinates = {0, 0, 0};
	finalDestination = {0, 0, 0};
	isCleared = false;
	departing = false;
	isAborted = false;
}

airplane::airplane(string fID, aircraft type)
{
	flightID = fID;
	Aircraft = type;
	speed = 0;
	altitude = 0;
	heading = 0;

	flightCoordinates.push_back(0);
	flightCoordinates.push_back(0);
	flightCoordinates.push_back(0);
	boundForCoordinates.push_back(0);
	boundForCoordinates.push_back(0);
	boundForCoordinates.push_back(0);
	finalDestination.push_back(0);
	finalDestination.push_back(0);
	finalDestination.push_back(0);
	isCleared = false;
	departing = false;
	Runway = NULL;
}

#endif