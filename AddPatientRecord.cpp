#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Add_Patient {
private:
    void getLastPatientIndex(); 

public:
    string name;
    string icNumber;
    string gender;
    string contactNumber;
    string reasonForAdmission;
    string ward;
    static int Patient_Index;

    Add_Patient() {
        if (Patient_Index == 0) { 
            getLastPatientIndex(); 
        }
    }

    int getIndex() const { return Patient_Index; }

    void savePatientDetails() {   
        cout << "Enter patient name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter IC number: ";
        getline(cin, icNumber);

        cout << "Enter gender (Male/Female): ";
        getline(cin, gender);

        cout << "Enter contact number: ";
        getline(cin, contactNumber);

        cout << "Enter reason for admission: ";
        getline(cin, reasonForAdmission);

        cout << "Enter ward number: ";
        getline(cin, ward);

        Patient_Index++;
        savePatientToFile(name, icNumber, gender, contactNumber, reasonForAdmission, ward, Patient_Index); 
    }

    void savePatientToFile(const string& name, const string& icNumber, const string& gender, 
                           const string& contactNumber, const string& reason, const string& ward, int& index);

};

int Add_Patient::Patient_Index = 0;

void Add_Patient::getLastPatientIndex() {
    ifstream infile("patients.txt");
    string line;
    int lastIndex = 0;

    while (getline(infile, line)) {
        lastIndex = stoi(line); 
        getline(infile, line); 
        getline(infile, line);
        getline(infile, line);
        getline(infile, line);
        getline(infile, line);
        getline(infile, line);
    }

    infile.close();
    Add_Patient::Patient_Index = lastIndex; 
}

void Add_Patient::savePatientToFile(const string& name, const string& icNumber, const string& gender, 
                                    const string& contactNumber, const string& reason, const string& ward, int& index) {
    ofstream outfile("patients.txt", ios::app); 
    if (outfile.is_open()) { 
        outfile << index << endl;
        outfile << name << endl;
        outfile << icNumber << endl;
        outfile << gender << endl;
        outfile << contactNumber << endl;
        outfile << reason << endl;
        outfile << ward << endl;

        outfile.close();
        cout << "Patient data saved to file.\n";
    } else {
        cout << "Error: Unable to open file for saving.\n";
    }
}
