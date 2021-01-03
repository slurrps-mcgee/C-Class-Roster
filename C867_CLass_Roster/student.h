/*
    Author: Kenneth Lamb

    Created: 12/6/2020
*/
#pragma once

#ifndef STUDENT_H
#define STUDENT_H
//Include Header
#include "degree.h"//Allows the use of Enum
#include <string>
using namespace std;

//Create Student Class
class Student 
{
    //Set public methods and variables
public:

    Student();//Constructor
    
    Student(
        string studentID,
        string fName, 
        string lName, 
        string emailAddr, 
        int age,
        int daysInCourse1, 
        int daysInCourse2, 
        int daysInCourse3, 
        DegreeProgram degree);//Overloaded constructor

    //-----------------------------Functions Student Class---------------------------------
    void print();//print Student
    
    //Accessors Functions
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumDays();
    DegreeProgram getDegreeProgram();

    //Mutators Functions
    void setStudentID(string ID);
    void setFirstName(string fname);
    void setLastName(string lname);
    void setEmail(string emailAddr);
    void setAge(int studentAge);
    void setNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degree);

    ~Student();//Deconstructor 

    //Set Private variables
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
    DegreeProgram degree;
};

#endif /* STUDENT_H */
