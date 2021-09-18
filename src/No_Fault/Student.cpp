#include "Student.h"

#include <iostream>

using std::cin;
using std::cout;

Student::Student(std::string name, std::string id, std::string email,
                 double grade_presentation, double grade_essay,
                 double grade_project) {
  name_ = name;
  id_ = id;
  email_ = email;
  grade_presentation_ = grade_presentation;
  grade_essay_ = grade_essay;
  grade_project_ = grade_project;
}

std::string Student::verify_input(std::string keyword, std::string input) {
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
    if (std::stoi(input) >= 0 && std::stoi(input) <= 4) {
      return input;
    } else {
      cout << "Grade should be from 0(F) to 4(A).";
    }
  }

  return "";
}

bool Student::update_info(std::string keyword, std::string updated_info) {
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
      grade_presentation_ = std::stoi(updated_info);
    } else if (keyword == "grade_essay") {
      grade_essay_ = std::stoi(updated_info);
    } else if (keyword == "grade_project") {
      grade_project_ = std::stoi(updated_info);
    }
  }
}