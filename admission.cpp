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
                    cerr << "\033[1;31mError: Invalid ward number format in file:\033[0m " << wardStr << endl;
                } catch (const out_of_range&) {
                    cerr << "\033[1;31mError: Ward number out of range in file:\033[0m " << wardStr << endl;
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
        cout << "\033[1;31mError opening file!\033[0m" << endl;
        return;
    }

    srand(time(0));  

    set<int> assignedWards = getAssignedWards(); 
    int ward = assignRandomWard(assignedWards);  

    if (ward == -1) {
        cout << "\033[1;31mAll ward numbers are occupied. Cannot admit new patients!\033[0m" << endl;
        return;
    }

    string name, ic, gender, contact, reason, date;
    int age;

    cout << "\033[1;36m\nEnter Patient Full Name as per IC: \033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "\033[1;36mEnter Age: \033[0m";
    while (!(cin >> age) || age <= 0) {
        cout << "\033[1;31mInvalid input! Enter a valid age: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\033[1;36mEnter IC Number (XXXXXX-XX-XXXX): \033[0m";
    getline(cin, ic);

    cout << "\033[1;36mEnter Gender (Male/Female): \033[0m";
    getline(cin, gender);

    cout << "\033[1;36mEnter Contact Number (without -): \033[0m";
    getline(cin, contact);

    cout << "\033[1;36mEnter Admission Reason: \033[0m";
    getline(cin, reason);

    cout << "\033[1;36mEnter Admission Date (DD/MM/YYYY): \033[0m";
    getline(cin, date);

    file << name << "," << age << "," << ic << "," << gender << "," << contact << "," << reason << "," << date << ",W" << ward << endl;
    file.close();

    cout << "\033[1;32m\nPatient admitted successfully! Assigned ward number: W" << ward << "\033[0m\n";
}
