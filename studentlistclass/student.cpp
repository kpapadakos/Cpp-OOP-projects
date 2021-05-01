#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student()
{
    
}

void Student::setFirstName(char fn[20])
{
  for(int i = 0; i < strlen(fn); i++)
    firstname[i] = fn[i];
}

void Student::setLastName(char ln[20])
{
  for(int i = 0; i < strlen(ln); i++)
    lastname[i] = ln[i];
}

void Student::setCourse(char c[8])
{
  for(int i = 0; i < strlen(c); i++)
    course[i] = c[i];
}

char* Student::getFirstName()
{
  return firstname;
}

char* Student::getLastName()
{
  return lastname;
}

char* Student::getCourse()
{
  return course;
}

char* Student::getName()
{
  strcat(fullname, firstname);
  strcat(fullname, " ");
  strcat(fullname, lastname);

  return fullname;
}

char Student::lettergrade()
{
  if(FinalAverage() >= 90)
    return 'A';
  else if(FinalAverage() <= 89 && FinalAverage() >= 80)
    return 'B';
  else if(FinalAverage() <= 79 && FinalAverage() >= 70)
    return 'C';
  else if(FinalAverage() <= 69 && FinalAverage() >= 60)
    return 'D';
  else if(FinalAverage() < 60)
    return 'F';
  
}

EnglishStudent::EnglishStudent()
{
  strcpy(firstname, " ");
  strcpy(lastname, " ");
  strcpy(course, "English"); 
}

EnglishStudent::EnglishStudent(char fn[], char ln[], char c[], int TP, int MT, int FE)
{
  strcpy(firstname, fn);
  strcpy(lastname, ln);
  strcpy(course, c);

  TermPaper = TP;
  Midterm = MT;
  FinalExam = FE;
}

int EnglishStudent::getFinalExam()
{
  return FinalExam;
}

double EnglishStudent::FinalAverage()
{
  double TPavg, MTavg, FEavg;

  TPavg = TermPaper * TermPaperWeight;
  MTavg = Midterm * MidtermWeight;
  FEavg = FinalExam * FinalExamWeight;

  FinalAvg = TPavg + MTavg + FEavg;
  return FinalAvg;
}

HistoryStudent::HistoryStudent()
{
  strcpy(firstname, " ");
  strcpy(lastname, " ");
  strcpy(course, "History"); 
}

HistoryStudent::HistoryStudent(char fn[], char ln[], char c[], int Att, int Proj, int MT, int FE)
{
  strcpy(firstname, fn);
  strcpy(lastname, ln);
  strcpy(course, c);

  Attendance = Att;
  Project =  Proj;
  Midterm = MT;
  FinalExam = FE;
}

int HistoryStudent::getFinalExam()
{
  return FinalExam;
}

double HistoryStudent::FinalAverage()
{
  double ATTavg, PROJavg, MTavg, FEavg;

  ATTavg = Attendance * AttendanceWeight;
  PROJavg = Project * ProjectWeight;
  MTavg = Midterm * MidtermWeight;
  FEavg = FinalExam * FinalExamWeight;

  FinalAvg = ATTavg + PROJavg + MTavg + FEavg;
  return FinalAvg;
}

MathStudent::MathStudent()
{  
  strcpy(firstname, " ");
  strcpy(lastname, " ");
  strcpy(course, "Math"); 
}

MathStudent::MathStudent(char fn[], char ln[], char c[], int q1, int q2, int q3, int q4, int q5, int t1, int t2, int FE)
{
  strcpy(firstname, fn);
  strcpy(lastname, ln);
  strcpy(course, c);

  Q1 = q1;
  Q2 = q2;
  Q3 = q3;
  Q4 = q4;
  Q5 = q5;
  T1 = t1;
  T2 = t2;
  FinalExam = FE;
}

int MathStudent::getFinalExam()
{
  return FinalExam;
}

double MathStudent::FinalAverage()
{
  double Qavg, T1avg, T2avg, FEavg;

  QuizAverage = (Q1 + Q2 + Q3 + Q4 + Q5) / 5.0;
  Qavg = QuizAverage * QuizWeight;
  T1avg = T1 * T1Weight;
  T2avg = T2 * T2Weight;
  FEavg = FinalExam * FinalExamWeight;

  FinalAvg = Qavg + T1avg + T2avg + FEavg;
  return FinalAvg;
}
