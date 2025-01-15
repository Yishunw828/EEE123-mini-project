#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Add_Patient {
private:
    static int Patient_Index; 
    void getLastPatientIndex();

public:
    string name, icNumber, gender, contactNumber, reason, ward;
    int age;

    Add_Patient() {
        if (Patient_Index == 0) {
            getLastPatientIndex();
        }
    }

    int getIndex() const { return Patient_Index; }

    void savePatientDetails() {
        cout << "Enter patient name: ";
        cin.ignore ();
        getline(cin, name);

        cout << "Enter patient age: ";
        cin >> age;
        while (age <= 0) { 
            cout << "Invalid age. Enter a valid age: ";
            cin >> age;
            cin.ignore();
        }

        cout << "Enter patient IC number (without -): ";
        getline(cin, icNumber);

        cout << "Enter patient gender (Male/Female): ";
        getline(cin, gender);
        while (gender != "Male" && gender != "Female") { 
            cout << "Invalid gender. Enter Male or Female: ";
            getline(cin, gender);
        }

        cout << "Enter patient contact number (without -): ";
        getline(cin, contactNumber);

        cout << "Enter reason for admission: ";
        getline(cin, reason);

        cout << "Enter ward number: ";
        getline(cin, ward);

        Patient_Index++;
        savePatientToFile(name, age, icNumber, gender, contactNumber, reason, ward);
    }

    void savePatientToFile(const string& name, int age, const string& icNumber, 
                           const string& gender, const string& contactNumber, 
                           const string& reason, const string& ward) {
        ofstream outfile("patients.txt", ios::app); 
        if (outfile.is_open()) {
            outfile << Patient_Index << endl;
            outfile << name << endl;
            outfile << age << endl;
            outfile << icNumber << endl;
            outfile << gender << endl;
            outfile << contactNumber << endl;
            outfile << reason << endl;
            outfile << ward << endl;
            outfile << "-----" << endl; // 
            outfile.close();
            cout << "Patient data saved to file.\n";
        } else {
            cout << "Error: Unable to open file for saving.\n";
        }
    }
};

int Add_Patient::Patient_Index = 0;

void Add_Patient::getLastPatientIndex() {
    ifstream infile("patients.txt");
    if (!infile.is_open()) {
        Add_Patient::Patient_Index = 0; 
        return;
    }

    string line;
    int lastIndex = 0;
    while (getline(infile, line)) {
        lastIndex = stoi(line); 
        for (int i = 0; i < 7; ++i) getline(infile, line); 
    }

    infile.close();
    Add_Patient::Patient_Index = lastIndex;
}

