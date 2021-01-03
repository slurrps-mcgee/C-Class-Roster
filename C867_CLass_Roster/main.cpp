/*
    Author: Kenneth Lamb

    Created: 12/6/2020
*/
#include <sstream>//
#include <cstring> //email character checking function
#include <string>//Use string operations
#include <iostream>//Use COUT CIN
//Include headers
#include "roster.h"
#include "student.h"
#include "degree.h"

int main() 
{

    //Student Data coming in--
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Kenneth,Lamb,klam114@wgu.edu,28,50,48,40,SOFTWARE"
	};

    //create a instance of Roster
	Roster classRoster;
    //create a instance of DegreeProgram
    DegreeProgram myDegree{};

    //Add each student to class roster from studentData
    for (int i = 0; i < 5; i++) 
    {
        //create a string stream and hold the studentData table at index i
        stringstream row(studentData[i]);

        //Create string array to hold incoming data
        string student[9];

        //Go through the string stream and fill in the string array 
        for (int i = 0; i < 9; i++)
        {
            //Use getline method to take in the string stream row and read until ',' character and set the string to the student array at index i
            getline(row, student[i], ',');
        }

        //Check for degree
        if (student[8] == "SECURITY") 
        {
            myDegree = DegreeProgram::SECURITY;
        }
        if (student[8] == "SOFTWARE") 
        {
            myDegree = DegreeProgram::SOFTWARE;
        }
        if (student[8] == "NETWORK") 
        {
            myDegree = DegreeProgram::NETWORK;
        }
        //-----------------------------
        //Add the student to the roster by calling the add method
        classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]), stoi(student[5]),
            stoi(student[6]), stoi(student[7]), myDegree);
    }

    //Title---------------------------
    cout << "-------------------------------------------------------" << endl;
    cout << "Course: Scripting and Programming - Applications - C867" << endl;
    cout << "Language used: C++" << endl;
    cout << "Student ID: #001508907" << endl;
    cout << "Student Name: Kenneth Lamb" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;

    //Call Methods below

    classRoster.printAll();//Call the method printAll

    classRoster.printInvalidEmails();//Call the method printInvalidEmails

    //For loop to go through students and list the average days in class
    for (int i = 0; i < 5; i++) 
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());//Call the method printAverageDaysInCourse
    }

    cout << endl;//Print new line

    classRoster.printByDegreeProgram(SOFTWARE);//Call the method printByDegreeProgram

    classRoster.remove("A3");//Call the method remove
    
    classRoster.printAll();//Call the method printAll

    classRoster.remove("A3");//Call the method remove

    classRoster.~Roster();//Call the deconstructor
	return 0;
	
}