#include <iostream>
#include <string>
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

cout << "\nEnter patient name: ";
cin.ignore(); 
getline(cin, newPatient.name);

cout << "Enter patient age: ";
cin >> newPatient.age;

cout << "Enter patient IC number (without -): ";
cin >> newPatient.icNumber;

cout << "Enter patient gender (Male/Female): ";
cin >> newPatient.gender;

cout << "Enter patient contact number (XXX-XXXXXXX): ";
cin >> newPatient.contactNumber;

cout << "Enter reason for admission: ";
cin >> newPatient.admissionReason;

cout << "Enter ward number (XXXX): ";
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

void displayMenu() {
    cout << "\n===== Ward Admission System =====" << endl;
    cout << "1. Add Admission Note" << endl;
    cout << "2. View All Admission Notes" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int addAdmissionNote(string patientNames[], string reasons[], int count, int maxNotes) {
    if (count >= maxNotes) {
        cout << "\nMaximum number of admission notes reached!" << endl;
        return count;
    }

    cin.ignore();

    cout << "Enter patient name: ";
    getline(cin, patientNames[count]);

    cout << "Enter reason for admission: ";
    getline(cin, reasons[count]);

    cout << "\nAdmission note added successfully!" << endl;
    return count + 1;
}

void viewAdmissionNotes(const string patientNames[], const string reasons[], int count) {
    if (count == 0) {
        cout << "\nNo admission notes available." << endl;
        return;
    }

    cout << "\n===== Admission Notes =====" << endl;
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". Patient Name: " << patientNames[i] << endl;
        cout << "   Reason: " << reasons[i] << endl;
    }
}

int main() {
    Patient patients[MAX_PATIENTS];
    int patientCount = 0;
    int choice;
    const int maxNotes = 100;
    string patientNames[maxNotes];
    string reasons[maxNotes];
    int count = 0;


    do {
        cout << "\n---------------------------------------------\n";
        cout << "Ward Admission System\n";
        cout << "1. Register a new patient\n";
        cout << "2. Display all patients\n";
        cout << "3. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "\nEnter your choice > ";
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
    
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                count = addAdmissionNote(patientNames, reasons, count, maxNotes);
                break;
            case 2:
                viewAdmissionNotes(patientNames, reasons, count);
                break;
            case 3:
                cout << "\nExiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

