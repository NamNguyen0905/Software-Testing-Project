#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

#include "Student.hpp"

bool readFile(vector<Student>& students, string fileName);
bool writeFile(vector<Student>& students, string fileName);

#endif