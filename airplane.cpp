#include "airplane.h"



bool airplane::land(string Runway)
{
	if (altitude <= 3000 && Degree_Clearance(heading, Runway)==1)
	{
		int distance = 0;/*(distance between aircraft and runway)*/
		int howLong = 0; /*distance / speed */
		int toDecel = 0; /*distance / aircraft.acceleration[1]*/
		if (howLong < toDecel)
		{
			set_speed(0);
		}
		set_course(Runway.coordinates);

	}

}

bool airplane::takeOff(vector<int> Coordinates)
{
	if (/*requirements for takeoff are met*/)
	{
		set_course(Coordinates);
		set_speed(takeoffSpeed);
		set_altitude(takeoffAltitude);
	}
	if (boundForCoordinates == Coordinates) return true;
	else return false;
}

bool airplane::set_speed(int givenSpeed)
{
	while(speed != givenSpeed)
	{
		if (speed > givenSpeed)
		{
			if (speed - aircraft.acceleration[1] < givenSpeed)
			{
				speed = givenSpeed;
			}
			else
			{
				speed -= aircraft.acceleration[1];
			}	
		}

		else if (speed < givenSpeed)
		{
			if (speed + aircraft.acceleration[0] > givenSpeed)
			{
				speed = givenSpeed;
			}
			else
			{
				speed += aircraft.acceleration[0];
			}
		}
		sleep(1);
	}
	return true;
}

int airplane::get_speed()
{
	return speed;
}

bool airplane::set_altitude(int givenAltitude)
{
	while (altitude != givenAltitude)
	{
		if (altitude > givenAltitude)
		{
			if (altitude - aircraft.climb < givenAltitude)
			{
				altitude = givenAltitude;
			}
			else
			{
				altitude -= aircraft.climb;
			}
		}

		else if (altitude < givenAltitude)
		{
			if (altitude + aircraft.climb > givenAltitude)
			{
				altitude = givenAltitude;
			}
			else
			{
				altitude += aircraft.climb;
			}
		}
		sleep(1);
	}
	return true;
}

int airplane::get_altitude()
{
	return altitude;
}

bool airplane::set_heading(int Heading)
{
	heading = Heading;
	if (heading == Heading) return true;
	else return false;
}

int airplane::get_heading()
{
	return heading;
}

bool airplane::set_course(vector<int> Coordinates)
{
	boundForCoordinates[0] = Coordinates[0];
	boundForCoordinates[1] = Coordinates[1];
	boundForCoordinates[2] = Coordinates[2];

	if (Coordinates == boundForCoordinates) return true;
	else return false;
}

vector<int> airplane::get_course()
{
	vector<int> Course;
	Course.push_back(boundForCoordinates[0]);
	Course.push_back(boundForCoordinates[1]);
	Course.push_back(boundForCoordinates[2]);

	return Course;
}

bool airplane::set_intention(bool boolean)
{
	departing = boolean;
	if (departing == boolean) return true;
	else return false;
}

bool airplane::get_intention()
{
	return departing;
}

bool airplane::set_coordinates(vector<int> Coordinates)
{
	flightCoordinates[0] = Coordinates[0];
	flightCoordinates[1] = Coordinates[1];
	flightCoordinates[2] = Coordinates[2];

	if (Coordinates == flightCoordinates) return true;
	else return false;
}

vector<int> airplane::get_coordinates()
{
	vector<int> Coordinates;
	Coordinates.push_back(flightCoordinates[0]);
	Coordinates.push_back(flightCoordinates[1]);
	Coordinates.push_back(flightCoordinates[2]);

	return Coordinates;
}

bool airplane::set_runway(string Runway)
{
	runway = Runway;
	if (Runway == runway) return true;
	else return false;
}

string airplane::get_runway()
{
	return runway;
}

bool airplane::set_flightID(string FlightID)
{
	flightID = FlightID;
	if (flightID == FlightID) return true;
	else return false;
}

string airplane::get_flightID()
{
	return flightID;
}