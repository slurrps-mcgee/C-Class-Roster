/*
    Author: Kenneth Lamb

    Created: 12/6/2020
*/
#include <cstring> //email character checking function
#include <string>//Alows the use of string
#include <iostream>//Allows the use of Cout Cin
//Include headers
#include "roster.h"//Allows the use of Roster methods
#include "degree.h"//Allows the use of Enum
#include "student.h"//Allows the use of Student methods
using namespace std;

Roster::Roster() { } //Default Constructor

//Add Students to Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) 
{
    //Add new student to array
    Student* student = new Student;

    int index = stoi(studentID.substr(1)) - 1; //Convert string to int

    //Fill in the accessors calling the appropriate methods
    student->setStudentID(studentID);
    student->setFirstName(firstName);
    student->setLastName(lastName);
    student->setEmail(emailAddress);
    student->setAge(age);
    student->setNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
    student->setDegreeProgram(degree);
    classRosterArray[index] = student; //insert student at the index in the array
}//End Roster::add

//removes students from the roster by student ID. 
void Roster::remove(string studentID) 
{
    //For loop to go through the classRosterArray
    for (int i = 0; i < 5; ++i) 
    {
        //Check the current index
        if (classRosterArray[i]) 
        {
            //if the current index studentID == the provided studentID
            if (classRosterArray[i]->getStudentID() == studentID) 
            {
                classRosterArray[i] = 0;//Remove student
                cout << "Removing student " << studentID << endl;
            }
        }
        else 
        {
            cout << "Error this student does not exist." << endl;//Print Error
        }
        cout << endl;
    }
}//End Roster::remove

//Print average days in course per student ID
void Roster::printAverageDaysInCourse(string studentID) 
{
    //For loop to go through the array
    for (int i = 0; i < 5; i++) 
    {
        //Check the current index
        if (classRosterArray[i]) 
        {
            //if the current index studentID == the provided studentID
            if (classRosterArray[i]->getStudentID() == studentID) 
            {
                int avgDaysInCourse = 0;

                avgDaysInCourse = (classRosterArray[i]->getNumDays()[0] + 
                    classRosterArray[i]->getNumDays()[1] + 
                    classRosterArray[i]->getNumDays()[2]) / 3;//Set the avgDaysInCourse to adding the array and dividing by 3
                cout << "Average time take for: " << studentID << " to finish 3 courses: " << avgDaysInCourse << " days." << endl;//Print the average time to finish 3 courses
            }
        }
    }
}//Roster::printAverageDaysInCourse

//Check emails for validity and print invalid emails
void Roster::printInvalidEmails() 
{
    //Booleans for the characters to search
    bool at = false;
    bool space = false;
    bool period = false;

    cout << "Invalid Emails Listed are: " << endl;//Print title

    //Go through the student array classRosterArray
    for (int i = 0; i < 5; i++) 
    {
        string email = classRosterArray[i]->getEmail();//Set email to the array position [i]->getEmail()
        //Reset booleans
        at = false;
        space = false;
        period = false;

        //Check for certain characters in the string
        if (email.find(".") < email.length()) 
        {
            period = true;
        }//Check for periods
                
        if (email.find(" ") < email.length()) 
        {
            space = true;
        }//Check for spacces
                
        if (email.find("@") < email.length()) 
        {
            at = true;
        }//Check for @ symbol
          
        //Check if at is false period is false and space is true
        if (at == false || period == false || space == true) {
            cout << (classRosterArray[i])->getEmail() << endl;//Print invalid emails
        }
    }
    cout << endl;//Add end line
}//Roster::printInvalidEmails

//Print the students by degree inputed
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) 
{
    //For loop to go through the array
    for (int i = 0; i < 5; i++)
    {
        //Check if the degree program equals the input degree
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) 
        {
            classRosterArray[i]->print();//Call the print function
            cout << endl;//Print new line
        }
    }
}//Roster::printByDegreeProgram

//Print entire student roster
void Roster::printAll() 
{
    //For loop to go through the array
    for (int i = 0; i < 5; i++) 
    {
        //Check the current index
        if (classRosterArray[i]) 
        {
            //if the current index is not equal to nullptr
            if (classRosterArray[i] != 0) 
            {
                classRosterArray[i]->print();//Call the print function to print the student to console
            }
        }
    }
}//Roster::printAll

Roster::~Roster() {}//Deconstructor