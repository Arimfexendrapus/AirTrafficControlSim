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
	*/
	int aircraft_acceleration[2];

	/*
		Units: meters/second^2
		index 0: climb rate
		index 1: descent rate
	*/
	int aircraft_elevation_rate[2];
	int aircraft_max_speed;	   // meters per second
	int aircraft_max_altitude; // meters
};

vector<aircraft> GetAircraftInfo(){
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

	return aircraftHold;
}

#endif
