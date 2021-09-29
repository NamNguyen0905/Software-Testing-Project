#include "Student.hpp"

#include <iostream>

using namespace std;

string Student::verify_input(string keyword, string input) {
  if (keyword == "name" || keyword == "email") {
    if (input.length() > 0 && input.length() <= 40) {
      return input;
    } else if (input.length() <= 0) {
      cout << "Student's " << input << " should not be empty.";
    } else {
      cout << "Student's " << input << " should have up to 40 characters.";
    }
  } else if (keyword == "id") {
    if (input.length() == 10) {
      return input;
    } else {
      cout << "Student's ID should have 10 characters.";
    }
  } else {
    if (stoi(input) >= 0 && stoi(input) <= 4) {
      return input;
    } else {
      cout << "Grade should be from 0(F) to 4(A).";
    }
  }

  return "";
}

bool Student::update_info(string keyword, string updated_info) {
  updated_info = verify_input(keyword, updated_info);
  while (updated_info == "") {
    cout << "Please try again.";
    cin >> updated_info;

    if (keyword == "name") {
      name_ = updated_info;
    } else if (keyword == "id") {
      id_ = updated_info;
    } else if (keyword == "email") {
      email_ = updated_info;
    } else if (keyword == "grade_presentation") {
      grade_presentation_ = stoi(updated_info);
    } else if (keyword == "grade_essay") {
      grade_essay_ = stoi(updated_info);
    } else if (keyword == "grade_project") {
      grade_project_ = stoi(updated_info);
    }
  }

  return true;
}