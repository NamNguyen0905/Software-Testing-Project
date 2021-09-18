#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>

class Student {
 private:
  std::string name_;
  std::string id_;
  std::string email_;
  double grade_presentation_;
  double grade_essay_;
  double grade_project_;

 public:
  Student(std::string name, std::string id, std::string email,
          double grade_presentation, double grade_essay, double grade_project);

  std::string get_name() { return name_; }
  std::string get_id() { return id_; }
  std::string get_email() { return email_; }
  double get_grade_presentation() { return grade_presentation_; }
  double get_grade_essay() { return grade_essay_; }
  double get_grade_project() { return grade_project_; }

  std::string verify_input(std::string keyword, std::string input);
  bool update_info(std::string keyword, std::string updated_info);
};

#endif