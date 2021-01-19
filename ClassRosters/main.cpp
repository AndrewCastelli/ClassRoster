//
//  main.cpp
//  StudentRoster
//
//  Created by Andrew Castelli on 11/27/20.
//
#include <iostream>
#include "roster.hpp"
using namespace std;

int main() {
    
	const string studentData[] =
    // Added myself to studentData list
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Andrew,Castelli,acas347@wgu.edu,29,50,40,58,SOFTWARE"
    };
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ C867 Scripting and Programming - C++\t" << "#001488272 \t" << "Andrew Castelli ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    
    // Initialize new Roster
    int rosterSize = 5;
	Roster* classRoster = new Roster(rosterSize);
    
    // Loop through Student Data to Parse
    for (int i = 0; i < rosterSize; i++) {
        classRoster->parseRoster(studentData[i]);
    };
    
    // Print All Student Data in Roster & Print Invalid Emails
    classRoster->printAll();
    classRoster->printInvalidEmails();
    
    // Loop through each classRosterArray element
    for (int i = 0; i < rosterSize; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getstudentID());
    };

    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");
    classRoster->remove("A3");
    
    return 0;
};
