#include <iostream>
#include "roster.h"

using namespace std;



int main() 
{
    Roster classRoster;

    classRoster.parseStudentData();

    //classRoster.classRosterArray[1]->print();

    cout << "Removing student A5" << endl;
    classRoster.remove("A5");

    cout << "Adding test student" << endl;
    classRoster.add("A5", "test", "student", "test@gmail.com", 31, 20, 15, 16, NETWORK);

    return 0;
}
