// Programmers: 
// Purpose: Functions to search patient records by name, ward, or date.

#include <iostream>
#include <fstream>
#include <sstream>
#include "search.hpp"

using namespace std;

void searchMenu(){
    int choice;
    cout << "\nSearch Patient Record By:\n";
    cout << "1. Name\n";
    cout << "2. Ward Number\n";
    cout << "3. Admission Date\n";
    cout << "\nEnter your choice > ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            searchByName();
            break;
        case 2:
            searchByWard();
            break;
        case 3:
            searchByDate();
            break;
        default:
            cout << "Invalid choice!\n";
    }
}

void searchByName() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name, line;
    cout << "\nEnter Patient Name to search: ";
    getline(cin, name);

    bool found = false;
    while (getline(file, line)) {
        if (line.find(name) != string::npos) {
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
            found = true;
        }
    }
    if (!found) cout << "No record found for " << name << endl;

    file.close();
}

void searchByWard() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string ward, line;
    cout << "Enter Ward Number to search: ";
    getline(cin, ward);

    bool found = false;
    while (getline(file, line)) {
        if (line.find("," + ward) != string::npos) {
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
            found = true;
        }
    }
    if (!found) cout << "No record found for Ward " << ward << endl;

    file.close();
}

void searchByDate() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string date, line;
    cout << "Enter Admission Date to search (DD/MM/YYYY): ";
    getline(cin, date);

    bool found = false;
    while (getline(file, line)) {
        if (line.find(date) != string::npos) {
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
            found = true;
        }
    }
    if (!found) cout << "No record found for Date " << date << endl;

    file.close();
}