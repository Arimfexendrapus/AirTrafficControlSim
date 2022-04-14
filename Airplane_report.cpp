#include Airplane.h
#include string
#include vector

using namespace std;

public class Airplane_Report{

		void PrintProgressStrip(){

			string Travel; 
			string Destination;
			string Color;

			For i in 1 to Number of Airplanes{

				int Altitude = Airplane[i]->Get_Altitude();
				if(Airplane[i]->Get_Intention() == Departing){
					Color = light blue;
					if (altitude == 83)
					{	Travel = Airplane[i]->Get_Runway();}
					Else 
					{	Travel = Airplane[i]->Get_Heading();}
					Destination = Airplane[i]->Get_NavAid();
					
				}
				else {
					Color = "pale yellow";
					Travel = Airplane[i]->Get_Heading(); 
					Destination = "Arrival";
					
				print(Airplane[i]->Get_FlightID());
				print(Travel);
				print(Altitude);
				print(Airplane[i]->Get_Airplane_Type());
				print(Destination);
				}
			}

		}

		void PrintDisplayStrip(){
			For i in 1 to Number of Airplanes{
			
				Print(Airplane[i]->Get_FlightID());
				Print(Airplane[i]->Get_Altitude());
				Print(Airplane[i]->Get_Speed());

			}

		}








}
