#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
private: 
	
public:
	Student* classRosterArray[5];
	Roster();
	~Roster();
	void parseStudentData();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
};

#endif 

