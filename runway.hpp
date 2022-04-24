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
	string runwayID[2];
	int startlocation[2]; // left side coordinates
	int endlocation[2];	  // right side coordinates
	int leftHeading;	  // heading coming out from the left
	int rightHeading;	  // heading coming out from the right
	bool available;		  // is it available
};

vector<runway> runwayInfo()
{
	vector<runway> local;

	runway top; // the "upper" runway
	runway bot; // the "lowwer" runway
	top.runwayID[0] = "9l";
	top.runwayID[1] = "27r";
	top.startlocation[0] = -1950; // x
	top.startlocation[1] = 685;	  // y
	top.endlocation[0] = 1950;	  // x
	top.endlocation[1] = 685;	  // y
	top.leftHeading = 270;		  // base heading around the center coordinate
	top.rightHeading = 90;
	top.available = true;

	bot.runwayID[0] = "9r";
	bot.runwayID[1] = "27l";
	bot.startlocation[0] = -1709; // x
	bot.startlocation[1] = -685;  // y
	bot.endlocation[0] = 1950;	  // x
	bot.endlocation[1] = -685;	  // y
	bot.leftHeading = 270;		  // base heading around the center coordinate
	bot.rightHeading = 90;
	bot.available = true;

	local.push_back(top);
	local.push_back(bot);

	return local;
}
#endif