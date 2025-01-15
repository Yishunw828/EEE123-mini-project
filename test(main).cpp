#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "AddPatient.cpp"
#include "Display_Patient.cpp"

using namespace std;

class WardAdmissionSystem {
public:
    void Add_Patient();
 
struct PatientRecord {
    string name;
    int age;
    string icNumber;
    string gender;
    string contactNumber;
    string reasonForAdmission;
    string ward;
};
PatientRecord record;
 vector<PatientRecord> records;
    void loadRecordsFromFile() {
        ifstream infile("patients.txt");
        if (!infile.is_open()) {
            cout << "No existing patient records found.\n";
            return;
        }

        else {
        string line;
        while (getline(infile, line)) {
            
            record.name = line;
            getline(infile, line);
            record.age = stoi(line);
            getline(infile, record.icNumber);
            getline(infile, record.gender);
            getline(infile, record.contactNumber);
            getline(infile, record.reasonForAdmission);
            getline(infile, record.ward);
            records.push_back(record);
        }

        infile.close();
        }
    }

    void saveRecordsToFile() const {
        ofstream outfile("patients.txt",ios::app);
        if (!outfile.is_open()) {
            cout << "Error: Unable to save records to file.\n";
            return;
        }
    
    
    else{
            outfile << record.name << "\n";
            outfile << record.age << "\n";
            outfile << record.icNumber << "\n";
            outfile << record.gender << "\n";
            outfile << record.contactNumber << "\n";
            outfile << record.reasonForAdmission << "\n";
            outfile << record.ward << "\n";
        

        outfile.close();
    }
    }
    
    void displayAllRecords() const {
        if (records.empty()) {
            cout << "No patient records available.\n";
            return;
        }

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

int main() {
    WardAdmissionSystem system;
    system.loadRecordsFromFile();

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
        cin.ignore();

        switch (choice) {
        case 1:
            system.Add_Patient();
            break;

        case 2:
            system.displayAllRecords();
            break;

        case 3: {
            string name, ward;
            cout << "Enter patient name to search: ";
            getline(cin, name);
            cout << "Enter ward number to search: ";
            getline(cin, ward);

            system.searchRecords(name, ward);
            break;
        }

        case 4:
            system.saveRecordsToFile();
            cout << "Exiting the system.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
