#include <iostream>
#include "roster.h"

using namespace std;



int main() 
{
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 012483817" << endl;
    cout << "Name: Raymond Mak" << endl; 
    cout << endl;
    cout << endl;

    Roster classRoster;

    classRoster.parseStudentData();

    cout << "All student data:" << endl;
    classRoster.printAll();
    cout << endl;
    cout << endl;

    cout << "Invalid email addresses:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    cout << endl;

    cout << "Average days in course: " << endl;
    for (int i = 0; i < 5; i++) {
        string studentID = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << endl;
    cout << endl;

    classRoster.printDegreeByProgram(SOFTWARE);
    cout << endl;
    cout << endl;

    classRoster.remove("A3");
    cout << endl;
    cout << endl;

    classRoster.printAll();
    cout << endl;
    cout << endl;

    classRoster.remove("A3");
    cout << endl;
    cout << endl;


    //classRoster.classRosterArray[1]->print();

    /*cout << "Removing student A5" << endl;
    classRoster.remove("A5");

    cout << "Adding test student" << endl;
    classRoster.add("A5", "test", "student", "test@gmail.com", 31, 20, 15, 16, NETWORK);*/

    //classRoster.printAll();

    //classRoster.printAverageDaysInCourse("A1");

    //classRoster.printInvalidEmails();

    

    return 0;
}
