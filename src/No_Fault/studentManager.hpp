#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.hpp"

/*
    Functions to add, delete, and update students
*/

bool add_student(vector<Student>& students);
bool delete_student(vector<Student>& students);
bool update_student(vector<Student>& students);

#endif