#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct PatientRecord {
    string name;
    int age;
    string icNumber;
    string gender;
    string contactNumber;
    string reasonForAdmission;
    string ward;
};

vector<PatientRecord> loadPatientList(const string& filename) {
    vector<PatientRecord> patients;
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        return patients;
    }

    PatientRecord patient;
    while (infile) {
        getline(infile, patient.name);
        if (patient.name.empty()) break; 

        infile >> patient.age;
        infile.ignore(); 
        getline(infile, patient.icNumber);
        getline(infile, patient.gender);
        getline(infile, patient.contactNumber);
        getline(infile, patient.reasonForAdmission);
        getline(infile, patient.ward);
        infile.ignore(); 

        patients.push_back(patient);
    }

    infile.close();
    return patients;
}

void searchPatientByName(const vector<PatientRecord>& patients, const string& name) {
    bool found = false;
    for (const auto& patient : patients) {
        if (patient.name == name) {
            cout << "Patient found:\n";
            cout << "Name: " << patient.name << "\n";
            cout << "Age: " << patient.age << "\n";
            cout << "IC Number: " << patient.icNumber << "\n";
            cout << "Gender: " << patient.gender << "\n";
            cout << "Contact Number: " << patient.contactNumber << "\n";
            cout << "Reason for Admission: " << patient.reasonForAdmission << "\n";
            cout << "Ward: " << patient.ward << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Patient with name '" << name << "' not found.\n";
    }
}

void searchPatientByWard(const vector<PatientRecord>& patients, const string& ward) {
    bool found = false;
    for (const auto& patient : patients) {
        if (patient.ward == ward) {
            cout << "Patient found:\n";
            cout << "Name: " << patient.name << "\n";
            cout << "Age: " << patient.age << "\n";
            cout << "IC Number: " << patient.icNumber << "\n";
            cout << "Gender: " << patient.gender << "\n";
            cout << "Contact Number: " << patient.contactNumber << "\n";
            cout << "Reason for Admission: " << patient.reasonForAdmission << "\n";
            cout << "Ward: " << patient.ward << "\n";
            cout << "---------------------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No patients found in ward '" << ward << "'.\n";
    }
}

int main() {
    string filename = "patients.txt";
    vector<PatientRecord> patients = loadPatientList(filename);

    if (patients.empty()) {
        cerr << "No patient records found or could not load the file.\n";
        return 1;
    }

    int choice;
    do {
        cout << "\n=== Ward Admission System ===\n";
        cout << "1. Search for a patient by name\n";
        cout << "2. Search for patients by ward\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from input buffer

        switch (choice) {
            case 1: {
                string name;
                cout << "Enter the name of the patient to search: ";
                getline(cin, name);
                searchPatientByName(patients, name);
                break;
            }
            case 2: {
                string ward;
                cout << "Enter the ward number to search: ";
                getline(cin, ward);
                searchPatientByWard(patients, ward);
                break;
            }
            case 3:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
