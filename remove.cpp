// Programmers: 
// Purpose: Function to remove a patient from patients.txt by name.

#include <iostream>
#include <fstream>
#include <sstream>
#include "remove.hpp"

using namespace std;

void removePatient() {
    string nameToRemove;
    cout << "\nEnter patient name to remove: ";
    cin.ignore();
    getline(cin, nameToRemove);

    ifstream file("patients.txt");
    if (!file) {
        cout << "Error opening file or no records found!" << endl;
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
        cout << "Patient '" << nameToRemove << "' has been removed successfully.\n";
    } else {
        remove("temp.txt"); 
        cout << "Patient not found!\n";
    }
}