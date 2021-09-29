
#include <iostream>
#include <string>
#include <vector>

#include "fileManager.hpp"
#include "helper.hpp"
#include "studentManager.hpp"

using namespace std;

void menu();

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
        add_student(students);
        break;
      }
      case 2: {  // Update info
        update_student(students);
        break;
      }
      case 3: {  // Delete student
        delete_student(students);
        break;
      }
      case 4: {  // Get info
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
        cout << "Invalid option!! Please choose again." << endl;
    }
  }

  return 0;
}

void menu() {
  cout << "======================" << endl;
  cout << "1. Add student" << endl;
  cout << "2. Update student info" << endl;
  cout << "3. Delete student" << endl;
  cout << "4. Get student info" << endl;
  cout << "5. Exit" << endl;
  cout << "======================" << endl << endl;
}