// Programmers: 
// Purpose: Function to handle searching record sub-menu.

#include <iostream>
#include <string>
#include "search.cpp"
#include "search.hpp"
#include "display.cpp"
#include "display.hpp"
#include "S_R_Menu.hpp"

using namespace std;

// Function to display the Searching Record menu with a box design
void displaySearchingRecordMenu() {
    cout << "\033[1;34m\n";
    cout << "==============================================\n";
    cout << "|        \033[1;33m--- Searching Record Menu ---          \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "|  \033[0;33m1. Search Patient                            \033[1;34m|\n";
    cout << "|  \033[0;33m2. Display All Records                       \033[1;34m|\n";
    cout << "|  \033[1;31m3. Return to Main Menu                       \033[1;34m|\n";
    cout << "==============================================\n";
    cout << "\033[1;36mEnter your choice > \033[0m";
}

// Function for handling the Searching Record menu
void searchingRecordMenu() {
    string input;
    int choice;

    while (true) {
        displaySearchingRecordMenu();

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
                searchMenu();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                return; // Exit to main menu
            default:
                cout << "\033[1;31m\nInvalid choice! Please enter a number between 1 and 3.\033[0m\n";
                break;
        }
    }
}
