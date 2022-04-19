#include "airspace.h"
#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class airplane
{
private:
	string flightID;
	aircraft Aircraft;
	int speed;
	int altitude;
	int heading;
	vector<int> flightCoordinates;
	vector<int> boundForCoordinates;
	vector<int> finalDestination;
	bool isCleared;
	bool departing;
	string runway;
public:
	bool land(string Runway);
	bool takeOff(vector<int> Coordinates);

	bool set_speed(int Speed);
	int get_speed();

	bool set_altitude(int Altitutde);
	int get_altitude();

	bool set_heading(int Heading);
	int get_heading();

	bool set_course(vector<int> Coordinates);
	vector<int> get_course();

	bool set_intention(bool boolean);
	bool get_intention();

	bool set_coordinates(vector<int> Coordinates);
	vector<int> get_coordinates();

	bool set_runway(string Runway);
	string get_runway();

	bool set_flightID(string FlightID);
	string get_flightID();


};

