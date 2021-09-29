#include "helper.hpp"

#include <iostream>

int search_studentByID(vector<Student>& students, string uid) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_id() == uid) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}

int search_studentByName(vector<Student>& students, string name) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_name() == name) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}
int search_studentByEmail(vector<Student>& students, string email) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_email() == email) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}
