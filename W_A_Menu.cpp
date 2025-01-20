// Programmers: 
// Purpose: Function to handle ward admission sub-menu.

#include <iostream>
#include "admission.cpp"
#include "admission.hpp"
#include "remove.cpp"
#include "remove.hpp"
#include "W_A_Menu.hpp"

using namespace std;

void wardAdmissionMenu() {
    int choice;
    while (true) {
        cout << "\nPlease select the number\n";
        cout << "1. Admit Patient\n";
        cout << "2. Remove Patient\n";
        cout << "3. Return to menu\n";
        cout << "\nEnter your choice > ";
        cin >> choice;

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
                cout << "\nInvalid choice! Please enter again.\n";
        }
    }
}