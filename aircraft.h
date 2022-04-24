#ifndef AIRCRAFT
#define AIRCRAFT

#include <string>
#include <iostream>
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
#endif
