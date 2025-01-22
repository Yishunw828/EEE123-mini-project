// Programmers: 
// Purpose: Function to handle ward admission sub-menu.

// Programmers:  
// Purpose: Function to handle ward admission sub-menu. 
 
#include <iostream> 
#include <string> 
#include "admission.cpp" 
#include "admission.hpp" 
#include "remove.cpp" 
#include "remove.hpp" 
#include "W_A_Menu.hpp" 

using namespace std; 

void displayWardAdmissionMenu() {
    cout << "\033[1;34m\n--- Ward Admission Menu ---\033[0m\n"; 
    cout << "\033[1;32m1. Admit Patient\033[0m\n"; 
    cout << "\033[1;33m2. Remove Patient\033[0m\n"; 
    cout << "\033[1;31m3. Return to Main Menu\033[0m\n"; 
    cout << "\033[1;36m\nEnter your choice > \033[0m"; 
}

void wardAdmissionMenu() { 
    string input; 
    int choice; 

    while (true) { 
        displayWardAdmissionMenu(); 

        cin >> input;  

        bool isValid = true; 
        for (char ch : input) { 
            if (!isdigit(ch)) { 
                isValid = false; 
                break; 
            } 
        } 

        if (!isValid) { 
            cout << "\033[1;31m\nInvalid input! Please enter a valid number.\033[0m\n"; 
            continue;  
        } 

        choice = stoi(input); 

        switch (choice) { 
            case 1: 
                admitPatient(); 
                break; 
            case 2: 
                removePatient(); 
                break; 
            case 3: 
                return; 
            default: 
                cout << "\033[1;31m\nInvalid choice! Please enter a number between 1 and 3.\033[0m\n"; 
        } 
    } 
}
