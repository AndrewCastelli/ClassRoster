//
//  student.cpp
//  StudentRoster
//
//  Created by Andrew Castelli on 11/27/20.
//
#include "student.hpp"
#include <string>
#include <iostream>

using namespace std;

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    this->daystoCompletion = new int[3];
    for (int i = 0; i < 3; i++) this->daystoCompletion[i] = 0;
    this->degree = degreeProgram::SOFTWARE;
}

Student::Student(string studentID, string lastName, string firstName, string emailAddress, int studentAge, int daystoCompletion[], degreeProgram degree) {
    
    this->studentID = studentID;
    this->lastName = lastName;
    this->firstName = firstName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    this->daystoCompletion = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daystoCompletion[i] = daystoCompletion[i];
    }
    this->degree = degree;
    
}

//Student Methods Implementation

// Destructor
Student::~Student() {
}

// Accessors
string Student::getstudentID() {
    return studentID;
}
string Student::getlastName() {
    return lastName;
}
string Student::getfirstName() {
    return firstName;
}
string Student::getemailAddress() {
    return emailAddress;
}
int Student::getstudentAge() {
    return studentAge;
}
int* Student::getdaystoCompletion() {
    return daystoCompletion;
}
degreeProgram Student::getdegreeProgram() {
    return degree;
}

// Mutators
void Student::setstudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setlastName(string lastName) {
    this->lastName = lastName;
}
void Student::setfirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setemailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setstudentAge(int studentAge) {
    this->studentAge = studentAge;
}
void Student::setdaystoCompletion(int daystoCompletion[]) {
    for (int i = 0; i < 3; i++) {
        this->daystoCompletion[i] = daystoCompletion[i];
    }
}
void Student::setdegreeProgram(degreeProgram degree) {
    this->degree = degree;
}
void Student::printstudentData() {
    int *days = getdaystoCompletion();
    cout << "Student ID: " << getstudentID() << "\t";
    cout << "Student Name: " << getfirstName() << " " << getlastName() << "\t";
    cout << "Student Email: " << getemailAddress() << "\t";
    cout << "Student Age: " << getstudentAge() << "\t\t\t";
    cout << "Days left in Classes: " << days[0] << ", " << days[1] << ", " << days[2] << "\t";
    cout << "Degree Program: " << programStrings[getdegreeProgram()] << endl;
    
}
