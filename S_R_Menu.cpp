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
 
void searchingRecordMenu() { 
    string input; 
    int choice; 
 
    while (true) { 
        cout << "\n--- Searching Record Menu ---\n"; 
        cout << "1. Search Patient\n"; 
        cout << "2. Display All Records\n"; 
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
                searchMenu(); 
                break; 
            case 2: 
                displayAllRecords(); 
                break; 
            case 3: 
                return;  
            default: 
                cout << "\nInvalid choice! Please enter a number between 1 and 3.\n"; 
                break; 
        } 
    } 
}
