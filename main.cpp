//
//  main.cpp
//  ChristianGoodmanProject2
//
//  Created by Christian Goodman on 4/17/14.
//  Copyright (c) 2014 Christian Goodman. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include "Student.h"
#include <vector>

using namespace std;

//English-History-Math
int main()
{
    char fn[20] = {}; //local first name var
    char ln[20] = {}; //local last name var
    string stuCourse; //local var to hold course
    int int1, int2, int3, int4, int5, int6, int7, int8 = 0; //vars to hold data from txt file
    int obCount = -1; //counter to count num of objects created
    
    Math mathOb(fn, ln, stuCourse, int1, int2, int3, int4, int5, int6, int7, int8);
    History histOb(fn, ln, stuCourse, int1, int2, int3);
    English engOb(fn, ln, stuCourse, int1, int2, int3, int4); // 3 derivded classes created
    Student * stuArray[6]; //pointer to array of Student Abstract class
    
    
    cout << "\nPlease enter the name of the input file.\n";
    cout << "File Name: ";
    char fileAddress[50];
    cin.getline(fileAddress, 50); //"/Users/ChrisGoodman/Desktop/cs2project.txt"
    
    ifstream stuFile; //declares file stream for input
    stuFile.open(fileAddress); //opens file stream for input
        if (stuFile.is_open())
    {
        cout <<"opened!\n";
        while (obCount !=6)
        {
            stuFile.getline(ln, 20, ',' ); //gets last name
            stuFile.getline(fn, 20, '\r'); //gets first name
            stuFile >> stuCourse; //gets course of student
            
            if (stuCourse == "Math") //If course is Math
            {
                stuFile >> int1 >> int2 >> int3 >> int4 >> int5 >> int6 >> int7 >> int8; //gets Math grades
                obCount++; //Count increased because new student has been stored to local vars
                stuArray[obCount]= &mathOb; //make the array[count] reference to a math Object
                stuArray[obCount] = new Math(fn, ln, stuCourse, int1, int2, int3, int4, int5, int6, int7, int8); //fill the array[count] with a new Math Object
            }
            
            if (stuCourse == "History") //If course is History
            {
                stuFile >> int1 >> int2 >> int3;
                obCount++;
                stuArray[obCount]= &histOb;
                stuArray[obCount] = new History(fn, ln, stuCourse, int1, int2, int3);
            }
            
            if (stuCourse == "English") //If course is English
            {
                stuFile >> int1 >> int2 >> int3 >> int4;
                obCount++;
                stuArray[obCount]= &engOb;
                stuArray[obCount] = new English(fn, ln, stuCourse, int1, int2, int3, int4);
            }
        }
    }
    else
        cout << "\nError opening file!\n";
    stuFile.close();
    
    string mathCheck = "Math";          //3 strings to check which course array[count] the student is in
    string historyCheck = "History";
    string englishCheck = "English";
    
    cout << "\n  Student Grade Summary\n";
    cout << "   ----------------------";
    
    cout << "\n-English Class-\n";
    cout << "Student Name -------- Final Exam--Final Avg--Letter Grade-";
    for (int i = 0; i<6; i++)
    {if (stuArray[i]->compareCourse(englishCheck) == true) //checks if course is English
        {stuArray[i]->printInfo();}} //if true, array[count] prints info
    
    cout << "\n\n-History Class-\n";
    cout << "Student Name -------- Final Exam--Final Avg--Letter Grade-";
    for (int i = 0; i<6; i++)
    {if (stuArray[i]->compareCourse(historyCheck) == true) //checks if course is History
    {stuArray[i]->printInfo();}} //if History student, prints info
    
    cout << "\n\n-Math Class-\n";
    cout << "Student Name -------- Final Exam--Final Avg--Letter Grade-";
    for (int i = 0; i<6; i++)
    {if (stuArray[i]->compareCourse(mathCheck) == true) //checks if course is math
    {stuArray[i]->printInfo();}} //if Math, prints info
    
    cout << endl << endl;
    delete stuArray[6];

    
    cout << "Thanks for using the program!";
   };
