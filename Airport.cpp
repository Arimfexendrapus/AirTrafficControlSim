#include "nav_aid.h"
#include "airport.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;


	bool airport::degree_clearance(vector<int> planeCoords, string runway)
	{
		int i = identify_runway(runway);
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
		for(int i = 0; i<runwayEndPoints.length;i++)
		{
			if(runway == runwayEndPoints[i].ID)
			{
				return i;
			}
		}
		//if invalid runway name what should we do in this case? or is it already checked
	}