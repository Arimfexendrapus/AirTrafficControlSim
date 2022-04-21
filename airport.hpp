#ifndef AIRPORT
#define AIRPORT

#include <string>
#include <vector>
#include <cmath>
#include "nav_aid.hpp"
#include "runway.hpp"

using namespace std;

class airport {
private:
	vector<runway> runways; // contains runways
public:
	bool degree_clearance(int heading, int runwayID);
	bool runway_availability(int runwayID);
	runway get_runway(int runwayID);
	void empty_runway(int runwayID);
	void occupy_runway(int runwayID);
	int identify_runway(int runwayID);
};
#endif

int airport::identify_runway(int runwayID)
{
	for (int i = 0; i < runways.size(); i++)
	{
		if (runwayID == runways[i].runwayID) return i;
	}

	return -1;
	//if invalid runway name what should we do in this case? or is it already checked
}

bool airport::degree_clearance(int heading, int runwayID)
{
	int i = identify_runway(runwayID);

	if (heading > runways[i].inHeading-30)
	{
		if (heading < runways[i].inHeading+30)
		{
			return true;
		}
	}
	return false;
/*------------------- To Be Combined ------------------------------------*/
		int refAngle = abs((180/pi)*arccos(
			(planeCoords[0] - runwayEndPoints[i].Coordinates[0])//divided by
			/((planeCoords[0] - runwayEndPoints[i].Coordinates[0])^2 + (planeCoords[1] - runwayEndPoints[i].Coordinates[1])^2)^(1/2))); // cos^-1(a/h) 
		if(refAngle <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool airport::runway_availability(int runwayID)
{
	int i = identify_runway(runwayID);
	return runways[i].available;
}

void airport::empty_runway(int runwayID)
{
	int i = identify_runway(runwayID);
	runways[i].available = true;
}

void airport::occupy_runway(int runway)
{
	int i = identify_runway(runway);
	runways[i].available = false;
}

runway airport::get_runway(int runway)
{
	int i = identify_runway(runway);
	return runways[i];
}

