// Programmers: 
// Purpose: Functions to search patient records by name, ward, or date.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include "search.hpp"

using namespace std;

void searchMenu() {
    string input;
    int choice;

    cout << "\033[1;34m\n";
    cout << "==============================================\n";
    cout << "|              \033[1;36mSearch Patient Record By       \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "|  \033[1;36m1. Name                                    \033[1;34m|\n";
    cout << "|  \033[1;36m2. Ward Number                             \033[1;34m|\n";
    cout << "|  \033[1;36m3. Admission Date                          \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "\033[1;36mEnter your choice > \033[0m";
    
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

void searchByName() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\nUnable to open the file for reading.\033[0m\n";
        return;
    }

    string name, line;
    regex namePattern("^[a-zA-Z\\s]+$");

    do {
        cout << "\033[1;36m\nEnter Patient Name to search: \033[0m";
        getline(cin, name);

        if (!regex_match(name, namePattern)) {
            cout << "\033[1;31mInvalid name format. Please enter a valid name (alphabets and spaces only).\033[0m\n";
        } else {
            break;
        }
    } while (true);

    bool found = false;
    cout << "\033[1;34m\n==============================================\033[0m\n";
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

            cout << "\033[1;32m\nPatient Record Found:\033[0m\n";
            cout << "| \033[1;32mPatient Name: \033[0m" << name
                 << "\n| \033[1;33mAge: \033[0m" << age
                 << "\n| \033[1;36mIC Number: \033[0m" << ic
                 << "\n| \033[1;35mGender: \033[0m" << gender
                 << "\n| \033[1;34mContact Number: \033[0m" << contact
                 << "\n| \033[1;32mAdmission Reason: \033[0m" << reason
                 << "\n| \033[1;33mAdmission Date: \033[0m" << date
                 << "\n| \033[1;31mWard Number: \033[0m" << ward
                 << "\n\033[1;34m----------------------------------------------\033[0m\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\033[1;31m\nNo record found for patient name: \033[0m" << name << ".\n";
    }
    cout << "\033[1;34m==============================================\033[0m\n";

    file.close();
}



#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

void searchByWard() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\nUnable to open the file for reading.\033[0m\n";
        return;
    }

    string ward, line;
    regex wardPattern("^(WFE|WMA)\\d{1,3}$");

    do {
        cout << "\033[1;36m\nEnter Ward Number to search (e.g., WFE123 or WMA45): \033[0m";
        getline(cin, ward);

        if (!regex_match(ward, wardPattern)) {
            cout << "\033[1;31mInvalid ward number format. Please enter a valid ward number.\033[0m\n";
        } else {
            break;
        }
    } while (true);

    bool found = false;
    cout << "\033[1;34m\n==============================================\033[0m\n";
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

            cout << "| Patient Name: " << name
                 << "\n| Age: " << age
                 << "\n| IC Number: " << ic
                 << "\n| Gender: " << gender
                 << "\n| Contact Number: " << contact
                 << "\n| Admission Reason: " << reason
                 << "\n| Admission Date: " << date
                 << "\n| Ward Number: " << ward
                 << "\n----------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\033[1;31m\nNo record found for ward number: \033[0m" << ward << ".\n";
    }
    cout << "\033[1;34m==============================================\033[0m\n";

    file.close();
}


bool ValidDate(const std::string& date) { 
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') return false; 
    std::string dayStr = date.substr(0, 2), monthStr = date.substr(3, 2), yearStr = date.substr(6, 4); 
    try { 
        int day = std::stoi(dayStr), month = std::stoi(monthStr), year = std::stoi(yearStr); 
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) return false; 
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
        if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) daysInMonth[1] = 29; 
        return day <= daysInMonth[month - 1]; 
    } catch (...) { 
        return false; 
    } 
}

void searchByDate() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31m\nUnable to open the file for reading.\033[0m\n";
        return;
    }

    string date, line;

    do {
        cout << "\033[1;36m\nEnter Admission Date to search (DD/MM/YYYY): \033[0m";
        getline(cin, date);

        if (!ValidDate(date)) {
            cout << "\033[1;31mInvalid date format. Please enter a valid date in DD/MM/YYYY format.\033[0m\n";
        } else {
            break;
        }
    } while (true);

    bool found = false;
    cout << "\033[1;34m\n==============================================\033[0m\n";
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

            cout << "| \033[1;32mPatient Name: \033[0m" << name
                 << "\n| \033[1;33mAge: \033[0m" << age
                 << "\n| \033[1;36mIC Number: \033[0m" << ic
                 << "\n| \033[1;35mGender: \033[0m" << gender
                 << "\n| \033[1;34mContact Number: \033[0m" << contact
                 << "\n| \033[1;32mAdmission Reason: \033[0m" << reason
                 << "\n| \033[1;33mAdmission Date: \033[0m" << date
                 << "\n| \033[1;31mWard Number: \033[0m" << ward
                 << "\n\033[1;34m----------------------------------------------\033[0m\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\033[1;31m\nNo record found for admission date: \033[0m" << date << ".\n";
    }
    cout << "\033[1;34m==============================================\033[0m\n";

    file.close();
}

