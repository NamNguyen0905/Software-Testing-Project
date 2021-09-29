#include "studentManager.hpp"

#include "helper.hpp"

void update_menu() {
  cout << "0. View updated info" << endl;
  cout << "1. Update name" << endl;
  cout << "2. Update uid" << endl;
  cout << "3. Update email" << endl;
  cout << "4. Update presentation grade" << endl;
  cout << "5. Update essay grade" << endl;
  cout << "6. Update project grade" << endl;
  cout << "7. Done." << endl << endl;
}

bool add_student(vector<Student>& students) {
  string name, id, email;
  int grade_presentation, grade_essay, grade_project;

  cout << "Enter student's info:\n";
  cout << "Name: ";
  getline(cin, name);
  cout << "UID: ";
  cin >> id;
  cout << "Email: ";
  cin >> email;
  cout << "Grade presentation: ";
  cin >> grade_presentation;
  cout << "Grade essay: ";
  cin >> grade_essay;
  cout << "Grade project: ";
  cin >> grade_project;

  Student new_student(name, id, email, grade_presentation, grade_essay,
                      grade_project);
  students.push_back(new_student);

  cout << "Added successfully!" << endl << endl;

  return true;
}

bool delete_student(vector<Student>& students) {
  string delete_id;

  cout << "Enter the UID of the student you want to delete: ";
  cin >> delete_id;

  int idx = search_studentByID(students, delete_id);
  if (idx != -1) {
    students.erase(students.begin() + idx);
    cout << "Deleted successfully!" << endl << endl;

    return true;
  } else {
    return false;
  }
}

bool update_student(vector<Student>& students) {
  string update_id;

  cout << "Enter the UID of the student you want to update: ";
  cin >> update_id;

  int idx = search_studentByID(students, update_id);
  if (idx != -1) {
    int update_choice = -1;

    cout << "Here is the student's info:" << endl << endl;
    students[idx].toString();
    cout << endl;

    while (update_choice != 7) {
      cout << "What info would you like to change?" << endl;
      update_menu();

      cout << "> ";
      cin >> update_choice;
      cout << endl;

      switch (update_choice) {
        case 0: {
          cout << "************************" << endl;
          students[idx].toString();
          cout << "************************" << endl << endl;

          break;
        }
        case 1: {
          string new_name;
          cout << "Enter a new name: ";
          cin.ignore();
          getline(cin, new_name);

          students[idx].set_name(new_name);
          break;
        }
        case 2: {
          string new_id;
          cout << "Enter a new uid: ";
          cin >> new_id;

          students[idx].set_id(new_id);
          break;
        }
        case 3: {
          string new_email;
          cout << "Enter a new email: ";
          cin >> new_email;

          students[idx].set_email(new_email);
          break;
        }
        case 4: {
          int new_gradePresentation;
          cout << "Enter a new presentation grade: ";
          cin >> new_gradePresentation;

          students[idx].set_gradePresentation(new_gradePresentation);
          break;
        }
        case 5: {
          int new_gradeEssay;
          cout << "Enter a new essay grade: ";
          cin >> new_gradeEssay;

          students[idx].set_gradeEssay(new_gradeEssay);
          break;
        }
        case 6: {
          int new_gradeProject;
          cout << "Enter a new project grade: ";
          cin >> new_gradeProject;

          students[idx].set_gradeProject(new_gradeProject);
          break;
        }
        case 7:
          break;
        default:
          cout << "Invalid choice. Please choose again." << endl;
      }

      cout << "Updated successfully!" << endl << endl;
    }

    return true;
  } else {
    return false;
  }
}