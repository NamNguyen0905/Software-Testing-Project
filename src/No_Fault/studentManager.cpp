#include "studentManager.hpp"
#include "validation.hpp"
#include "helper.hpp"

/*
  Menu for updating info
*/
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

// function that adds a student based off user input
bool add_student(vector<Student>& students) {
  string name, id, email;
  int grade_presentation, grade_essay, grade_project;
  //while() for each
  cout << "Enter student's info:\n";
  while(true){
    cout << "Name: ";
    getline(cin, name);
    if (validateName(name) == false){
      cout << "Invalid Name" << endl;
      cout << "Please try again" << endl;
    }
    else{
      break;
    }
  }

  while(true){
    cout << "UID: ";
    getline(cin, id);
    if (validateID(id) == false){
      cout << "Invalid UID" << endl;
      cout << "Please try again" << endl;
    }
    else if (duplicateID(students, id) == false){
      break;
    }
  }
  while(true){
    cout << "Email: ";
    getline(cin, email);
    if (validateEmail(email) == false){
      cout << "Invalid Email" << endl;
      cout << "Please try again" << endl;
    }
    else{
      if(duplicateEmail(students, email) == false){
        break;
      }
    }
  }
  while(true){
    cout << "Grade Presentation: ";
    cin >> grade_presentation;
    if (validateGrade(grade_presentation) == false){
      cout << "Invalid grade entered" << endl;
      cout << "Please try again" << endl;
    }
    else{
      break;
    }
  }
  while(true){
    cout << "Grade Essay: ";
    cin >> grade_essay;
    if (validateGrade(grade_essay) == false){
      cout << "Invalid grade entered" << endl;
      cout << "Please try again" << endl;
    }
    else{
      break;
    }
  }
  while(true){
    cout << "Grade Project: ";
    cin >> grade_project;
    if (validateGrade(grade_project) == false){
      cout << "Invalid grade entered" << endl;
      cout << "Please try again" << endl;
    }
    else{
      break;
    }
  }

  Student new_student(name, id, email, grade_presentation, grade_essay,
                      grade_project); // makes a new student
  students.push_back(new_student); 

  cout << "Added successfully!" << endl << endl;

  return true;
}

// deletes a student from the vector and csv
// Searches for student by UID
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

// Updates student info through their UID
// Gives the option to enter new information 1 at a time
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
          cin.ignore();
          while(true){
            cout << "Enter a new name: ";
            getline(cin, new_name);
            if (validateName(new_name) == false){
              cout << "Invalid Name" << endl;
              cout << "Please try again" << endl;
            }
            else{
              break;
            }
        }


          students[idx].set_name(new_name);
          break;
        }
        case 2: {
          string new_id;
          while(true){
            cout << "Enter a new UID: ";
            cin >> new_id;
            if (validateID(new_id) == false){
              cout << "Invalid UID" << endl;
              cout << "Please try again" << endl;
            }
            else{
              if(duplicateID(students, new_id) == false){
                break;
              }
            }
          }
          
          students[idx].set_id(new_id);
          break;
        }
        case 3: {
          string new_email;
          while(true){
            cout << "Enter a new email: ";
            cin >> new_email;
            if (validateEmail(new_email) == false){
              cout << "Invalid Email" << endl;
              cout << "Please try again" << endl;
            }
            else{
              if(duplicateEmail(students, new_email) == false){
                break;
              }
            }
          }

          students[idx].set_email(new_email);
          break;
        }
        case 4: {
          int new_gradePresentation;
          while(true){
            cout << "Enter a new presentation grade: ";
            cin >> new_gradePresentation;
            if (validateGrade(new_gradePresentation) == false){
              cout << "Invalid grade entered" << endl;
              cout << "Please try again" << endl;
            }
            else{
              break;
            }
          }

          students[idx].set_gradePresentation(new_gradePresentation);
          break;
        }
        case 5: {
          int new_gradeEssay;
          while(true){
            cout << "Enter a new essay grade: ";
            cin >> new_gradeEssay;
            if (validateGrade(new_gradeEssay) == false){
              cout << "Invalid grade entered" << endl;
              cout << "Please try again" << endl;
            }
            else{
              break;
            }
          }

          students[idx].set_gradeEssay(new_gradeEssay);
          break;
        }
        case 6: {
          int new_gradeProject;
          while(true){
            cout << "Enter a new project grade: ";
            cin >> new_gradeProject;
            if (validateGrade(new_gradeProject) == false){
              cout << "Invalid grade entered" << endl;
              cout << "Please try again" << endl;
            }
            else{
              break;
            }
          }

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