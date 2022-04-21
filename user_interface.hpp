#include <iostream>
#include <string>
#include "user_interface.hpp"

using namespace std;

User_Interface::User_Interface(Airspace *as, Airplane_Report *apr)
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
            this->Parse_Input(input);                            // send the command to be parsed
            cout << returnMessage << endl;                       // print the message to the user
            cout << Report_Object->PrintProgressStrip() << endl; // print the progress and display strips
            cout << Report_Object->PrintDisplayStrip() << endl;
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
        returnMessage = "Invalid Command: Not enough information supplied";
        return;
    }
    while (multi) // put main logic in loop to continue if multiple commands are strung together
    {
        parameter = "";
        command = input[index]; // the next character should be a command
        index += 2;             // increment index
        size -= 2;              // decrement size taking into account trailing space
        if (command == 'c')     // if clearance
        {
            if (debugging)
            {
                returnMessage += planeID + " issued clearance";
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
                // need to check and see if there is a direction specified
                // if there is more input make sure you are only taking if its a r or l character
                if (size >= 1 && (input[index] == 'r' || input[index] == 'l')) // could be another command strung to the end
                {
                    turning = input[index];
                    index++;
                    size -= 1;
                }
                index++;
                size -= 1;
                returnMessage += Airspace_Object->Clear_Aircraft(planeID, stoi(parameter), turning) + "\n";
            }
            else if (isdigit(parameter[0])) // if it isnt a heading but still a number treat it as altitude
            {
                returnMessage += Airspace_Object->Clear_Aircraft(planeID, stoi(parameter)) + "\n";
            }
            else // else treat it as a navpoint
            {
                // need to check and see if there is a direction specified
                // if there is more input make sure you are only taking if its a r or l character
                if (size >= 1 && (input[index] == 'r' || input[index] == 'l')) // could be another command strung to the end
                {
                    turning = input[index];
                    index++;
                    size -= 1;
                }
                index++;
                size -= 1;
                returnMessage += Airspace_Object->Clear_Aircraft(planeID, parameter, turning) + "\n";
            }
        }
        else if (command == 'h')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued hold";
            }
        }
        else if (command == 't')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued takeoff";
            }
        }
        else if (command == 's')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued speed";
            }
        }
        else if (command == 'w')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued wait";
            }
        }
        else if (command == 'a')
        {
            if (debugging)
            {
                returnMessage += planeID + "issued abort";
            }
        }
        else
        {
            // returnMessage += "Invalid Command";
            return;
        }
        // multi = false;
    }
}