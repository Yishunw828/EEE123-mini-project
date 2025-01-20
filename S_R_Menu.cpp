// Programmers: 
// Purpose: Function to handle searching record sub-menu.

#include <iostream>
#include "search.cpp"
#include "search.hpp"
#include "display.cpp"
#include "display.hpp"
#include "S_R_Menu.hpp"

using namespace std;

void searchingRecordMenu() {
    int choice;
    while (true) {
        cout << "\n--- Searching Record Menu ---\n";
        cout << "1. Search Patient\n";
        cout << "2. Display All Records\n";
        cout << "3. Return to menu\n";
        cout << "\nEnter your choice > ";
        cin >> choice;

        switch (choice) {
            case 1:
                searchMenu();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                return; 
                cout << "Invalid choice! Please enter again.\n";
        }
    }
}