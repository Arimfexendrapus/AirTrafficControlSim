#ifndef RUNWAY
#define RUNWAY

#include <string>
#include <vector>

using namespace std;

struct runway_ends
{
	string runwayID;
	vector<int> coordinates;
	int heading = 0;
	bool available = false; // is it available
};

vector<runway_ends> runwayInfo()
{
	vector<runway_ends> local;

	runway_ends topRight; // the "upper" runway
	runway_ends botRight; // the "lower" runway
	runway_ends topLeft;  // the "upper" runway
	runway_ends botLeft;  // the "lower" runway

	topLeft.runwayID = "9L";
	topRight.runwayID = "27R";

	topLeft.coordinates.push_back(-1950); // x
	topLeft.coordinates.push_back(685);	  // y
	topLeft.coordinates.push_back(0);	  // z

	topRight.coordinates.push_back(1950); // x
	topRight.coordinates.push_back(685);  // y
	topRight.coordinates.push_back(0);	  // z

	topLeft.heading = 270; // base heading around the center coordinate
	topRight.heading = 90;
	topLeft.available = true;
	topRight.available = topLeft.available;

	botLeft.runwayID = "9R";
	botRight.runwayID = "27L";
	botLeft.coordinates.push_back(-1709); // x
	botLeft.coordinates.push_back(-685);  // y
	botLeft.coordinates.push_back(0);	  // z

	botRight.coordinates.push_back(1950); // x
	botRight.coordinates.push_back(-685); // y
	botRight.coordinates.push_back(0);	  // z

	botLeft.heading = 270; // base heading around the center coordinate
	botRight.heading = 90;
	botRight.available = true;
	botLeft.available = botRight.available;

	local.push_back(topLeft);
	local.push_back(botLeft);
	local.push_back(topRight);
	local.push_back(botRight);

	return local;
}
#endif