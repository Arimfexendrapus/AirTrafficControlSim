#ifndef USER_INTERFACE
#define USER_INTERFACE

#include <string>
#include "airspace.h"
#include "Airplane_report.h"

class user_interface {
private:
    airspace* Airspace_Object;
    airplane_report* Report_Object;//
public:
    user_interface(airspace* as, airplane_report* apr);

    string Parse_Input(string input);
};
#endif

user_interface::user_interface(airspace* as, airplane_report* apr) {
    Airspace_Oject = as; // store pointer to the airspace object
    Report_Object = apr; // point to the airplane report object 
    string input; // to hold the user input
    string message; // message to be returned to the user
    while program is running{
            get input from user;
            message = Parse_Input(input);
            if there is a message{
                print message;
            }
            Report_Object.PrintProgressStrip();
            Report_Object.PrintDisplayStrip();
    }
}

string user_interface::Parse_Input(string input) {
    string planeID;
    string message = '';
    char command;
    char turning = 'n'; // N specifies there is no real turning direction
    int index;
    string navpoint = '';
    int headDir;
    string parameter;
    int len;
    get planeID;
    increment index to the next space past id;
    while input has characters{ // loop because the user can string multiple commands
        get command character;
        increment index;
        if command == clear{
            if no parameters supplied{
                return error string;
            }
            else {
                get parameter from input;
                increment index;
                if parameter == navpoint{
                    navpoint = parameter;
                    if valid turning direction supplied{
                        get turning from input;
                        increment index;
                    }
                    message = Airspace_Object->Clear_Aircraft(planeID,navpoint,turning);
                }
                else { // if the parameter is a heading or altitude
                    make sure parameter is valid; // must be numbers between 1 and 3 length
                    if parameter invalid{
                        return error message;
                    }
                    else {
                        if parameter is heading{
                            if turning direction supplied{
                                get turning direction from input;
                                increment index;
                            }
                            message = Airspace_Object->Clear_Aircraft(planeID, navpoint, turning);
                        }
                        else if parameter is altitude{
                            message = Airspace_Object->Clear_Aircraft(planeID, navpoint);
                        }
                        else {
                            return error message;
                        }
                    }
                }
            }
        }
        else if command == hold{
            get parameter from input string;
            increment index;
            message = Airspace_Object->Hold_Aircraft(planeID,parameter); // pass the plane ID 
        }
        else if command == takeoff{
            message = Airspace_Object->Takeoff_Aircraft(planeID);
        }
        else if command == land{
            get parameter from input string;
            increment index;
            message = Airspace_Object->Land_Aircraft(planeID,parameter);
        }
        else if command == set speed{
            get parameter from input string;
            increment index;
            speed = (int)parameter;
            message = Airspace_Object->Set_Aircraft_Speed(planeID,speed);
        }
        else if command == wait{
            message = Airspace_Object->Wait_Aircraft(planeID);
        }
        else if command == abort{
            message = Airspace_Object->Abort_Aircraft(planeID);
        }
        else {
            message = invald command message;
        }
    } // end of while loop
    return message;
}
