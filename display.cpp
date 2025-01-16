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
        cout << "Error opening file or no records found!" << endl;
        return;
    }

    string line;
    cout << "\n=== All Patient Records ===\n";
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

        cout << "\nPatient Name: " << name
             << "\nAge: " << age
             << "\nIC Number: " << ic
             << "\nGender: " << gender
             << "\nContact Number: " << contact
             << "\nAdmission Reason: " << reason
             << "\nAdmission Date: " << date
             << "\nWard Number: " << ward
             << "\n-------------------------\n";
    }
    file.close();
}
