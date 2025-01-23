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

// Function to display the Ward Admission menu with a box design
void displayWardAdmissionMenu() {
    cout << "\033[1;34m\n";
    cout << "==============================================\n";
    cout << "|         \033[1;35m--- Ward Admission Menu ---          \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "|  \033[0;35m1. Admit Patient                            \033[1;34m|\n";
    cout << "|  \033[0;35m2. Remove Patient                           \033[1;34m|\n";
    cout << "|  \033[1;31m3. Return to Main Menu                      \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "\033[1;36mEnter your choice > \033[0m";
}

// Function for handling the Ward Admission Menu
void wardAdmissionMenu() {
    string input;
    int choice;

    while (true) {
        displayWardAdmissionMenu();

        cin >> input;

        // Validate input
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

        // Process menu choice
        switch (choice) {
            case 1:
                admitPatient();
                break;
            case 2:
                removePatient();
                break;
            case 3:
                return; // Exit to main menu
            default:
                cout << "\033[1;31m\nInvalid choice! Please enter a number between 1 and 3.\033[0m\n";
        }
    }
}
