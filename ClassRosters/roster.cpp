//
//  roster.cpp
//  StudentRoster
//
//  Created by Andrew Castelli on 11/27/20.
//
#include <iostream>
#include "roster.hpp"
using namespace std;

Roster::Roster() {
    this->lastIndex = -1;
    this->rosterSize = 0;
    this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
    this->lastIndex = -1;
    this->rosterSize = rosterSize;
    this->classRosterArray = new Student*[rosterSize];
}

Roster::~Roster() {
    for (int i = 0; i < rosterSize; i++) {
        delete this->classRosterArray;
    }
}

void Roster::parseRoster(string row) {
    
    // Initialize new Student
    if (lastIndex < rosterSize) {
        lastIndex++;
    }
    this->classRosterArray[lastIndex] = new Student();
    // Parse ID
    int courses[3];
    int long comma = row.find(",");
    classRosterArray[lastIndex]->setstudentID(row.substr(0, comma));
    // Parse Last Name
    int long comma2 = comma + 1;
    comma = row.find(",", comma2);
    classRosterArray[lastIndex]->setlastName(row.substr(comma2, comma - comma2));
    // Parse First Name
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    classRosterArray[lastIndex]->setfirstName(row.substr(comma2, comma - comma2));
    // Parse Email Address
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    classRosterArray[lastIndex]->setemailAddress(row.substr(comma2, comma - comma2));
    // Parse Student Age
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    int age = stoi(row.substr(comma2, comma - comma2));
    classRosterArray[lastIndex]->setstudentAge(age);
    // Parse Days in Course 1
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    courses[0] = stoi(row.substr(comma2, comma - comma2));
    // Parse Days in Course 2
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    courses[1] = stoi(row.substr(comma2, comma - comma2));
    // Parse Days in Course 3
    comma2 = comma + 1;
    comma = row.find(",", comma2);
    courses[2] = stoi(row.substr(comma2, comma - comma2));
    // Populate Course Array
    classRosterArray[lastIndex]->setdaystoCompletion(courses);
    
    //Set Degree Program
    comma2 = comma +1;
    if (row[comma2] == 'S') {
        if (row[comma2 + 1] == 'E') {
            classRosterArray[lastIndex]->setdegreeProgram(SECURITY);
        } else {
            classRosterArray[lastIndex]->setdegreeProgram(SOFTWARE);
        }
    } else {
        classRosterArray[lastIndex]->setdegreeProgram(NETWORK);
    }
}

void Roster::add(string studentID, string lastName, string firstName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degreeprogram) {
    
    int courses[3];
    courses[0] = daysInCourse1;
    courses[1] = daysInCourse2;
    courses[2] = daysInCourse3;
    
    classRosterArray[lastIndex] = new Student(studentID, lastName, firstName, emailAddress, studentAge, courses, degreeprogram);
}

void Roster::remove(string studentID) {
    // If studentID matches input parameter studentID, remove Student from Roster
    bool gotcha = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getstudentID() == studentID) {
            gotcha = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            cout << "Student ID: " << studentID << " was removed." << endl;
            }
        }
    if (!gotcha) {
        cout << "Student ID: " << studentID << " does not exist." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < rosterSize; i++) {
        classRosterArray[i]->printstudentData();
    }
    cout << endl;
}

static bool isemailValid(const string& sub) {
    auto a = find(sub.begin(), sub.end(), '@');
    auto b = find(a, sub.end(), '.');
    auto c = (sub.find(" ") == string::npos);
    return (c && a != sub.end() && b != sub.end());
}

void Roster::printInvalidEmails() {
    
    for (int i = 0; i < rosterSize; i++) {
        string emailtoCheck = classRosterArray[i]->getemailAddress();
        if (!isemailValid(emailtoCheck) ) {
            cout << "Invalid Email: " << "\t" << emailtoCheck << endl;
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i]->getstudentID() == studentID) {
            int *days = classRosterArray[i]->getdaystoCompletion();
            int daysAvg = 0;
            for (int j = 0; j < 3; j++) {
                daysAvg += days[j];
            }
        cout << "Student: " << studentID << " has an average of " << (daysAvg / 3);
        cout << " days left in each class." << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(degreeProgram degreeprogram) {
    int count = 1;
    int i = 0;
    for (; i < rosterSize; i++) {
        if (classRosterArray[i]->getdegreeProgram() == degreeprogram) {
            cout << count << ". \t";
            classRosterArray[i]->printstudentData();
            count++;
        }
    }
    cout << endl;
}
