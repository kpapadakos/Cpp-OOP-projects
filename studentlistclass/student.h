#ifndef _STUDENT_H
#define _STUDENT_H

class Student
{
public:
  Student();

  virtual double FinalAverage()=0;
  virtual int getFinalExam()=0;

  void setFirstName(char [20]);
  void setLastName(char [20]);
  void setCourse(char [8]);
  char lettergrade();
  char* getFirstName();
  char* getLastName();
  char* getCourse();
  char* getName();

protected:
  char firstname[20];
  char lastname[20];
  char fullname[40];
  char course[8];
  int A, B, C, D, F;
};

class EnglishStudent : public Student
{
public:
  EnglishStudent();
  EnglishStudent(char fn[], char ln[], char c[], int, int, int);
  int getFinalExam();

protected:
  double FinalAverage();

  int TermPaper;
  static const double TermPaperWeight = 0.25;
  int Midterm;
  static const double MidtermWeight = 0.35;
  int FinalExam;
  static const double FinalExamWeight = 0.40;
  double FinalAvg;
};

class HistoryStudent : public Student
{
public:
  HistoryStudent();
  HistoryStudent(char fn[], char ln[], char c[], int, int, int, int);
  int getFinalExam();

protected:
  double FinalAverage();

  int Attendance;
  static const double AttendanceWeight = 0.10;
  int Project;
  static const double ProjectWeight = 0.30;
  int Midterm;
  static const double MidtermWeight = 0.30;
  int FinalExam;
  static const double FinalExamWeight = 0.30;
  double FinalAvg;
};

class MathStudent : public Student
{
public:
  MathStudent();
  MathStudent(char fn[], char ln[], char c[], int, int, int, int, int, int, int, int);
  int getFinalExam();

protected:
  double FinalAverage();

  int Q1;
  int Q2;
  int Q3;
  int Q4;
  int Q5;
  double QuizAverage;
  static const double QuizWeight = 0.20;
  int T1;
  static const double T1Weight = 0.25;
  int T2;
  static const double T2Weight = 0.25;
  int FinalExam;
  static const double FinalExamWeight = 0.30;   
  double FinalAvg;
};

#endif

