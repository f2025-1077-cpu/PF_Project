#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[20];
    int grade;
    int attendance;
    int bookIssued;
};

Student s[50];
int total = 0;

void addStudent() {
    cout << "Enter ID: ";
    cin >> s[total].id;
    cout << "Enter Name: ";
    cin >> s[total].name;
    s[total].grade = 0;
    s[total].attendance = 0;
    s[total].bookIssued = 0;
    total++;
}

void showStudents() {
    if (total == 0) {
        cout << "No students found\n";
        return;
    }

    cout << "\nID Name Grade Attendance Book\n";
    for (int i = 0; i < total; i++) {
        cout << s[i].id << " "
             << s[i].name << " "
             << s[i].grade << " "
             << s[i].attendance << " "
             << s[i].bookIssued << endl;
    }
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            for (int j = i; j < total - 1; j++) {
                s[j] = s[j + 1];
            }
            total--;
            cout << "Student deleted\n";
            return;
        }
    }
    cout << "Student not found\n";
}

void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            cout << "Enter new name: ";
            cin >> s[i].name;
            cout << "Student updated\n";
            return;
        }
    }
    cout << "Student not found\n";
}

void issueBook() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            if (s[i].bookIssued == 0) {
                s[i].bookIssued = 1;
                cout << "Book issued\n";
            } else {
                cout << "Book already issued\n";
            }
            return;
        }
    }
    cout << "Student not found\n";
}

void returnBook() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            if (s[i].bookIssued == 1) {
                s[i].bookIssued = 0;
                cout << "Book returned\n";
            } else {
                cout << "No book issued\n";
            }
            return;
        }
    }
    cout << "Student not found\n";
}

void updateGrade() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            cout << "Enter grade: ";
            cin >> s[i].grade;
            return;
        }
    }
    cout << "Student not found\n";
}

void updateAttendance() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (s[i].id == id) {
            cout << "Enter attendance percentage: ";
            cin >> s[i].attendance;
            return;
        }
    }
    cout << "Student not found\n";
}


int main() {
    int choice;

    while (1) {
        cout << "\n-------------------------------\n";
        cout << " STUDENT MANAGEMENT SYSTEM\n";
        cout << "-------------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Update Grade\n";
        cout << "8. Update Attendance\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: showStudents(); break;
        case 3: deleteStudent(); break;
        case 4: updateStudent(); break;
        case 5: issueBook(); break;
        case 6: returnBook(); break;
        case 7: updateGrade(); break;
        case 8: updateAttendance(); break;
        case 0: return 0;
        default: cout << "Invalid choice\n";
        }
    }
}

