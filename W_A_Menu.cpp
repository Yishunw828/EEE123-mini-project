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
 
void wardAdmissionMenu() { 
    string input; 
    int choice; 
 
    while (true) { 
        cout << "\nPlease select the number\n"; 
        cout << "1. Admit Patient\n"; 
        cout << "2. Remove Patient\n"; 
        cout << "3. Return to Main Menu\n"; 
        cout << "\nEnter your choice: "; 
         
        cin >> input;  
 
        bool isValid = true; 
        for (char ch : input) { 
            if (!isdigit(ch)) { 
                isValid = false; 
                break; 
            } 
        } 
 
        if (!isValid) { 
            cout << "\nInvalid input! Please enter a valid number.\n"; 
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
                cout << "\nInvalid choice! Please enter a number between 1 and 3.\n"; 
        } 
    } 
}