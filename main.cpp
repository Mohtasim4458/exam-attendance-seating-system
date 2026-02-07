#include <iostream>
#include <string>
using namespace std;
 
struct Student {
    int rollNo;
    string name;
    bool present;
    Student* next;
};
 
Student* top = NULL;
 
void addStudent() {
    Student* newNode = new Student();
 
    cout << "Enter roll number: ";
    cin >> newNode->rollNo;
    cout << "Enter student name: ";
    cin >> newNode->name;
 
    newNode->present = false;
    newNode->next = top;
    top = newNode;
 
    cout << "Student added successfully.\n";
}
 
void markAttendance() {
    if (top == NULL) {
        cout << "No students available.\n";
        return;
    }
 
    int roll;
    cout << "Enter roll number to mark present: ";
    cin >> roll;
 
    Student* temp = top;
    while (temp != NULL) {
        if (temp->rollNo == roll) {
            temp->present = true;
            cout << "Attendance marked PRESENT.\n";
            return;
        }
        temp = temp->next;
    }
 
    cout << "Student not found.\n";
}
 
void removeStudent() {
    if (top == NULL) {
        cout << "No students to remove.\n";
        return;
    }
 
    Student* temp = top;
    top = top->next;
    delete temp;
 
    cout << "Last added student removed.\n";
}
 
void showAttendance() {
    if (top == NULL) {
        cout << "No students available.\n";
        return;
    }
 
    cout << "\nAttendance List\n";
    Student* temp = top;
 
    while (temp != NULL) {
        cout << "Roll No: " << temp->rollNo
             << ", Name: " << temp->name
             << ", Status: ";
 
        if (temp->present)
            cout << "Present\n";
        else
            cout << "Absent\n";
 
        temp = temp->next;
    }
}
 
void arrangeSeats() {
    if (top == NULL) {
        cout << "No students available.\n";
        return;
    }
 
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
 
    Student* temp = top;
 
    cout << "\nExam Seating Arrangement\n\n";
 
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
 
            if (temp != NULL) {
                cout << temp->name << " (" << temp->rollNo << ")";
 
                if (temp->present)
                    cout << "[P]";
                else
                    cout << "[A]";
 
                temp = temp->next;
            } else {
                cout << "Empty Seat";
            }
 
            cout << "\t";
        }
        cout << endl;
    }
}
 
int main() {
    int choice;
 
    do {
        cout << "\n===== Exam Attendance & Seating System =====\n";
        cout << "1. Add a student\n";
        cout << "2. Mark attendance\n";
        cout << "3. Remove last added student\n";
        cout << "4. Show attendance list\n";
        cout << "5. Arrange exam seats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        if (choice == 1)
            addStudent();
        else if (choice == 2)
            markAttendance();
        else if (choice == 3)
            removeStudent();
        else if (choice == 4)
            showAttendance();
        else if (choice == 5)
            arrangeSeats();
 
    } while (choice != 6);
 
    cout << "Program closed.\n";
    return 0;
}

