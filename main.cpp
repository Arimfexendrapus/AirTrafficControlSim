#include <iostream>
#include <string>
#include "airspace.h"
#include "airplane_Report.h"
#include "User_Interface.h"

using namespace std;

int main()
{

    Airplane_Report *ReportObject = NULL;
    Airspace *AirspaceObject = NULL;
    ReportObject = new Airplane_Report();
    AirspaceObject = new Airspace();

    User_Interface InterfaceObject(AirspaceObject, ReportObject);

    return 0;
}
