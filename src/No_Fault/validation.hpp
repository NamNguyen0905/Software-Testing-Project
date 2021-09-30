#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <sstream>
#include "Student.hpp"
#include <string>
#include <regex>

using namespace std;

//functions for validating student information

bool validateName(string input);
bool validateID(string input);
bool validateEmail(string input);
bool validateGrade(int input);
bool duplicateEmail(vector<Student>& students, string email);
bool duplicateID(vector<Student>& students, string id);
#endif