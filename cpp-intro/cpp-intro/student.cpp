#include "student.h"
#include <iostream>
using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->degreeProgram = degreeProgram;

	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}


string Student::getStudentID() const {
	return studentID;
}
string Student::getFirstName() const {
	return firstName;
}
string Student::getLastName() const {
	return lastName;
}
string Student::getEmailAddress() const {
	return emailAddress;
}
int Student::getAge() const {
	return age;
}
int Student::getDaysToComplete(int index) const {
	return daysToComplete[index];
}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram;
}


void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToComplete(const int daysToComplete[]) {
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


string degreeProgramToString(DegreeProgram degreeProgram) {
	switch (degreeProgram) {
	case SECURITY: 
		return "SECURITY";
	case NETWORK:
		return "NETWORK";
	case SOFTWARE:
		return "SOFTWARE";
	}
}

void Student::print() const {
	cout << "ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email: " << emailAddress << endl;
	cout << "Age: " << age << endl;
	cout << "Days to Complete: " << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << endl;
	cout << "Degree Program: " << degreeProgramToString(degreeProgram) << endl;
}