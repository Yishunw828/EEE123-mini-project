// Programmers: 
// Purpose: Handles patient admission and stores data in patients.txt.

#include <iostream>
#include <fstream>
#include "admission.hpp"

using namespace std;

void admitPatient() {
    ofstream file("patients.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string name, ic, gender, contact, reason, date, ward;
    int age;

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, name); 

    cout << "Enter Age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Invalid input! Enter a valid age: ";
    }

    cin.ignore();  
    cout << "Enter IC Number(XXXXXX-XX-XXXX): ";
    getline(cin, ic);
    cout << "Enter Gender (Male/Female): ";
    getline(cin, gender);
    cout << "Enter Contact Number: ";
    getline(cin, contact);
    cout << "Enter Admission Reason: ";
    getline(cin, reason);
    cout << "Enter Admission Date (DD/MM/YYYY): ";
    getline(cin, date);
    cout << "Enter Ward Number: ";
    getline(cin, ward);

    file << name << "," << age << "," << ic << "," << gender << "," << contact << "," << reason << "," << date << "," << ward << endl;
    file.close();

    cout << "Patient admitted successfully!\n";
}
