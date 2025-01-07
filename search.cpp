#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

class WardAdmissionSystem {
private:
    vector<PatientRecord> records;

public:
    void addRecord(const string& name, int age, const string& icNumber, const string& gender, const string& contactNumber, const string& reason, const string& ward) {
        records.push_back({name, age, icNumber, gender, contactNumber, reason, ward});
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
                cout << "----------------------------------------\n";
            }
        }

        if (!found) {
            cout << "No records found matching the criteria.\n";
        }
    }
};

int main() {
    WardAdmissionSystem system;

    system.addRecord("Katheline", 27, "980421042156", "Female", "011-41552364", "Fracture Treatment", "2120");
    system.addRecord("Ahmad Falli", 21, "040526018333", "Male", "017-2542654", "Heart Surgery", "1423");

    cout << "---------------------------------------------" << endl;
    cout << "Welcome to the Ward Admission System\n";

    string name, ward;
    cout << "Enter patient name to search: ";
    getline(cin, name);
    cout << "Enter ward number to search: ";
    getline(cin, ward);

    system.searchRecords(name, ward);

    return 0;
}
