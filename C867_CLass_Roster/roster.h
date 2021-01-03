/*
    Author: Kenneth Lamb

    Created: 12/6/2020
*/
#pragma once

#ifndef ROSTER_H
#define ROSTER_H
//Include Headers
#include "student.h"//Allows the use of Student methods

using namespace std;

//Create Class Roster
class Roster
{
    //Set public methods and variables
public:

	Roster();//Constructor

    Student* classRosterArray[5]; //Array of Student pointers called classRosterArray
    
    //-------------------------Functions from Roster Class------------------------------
    void add(string studentID, string firstName, string lastName, string emailAddress, 
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);//Add Function

    void remove(string studentID);//Remove Function

    void printAll();//PrintAll Function

    void printAverageDaysInCourse(string StudentID);//Print Average days In Course

    void printInvalidEmails();//Print Invalid Emails

    void printByDegreeProgram(DegreeProgram degreeProgram);//Print By Degree Program

    ~Roster();//Deconstructor

};

#endif // !ROSTER_H

