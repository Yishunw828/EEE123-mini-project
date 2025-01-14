#include <iostream>
#include <string>
#include <limits>
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

bool isValidNumber(const string &input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isValidGender(const string &gender) {
    return gender == "Male" ; gender == "Female" ; gender == "male" || gender == "female";
}

void registerPatient(Patient patients[], int &count) {
    if (count >= MAX_PATIENTS) {
        cout << "Maximum capacity reached.\n";
        return;
    }

    Patient newPatient;

    cout << "Enter patient name: ";
    cin.ignore(); 
    getline(cin, newPatient.name);
    while (newPatient.name.empty()) {
        cout << "Name cannot be empty. Enter patient name: ";
        getline(cin, newPatient.name);
    }

    string ageInput;
    cout << "Enter patient age: ";
    cin >> ageInput;
    while (!isValidNumber(ageInput)) {
        cout << "Invalid age. Enter a numeric value for age: ";
        cin >> ageInput;
    }
    newPatient.age = stoi(ageInput);

    cout << "Enter patient IC number(without -): ";
    cin >> newPatient.icNumber;
    while (!isValidNumber(newPatient.icNumber)) {
        cout << "Invalid IC number. Enter a numeric value: ";
        cin >> newPatient.icNumber;
    }

    cout << "Enter patient gender (Male/Female): ";
    cin >> newPatient.gender;
    while (!isValidGender(newPatient.gender)) {
        cout << "Invalid gender. Enter 'Male' or 'Female': ";
        cin >> newPatient.gender;
    }

    cout << "Enter patient contact number(XXX-XXXXXXX): ";
    cin >> newPatient.contactNumber;
    while (!isValidNumber(newPatient.contactNumber)) {
        cout << "Invalid contact number. Enter a numeric value: ";
        cin >> newPatient.contactNumber;
    }

    cout << "Enter reason for admission: ";
    cin.ignore(); 
    getline(cin, newPatient.admissionReason);

    cout << "Enter ward number(XXXX): ";
    getline(cin, newPatient.wardNumber);

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
        cout << "\nMenu of the system";
        cout << "\n1. Ward Admission System";
        cout << "\n2. Seaching Record";
        cout << "\n3. Exit";
        cout << "\n\nEnter the number for the system > \n";

        switch (choice) {
            case 1:
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
    } while (choice != 3);;
                break;
            case 2:
                ;
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