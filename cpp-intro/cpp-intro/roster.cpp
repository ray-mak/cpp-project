#include "roster.h"
#include <iostream>
#include <sstream>

using namespace std;

Roster::Roster() {
	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = nullptr;
	}
}

void Roster::parseStudentData() {
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Raymond,Mak,rmak2@wgu.edu,31,12,20,16,SOFTWARE"
	};

	for (int i = 0; i < 5; i++) {
		stringstream ss(studentData[i]);
		string studentID, firstName, lastName, emailAddress, degreeProgramStr;
		int age, daysToComplete1, daysToComplete2, daysToComplete3;
		DegreeProgram degreeProgram;

		getline(ss, studentID, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, emailAddress, ',');
		ss >> age;
		ss.ignore();
		ss >> daysToComplete1;
		ss.ignore();
		ss >> daysToComplete2;
		ss.ignore();
		ss >> daysToComplete3;
		ss.ignore();
		getline(ss, degreeProgramStr);

		if (degreeProgramStr == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (degreeProgramStr == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = SOFTWARE;
		}

		int daysToCompleteArray[3] = { daysToComplete1, daysToComplete2, daysToComplete3 };

		classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteArray, degreeProgram);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysToCompleteArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteArray, degreeProgram);
			cout << "Student  " << firstName << lastName  << " has been added." << endl;
			return;
		}
	}
}

void Roster::remove(string studentID) {
	bool idExists = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			idExists = true;
			cout << "Student with ID " << studentID << " has been removed." << endl;
			return;
		}
	}

	if (!idExists) {
		cout << "Student with ID " << studentID << " not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool studentExists = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			studentExists = true;

			int days1 = classRosterArray[i]->getDaysToComplete(0);
			int days2 = classRosterArray[i]->getDaysToComplete(1);
			int days3 = classRosterArray[i]->getDaysToComplete(2);
			int averageDays = (days1 + days2 + days3) / 3;

			cout << "Student ID: " << studentID << ". Average Days in Course: " << averageDays << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmailAddress();
			
			bool hasAt = false, hasDot = false, hasSpace = false;

			for (char c : email) {
				if (c == '@') {
					hasAt = true;
				}
				if (c == '.') {
					hasDot = true;
				}
				if (c == ' ') {
					hasSpace = true;
				}
			}

			if (!hasAt || !hasDot || hasSpace) {
				cout << "Invalid Email: " << email << endl;
			}
		}
	}
}


void Roster::printDegreeByProgram(DegreeProgram degreeProgram) {
	cout << "Students in the " << degreeProgramToString(degreeProgram) << " degree program:" << endl;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
}

