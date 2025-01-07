#include <iostream> 
using namespace std; 
 
int filterAndDisplayPatientIDs(const int allIDs[], int totalPatients, int threshold); 
int filterAndDisplayAdmissionDates(const int allDates[], int totalDates, int month); 
 
int num; 
 
int main() { 
    cout << "What would you like to filter for search?" << endl; 
    cout << "---------------------------------------------" << endl; 
    cout << "| 1. Patient ID                             |" << endl; 
    cout << "| 2. Admission date                         |" << endl; 
    cout << "| 3. Room Number                            |" << endl; 
    cout << "---------------------------------------------" << endl; 
    cin >> num; 
 
    if (num == 1) { 
        const int totalPatients = 5; 
        int patientIDs[totalPatients] = {101, 202, 303, 404, 505}; 
        int threshold; 
 
        cout << " "; 
        cin >> threshold; 
  
        filterAndDisplayPatientIDs(patientIDs, totalPatients, threshold); 
 
    } else if (num == 2) {  
        const int totalDates = 5; 
        int admissionDates[totalDates] = {1, 3, 5, 7, 12}; 
        int month; 
 
        cout << "Enter the month number (1 for January, 12 for December) to filter: "; 
        cin >> month; 
 
        if (month < 1 || month > 12) { 
            cout << "Invalid month! Please enter a value between 1 and 12." << endl; 
        } else { 
            filterAndDisplayAdmissionDates(admissionDates, totalDates, month); 
        } 
 
    } else { 
        cout << "Invalid option selected!" << endl; 
    } 
 
    return 0; 
} 
 
int filterAndDisplayPatientIDs(const int allIDs[], int totalPatients, int threshold) { 
    int filteredIDs[totalPatients]; 
    int count = 0; 
 
    cout << "\nFiltered Patient IDs:\n"; 
    for (int i = 0; i < totalPatients; i++) { 
        if (allIDs[i] > threshold) { // 
            filteredIDs[count++] = allIDs[i]; 
            cout << allIDs[i] << " "; 
        } 
    } 
 
    cout << "\n\nTotal Filtered Patient IDs: " << count << endl; 
    return count; 
} 
 

int filterAndDisplayAdmissionDates(const int allDates[], int totalDates, int month) { 
    int filteredDates[totalDates];  
    int count = 0; 
 
    cout << "\nFiltered Admission Dates (Month " << month << "):\n"; 
    for (int i = 0; i < totalDates; i++) { 
        if (allDates[i] == month) { 
            filteredDates[count++] = allDates[i]; 
            cout << "Patient admitted in month " << allDates[i] << endl; 
        } 
    } 
 
    if (count == 0) { 
        cout << "No patients admitted in month " << month << "." << endl; 
    } 
 
    cout << "\nTotal Patients Admitted in Month " << month << ": " << count << endl; 
    return count; 
}