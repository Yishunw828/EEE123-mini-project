#ifndef ADMISSION_HPP
#define ADMISSION_HPP 

#include <string>
#include <set>

using namespace std; 

// Programmers: Nick Wong Paul Ian
// Matric No. : 23305339
// Purpose: Declare functions for admit patient, ensuring all inputs are valid and properly formatted.
bool isValidName(const string& name);
string getValidName();
bool isValidIC(const string& ic);
string getValidIC();
bool isValidContact(const string& contact);
string getValidContact();
bool isValidReason(const string& reason);
string getValidReason();
bool isValidDate(const string& date);
string getValidDate();
set<int> getAssignedWards();
int assignRandomWard(const set<int>& assignedWards);
void admitPatient();

#endif


