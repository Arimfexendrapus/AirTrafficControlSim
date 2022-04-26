#ifndef AIRPORT
#define AIRPORT
#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include "nav_aid.hpp"
#include "runway.hpp"

using namespace std;

class airport
{
private:
	vector<runway_ends> runways; // contains runways
public:
	airport(); // constructor
	bool degree_clearance(int heading, string runwayID, airplane* Plane);
	bool runway_availability(string runwayID);
	runway_ends get_runway(string runwayID);
	void empty_runway(string runwayID);
	void occupy_runway(string runwayID);
	int identify_runway(string runwayID);
};
#endif

airport::airport()
{
	runways = runwayInfo();
}

int airport::identify_runway(string runwayID)
{
	for (int i = 0; i < runways.size(); i++)
	{
		if (runwayID == runways[i].runwayID) return i;
	}

	return -1;
	// if invalid runway name what should we do in this case? or is it already checked
}

bool airport::degree_clearance(int heading, string runwayID, airplane* Plane)
{
	int i = identify_runway(runwayID);

	int refAngle =
	abs((180 / M_PI) * acos((Plane.flightCoordinates[0] - runways[i].Coordinates[0]) // divided by
	/((Plane.flightCoordinates[0] - runways[i].Coordinates[0])^2 + (Plane.flightCoordinates[1] - runways[i].Coordinates[1])^2)^(1 / 2))); // cos^-1(a/h)
	if (refAngle <= 30)
	{
		if (heading > runways[i].heading - 30)
		{
			if (heading < runways[i].heading + 30)
			{
				return true;
			}
		}
	}
	return false;
	
}

bool airport::runway_availability(string runwayID)
{
	int i = identify_runway(runwayID);
	return runways[i].available;
}

void airport::empty_runway(string runwayID)
{
	int i = identify_runway(runwayID);
	runways[i].available = true;
}

void airport::occupy_runway(string runway)
{
	int i = identify_runway(runway);
	runways[i].available = false;
}

runway_ends airport::get_runway(string runway)
{
	int i = identify_runway(runway);
	return runways[i];
}
