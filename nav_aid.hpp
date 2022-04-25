#ifndef NAV_AID
#define NAV_AID

#include <string>
#include <vector>

struct nav_aid
{
	string ID;
	int coordinates[2];
};
#endif

vector<nav_aid> getNavAids()
{
	vector<nav_aid> local;

	nav_aid navA;
	navA.ID = "daisy";
	navA.coordinates[0] = 30000; // x
	navA.coordinates[1] = 12000; // y
	local.push_back(navA);

	return local;
}