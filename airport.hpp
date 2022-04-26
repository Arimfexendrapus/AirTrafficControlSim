#ifndef AIRPORT
#define AIRPORT
#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include "nav_aid.hpp"
#include "runway.hpp"
#include "airplane.hpp"

using namespace std;

class airport
{
private:
	vector<runway_ends> runways; // contains runways
public:
	airport(); // constructor
	bool degree_clearance(string runwayID, airplane *Plane);
	bool runway_availability(string runwayID);
	runway_ends get_runway(string runwayID);
	void empty_runway(string runwayID);
	void occupy_runway(string runwayID);
	int identify_runway(string runwayID);
};


bool airport::degree_clearance(string runwayID, airplane *Plane)
{
	int i = identify_runway(runwayID);
	vector<int> planeCoords = Plane->get_coordinates();

	int refAngle =
		abs((180 / M_PI) * acos((planeCoords[0] - runways[i].coordinates[0]) // divided by
			/ ((planeCoords[0] - runways[i].coordinates[0]) ^ 2 +
				(planeCoords[1] - runways[i].coordinates[1]) ^ 2) ^ (1 / 2))); // cos^-1(a/h)

	if (refAngle <= 30)
	{
		if (Plane->get_heading() > runways[i].heading - 30)
		{
			if (Plane->get_heading() < runways[i].heading + 30)
			{
				return true;
			}
		}
	}
	return false;
}

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

#endif