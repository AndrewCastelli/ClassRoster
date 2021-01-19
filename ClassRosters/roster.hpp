//
//  roster.hpp
//  StudentRoster
//
//  Created by Andrew Castelli on 11/27/20.
//
#pragma once
#ifndef roster_hpp
#define roster_hpp
#include "student.hpp"
#include <iostream>
#include <string>

class Roster {
public:
    // Params
    int lastIndex;
    int rosterSize;
    Student **classRosterArray;
    
    // ConstructorDestructor
    Roster(int rosterSize);
    Roster();
    ~Roster();
    
    // Methods
    void parseRoster(string row);
    void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degreeprogram);
    
    void remove(string studentID); // Remove Student from Roster by ID // Throw Error if ID doesn't exist.
    
    void printAll(); // Print complete tab-separated list of student data to console (for each student).
    
    void printAverageDaysInCourse(string studentID); // Prints a Student's avg # days in each course.
    
    void printInvalidEmails(); // Verifies student email address & displays all invalid email addresses.
    
    void printByDegreeProgram(degreeProgram degreeprogram); // Print student information for degree specified
    
};

#endif /* roster_hpp */
