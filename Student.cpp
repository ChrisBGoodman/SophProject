//
//  Student.cpp
//  ChristianGoodmanProject2
//
//  Created by Christian Goodman on 4/17/14.
//  Copyright (c) 2014 Christian Goodman. All rights reserved.
//

#include "ChristianGoodman_P-2.h"
#include <string>
#include <string.h>
#include <iomanip>

Student::Student(string x, string y, string z) //Abstract Class constructor
{
    firstName = x;
    lastName = y;
    course = z;
}

Student::Student()
{
    cout << "hi..."; 
}

//*****************************************************************************
void English::printInfo()
{
    cout << setw(15) << left <<lastName << setw(12) << left << firstName << setw(10) <<finalExam << setw(12) << finalGrade() << setw(15) << getLetterGrade();
};

void History::printInfo()
{
    cout << setw(15) << left <<lastName << setw(12) << left << firstName << setw(10) <<finalExam << setw(12) << finalGrade() << setw(15) << getLetterGrade();
};

void Math::printInfo()
{
    cout << setw(15) << left <<lastName << setw(12) << left << firstName << setw(10) <<finalExam << setw(12) << finalGrade() << setw(15) << getLetterGrade();
};
//*****************************************************************************

double English::finalGrade()
{
    finGrade= attendance*(.1)+project*(.3)+midterm*(.3)+finalExam*(.3);
    return finGrade;
}


double History::finalGrade()
{
    finGrade = termPaper*(.25)+midTerm*(.35)+finalExam*(.4);
    return finGrade;
};

double Math::finalGrade()
{
    double quizGrade;
    quizGrade = (quiz1+quiz2+quiz3+quiz4+quiz5)/5;
    finGrade = quizGrade*(.15)+test1*(.25)+test2*(.25)+finalExam*(.35);
    return finGrade;
};
//*****************************************************************************
char Student::getLetterGrade()
{
    char lGrade;
    if (finalGrade()>=90 && finalGrade()<=100) //A
        lGrade = 'A';
    
    if (finalGrade()>=80 && finalGrade()<90)  //B
        lGrade = 'B';
    
    if (finalGrade() >=70 && finalGrade()<80)  //C
        lGrade = 'C';
    
    if (finalGrade() >=60 && finalGrade()<70)  //D
        lGrade = 'D';
    
    if (finalGrade() >=0 && finalGrade()<60)   //F
        lGrade = 'F';
    
    return lGrade;
}
//****************************************************************************
bool Math::compareCourse(string mathCheck)
{
    bool check = false;
    if (course == mathCheck)
    {
        check = true;
    }
    return check;
}

bool English::compareCourse(string englishCheck)
{
    bool check = false;
    if (course == englishCheck)
    {
        check = true;
    }
    return check;
}

bool History::compareCourse(string historyCheck)
{
    bool check = false;
    if (course == historyCheck)
    {
        check = true;
    }
    return check;
}

