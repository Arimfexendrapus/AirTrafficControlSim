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
	navA.ID = "DAISY";
	navA.coordinates.push_back(30000); // x
	navA.coordinates.push_back(12000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "LHR";
	navA.coordinates.push_back(41000); // x
	navA.coordinates.push_back(14000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "WAT";
	navA.coordinates.push_back(14000); // x
	navA.coordinates.push_back(80000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "READ";
	navA.coordinates.push_back(-72000); // x
	navA.coordinates.push_back(-37000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "MAR";
	navA.coordinates.push_back(22000); // x
	navA.coordinates.push_back(11000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "GUI";
	navA.coordinates.push_back(-24000); // x
	navA.coordinates.push_back(-7000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);

	nav_aid navA;
	navA.ID = "LEA";
	navA.coordinates.push_back(8000); // x
	navA.coordinates.push_back(-18000); // y
	navA.coordinates.push_back(0);  // z
	local.push_back(navA);



	return local;
}

#endif