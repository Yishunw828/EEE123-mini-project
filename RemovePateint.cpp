#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Remove_Patient
{
private:
    string patientIDToRemove;

public:
    void Remove_Patient_Record()
    {
        ifstream infile("patient.txt");
        if (!infile.is_open())
        {
            cout << "No saved patient data found. Please ensure the patient records exist.\n";
            return;
        }

        cout << "Enter the Patient_ID to remove: ";
        cin.ignore();
        getline(cin, patientIDToRemove);

        vector<string> remainingPatients;
        string line;
        bool patientFound = false;

        while (getline(infile, line))
        {
            string patientID = line;
            remainingPatients.push_back(patientID);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  
            getline(infile, line);
            remainingPatients.push_back(line);  

            if (patientID == patientIDToRemove)
            {
                patientFound = true;
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
                remainingPatients.pop_back();  
            }
        }

        infile.close();

        if (!patientFound)
        {
            cout << "Patient not found in the records.\n";
            return;
        }

        ofstream outfile("patient.txt");
        if (outfile.is_open())
        {
            for (size_t i = 0; i < remainingPatients.size(); i++)
            {
                outfile << remainingPatients[i] << endl;
            }
            outfile.close();
            cout << "Patient removed successfully.\n";
        }
        else
        {
            cout << "Error: Unable to open file for writing.\n";
        }
    }
};

int main()
{
    Remove_Patient rp;
    rp.Remove_Patient_Record();

    return 0;
}
