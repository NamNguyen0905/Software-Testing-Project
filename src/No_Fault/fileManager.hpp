#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

#include "Student.hpp"
/*
    These functions read input and write to the csv file
*/
bool readFile(vector<Student>& students, string fileName);
bool writeFile(vector<Student>& students, string fileName);

#endif