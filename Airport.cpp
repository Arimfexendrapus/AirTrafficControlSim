#include "Nav_Aids"
#include "Airport.h"
#include <string>
#include <vector>

using namespace std;




	bool Airport::Degree_Clearance(int planeCoords[], string runway) 
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
		
	bool Airport::Runway_Availability(string runway)
	{
		int i = Identify_Runway(runway);
		return runwayAvailable[i];

	}
	
	void Airport::Empty_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		runwayAvailable[i] = true;

		
	}
	
	void Airport::Occupy_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		runwayAvailable[i] = false;

	}
	
	Nav_Aids Airport::Get_Runway(string runway)
	{
		int i = Identify_Runway(runway);
		return runwayEndPoints[i];

	}
	
	int Airport::Identify_Runway(string runway)
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