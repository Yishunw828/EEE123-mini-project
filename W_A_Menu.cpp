#include <iostream>
#include <string>
#include "W_A_Menu.hpp" 
#include "admission.cpp"
#include "admission.hpp"
#include "remove.cpp"
#include "remove.hpp"

using namespace std;

// Programmers: Nick Wong Paul Ian
// Matric No. : 23305339
// Purpose: Display the ward admission menu and process user choices.
void wardAdmissionMenu() {
    string input;
    int choice;

    while (true) {
        cout << "\033[1;34m\n";
        cout << "==============================================\n";
        cout << "|         \033[1;35m--- Ward Admission Menu ---          \033[1;34m|\n";
        cout << "==============================================\n";
        cout << "|  \033[0;35m1. Admit Patient                            \033[1;34m|\n";
        cout << "|  \033[0;35m2. Remove Patient                           \033[1;34m|\n";
        cout << "|  \033[1;31m3. Return to Main Menu                      \033[1;34m|\n";
        cout << "==============================================\n";
        cout << "\033[1;36mEnter your choice > \033[0m";

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
