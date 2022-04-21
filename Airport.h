#include "nav_aid.h"
#include <string>
#include <vector>

using namespace std;

#ifndef AIRPORT_H
#define AIRPORT_H

class airport {
private:
	const nav_aid runwayEndPoints[4] = 
	[
		{
			ID = 27R,
			Coordinates = [10,5]
		},
		{
			ID = 27L,
			Coordinates = [10,-5]
		},
		{
			ID = 9R,
			Coordinates = [-10,5]
		},
		{
			ID = 9L,
			Coordinates = [-10,-5]
		}
	]; // contains name and coordinate locations of each runway
	bool runwayAvailable[4] = [true,true,false,true]; // true means the runway is available and false means it is unavailable
public:
	bool degree_clearance(vector<int> planeCoords, string runway);
	bool runway_availability(string runway);
	nav_aid get_runway(string runway);
	void empty_runway(string runway);
	void occupy_runway(string runway);
	int identify_runway(string runway);
}
#endif