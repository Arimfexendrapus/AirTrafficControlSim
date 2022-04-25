#ifndef RUNWAY
#define RUNWAY

#include <string>
#include <vector>

using namespace std;

struct runway
{
	/*
		index 0: left side id
		index 1: right side id
	*/
	string runwayID;
	vector<int> startlocation; // left side coordinates
	vector<int> endlocation;   // right side coordinates
	int leftHeading;		   // heading coming out from the left
	int rightHeading;		   // heading coming out from the right
	bool available;			   // is it available
};

vector<runway> runwayInfo()
{
	vector<runway> local;

	runway top; // the "upper" runway
	runway bot; // the "lower" runway
	top.runwayID[0] = "9l";
	top.runwayID[1] = "27r";
	top.startlocation.push_back(-1950); // x
	top.startlocation.push_back(685);	// y
	top.endlocation.push_back(1950);	// x
	top.endlocation.push_back(685);		// y
	top.leftHeading = 270;				// base heading around the center coordinate
	top.rightHeading = 90;
	top.available = true;

	bot.runwayID[0] = "9r";
	bot.runwayID[1] = "27l";
	bot.startlocation.push_back(-1709); // x
	bot.startlocation.push_back(-685);	// y
	bot.endlocation.push_back(1950);	// x
	bot.endlocation.push_back(-685);	// y
	bot.leftHeading = 270;				// base heading around the center coordinate
	bot.rightHeading = 90;
	bot.available = true;

	local.push_back(top);
	local.push_back(bot);

	return local;
}
#endif