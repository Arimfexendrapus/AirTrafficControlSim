#ifndef RUNWAY
#define RUNWAY

#include <string>
#include <vector>

using namespace std;

struct runway {
	int runwayID = 0;
	vector<int> location = { 0,0,0 };
	int outHeading = 0;
	int inHeading = outHeading + 180;
};

#endif