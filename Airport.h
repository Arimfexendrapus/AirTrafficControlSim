#ifndef AIRPORT
#define AIRPORT

#include <string>
#include <vector>
#include "nav_aid.h"

using namespace std;

class airport {
private:
	const vector<nav_aid> runwayEndPoints; // contains name and coordinate locations of each runway
	bool runwayAvailable[4]; // true means the runway is unavailable and false means it is available
public:
	bool degree_clearance(int heading, string runway);
	bool runway_availability(string runway);
	nav_aid get_runway(string runway);
	void empty_runway(string runway);
	void occupy_runway(string runway);
	int identify_runway(string runway);
};

#endif

bool airport::degree_clearance(int heading, string runway)
{
	int i = identify_runway(runway);
	refAngle = calculated degrees between planeCoords and runwayEndPoints[i] // cos^-1(a/h) 

		if (refAngle <= 30) return true;
		else return false;
}

bool airport::runway_availability(string runway)
{
	int i = identify_runway(runway);
	return runwayAvailable[i];
}

void airport::empty_runway(string runway)
{
	int i = identify_runway(runway);
	runwayAvailable[i] = true;
}

void airport::occupy_runway(string runway)
{
	int i = identify_runway(runway);
	runwayAvailable[i] = false;
}

nav_aid airport::get_runway(string runway)
{
	int i = identify_runway(runway);
	return runwayEndPoints[i];
}

int airport::identify_runway(string runway)
{
	for (int i = 0; i < runwayEndPoints.length; i++)
	{
		if (runway == runwayEndPoints[i].ID) return i;
	}
	//if invalid runway name what should we do in this case? or is it already checked
}