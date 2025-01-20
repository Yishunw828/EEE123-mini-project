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
     
    cout << "\nSearch Patient Record By:\n"; 
    cout << "1. Name\n"; 
    cout << "2. Ward Number\n"; 
    cout << "3. Admission Date\n"; 
    cout << "\nEnter your choice: "; 
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
        cout << "\nInvalid input! Please enter a valid number.\n"; 
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
            cout << "\nInvalid choice! Please select a valid option.\n"; 
    } 
} 
 
void searchByName() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\nError opening file!" << endl; 
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
    if (!found) { 
        cout << "\nNo record found for " << name << ".\n"; 
    } 
 
    file.close(); 
} 
 
void searchByWard() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\nError opening file!" << endl; 
        return; 
    } 
 
    string ward, line; 
    cout << "\nEnter Ward Number to search: "; 
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
    if (!found) { 
        cout << "\nNo record found for Ward " << ward << ".\n"; 
    } 
 
    file.close(); 
} 
 
void searchByDate() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\nError opening file!" << endl; 
        return; 
    } 
 
    string date, line; 
    cout << "\nEnter Admission Date to search (DD/MM/YYYY): "; 
    getline(cin,date); 
 
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
    if (!found) { 
        cout << "\nNo record found for Date " << date << ".\n"; 
    } 
 
    file.close(); 
}