#include "student.h"
#include "studentlist.h"
#include <iostream>
#include <fstream>


using namespace std;

void Menu();

int main()
{
  char s;
  char filename[30];
  StudentList sl1;

  Menu();

  while(cin)
  {
    cout << "\n> ";
    cin >> s;

    switch(s)
    {
      case 'I':
      case 'i':
        cout << "Enter filename > ";
        cin >> filename;
        sl1.ImportFile(filename);
        break;
      case 'S':
      case 's':
        sl1.ShowList();
        break;
      case 'E':
      case 'e':
        cout << "Enter filename > ";
        cin >> filename;
        sl1.CreateReportFile(filename);
        break;
      case 'M':
      case 'm':
        Menu();
        break;
      case 'Q':
      case 'q':
        cout << "Goodbye!" << endl;
        return 0;
        break;        
      default:
        cout << "Invalid selection...";
        break;
    }
  }
  cout << "OUT OF LOOP BYE";
};

void Menu()
{
  cout << "\n\t\t" << " *** Student List Menu ***" << endl;
  cout << "\n\t" << "I" << '\t' << "Import students from a file" << endl;
  cout << '\t' << "S" << '\t' << "Show students from a list (brief)" << endl;
  cout << '\t' << "E" << '\t' << "Export a grade report (to file)" << endl;
  cout << '\t' << "M" << '\t' << "Show this Menu" << endl;
  cout << '\t' << "Q" << '\t' << "Quit Program\n" << endl;
}
