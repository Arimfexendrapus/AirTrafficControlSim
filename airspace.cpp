// Airspace Class Pseudo Code

#include "airspace.h"

airspace::airspace(vector<aircraft*> apVector, airport* aPort){
        Aircraft = apVector;
        Airport_Object = aPort;
        ReturnMessage = "";
        NavAids = GENERATE ALL NAVAIDS STRUCTURES AND PUSH INTO THIS VARIABLE;
    }

void airspace::generate_airplane(){
    string airlineID;
    string randID;
    string FID = "";
    while FID in FlightIDs{ // generate aircraft ID and make sure its not in the vector already
        airlineID = random chosen airline id;
        randID = randomly generated 3 digit number;
        FID = airlineID + randID;
    }

    FlightIDs.push_back(FID); // add the id to the vector
    aircraft* NewAirplane = new Airplane(FID); // generate a new airplane pointer
    Aircraft->push_back(NewAirplane); // push that aircraft into vector


}

string airspace::clear_aircraft(string FlightID, string NavPoint, char Directrion){ // clearing to a navpoint
    int idx1 = -1;
    int idx2 = -1;
    int coords[2];

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx1 = x;
        }
    }
    if idx1 == -1{
        return invalid flight id
    }

    for x in NavAids.size{
        if NavPoint == NavAids[x].ID{
            idx2 = x;
        }
    }
    if idx2 == -1{
        return invalid navaid
    }

    coords[1] = NavAids[idx2].Coordinates[1];
    coords[2] = NavAids[idx2].Coordinates[2];

    if Direction == 'n'{// no turning direction specified
        ReturnMessage = Aircraft[idx1]->Set_Course(coords);
    }
    else{
        ReturnMessage = Aircraft[idx1]->Ser_Course(coords,Direction);
    }
    Aircraft[idx].Set_Cleared(true);
    return ReturnMessage;
}
string airspace::clear_aircraft(string FlightID, int heading, char Directrion){// clearing to a heading
    int idx = -1;
    bool ret;

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx = x;
        }
    }
    if idx == -1{
        return invalid flight id
    }

    if heading >= 0 <= 360{
        if direction == 'n'{
            ret = Aircraft[idx]->Set_Heading(heading);        
        }
        else{
            ret = Aircraft[idx]->Set_Heading(heading,Direction);
        }
    }
    else{
        return invalid heading value
    }
    if(!ret){
        return setting heading error message
    }
    Aircraft[idx].Set_Cleared(true);
    return success message
}

string airspace::clear_aircraft(string FlightID, int altitude){
    int idx = -1;
    bool ret; 

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx = x;
        }
    }
    if idx == -1{
        return invalid flight id
    }
    altitude = altitude * 1000;
    if 0 < altitude <= 40,000{
        ret = Aircraft[idx]->Set_Altitude(altitude);
    }
    else{
        return invalid altitude message
    }

    if !ret {
        return invalid set altitude message
    }
    Aircraft[idx].Set_Cleared(true);
    return success message

}

string airspace::land_aircraft(string FlightID, string runway){
    nav_aid runwayInfo;
    int idx = -1;
    bool ret;
    int coords[2];

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx = x;
        }
    }
    if idx == -1{
        return invalid flight id
    }

    coords = Aircraft[idx]->Get_Coordinates(); // get current aircraft coordinates to send to the 

    if Aircraft[idx]->Get_Intention() == true{ // true means departing
        return departing aircraft cannot land error message;
    }
    runwayInfo = Airport_Object->Get_Runway(runway); // get the runway information
    Aircraft[idx]->Set_Runway(runwayInfo.ID);
    // check and make sure that the parameters are met for an aircraft to land
    if Aircraft[idx]->Get_Altitude() > 3,000 and !Airport_Object->Degree_Clearance(coords,runwayInfo.ID){
        return plane does not meet landing criteria error
    }
    else{
        ret = Aircraft[idx]->Land();
    }

    if !ret{
        retrun error landing message
    }

    return success message

}

string airspace::takeoff_aircraft(string FlightID){
    int idx = -1;
    bool ret;
    int coords[2];
    string runway;

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx = x;
        }
    }
    if idx == -1{
        return invalid flight id
    }

    // aircraft needs to be cleared before it can takeoff
    if !Aircraft[idx]->Get_Clearance(){ // if it isnt cleared
        return not cleared error message
    } 
        
    // if it is cleared then tell it to takeoff
    runway = Aircraft[idx]->Get_Runway();
    if Airport_Object->Runway_Availability(runway) == true{ // if the runway is available
        ret = Aircraft[idx]->Takeoff();
    }
    else{
        return runway not available for Takeoff
    }

    if ret == false{
        return error taking off message
    }  
        
    return success takeoff message
}

string airspace::hold_aircraft(string FlightID, string NavPoint)
{
    int idx1 = -1;
    int idx2 = -1;
    bool ret;

    for x in Aircraft.size{
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx1 = x;
        }
    }
    if idx1 == -1{
        return invalid flight id
    }
    for x in NavAids.size{
        if NavPoint == NavAids[x].ID{
            idx2 = x;
        }
    }
    if idx2 == -1{
        return invalid navaid
    }

    coords[1] = NavAids[idx2].Coordinates[1];
    coords[2] = NavAids[idx2].Coordinates[2];

    ret = Aircraft[idx1]->Set_Course(coords);

    if ret == false{
        return error message
    }    

    return success message
}

    
    


bool airspace::set_aircraft_speed(string FlightID, int Speed){
    //Take the flightID and have the user enter the speed they want assigned to the aircraft. Once we have the speed then we can assign that speed to the flightID (General Idea will flesh out shortly)
    //not less than 150 and not more than 400


    // this should iterate through the list of aircrafts we have and get the right one
    for x in Aircraft.size{ 
        if FlightID == Aircraft[x]->Get_FlightID(){
            idx = x;
        }

    }
        
    If(Speed >= 150 && Speed <= 400)
    {

        FlightIDSpeed = Speed;

        Return Success Message

    }
    Else
    {

        Return error message

    }


}

bool airspace::wait_aircraft(string FlightID) // takes the aircraft object which corresponds to the ID and just tells it to wait on the runway
{

//Take the FlightID and give it the command to wait on the runway given that it is on a runway

for x in Aircraft.size{ // this should iterate through the list of aircrafts we have and get the right one
            if FlightID == Aircraft[x]->Get_FlightID(){
                idx = x;
            }


if(FlightID is on a runway)
{

Give FlightID the wait command;
Return success message;

}
Else
{

Return error message;// FlightID cannot wait, it's not on a runway
}
}


}


bool airspace::abort_aircraft(string FlightID)
{

//We are going to take the FlightID and give it the command to abort, either the FlightID will abort takeoff or abort landing

for x in Aircraft.size{ // this should iterate through the list of aircrafts we have and get the right one
            if FlightID == Aircraft[x]->Get_FlightID(){
                idx = x;
            }

if(FlightID is about to takeoff)
{

Tell FlightID to abort takeoff;
Set Speed to zero, move FlightID back to start of runway;
Return success message;

}
elseif(FlightID is about to land)
{

Tell FlightID to abort landing;
Set altitude to default  altitude;
Return success message;

}
Else
{

Return error message; //There is nothing to abort
}

}

};