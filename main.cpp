#include <iostream>
#include <string>
#include "W_A_Menu.cpp"
#include "W_A_Menu.hpp"
#include "S_R_Menu.cpp"
#include "S_R_Menu.hpp"

using namespace std;

// Programmers: Muhammad Ammer Asyraff bin Mohd Farid
// Matric No. : 22306881
// Purpose: Run the main menu of system and handle user choices.
int main() {
    bool running = true;

    while (running) {
        cout << "\033[1;34m\n";
        cout << "========================================================\n";
        cout << "|  \033[1;36m=== Ward Admission and Searching Record System ===\033[1;34m  |\n";
        cout << "========================================================\n";
        cout << "|  \033[1;35m1. Ward Admission                               \033[1;34m    |\n";
        cout << "|  \033[1;33m2. Searching Record                            \033[1;34m     |\n";
        cout << "|  \033[1;31m3. Exit                                        \033[1;34m     |\n";
        cout << "========================================================\n";
        cout << "\033[1;36mEnter your choice > \033[0m";

        string input;
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

        int choice = stoi(input);

        switch (choice) {
            case 1:
                wardAdmissionMenu();
                break;
            case 2:
                searchingRecordMenu();
                break;
            case 3:
                cout << "\033[1;31m\nExiting system...\033[0m\n";
                running = false;
                break;
            default:
                cout << "\033[1;31m\nInvalid choice! Please enter a number between 1 and 3.\033[0m\n";
                break;
        }
    }

    return 0;
}

