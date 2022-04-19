#include "airport.h"

using namespace std;

	bool airport::degree_clearance(int heading, string runway)
	{
		int i = identify_runway(runway);
		refAngle = calculated degrees between planeCoords and runwayEndPoints[i] // cos^-1(a/h) 
		
		if(refAngle <= 30) return true;
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
		for(int i = 0; i<runwayEndPoints.length;i++)
		{
			if(runway == runwayEndPoints[i].ID) return i;
		}
		//if invalid runway name what should we do in this case? or is it already checked
	}