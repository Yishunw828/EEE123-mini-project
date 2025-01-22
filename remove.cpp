// Programmers: 
// Purpose: Function to remove a patient from patients.txt by name.

#include <iostream>
#include <fstream>
#include <sstream>
#include "remove.hpp"

using namespace std;

void removePatient() {
    string nameToRemove;
    cout << "\033[1;36m\nEnter patient name to remove: \033[0m";
    cin.ignore();
    getline(cin, nameToRemove);

    ifstream file("patients.txt");
    if (!file) {
        cout << "\033[1;31mError opening file or no records found!\033[0m" << endl;
        return;
    }

    ofstream tempFile("temp.txt"); 
    string line;
    bool found = false;

    while (getline(file, line)) {
        istringstream record(line);
        string name;
        getline(record, name, ',');

        if (name != nameToRemove) {
            tempFile << line << endl; 
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("patients.txt");          
        rename("temp.txt", "patients.txt"); 
        cout << "\033[1;32mPatient '" << nameToRemove << "' has been removed successfully.\033[0m\n";
    } else {
        remove("temp.txt"); 
        cout << "\033[1;31mPatient not found!\033[0m\n";
    }
}
