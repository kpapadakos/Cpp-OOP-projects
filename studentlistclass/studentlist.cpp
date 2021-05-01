#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "studentlist.h"

using namespace std;

StudentList::StudentList()		//starts out empty
{
  size = 0;
  oldsize = 0;
  studentlist = new Student*[size];
}

StudentList::~StudentList()		//cleanup (destructor)
{
  delete [] studentlist;
}

bool StudentList::ImportFile(const char* filename)
{
  ifstream in1;
  int num;
  int i = 0;
  char last_name[20];
  char first_name[20];
  char _course[8];
  int q1, q2, q3, q4, q5, t1, t2, FE;
  int TP, att, proj, MT;

  in1.open(filename);

  if(!in1)
  {
    cout << "Invalid file. No data imported." << endl;
    return false;
  }  

  in1 >> num;
  size = size + num;        
  oldsize = size - num;
  Grow(size);
  in1.ignore();

  for(int i = 0; i < num; i++)
  {   
    in1.get(last_name, 20, ',');
    in1.ignore(2);
    in1.get(first_name, 20, '\n');
    in1 >> _course;
    
    if(strcmp(_course, "Math") == 0)
    {
      in1 >> q1 >> q2 >> q3 >> q4 >> q5 >> t1 >> t2 >> FE;
      studentlist[i + oldsize] = new MathStudent(first_name, last_name, _course, q1, q2, q3, q4, q5, t1, t2, FE);
    }
    else if(strcmp(_course, "History") == 0)
    {
      in1 >> att >> proj >> MT >> FE;
      studentlist[i + oldsize] = new HistoryStudent(first_name, last_name, _course, att, proj, MT, FE);
    }
    else if(strcmp(_course, "English") == 0)
    {
      in1 >> TP >> MT >> FE;
      studentlist[i + oldsize] = new EnglishStudent(first_name, last_name, _course, TP, MT, FE);
    }
    in1.ignore();
  }
  in1.close();
}

bool StudentList::CreateReportFile(const char* filename)
{
  int A, B, C, D, F;
  A = B = C = D = F = 0;
  ofstream out1;
  
  out1.open(filename);

  if(!out1)
  {
    cout << "Invalid file. No data exported" << endl;
    return false;
  }
  
  out1 << "Student Grade Summary" << endl;
  out1 << "---------------------\n" << endl;

  out1 << "ENGLISH CLASS\n\n"
       << "Student\t\t\t\t\tFinal Final    Letter\n"
       << "Name\t\t\t\t\tExam  Avg      Grade\n"
       << "--------------------------------------------------------------" << endl;

  for(int i = 0; i < size; i++)
  {
    if(strcmp(studentlist[i]->getCourse(), "English") == 0)
      out1 << left
           << setw(40) <<studentlist[i]->getName()
           << setw(6) << studentlist[i]->getFinalExam()
           << setw(9) << fixed << setprecision(2) << studentlist[i]->FinalAverage()
           << studentlist[i]->lettergrade() << endl;

    if(studentlist[i]->lettergrade() == 'A')
      A++;
    else if(studentlist[i]->lettergrade() == 'B')
      B++;
    else if(studentlist[i]->lettergrade() == 'C')
      C++;
    else if(studentlist[i]->lettergrade() == 'D')
      D++;
    else
      F++; 
  }

  out1 << "\n\nHISTORY CLASS\n\n"
       << "Student\t\t\t\t\tFinal Final    Letter\n"
       << "Name\t\t\t\t\tExam  Avg      Grade\n"
       << "--------------------------------------------------------------" << endl;

  for(int i = 0; i < size; i++)
  {
    if(strcmp(studentlist[i]->getCourse(), "History") == 0)
      out1 << left
           << setw(40) << studentlist[i]->getName()
           << setw(6) << studentlist[i]->getFinalExam()
           << setw(9) << fixed << setprecision(2) << studentlist[i]->FinalAverage()
           << studentlist[i]->lettergrade() << endl;

    if(studentlist[i]->lettergrade() == 'A')
      A++;
    else if(studentlist[i]->lettergrade() == 'B')
      B++;
    else if(studentlist[i]->lettergrade() == 'C')
      C++;
    else if(studentlist[i]->lettergrade() == 'D')
      D++;
    else
      F++; 
  }

  out1 << "\n\nMATH CLASS\n\n"
       << "Student\t\t\t\t\tFinal Final    Letter\n"
       << "Name\t\t\t\t\tExam  Avg      Grade\n"
       << "--------------------------------------------------------------" << endl;

  for(int i = 0; i < size; i++)
  {
    if(strcmp(studentlist[i]->getCourse(), "Math") == 0)
      out1 << left
           << setw(40) << studentlist[i]->getName()
           << setw(6) << studentlist[i]->getFinalExam()
           << setw(9) << fixed << setprecision(2) << studentlist[i]->FinalAverage()
           << studentlist[i]->lettergrade() << endl;

    if(studentlist[i]->lettergrade() == 'A')
      A++;
    else if(studentlist[i]->lettergrade() == 'B')
      B++;
    else if(studentlist[i]->lettergrade() == 'C')
      C++;
    else if(studentlist[i]->lettergrade() == 'D')
      D++;
    else
      F++; 
  }

  out1 << "\n\nOVERALL GRADE DISTRIBUTION\n" << endl;
  out1 << "A:\t" << A/3 << endl
       << "B:\t" << B/3 << endl
       << "C:\t" << C/3 << endl
       << "D:\t" << D/3 << endl
       << "F:\t" << F/3 << endl;

  out1.close(); 
}

void StudentList::ShowList() const	//print basic list data
{
  cout << "Last\t\t\tFirst\t\t\tCourse\n" << endl;
  for(int i = 0; i < size; i++)
  {
    cout << left
         << setw(24) << studentlist[i]->getLastName()
         << setw(24) << studentlist[i]->getFirstName()
         << setw(24) << studentlist[i]->getCourse() << endl;  
  }
}

void StudentList::Grow(int s)
{
  //DYNAMICALLY SIZED ARRAY
  size = s;
  Student ** slist = new Student*[size];

  for(int i = 0; i < oldsize; i++)
    slist[i] = studentlist[i];

  delete [] studentlist;
  studentlist = slist;
}
