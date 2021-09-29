#ifndef HELPER_H
#define HELPER_H

#include <vector>

#include "Student.hpp"

int search_studentByID(vector<Student>& students, string uid);
int search_studentByName(vector<Student>& students, string name);
int search_studentByEmail(vector<Student>& students, string email);

#endif