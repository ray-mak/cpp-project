#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram);

	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int getDaysToComplete() const;
	DegreeProgram getDegreeProgram() const;

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(const int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print() const;
};

#endif // !STUDENT_H

