#include "nav_aid.h"
#include <string>
#include <vector>

using namespace std;

class airport {
	private:
		const vector<nav_aid> runwayEndPoints; // contains name and coordinate locations of each runway
		bool runwayAvailable[4]; // true means the runway is unavailable and false means it is available
	public:
		bool airport::Degree_Clearance(int heading, string runway);
		bool airport::Runway_Availability(string runway);
		nav_aid airport::Get_Runway(string runway);
		void airport::Empty_Runway(string runway);
		void airport::Occupy_Runway(string runway);
}