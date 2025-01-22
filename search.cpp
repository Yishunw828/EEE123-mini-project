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
     
    cout << "\033[1;36m\nSearch Patient Record By:\033[0m\n"; 
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
        cout << "\033[1;31m\nInvalid input! Please enter a valid number.\033[0m\n"; 
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
            cout << "\033[1;31m\nInvalid choice! Please select a valid option.\033[0m\n"; 
    } 
} 
 
void searchByName() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\033[1;31m\nError opening file!\033[0m" << endl; 
        return; 
    } 
 
    string name, line; 
    cout << "\033[1;36m\nEnter Patient Name to search: \033[0m"; 
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
 
            cout << "\033[1;32m\nPatient Name: \033[0m" << name 
                 << "\n\033[1;32mAge: \033[0m" << age 
                 << "\n\033[1;32mIC Number: \033[0m" << ic 
                 << "\n\033[1;32mGender: \033[0m" << gender 
                 << "\n\033[1;32mContact Number: \033[0m" << contact 
                 << "\n\033[1;32mAdmission Reason: \033[0m" << reason 
                 << "\n\033[1;32mAdmission Date: \033[0m" << date 
                 << "\n\033[1;32mWard Number: \033[0m" << ward 
                 << "\n-------------------------\n"; 
            found = true; 
        } 
    } 
    if (!found) { 
        cout << "\033[1;31m\nNo record found for \033[0m" << name << ".\n"; 
    } 
 
    file.close(); 
} 
 
void searchByWard() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\033[1;31m\nError opening file!\033[0m" << endl; 
        return; 
    } 
 
    string ward, line; 
    cout << "\033[1;36m\nEnter Ward Number to search: \033[0m"; 
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
 
            cout << "\033[1;32m\nPatient Name: \033[0m" << name 
                 << "\n\033[1;32mAge: \033[0m" << age 
                 << "\n\033[1;32mIC Number: \033[0m" << ic 
                 << "\n\033[1;32mGender: \033[0m" << gender 
                 << "\n\033[1;32mContact Number: \033[0m" << contact 
                 << "\n\033[1;32mAdmission Reason: \033[0m" << reason 
                 << "\n\033[1;32mAdmission Date: \033[0m" << date 
                 << "\n\033[1;32mWard Number: \033[0m" << ward 
                 << "\n-------------------------\n"; 
            found = true; 
        } 
    } 
    if (!found) { 
        cout << "\033[1;31m\nNo record found for Ward \033[0m" << ward << ".\n"; 
    } 
 
    file.close(); 
} 
 
void searchByDate() { 
    ifstream file("patients.txt"); 
    if (!file) { 
        cout << "\033[1;31m\nError opening file!\033[0m" << endl; 
        return; 
    } 
 
    string date, line; 
    cout << "\033[1;36m\nEnter Admission Date to search (DD/MM/YYYY): \033[0m"; 
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
 
            cout << "\033[1;32m\nPatient Name: \033[0m" << name 
                 << "\n\033[1;32mAge: \033[0m" << age 
                 << "\n\033[1;32mIC Number: \033[0m" << ic 
                 << "\n\033[1;32mGender: \033[0m" << gender 
                 << "\n\033[1;32mContact Number: \033[0m" << contact 
                 << "\n\033[1;32mAdmission Reason: \033[0m" << reason 
                 << "\n\033[1;32mAdmission Date: \033[0m" << date 
                 << "\n\033[1;32mWard Number: \033[0m" << ward 
                 << "\n-------------------------\n"; 
            found = true; 
        } 
    } 
    if (!found) { 
        cout << "\033[1;31m\nNo record found for Date \033[0m" << date << ".\n"; 
    } 
}