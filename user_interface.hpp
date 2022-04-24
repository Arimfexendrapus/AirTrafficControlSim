/*
    Last Editor: Conor Rybacki
    Last Edit Date: 04.19.2022
    File Name: User_Interface.h

    Details:
    User interface class is meant to handel all of the input and output
    to and from the user. It will take input, parse it, then pass the
    necessary information to the necessary place. It handels all of the
    aircraft and simulation information output to the user.
*/
#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include <iostream>
#include <algorithm>

#include "airplane_report.hpp"
#include "airspace.hpp"
#include <string>
using namespace std;

class User_Interface
{
private:
    airspace *Airspace_Object;      // hold the pointer to the airspace object passed in the constructor
    airplane_report *Report_Object; // hold the pointer to the airplane report object
    bool run;                       // flag that tells the main control loop to keep running
    bool debugging;                 // debugging flag
    string returnMessage;           // variable that holds the message to be returned to the user
public:
    User_Interface(airspace *as, airplane_report *apr);
    // Constructor to handle the assignment of the airspace and airplane report
    // pointers to local instances to be utilized by the programming. Also manages
    // loop that will run while the program is running to continue accepting input from the user.
    // Preconditions: pass in 2 pointers; one to an Airspace object
    // and another on to an Airplane_Report object
    // Postconditions: Airspace_Object and Report_Object now point
    // to their corresponding instance in main
    void Parse_Input(string input);
    // This methods main purpose is to take the users input and break it up
    // into the necessary information needed by the simulation to alter the
    // state of the various entities
    // Precondition: user input must be passed into the function
    // Postcondition: any message returned from called methods or any message
    // specifically generate by this method itself
};
#endif

User_Interface::User_Interface(airspace *as, airplane_report *apr)
{
    debugging = true;
    returnMessage = "";
    run = true;
    Airspace_Object = as;
    Report_Object = apr;
    string input; // variable used to hold the users input
    while (run)   // while the user hasn't typed exit
    {
        cout << "Enter Command: " << endl;
        getline(cin, input);                                             // get the input string from the user
        transform(input.begin(), input.end(), input.begin(), ::tolower); // make the whole string lowercase

        if (input == "exit") // if the user supplies the exit command
        {
            run = false;
            cout << "Exiting..." << endl;
        }
        else
        {
            this->Parse_Input(input);            // send the command to be parsed
            cout << returnMessage << endl;       // print the message to the user
            Report_Object->PrintProgressStrip(); // print the progress and display strips
            Report_Object->PrintDisplayStrip();
        }
        returnMessage = "";
    }
}

void User_Interface::Parse_Input(string input)
{
    string planeID = "";
    // string to hold the planeID
    string tempHold;
    // temporary string to hold information
    char command;
    // holds the command character
    char turning = 'n';
    // this variable holds optionally supplied turning direction
    // default value 'n' specifies that there is no direction supplied to let
    // called method know
    int index = 0;                // variable used to move throughout the input string
    int heading;                  // variable used to hold the heading if supplied
    int size = (int)input.size(); // variable used to hold the size
    bool multi = true;            // will rerun the parsing logic if multiple commands strung together
    string parameter = "";
    // string used to hold the parameters for a command if applicable
    bool validParam = true; // used to validate parameter where necessary
    // get rid of preceeding spaces if necessary
    while (input[0] == ' ')
    {
        input.erase(0, 1);
    }
    // make sure there is the possibility of at least having a valid command
    // valid command will have at least a size of 8 with PlaneID + command
    if ((int)input.size() < 8)
    {
        returnMessage = "Invalid Command: Not enough information supplied";
        return;
    }
    // also need to check and see if 6 digit planeid is even valid

    // if a valid
    // get the flight ID
    while (index < 6)
    {
        if (input[index] == ' ') // make sure flight id is valid
        {
            returnMessage = "Invalid Command: Please enter valid Flight ID";
        }
        planeID += input[index];
        index++;
    }
    index++;   // account for space after flight id
    size -= 7; // get the new size of the string
    // check and make sure there is more elements in string to avoid
    // buffer overrun
    if (size < 1)
    {
        returnMessage = "Invalid Command: Not enough information supplied\n";
        return;
    }

    command = input[index]; // the next character should be a command
    index += 2;             // increment index
    size -= 2;              // decrement size taking into account trailing space
    while (multi)           // put main logic in loop to continue if multiple commands are strung together
    {
        validParam = true;
        parameter = "";
        turning = 'n';
        /*
        C - Cleared
        Parameters:
            Nav Point: navigation point identifier
            Heading: 3 digits representing degrees
            Altitude: up to 2 digits representing multiples of 1,000 units
        */
        if (command == 'c')
        {
            if (debugging)
            {
                returnMessage += planeID + " issued clearance\n";
            }
            // make sure there are parameters supplied
            if (size < 1)
            { // if there is no parameter then throw error
                returnMessage = "Invalid Command: Parameters required for clearance command";
                return;
            }

            // retrieve parameter for clearance from input string
            while (input[index] != ' ' && size > 0) // get all the characters up to the next space
            {
                parameter += input[index]; // add the chars to the parameter string
                index++;
                size -= 1;
            }
            // account for possible space
            index++;
            size -= 1;

            if (isdigit(parameter[0]) && (int)parameter.size() == 3) // if it is a heading
            {
                // validate 3 digit number is supplied
                for (int x = 0; x < (int)parameter.size(); x++)
                {
                    if (isdigit(parameter[x]) == false)
                    {
                        validParam = false;
                    }
                }
                if (validParam) // if the parameter is an integer
                {
                    // need to check and see if there is a direction specified
                    // if there is more input make sure you are only taking if its a r or l character
                    if (size >= 1 && (input[index] == 'r' || input[index] == 'l')) // could be another command strung to the end
                    {
                        turning = input[index];
                        index += 2;
                        size -= 2;
                    }
                    // index++;
                    // size -= 1;
                    returnMessage += Airspace_Object->clear_aircraft(planeID, stoi(parameter), turning) + "\n";
                }
                else
                {
                    returnMessage += "\nInvalid Command: Heading parameter must be 3 integer digits\n";
                }
            }
            else if (isdigit(parameter[0])) // if it isnt a heading but still a number treat it as altitude
            {
                for (int x = 0; x < (int)parameter.size(); x++)
                {
                    if (isdigit(parameter[x]) == false)
                    {
                        validParam = false;
                    }
                }
                if (validParam)
                {
                    returnMessage += Airspace_Object->clear_aircraft(planeID, stoi(parameter)) + "\n";
                }
                else
                {
                    returnMessage += "\nInvalid Command: Altitude parameter must consist of all integers\n";
                }
            }
            else // else treat it as a navpoint
            {
                // need to check and see if there is a direction specified
                // if there is more input make sure you are only taking if its a r or l character
                if (size >= 1 && (input[index] == 'r' || input[index] == 'l')) // could be another command strung to the end
                {
                    turning = input[index];
                    index += 2;
                    size -= 2;
                }
                returnMessage += Airspace_Object->clear_aircraft(planeID, parameter, turning) + "\n";
            }
        }
        /*
        L - Landing
        Parameters:
            Runway: runway identifier
        */
        else if (command == 'l')
        {
            if (debugging)
            {
                returnMessage += "\n" + planeID + "issued hold";
            }
            // make sure there are parameters supplied
            if (size < 1)
            { // if there is no parameter then throw error
                returnMessage = "Invalid Command: Parameters required for takeoff command\n";
                return;
            }
            // retrieve parameter for land from input string
            while (input[index] != ' ' && size > 0) // get all the characters up to the next space
            {
                parameter += input[index]; // add the chars to the parameter string
                index++;
                size -= 1;
            }
            // account for possible space
            index++;
            size -= 1;
            // invoke the land method
            returnMessage += Airspace_Object->land_aircraft(planeID, parameter);
        }
        /*
        H - Hold
        Parameters:
            Nav Point: navigation point identifier
        */
        else if (command == 'h')
        {
            if (debugging)
            {
                returnMessage += "\n" + planeID + "issued hold";
            }
            // make sure there are parameters supplied
            if (size < 1)
            { // if there is no parameter then throw error
                returnMessage = "Invalid Command: Parameters required for hold command\n";
                return;
            }

            // retrieve parameter for hold from input string
            while (input[index] != ' ' && size > 0) // get all the characters up to the next space
            {
                parameter += input[index]; // add the chars to the parameter string
                index++;
                size -= 1;
            }
            // account for possible space
            index++;
            size -= 1;

            // invoke the hold method of the airspace class
            returnMessage += Airspace_Object->hold_aircraft(planeID, parameter);
        }
        /*
        T - Takeoff
        Parameters: NONE
        */
        else if (command == 't')
        {
            if (debugging)
            {
                returnMessage += "\n" + planeID + "issued takeoff";
            }
            returnMessage += Airspace_Object->takeoff_aircraft(planeID);
        }
        /*
        S - Set aircraft speed
        Parameters:
            Speed: speed in set units
        */
        else if (command == 's')
        {
            if (debugging)
            {
                returnMessage += "\n" + planeID + "issued speed";
            }
            // make sure there are parameters supplied
            if (size < 1)
            { // if there is no parameter then throw error
                returnMessage = "Invalid Command: Parameters required for hold command";
                return;
            }

            // retrieve parameter for hold from input string
            while (input[index] != ' ' && size > 0) // get all the characters up to the next space
            {
                parameter += input[index]; // add the chars to the parameter string
                index++;
                size -= 1;
            }
            // account for possible space
            index++;
            size -= 1;
            // need to varify that an integer was supplied
            for (int x = 0; x < (int)parameter.size(); x++)
            {
                if (isdigit(parameter[x]) == false)
                {
                    validParam = false;
                }
            }
            if (validParam) // if the parameter is an integer
            {
                returnMessage += Airspace_Object->set_aircraft_speed(planeID, stoi(parameter));
            }
            else
            {
                returnMessage += "\nInvalid Command: Speed parameter must be an integer";
            }
        }
        /*
        W - Line up and wait
        Parameters: NONE
        */
        else if (command == 'w')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued wait";
            }
            returnMessage += Airspace_Object->wait_aircraft(planeID);
        }
        /*
        A - Abort current action
        Parameters: NONE
        */
        else if (command == 'a')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued abort";
            }
            returnMessage += Airspace_Object->abort_aircraft(planeID);
        }
        // if there isn't a valid command supplied
        else
        {
            returnMessage += "\nInvalid Command: ";
            returnMessage.push_back(command);
            return;
        }

        // basicall just loop again in there is still stuff in the input string
        if (size < 1)
        {
            multi = false;
        }
        else
        {
            command = input[index];
            index += 2;
            size -= 2;
            multi = true;
        }
    }
}