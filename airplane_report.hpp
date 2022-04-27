#include <string> 
#include <vector>
#include <iostream>

#include "airplane.hpp"

using namespace std;

#ifndef AIRPLANE_REPORT
#define AIRPLANE_REPORT

class airplane_report {
private:
    vector<airplane> Airplanes;

public:
    void PrintProgressStrip();
    void PrintDisplayStrip();
};


void airplane_report::PrintProgressStrip()
{
    string Travel;
    vector<int> Destination;
    //string Color;

    for (int i = 0; i < Airplanes.size(); i++)
    {

        double Altitude = Airplanes[i].get_altitude();
        if (Airplanes[i].get_intention() == true) {
            //Color = light blue;
            if (Altitude == 0) { //0 in relation to airport 
                Travel = Airplanes[i].get_runway()->runwayID;
            }
            else {
                Travel = Airplanes[i].get_heading();
            }
            Destination = Airplanes[i].get_coordinates();

        }
        else {
            //Color = "pale yellow";
            Travel = Airplanes[i].get_heading();
            //Destination = "Arrival";
        }
            cout << Airplanes[i].get_flightID() << endl;
            cout << Travel << endl;
            cout << Altitude << endl;
            cout << Airplanes[i].Aircraft.aircraft_name << endl;
            for (int i = 0; i < Destination.size(); i++)
            {
                cout << Destination[i] << endl;
            }

        
    }
}

void airplane_report::PrintDisplayStrip()
{
    for (int i = 0; i < Airplanes.size(); i++) 
    {
        cout << Airplanes[i].get_flightID() << endl;
        cout << Airplanes[i].get_altitude() << endl;
        cout << Airplanes[i].get_speed() << endl;
    }
}

#endif