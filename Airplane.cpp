#include "airplane.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

bool Airplane::land(string Runway)
{
	if (altitude <= 3000 && Degree_Clearance(heading, Runway)==1)
	{
		int distance = 0;/*(distance between aircraft and runway)*/
		int howLong = 0; /*distance / speed */
		int toDecel = 0; /*distance / aircraft.acceleration[1]*/
		if (howLong < toDecel)
		{
			Set_Speed(0);
		}
		Set_Course(Runway.coordinates);

	}

}

bool Airplane::takeOff(vector<int> Coordinates)
{
	if (/*requirements for takeoff are met*/)
	{
		Set_Course(Coordinates);
		Set_Speed(takeoffSpeed);
		Set_Altitude(takeoffAltitude);
	}
	if (boundForCoordinates == Coordinates) return true;
	else return false;
}

bool Airplane::Set_Speed(int givenSpeed)
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

int Airplane::Get_Speed()
{
	return speed;
}

bool Airplane::Set_Altitude(int givenAltitude)
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

int Airplane::Get_Altitude()
{
	return altitude;
}

bool Airplane::Set_Heading(int Heading)
{
	heading = Heading;
	if (heading == Heading) return true;
	else return false;
}

int Airplane::Get_Heading()
{
	return heading;
}

bool Airplane::Set_Course(vector<int> Coordinates)
{
	boundForCoordinates[0] = Coordinates[0];
	boundForCoordinates[1] = Coordinates[1];
	boundForCoordinates[2] = Coordinates[2];

	if (Coordinates == boundForCoordinates) return true;
	else return false;
}

vector<int> Airplane::Get_Course()
{
	vector<int> Course;
	Course.push_back(boundForCoordinates[0]);
	Course.push_back(boundForCoordinates[1]);
	Course.push_back(boundForCoordinates[2]);

	return Course;
}

bool Airplane::Set_Intention(bool boolean)
{
	departing = boolean;
	if (departing == boolean) return true;
	else return false;
}

bool Airplane::Get_Intention()
{
	return departing;
}

bool Airplane::Set_Coordinates(vector<int> Coordinates)
{
	flightCoordinates[0] = Coordinates[0];
	flightCoordinates[1] = Coordinates[1];
	flightCoordinates[2] = Coordinates[2];

	if (Coordinates == flightCoordinates) return true;
	else return false;
}

vector<int> Airplane::Get_Coordinates()
{
	vector<int> Coordinates;
	Coordinates.push_back(flightCoordinates[0]);
	Coordinates.push_back(flightCoordinates[1]);
	Coordinates.push_back(flightCoordinates[2]);

	return Coordinates;
}

bool Airplane::Set_Runway(string Runway)
{
	runway = Runway;
	if (Runway == runway) return true;
	else return false;
}

string Airplane::Get_Runway()
{
	return runway;
}

bool Airplane::Set_FlightID(string FlightID)
{
	flightID = FlightID;
	if (flightID == FlightID) return true;
	else return false;
}

string Airplane::Get_FlightID()
{
	return flightID;
}