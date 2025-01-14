#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Display_Patient
{
    private:
        string line;

    public:
        void Display_Patient_File()
        {
            cout << endl;

            ifstream infile("patient.txt");

            if (infile.is_open())
            {
                while (getline(infile, line))
                {
                    cout << "Patient_ID : " << line << endl;  
                    getline(infile, line);
                    cout << "Name : " << line << endl;        
                    getline(infile, line);
                    cout << "Age : " << line << endl;   
                    getline(infile, line);
                    cout << "IC number: " << line << endl; 
                    getline(infile, line);
                    cout << "Gender : " << line << endl;      
                    getline(infile, line);
                    cout << "Contact Number: " << line << endl;         
                    getline(infile, line);
                    cout << "Reason for Admission: " << line << endl;   
                    getline(infile, line);
                    cout << "Ward: : " << line << endl; 
                    cout << "-------------------------------" << endl;
                }

                infile.close();
            }
            else
            {
                cout << "Error: Unable to open file for reading.\n";
            }
        }
};

int main()
{
    Display_Patient dp;
    dp.Display_Patient_File();

    return 0;
}
