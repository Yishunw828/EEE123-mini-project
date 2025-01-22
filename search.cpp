// Programmers: 
// Purpose: Functions to search patient records by name, ward, or date.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "search.hpp"

using namespace std;

void searchMenu() {
    int choice;
    string input;

    cout << "\033[1;36m\n[MENU] Search Patient Record By:\033[0m\n";
    cout << "\033[1;36m1. Name\033[0m\n";
    cout << "\033[1;36m2. Ward Number\033[0m\n";
    cout << "\033[1;36m3. Admission Date\033[0m\n";
    cout << "\033[1;36m\n[INPUT] Enter your choice: \033[0m";
    cin >> input;
    cin.ignore();

    bool isValid = true;
    for (char ch : input) {
        if (!isdigit(ch)) {
            isValid = false;
            break;
        }
    }

    if (!isValid) {
        cout << "\033[1;31m\n[ERROR] Invalid input! Please enter a valid number.\033[0m\n";
        return;
    }

    choice = stoi(input);

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
            cout << "\033[1;31m\n[ERROR] Invalid choice! Please select a valid option.\033[0m\n";
    }
}

void searchByName() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\n[ERROR] Unable to open the file for reading.\033[0m\n";
        return;
    }

    string name, line;
    cout << "\033[1;36m\n[INPUT] Enter Patient Name to search: \033[0m";
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

            cout << "\033[1;32m\n[RESULT] Patient Record Found:\033[0m\n";
            cout << "Patient Name: " << name
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
    if (!found) {
        cout << "\033[1;31m\n[ERROR] No record found for patient name: \033[0m" << name << ".\n";
    }

    file.close();
}

void searchByWard() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\n[ERROR] Unable to open the file for reading.\033[0m\n";
        return;
    }

    string ward, line;
    cout << "\033[1;36m\n[INPUT] Enter Ward Number to search: \033[0m";
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

            cout << "\033[1;32m\n[RESULT] Patient Record Found:\033[0m\n";
            cout << "Patient Name: " << name
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
    if (!found) {
        cout << "\033[1;31m\n[ERROR] No record found for ward number: \033[0m" << ward << ".\n";
    }

    file.close();
}

void searchByDate() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\n[ERROR] Unable to open the file for reading.\033[0m\n";
        return;
    }

    string date, line;
    cout << "\033[1;36m\n[INPUT] Enter Admission Date to search (DD/MM/YYYY): \033[0m";
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

            cout << "\033[1;32m\n[RESULT] Patient Record Found:\033[0m\n";
            cout << "Patient Name: " << name
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
    if (!found) {
        cout << "\033[1;31m\n[ERROR] No record found for admission date: \033[0m" << date << ".\n";
    }

    file.close();
}