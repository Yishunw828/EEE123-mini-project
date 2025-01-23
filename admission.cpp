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
 
const int MAX_WARD = 899; 
 
bool isValidName(const string& name) { 
    if (name.empty()) return false; 
    for (char c : name) { 
        if (!isalpha(c) && c != ' ') return false; 
    } 
    return true; 
} 
 
string getValidName() {
    string name;
    cout << "\033[1;36m\nEnter Patient Full Name as per IC: \033[0m";

    while (true) {
        getline(cin, name);

        if (isValidName(name)) break; 
        cout << "\033[1;31mInvalid input! Name must contain only alphabets and spaces. Please try again: \033[0m";
    }
    return name;
}

bool isValidIC(const string& ic) {
    if (ic.length() != 14) return false;
    
    for (int i = 0; i < ic.length(); i++) {
        if ((i == 6 || i == 9)) {  
            if (ic[i] != '-') return false;
        } else {  
            if (!isdigit(ic[i])) return false;
        }
    }
    return true;
}

string getValidIC() {
    string ic;
    cout << "\033[1;36mEnter IC Number (XXXXXX-XX-XXXX): \033[0m";
    while (true) {
        getline(cin, ic);
        if (isValidIC(ic)) break;
        
        cout << "\033[1;31mInvalid input! Enter a valid IC Number (XXXXXX-XX-XXXX): \033[0m";
    }
    return ic;
}

bool isValidContact(const string& contact) {
    for (char c : contact) {
        if (!isdigit(c)) return false;
    }
    return !contact.empty();  
}

string getValidContact() {
    string contact;
    cout << "\033[1;36mEnter Contact Number (without -): \033[0m";
    
    while (true) {
        getline(cin, contact);
        
        if (isValidContact(contact)) break;

        cout << "\033[1;31mInvalid input! Enter a valid contact number (digits only): \033[0m";
    }
    return contact;
}

bool isValidReason(const string& reason) {
    for (char c : reason) {
        if (isdigit(c)) return false;  
    }
    return !reason.empty();  
}

string getValidReason() {
    string reason;
    cout << "\033[1;36mEnter Admission Reason: \033[0m";

    while (true) {
        getline(cin, reason);

        if (isValidReason(reason)) break;  
        cout << "\033[1;31mInvalid input! Reason must contain only alphabets and spaces. Please enter again: \033[0m";
    }
    return reason;
}
 
bool isValidDate(const std::string& date) { 
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

 
string getValidDate() {
    string date;
    cout << "\033[1;36mEnter Admission Date (DD/MM/YYYY): \033[0m";

    while (true) {
        getline(cin, date);

        if (isValidDate(date)) break;
        cout << "\033[1;31mInvalid input! Date must be in the format DD/MM/YYYY. Please try again: \033[0m";
    }
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
                    if (ward >= 101 && ward <= 999) {  
                        assignedWards.insert(ward); 
                    }
                } catch (...) {} 
            } 
        } 
    } 
    return assignedWards; 
} 
 
int assignRandomWard(const set<int>& assignedWards) { 
    if (assignedWards.size() >= 899) return -1;  
    int ward; 
    do { 
        ward = rand() % 899 + 101;  
    } while (assignedWards.find(ward) != assignedWards.end()); 
    return ward; 
}

void admitPatient() { 
    ofstream file("patients.txt", ios::app); 
    if (!file) { 
        cerr << "\033[1;31mError opening file!\033[0m\n"; 
        return; 
    } 
 
    srand(time(0)); 
    set<int> assignedWards = getAssignedWards(); 
    int ward = assignRandomWard(assignedWards); 
    if (ward == -1) { 
        cout << "\033[1;31mAll ward numbers are occupied. Cannot admit new patients!\033[0m\n"; 
        return; 
    } 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    string name = getValidName(); 
     
    int age;
    cout << "\033[1;36mEnter Age: \033[0m";
    while (!(cin >> age) || age <= 0 || age > 100) 
    {
        cout << "\033[1;31mInvalid input! Age must be between 0 and 100: \033[0m";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    string ic = getValidIC();
 
    string gender, wardPrefix; 
    cout << "\033[1;36mEnter Gender (Male/Female): \033[0m"; 
    while (true) { 
        getline(cin, gender); 
        if (gender == "Male" || gender == "Female") { 
            wardPrefix = (gender == "Male") ? "WMA" : "WFE"; 
            break; 
        } 
        cout << "\033[1;31mInvalid input! Please enter Male or Female: \033[0m"; 
    } 
 
    string contact  = getValidContact();
 
    string reason = getValidReason();
    
    string date = getValidDate(); 
    file << name << "," << age << "," << ic << "," << gender << "," << contact << "," << reason << "," << date << "," << wardPrefix << ward << endl; 
    file.close(); 
 
    cout << "\033[1;32m\nPatient admitted successfully! Assigned ward number: \033[0m" << wardPrefix << ward << "\n"; 
}