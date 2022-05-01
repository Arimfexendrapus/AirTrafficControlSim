#ifndef AIRCRAFT
#define AIRCRAFT

#include <string>
#include <iostream>
#include <vector>
using namespace std;
/*
	USING THE METRIC SYSTEM FOR ALL RATES AND SPEEDS
*/
struct aircraft
{

	string aircraft_name; // the type of the aircraft

	/*
		Units: meters/second^2
		index 0: acceleration rate
		index 1: deceleration rate
		NOTE:
		standardized value for each does not account for change based
		on elevation and speed just constant the whole time
		THIS IS IN THE X COORDINATE PLANE
		***
		REMEMBER acceleration = change in velocity / change in time

	*/
	double aircraft_acceleration[2] = { 0,0 };

	/*
		Units: meters/second
		index 0: climb rate
		index 1: descent rate
		THIS IS IN THE Y COORDINATE PLANE
	*/
	double aircraft_elevation_rate[2] = {0,0};
	int aircraft_max_speed = 0;	   // kilometers per hour
	int aircraft_max_altitude = 0; // meters
};

vector<aircraft> GetAircraftInfo()
{
	vector<aircraft> aircraftHold;
	/*

	Name: Boeing 737-800
	Acceleration:1.96 m/sec^2
	Climb Rate: 250 knots up to 10,000, above 10,000 280 to 300 knots
	Transition to mach 7 around 24,000
	Cruise Speed: 514 mph
	Max Speed: 588 mph
	Max Altitude:41,000
	Takeoff Speed: 150 mph
	Landing Speed:167 mph

*/
	aircraft ac1;
	ac1.aircraft_name = "Boeing 737-800";
	ac1.aircraft_acceleration[0] = 1.96; // m/s
	ac1.aircraft_acceleration[1] = 1.96;
	ac1.aircraft_elevation_rate[0] = 15.24;
	ac1.aircraft_elevation_rate[1] = 5.08;
	ac1.aircraft_max_speed = 946;	   // kmh
	ac1.aircraft_max_altitude = 12496; // meters
	aircraftHold.push_back(ac1);

	aircraft ac1;
	ac1.aircraft_name = "Airbus A320";
	ac1.aircraft_acceleration[0] = 1.45; // m/s
	ac1.aircraft_acceleration[1] = 1.45;
	ac1.aircraft_elevation_rate[0] = 15.24;
	ac1.aircraft_elevation_rate[1] = 5.08;
	ac1.aircraft_max_speed = 864;	   // kmh
	ac1.aircraft_max_altitude = 11887; // meters
	aircraftHold.push_back(ac1);

	aircraft ac1;
	ac1.aircraft_name = "Boeing 757-200";
	ac1.aircraft_acceleration[0] = 1.96; // m/s
	ac1.aircraft_acceleration[1] = 1.96;
	ac1.aircraft_elevation_rate[0] = 15.24;
	ac1.aircraft_elevation_rate[1] = 5.08;
	ac1.aircraft_max_speed = 982;	   // kmh
	ac1.aircraft_max_altitude = 12801; // meters
	aircraftHold.push_back(ac1);

	aircraft ac1;
	ac1.aircraft_name = "Bell 206 JetRanger";
	ac1.aircraft_acceleration[0] = 1.03; // m/s
	ac1.aircraft_acceleration[1] = 1.03;
	ac1.aircraft_elevation_rate[0] = 6.71;
	ac1.aircraft_elevation_rate[1] = 6.71;
	ac1.aircraft_max_speed = 225;	   // kmh
	ac1.aircraft_max_altitude = 6096; // meters
	aircraftHold.push_back(ac1);

	aircraft ac1;
	ac1.aircraft_name = "Robinson R44";
	ac1.aircraft_acceleration[0] = 1.03; // m/s
	ac1.aircraft_acceleration[1] = 1.03;
	ac1.aircraft_elevation_rate[0] = 6.71;
	ac1.aircraft_elevation_rate[1] = 6.71;
	ac1.aircraft_max_speed = 240;	   // kmh
	ac1.aircraft_max_altitude = 4267; // meters
	aircraftHold.push_back(ac1);

	return aircraftHold;
}

#endif
