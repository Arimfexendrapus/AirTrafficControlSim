#include <string> 
#include <vector>

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
#endif

void airplane_report::PrintProgressStrip()
{
    string Travel;
    string Destination;
    //string Color;

    for (int i = 0; i > Airplanes.size(); i++)
    {

        int Altitude = Airplanes[i].get_altitude();
        if (Airplanes[i].get_intention() == true) {
            //Color = light blue;
            if (altitude == 0) { //0 in relation to airport 
                Travel = Airplanes[i].Get_Runway();
            }
            else {
                Travel = Airplanes[i].Get_Heading();
            }
            Destination = Airplanes[i].Get_NavAid();

        }
        else {
            //Color = "pale yellow";
            Travel = Airplanes[i].Get_Heading();
            Destination = "Arrival";

            print(Airplanes[i].Get_FlightID());
            print(Travel);
            print(Altitude);
            print(Airplanes[i].Get_Airplane_Type());
            print(Destination);
        }
    }
}

void airplane_report::PrintDisplayStrip()
{
    for (int i = 0; i < sizeof(Airplanes); i++) {

        Print(Airplanes[i].Get_FlightID());
        Print(Airplanes[i].Get_Altitude());
        Print(Airplanes[i].Get_Speed());
    }
}

