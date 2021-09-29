#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
 private:
  string name_;
  string id_;
  string email_;
  int grade_presentation_;
  int grade_essay_;
  int grade_project_;

 public:
  Student(string name, string id, string email, int grade_presentation,
          int grade_essay, int grade_project)
      : name_(name),
        id_(id),
        email_(email),
        grade_presentation_(grade_presentation),
        grade_essay_(grade_essay),
        grade_project_(grade_project){};

  string get_name() { return name_; }
  void set_name(string name) { name_ = name; }

  string get_id() { return id_; }
  void set_id(string id) { id_ = id; }

  string get_email() { return email_; }
  void set_email(string email) { email_ = email; }

  int get_grade_presentation() { return grade_presentation_; }
  void set_gradePresentation(int grade_presentation) {
    grade_presentation_ = grade_presentation;
  }

  int get_grade_essay() { return grade_essay_; }
  void set_gradeEssay(int grade_essay) { grade_essay_ = grade_essay; }

  int get_grade_project() { return grade_project_; }
  void set_gradeProject(int grade_project) { grade_project_ = grade_project; }

  void toString() {
    cout << "UID: " << id_ << endl
         << "Name: " << name_ << endl
         << "Email: " << email_ << endl
         << "Grade Presentation: " << to_string(grade_presentation_) << endl
         << "Grade Essay: " << to_string(grade_essay_) << endl
         << "Grade Project: " << to_string(grade_project_) << endl;
  }

  string verify_input(string keyword, string input);
  bool update_info(string keyword, string updated_info);
};

#endif