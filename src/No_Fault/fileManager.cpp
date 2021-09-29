#include "fileManager.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool readFile(vector<Student>& students, string fileName) {
  ifstream fin;

  fin.open(fileName);

  string temp, line, data;

  int numLine = 0;

  getline(fin, line);
  while (fin.good()) {
    if (count(line.begin(), line.end(), ',') != 5) {
      cout << "The number of fields is not correct in line " << numLine + 1
           << "." << endl;
      cout << line << endl;
      return false;
    }

    stringstream ss(line);
    string tempStr;
    vector<string> row;

    while (ss.good()) {
      getline(ss, tempStr, ',');
      row.push_back(tempStr);
    }

    Student new_student(row[0], row[1], row[2], stoi(row[3]), stoi(row[4]),
                        stoi(row[5]));
    students.push_back(new_student);

    numLine++;
    getline(fin, line);
  }

  return true;
}

bool writeFile(vector<Student>& students, string fileName) {
  ofstream fout;

  fout.open(fileName);

  for (int i = 0; i < students.size(); i++) {
    fout << students[i].get_name() << "," << students[i].get_id() << ","
         << students[i].get_email() << ","
         << students[i].get_grade_presentation() << ","
         << students[i].get_grade_essay() << ","
         << students[i].get_grade_project() << endl;
  }

  return true;
}