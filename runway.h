#ifndef RUNWAY
#define RUNWAY

#include <string>
#include <vector>

using namespace std;

struct runway {
	int runwayID = 0;
	vector<int> startlocation = { 0,0,0 };
	vector<int> endlocation = { 0,0,0 };
	int outHeading = 0;
	int inHeading = outHeading + 180;
	string test = "test";
};

#endif