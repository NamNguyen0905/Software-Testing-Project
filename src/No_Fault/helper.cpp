#include "helper.hpp"
#include <iostream>

/*
  This file seacrhes the csv with either the students
  UID, their name, or their email.
*/


/*
  this function is taking the vector of all student info 
  and searching each one for the desired student UID
  If not found it is known to the user
*/
int search_studentByID(vector<Student>& students, string uid) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_id() == uid) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}

/*
  this function is taking the vector of all student info 
  and searching each one for the desired student Name
  If not found it is known to the user
*/
int search_studentByName(vector<Student>& students, string name) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_name() == name) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}

/*
  this function is taking the vector of all student info 
  and searching each one for the desired student email
  If not found it is known to the user
*/
int search_studentByEmail(vector<Student>& students, string email) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i].get_email() == email) {
      return i;
    }
  }

  cout << "Student not found!" << endl;
  return -1;
}
