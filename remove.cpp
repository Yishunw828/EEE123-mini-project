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

    ofstream tempFile("temp.txt"); // Temporary file to store updated records
    string line;
    bool found = false;

    while (getline(file, line)) {
        istringstream record(line);
        string name;
        getline(record, name, ',');

        if (name != nameToRemove) {
            tempFile << line << endl; // Keep the record if it's not the one to remove
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("patients.txt");          // Delete old file
        rename("temp.txt", "patients.txt"); // Rename temp file to original
        cout << "Patient '" << nameToRemove << "' has been removed successfully.\n";
    } else {
        remove("temp.txt"); // Clean up if no match found
        cout << "Patient not found!\n";
    }
}
