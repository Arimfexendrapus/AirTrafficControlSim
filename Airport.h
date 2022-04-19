#include <string>
#include <vector>
#include "nav_aid.h"

using namespace std;

class airport {
private:
	const vector<nav_aid> runwayEndPoints; // contains name and coordinate locations of each runway
	bool runwayAvailable[4]; // true means the runway is unavailable and false means it is available
public:
	bool degree_clearance(int heading, string runway);
	bool runway_availability(string runway);
	nav_aid get_runway(string runway);
	void empty_runway(string runway);
	void occupy_runway(string runway);
	int identify_runway(string runway);
}
