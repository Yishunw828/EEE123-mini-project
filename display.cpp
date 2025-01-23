// Programmers: 
// Purpose: Function to display all patient records from patients.txt.

#include <iostream>
#include <fstream>
#include <sstream>
#include "display.hpp"

using namespace std;

void displayAllRecords() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\nError opening file or no records found!\033[0m" << endl;
        return;
    }

    string line;
    cout << "\033[1;34m\n==============================================\033[0m" << endl;
    cout << "\033[1;34m        === All Patient Records ===         \033[0m" << endl;
    cout << "\033[1;34m==============================================\033[0m" << endl;

    bool recordFound = false;

    while (getline(file, line)) {
        istringstream record(line);
        string name, age, ic, gender, contact, reason, date, ward;

        getline(record, name, ',');
        getline(record, age, ',');
        getline(record, ic, ',');
        getline(record, gender, ',');
        getline(record, contact, ',');
        getline(record, reason, ',');
        getline(record, date, ',');
        getline(record, ward, ',');

        cout << "| \033[1;32mPatient Name: \033[0m" << name
             << "\n| \033[1;33mAge: \033[0m" << age
             << "\n| \033[1;36mIC Number: \033[0m" << ic
             << "\n| \033[1;35mGender: \033[0m" << gender
             << "\n| \033[1;34mContact Number: \033[0m" << contact
             << "\n| \033[1;32mAdmission Reason: \033[0m" << reason
             << "\n| \033[1;33mAdmission Date: \033[0m" << date
             << "\n| \033[1;31mWard Number: \033[0m" << ward
             << "\n\033[1;34m----------------------------------------------\033[0m" << endl;

        recordFound = true;
    }

    if (!recordFound) {
        cout << "\033[1;31m\nNo records found!\033[0m" << endl;
    }

    cout << "\033[1;34m==============================================\033[0m" << endl;

    file.close();
}
