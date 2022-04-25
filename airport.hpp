#ifndef AIRPORT
#define AIRPORT

#include <string>
#include <vector>
#include <cmath>
#include "nav_aid.hpp"
#include "runway.hpp"

using namespace std;

class airport
{
private:
	vector<runway> runways; // contains runways
public:
	airport(); // constructor
	bool degree_clearance(int heading, string runwayID);
	bool runway_availability(string runwayID);
	runway get_runway(string runwayID);
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
		if (runwayID == runways[i].runwayID)
			return i;
	}

	return -1;
	// if invalid runway name what should we do in this case? or is it already checked
}

bool airport::degree_clearance(int heading, string runwayID)
{
	int i = identify_runway(runwayID);

	if (heading > runways[i].leftHeading - 30)
	{
		if (heading < runways[i].leftHeading + 30)
		{
			return true;
		}
	}
	return false;
	/*------------------- To Be Combined ------------------------------------*/
	int refAngle = abs((180 / pi) * arccos(
										(planeCoords[0] - runwayEndPoints[i].Coordinates[0]) // divided by
											/ ((planeCoords[0] - runwayEndPoints[i].Coordinates[0]) ^ 2 + (planeCoords[1] - runwayEndPoints[i].Coordinates[1]) ^ 2) ^
										(1 / 2))); // cos^-1(a/h)
	if (refAngle <= 30)
	{
		return true;
	}
	else
	{
		return false;
	}
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

runway airport::get_runway(string runway)
{
	int i = identify_runway(runway);
	return runways[i];
}
