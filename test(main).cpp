#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    WardAdmissionSystem system;
    int choice;

    do {
        cout << "\n---------------------------------------------\n";
        cout << "Welcome to the Ward Admission System\n";
        cout << "1. Add a New Patient Record\n";
        cout << "2. Display All Patient Records\n";
        cout << "3. Search Patient Records\n";
        cout << "4. Exit\n";
        cout << "---------------------------------------------\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
        case 1: {
            string name, icNumber, gender, contactNumber, reason, ward;
            int age;

            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter patient age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter patient IC number(without -): ";
            getline(cin, icNumber);
            cout << "Enter patient gender (Male/Female): ";
            getline(cin, gender);
            cout << "Enter patient contact number(without -): ";
            getline(cin, contactNumber);
            cout << "Enter reason for admission: ";
            getline(cin, reason);
            cout << "Enter ward number: ";
            getline(cin, ward);

            system.addRecord(name, age, icNumber, gender, contactNumber, reason, ward);
            break;
        }
        case 2:
            system.displayAllRecords();
            break;
        case 3: {
            string name, ward;
            cout << "Enter patient name to search : ";
            getline(cin, name);
            cout << "Enter ward number to search : ";
            getline(cin, ward);

            system.searchRecords(name, ward);
            break;
        }
        case 4:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

struct PatientRecord {
    string name;
    int age;
    string icNumber;
    string gender;
    string contactNumber;
    string reasonForAdmission;
    string ward;
};

class WardAdmissionSystem {
private:
    vector<PatientRecord> records;

public:
    void addRecord(const string& name, int age, const string& icNumber, const string& gender, const string& contactNumber, const string& reason, const string& ward) {
        records.push_back({name, age, icNumber, gender, contactNumber, reason, ward});
        cout << "Patient record added successfully!\n";
    }

    void displayAllRecords() {
        if (records.empty()) {
            cout << "No records to display.\n";
            return;
        }

        cout << "\nAll Patient Records:\n";
        cout << "---------------------------------------------\n";
        for (const auto& record : records) {
            cout << "Name: " << record.name << "\n";
            cout << "Age: " << record.age << "\n";
            cout << "IC Number: " << record.icNumber << "\n";
            cout << "Gender: " << record.gender << "\n";
            cout << "Contact Number: " << record.contactNumber << "\n";
            cout << "Reason for Admission: " << record.reasonForAdmission << "\n";
            cout << "Ward: " << record.ward << "\n";
            cout << "---------------------------------------------\n";
        }
    }

    void searchRecords(const string& searchName = "", const string& searchWard = "") {
        cout << "\nSearch Results:\n";
        bool found = false;

        for (const auto& record : records) {
            if ((searchName.empty() || record.name.find(searchName) != string::npos) &&
                (searchWard.empty() || record.ward == searchWard)) {
                found = true;
                cout << "Name: " << record.name << "\n";
                cout << "Age: " << record.age << "\n";
                cout << "IC Number: " << record.icNumber << "\n";
                cout << "Gender: " << record.gender << "\n";
                cout << "Contact Number: " << record.contactNumber << "\n";
                cout << "Reason for Admission: " << record.reasonForAdmission << "\n";
                cout << "Ward: " << record.ward << "\n";
                cout << "---------------------------------------------\n";
            }
        }

        if (!found) {
            cout << "No records found matching the criteria.\n";
        }
    }
};

