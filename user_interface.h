#include <string>
#include "airspace.h"
#include "Airplane_report.h"

class user_interface {

private:
    airspace* Airspace_Object;
    airplane_report* Report_Object;
public:
    user_interface(airspace* as, airplane_report* apr);

    string Parse_Input(string input);
};
