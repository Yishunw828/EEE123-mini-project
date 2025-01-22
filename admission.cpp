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

set<int> getAssignedWards() {
    set<int> assignedWards;
    ifstream file("patients.txt");
    if (!file) return assignedWards;  

    string line;
    while (getline(file, line)) {
        size_t lastComma = line.find_last_of(',');
        if (lastComma != string::npos) {
            string wardStr = line.substr(lastComma + 1);
            if (!wardStr.empty() && wardStr[0] == 'W') { 
                try {
                    int ward = stoi(wardStr.substr(1)); 
                    assignedWards.insert(ward);
                } catch (const invalid_argument&) {
                    cout << "\n\033[1;31m[ERROR]\033[0m Invalid ward number format in file: " << wardStr << endl;
                } catch (const out_of_range&) {
                    cout << "\n\033[1;31m[ERROR]\033[0m Ward number out of range in file: " << wardStr << endl;
                }
            }
        }
    }
    file.close();
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
        cout << "\n\033[1;31m[ERROR]\033[0m Unable to open the file for saving patient data.\n";
        return;
    }

    srand(time(0));  

    set<int> assignedWards = getAssignedWards(); 
    int ward = assignRandomWard(assignedWards);  

    if (ward == -1) {
        cout << "\n\033[1;31m[ERROR]\033[0m All ward numbers are occupied. Cannot admit new patients!\n";
        return;
    }

    string name, ic, gender, contact, reason, date;
    int age;

    cout << "\n\033[1;36m[INPUT]\033[0m Enter Patient Full Name as per IC: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "\033[1;36m[INPUT]\033[0m Enter Age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "\n\033[1;31m[ERROR]\033[0m Invalid input! Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\033[1;36m[INPUT]\033[0m Enter IC Number (XXXXXX-XX-XXXX): ";
    getline(cin, ic);

    cout << "\033[1;36m[INPUT]\033[0m Enter Gender (Male/Female): ";
    getline(cin, gender);

    cout << "\033[1;36m[INPUT]\033[0m Enter Contact Number (without -): ";
    getline(cin, contact);

    cout << "\033[1;36m[INPUT]\033[0m Enter Admission Reason: ";
    getline(cin, reason);

    cout << "\033[1;36m[INPUT]\033[0m Enter Admission Date (DD/MM/YYYY): ";
    getline(cin, date);

    file << name << "," << age << "," << ic << "," << gender << "," << contact << "," << reason << "," << date << ",W" << ward << endl;
    file.close();

    cout << "\n\033[1;32m[SUCCESS]\033[0m Patient admitted successfully! Assigned ward number: W" << ward << "\n";
}