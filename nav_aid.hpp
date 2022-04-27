#ifndef NAV_AID
#define NAV_AID

#include <string>
#include <vector>

struct nav_aid
{
	string ID;
	vector<int> coordinates = {0,0,0};
};


vector<nav_aid> getNavAids()
{
	vector<nav_aid> local;

	nav_aid navA;
	navA.ID = "daisy";
	navA.coordinates.push_back(30000); // x
	navA.coordinates.push_back(12000); // y
	navA.coordinates.push_back(6000);  // z
	local.push_back(navA);

	return local;
}

#endif