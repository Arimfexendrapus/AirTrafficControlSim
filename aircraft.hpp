#ifndef AIRCRAFT
#define AIRCRAFT

#include <string>

struct aircraft {
	string aircraft_name;
	int aircraft_acceleration[2]; //0 is acceleration 1 is deceleration 
	int aircraft_elevation_rate; // climb and descent
	int aircraft_max_speed;
	int aircraft_max_altitude;
};
#endif