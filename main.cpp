// Programmers: 
// Purpose: Main program to handle ward admission and record searching.

#include <iostream>
#include "W_A_Menu.cpp"
#include "W_A_Menu.hpp"
#include "S_R_Menu.cpp"
#include "S_R_Menu.hpp"

using namespace std;

int main() {
    int choice;
    bool running = true; 

    while (running) {
        cout << "\n=== Ward Admission and Searching Record System ===\n";
        cout << "1. Ward Admission\n";
        cout << "2. Searching Record\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice > ";
        cin >> choice;

        switch (choice) {
            case 1:
                wardAdmissionMenu();
                break;
            case 2:
                searchingRecordMenu();
                break;
            case 3:
                cout << "\nExiting system...\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice! Please enter again.\n";
        }
    }

    return 0;
}
