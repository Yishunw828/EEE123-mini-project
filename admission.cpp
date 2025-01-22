// Programmers:
// Purpose: Handles patient admission and stores data in patients.txt.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <set>
#include "admission.hpp"

using namespace std;

const int MAX_WARD = 1000;

bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false;
    }
    return true;
}

string getValidName() {
    string name;
    do {
        cout << "\nEnter Patient Full Name as per IC: ";
        getline(cin, name);
        if (!isValidName(name)) {
            cout << "Invalid input! Name must contain only alphabets and spaces. Please try again.\n";
        }
    } while (!isValidName(name));
    return name;
}

bool isValidDate(const string& date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') return false;
    string dayStr = date.substr(0, 2), monthStr = date.substr(3, 2), yearStr = date.substr(6, 4);
    try {
        int day = stoi(dayStr), month = stoi(monthStr), year = stoi(yearStr);
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1000 || year > 9999) return false;
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) daysInMonth[1] = 29;
        return day <= daysInMonth[month - 1];
    } catch (...) {
        return false;
    }
}

string getValidDate() {
    string date;
    do {
        cout << "Enter Admission Date (DD/MM/YYYY): ";
        getline(cin, date);
        if (!isValidDate(date)) {
            cout << "Invalid input! Date must be in the format DD/MM/YYYY. Please try again.\n";
        }
    } while (!isValidDate(date));
    return date;
}

set<int> getAssignedWards() {
    set<int> assignedWards;
    ifstream file("patients.txt");
    if (!file) return assignedWards;
    string line;
    while (getline(file, line)) {
        size_t lastComma = line.find_last_of(',');
        if (lastComma != string::npos) {
            string wardStr = line.substr(lastComma + 1);
            if (!wardStr.empty() && (wardStr.find("WMA") == 0 || wardStr.find("WFE") == 0)) {
                try {
                    int ward = stoi(wardStr.substr(3));
                    assignedWards.insert(ward);
                } catch (...) {}
            }
        }
    }
    return assignedWards;
}

int assignRandomWard(const set<int>& assignedWards) {
    if (assignedWards.size() >= MAX_WARD) return -1;
    int ward;
    do {
        ward = rand() % MAX_WARD + 1;
    } while (assignedWards.find(ward) != assignedWards.end());
    return ward;
}

void admitPatient() {
    ofstream file("patients.txt", ios::app);
    if (!file) {
        cerr << "Error opening file!\n";
        return;
    }

    srand(time(0));
    set<int> assignedWards = getAssignedWards();
    int ward = assignRandomWard(assignedWards);
    if (ward == -1) {
        cout << "All ward numbers are occupied. Cannot admit new patients!\n";
        return;
    }

    string name = getValidName();
    int age;
    cout << "Enter Age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Invalid input! Enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ic;
    cout << "Enter IC Number (XXXXXX-XX-XXXX): ";
    getline(cin, ic);

    string gender, wardPrefix;
    cout << "Enter Gender (Male/Female): ";
    while (true) {
        getline(cin, gender);
        if (gender == "Male" || gender == "Female") {
            wardPrefix = (gender == "Male") ? "WMA" : "WFE";
            break;
        }
        cout << "Invalid input! Please enter Male or Female: ";
    }

    string contact;
    cout << "Enter Contact Number (without -): ";
    getline(cin, contact);

    string reason;
    cout << "Enter Admission Reason: ";
    getline(cin, reason);

    string date = getValidDate();

    file << name << "," << age << "," << ic << "," << gender << "," << contact << "," << reason << "," << date << "," << wardPrefix << ward << endl;
    file.close();

    cout << "\nPatient admitted successfully! Assigned ward number: " << wardPrefix << ward << "\n";
}
