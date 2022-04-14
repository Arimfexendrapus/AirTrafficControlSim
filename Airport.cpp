#include "nav_aids.h"
#include "airport.h"
#include <string>
#include <vector>

using namespace std;




	bool airport::Degree_Clearance(int planeCoords[], string runway) 
	{
		int i = Identify_Runway(runway);
		refAngle = calculated degrees between planeCoords and runwayEndPoints[i] // cos^-1(a/h) 
		if(refAngle <= 30)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
		
	bool airport::Runway_Availability(string runway)
	{
		int i = Identify_Runway(runway);
		return runwayAvailable[i];

	}
	
	void airport::Empty_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		runwayAvailable[i] = true;

		
	}
	
	void airport::Occupy_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		runwayAvailable[i] = false;

	}
	
	nav_aid airport::Get_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		return runwayEndPoints[i];

	}
	
	int airport::Identify_Runway(string runway)
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