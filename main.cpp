#include <iostream>
#include <string>
#include "main.hpp"

using namespace std;

const int MAX_PATIENTS = 100; 


struct Patient {
    string name;
    int age;
    string icNumber; 
    string gender;
    string contactNumber;
    string admissionReason;
    string wardNumber;
};


void registerPatient(Patient patients[], int &count) {
    if (count >= MAX_PATIENTS) {
        cout << " Maximum capacity reached.\n";
        return;
    }

    Patient newPatient;

cout << "Enter patient name: ";
cin.ignore(); 
getline(cin, newPatient.name);

cout << "Enter patient age: ";
cin >> newPatient.age;

cout << "Enter patient IC number: ";
cin >> newPatient.icNumber;

cout << "Enter patient gender : ";
cin >> newPatient.gender;

cout << "Enter patient contact number: ";
cin >> newPatient.contactNumber;

cout << "Enter reason for admission: ";
cin >> newPatient.admissionReason;

cout << "Enter ward number: ";
cin >> newPatient.wardNumber;

    patients[count] = newPatient;
    count++;

    cout << "Patient registered successfully!\n\n";
}


void displayPatients(const Patient patients[], int count) {
    if (count == 0) {
        cout << "No patients registered yet.\n";
        return;
    }

    cout << "\nRegistered Patients:\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << "Patient " << i + 1 << ":\n";
        cout << "Name: " << patients[i].name << "\n";
        cout << "Age: " << patients[i].age << "\n";
        cout << "IC Number: " << patients[i].icNumber << "\n";
        cout << "Gender: " << patients[i].gender << "\n";
        cout << "Contact Number: " << patients[i].contactNumber << "\n";
        cout << "Reason for Admission: " << patients[i].admissionReason << "\n";
        cout << "Ward Number: " << patients[i].wardNumber << "\n";
        cout << "---------------------------------------------\n";
    }
}

int main() {
    Patient patients[MAX_PATIENTS];
    int patientCount = 0;
    int choice;

    do {
        cout << "\nWard Admission System\n";
        cout << "1. Register a new patient\n";
        cout << "2. Display all patients\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient(patients, patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                cout << "System exited.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
