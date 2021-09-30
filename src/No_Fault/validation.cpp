#include "validation.hpp"
using namespace std;

/*
    This file is for validating name, UID, and email,
    It will also check the csv file for if a duplicate,
    email or UID is used when updating or adding a new student
*/


bool validateName(string input){
    //cout << input.length();
    if(input.length() > 40 || input.length() == 0 || input == " ")
     {
         cout << "Maximum length is 40 characters for name" << endl;
         cout << "Please input a valid name" << endl;
         return false;
     }
     return true;
}

bool validateID(string input){
    if (input.length() != 10){
        cout << "UID must be exactly 10 characters" << endl;
        return false;
    }
    if(input[0] != 'U'){
        cout << "UID must start with capital U" << endl;
        return false;
    }
    else{
        return true;
    }
}

bool validateEmail(string input){
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    if (regex_match(input, pattern) == true) {
        return true;
    }
    else{
        cout << "Incorrect email format, please include '@' symbol" << endl;
        return false;
    }
}

bool validateGrade(int input){
    if( input == 0 || input == 1 || input == 2 || input == 3 || input == 4){
        return true;
    }
    else{
        cout << "Invalid input, must be a integer number from 0-4" << endl;
        return false;
    }
}

bool duplicateEmail(vector<Student>& students, string email){
    for(int i=0; i < students.size(); i++){
        if(students[i].get_email() == email){
            cout << "Duplicate email, please input a new email" << endl;
            return true;
        }
    }
    return false;
}

bool duplicateID(vector<Student>& students, string id){
    for(int i=0; i < students.size(); i++){
        if(students[i].get_id() == id){
            cout << "Duplicate UID, please input a new UID" << endl;
            return true;
        }
    }
    return false;
}