#include "Airplane.h"

bool Airplane::land(string FlightID, string Runway)
{
	if (altitude <= 3000 && Degree_Clearance(heading, Runway)==true)
	{
		//heading,speed,altitude,course
		Set_Altitude(altitude);
		Set_Heading(heading);
		Set_Speed(speed);
		Set_Course(coordinates);
	}

}

bool Airplane::takeOff()
{
	//heading,speed,altitude
	Set_Altitude(altitude);
	Set_Heading(heading);
	Set_Speed(speed);
}

bool Airplane::Set_Speed(int Speed)
{
	speed = Speed;
	if (speed == Speed) return true;
	else return false;
}

int Airplane::Get_Speed()
{
	return speed;
}

bool Airplane::Set_Altitude(int Altitutde)
{
	altitude = Altitutde;
	if (altitude == Altitutde) return true;
	else return false;
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