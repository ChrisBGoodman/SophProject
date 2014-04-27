//
//  Student.h
//  ChristianGoodmanProject2
//
//  Created by Christian Goodman on 4/17/14.
//  Copyright (c) 2014 Christian Goodman. All rights reserved.
//

#ifndef __ChristianGoodmanProject2__Student__
#define __ChristianGoodmanProject2__Student__

#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    string firstName;
    string lastName;
    string course; // Variable to hold what course student is in
public:
    Student(string ln, string fn, string c); //constructor
    Student();
    virtual ~Student(){}; //virtual destructor
    virtual double finalGrade() = 0; //pure virtual, gets Final Grade
    virtual void printInfo() = 0;    //pure virtual, prints Student Info
    virtual char getLetterGrade();
    virtual bool compareCourse(string a) =0;
    

};

//--------------------------------------------------------------------------------------------------
//derived class's below
class English: public Student
{
protected:
    int attendance = 0;
    int project = 0;
    int midterm = 0;
    int finalExam = 0;
    double finGrade;

public:
    English(string ln = "", string fn = "", string c = "", int a=0, int p=0, int m=0, int f=0)
    :Student(ln,fn,c), attendance(a), project(p), midterm(m), finalExam(f){}
    //constuctor, passes values to base class when constructed
    
    ~English(){}; //destructor
    double finalGrade(); //calculates English final grade based of Percentage worth and Grades
    void printInfo();
    bool compareCourse(string check);
   
    
};
//*****************************************************************************

class History: public Student
{
protected:
    int termPaper;
    int midTerm;
    int finalExam;
    double finGrade;
    //char letterGrade = getLetterGrade();

public:
    History(string ln = "", string fn = "", string c = "", int t = 0, int m=0, int f=0)
    :Student(ln, fn, c), termPaper(t), midTerm(m), finalExam(f){}
    //constuctor, passes values to base class when constructed
    
    ~History(){} //destructor
    double finalGrade(); //calculates History final grade based on percentage worth and grades
    void printInfo();
    bool compareCourse(string check);

};
//*****************************************************************************

class Math: public Student
{
protected:
    int quiz1 = 0;
    int quiz2 = 0;
    int quiz3 = 0;
    int quiz4 = 0;
    int quiz5 = 0;
    int test1 = 0;
    int test2 = 0;
    int finalExam = 0;
    double finGrade;

public:
    Math(char ln[], char fn[], string c = "", int q1=0, int q2=0, int q3=0, int q4=0, int q5=0, int t1=0, int t2=0, int f=0)
    : Student(ln, fn, c), quiz1(q1), quiz2(q2), quiz3(q3), quiz4(q4), quiz5(q5), test1(t1), test2(t2), finalExam(f){} //constuctor, passes values to base class when constructed
    
    ~Math(){}; //destructor
    double finalGrade();
    void printInfo(); 
    bool compareCourse(string check);
    
};
#endif /* defined(__ChristianGoodmanProject2__Student__) */
