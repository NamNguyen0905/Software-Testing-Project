
#include <iostream>
#include <string>
#include <vector>

#include "fileManager.hpp"
#include "helper.hpp"
#include "studentManager.hpp"

using namespace std;

void menu(); // prints menu options



/*
  We open the csv file and read it,
  The user is asked to make a choice from the menu options,
  They can Add a student, Update Info, Delete a Student, or Get Info,
  All these functions happen in studentManager.cpp
*/
int main() {
  vector<Student> students;

  readFile(students, "students.csv");

  int choice = -1;

  while (choice != 5) {
    menu();

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {  // Add student
        cin.ignore();
        add_student(students); // function that adds student in studentManager.cpp
        break;
      }
      case 2: {  // Update info
        update_student(students); // Updates info for one specific student
        break;
      }
      case 3: {  // Delete student
        delete_student(students); // Deletes a row of info from the csv
        break;
      }
      case 4: {  // Prints all info of the student with matching UID
        string uid;
        cout << "Enter the UID of the student you want to get info: ";
        cin >> uid;

        int idx = search_studentByID(students, uid);

        cout << endl;
        cout << "************************" << endl;
        students[idx].toString();
        cout << "************************" << endl << endl;

        break;
      }
      case 5:
        writeFile(students, "students.csv");
        break;
      default:
        cout << "Invalid option!! Please choose again." << endl; // if invalid input, asks for valid inpit
    }
  }

  return 0;
}
/*
  Displays menu options
*/
void menu() {
  cout << "======================" << endl;
  cout << "1. Add student" << endl;
  cout << "2. Update student info" << endl;
  cout << "3. Delete student" << endl;
  cout << "4. Get student info" << endl;
  cout << "5. Exit" << endl;
  cout << "======================" << endl << endl;
}