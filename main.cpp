// ============================================
// Advanced Feedback Management System
// Backend in C++ using OOP + File Handling
// ============================================

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ============================================
// Feedback Class
// ============================================

class Feedback {

private:
    string studentName;
    string department;
    string message;

public:

    // Constructor
    Feedback(string name, string dept, string msg) {

        studentName = name;
        department = dept;
        message = msg;
    }

    // Save Feedback
    void saveFeedback() {

        ofstream file("feedback.txt", ios::app);

        file << "=====================================\n";
        file << "Student Name : " << studentName << endl;
        file << "Department   : " << department << endl;
        file << "Feedback     : " << message << endl;
        file << "=====================================\n\n";

        file.close();

        cout << "\nFeedback Submitted Successfully!\n";
    }
};

// ============================================
// Admin Class
// ============================================

class Admin {

public:

    // View Feedback
    void viewFeedback() {

        ifstream file("feedback.txt");

        if (!file) {

            cout << "\nNo Feedback Records Found!\n";
            return;
        }

        string line;

        cout << "\n========== ALL FEEDBACK ==========\n\n";

        while (getline(file, line)) {

            cout << line << endl;
        }

        file.close();
    }

    // Delete All Feedback
    void clearFeedback() {

        ofstream file("feedback.txt");

        file.close();

        cout << "\nAll Feedback Deleted Successfully!\n";
    }
};

// ============================================
// Main Function
// ============================================

int main() {

    Admin admin;

    int choice;

    while (true) {

        cout << "\n========================================";
        cout << "\n     FEEDBACK MANAGEMENT SYSTEM";
        cout << "\n========================================\n";

        cout << "1. Submit Feedback\n";
        cout << "2. View Feedback\n";
        cout << "3. Delete All Feedback\n";
        cout << "4. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {

        case 1: {

            string name;
            string department;
            string message;

            cout << "\nEnter Student Name: ";
            getline(cin, name);

            cout << "Enter Department: ";
            getline(cin, department);

            cout << "Enter Feedback: ";
            getline(cin, message);

            Feedback fb(name, department, message);

            fb.saveFeedback();

            break;
        }

        case 2:

            admin.viewFeedback();

            break;

        case 3:

            admin.clearFeedback();

            break;

        case 4:

            cout << "\nThank You!\n";

            return 0;

        default:

            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}