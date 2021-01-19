//
//  student.hpp
//  StudentRoster
//
//  Created by Andrew Castelli on 11/27/20.
//
#pragma once
#ifndef student_hpp
#define student_hpp
#include "degree.hpp"
#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    // Params
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int studentAge;
    int *daystoCompletion;
    degreeProgram degree;
    
public:
    // Constructor
    Student(string studentID, string lastName, string firstName, string emailAddress, int studentAge, int daystoCompletion[], degreeProgram degree);
    Student();
    // Destructor
    ~Student();
    
    //accessors - getters
    string getstudentID();
    string getfirstName();
    string getlastName();
    string getemailAddress();
    int getstudentAge();
    int* getdaystoCompletion();
    degreeProgram getdegreeProgram();
    
    //mutators - setters
    void setstudentID(string studentID);
    void setfirstName(string firstName);
    void setlastName(string lastName);
    void setemailAddress(string emailAddress);
    void setstudentAge(int studentAge);
    void setdaystoCompletion(int daystoCompletion[]);
    void setdegreeProgram(degreeProgram degree);
    void printstudentData();
};

#endif /* student_hpp */
