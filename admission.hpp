// Programmers: 
// Purpose: Declaration of patient admission functions.

#ifndef ADMISSION_HPP
#define ADMISSION_HPP

#include <iostream>
#include <set>
#include <string>

using namespace std;

bool isValidName(const std::string& name);
string getValidName();
bool isValidDate(const std::string& date);
string getValidDate();
set<int> getAssignedWards();
int assignRandomWard(const std::set<int>& assignedWards);
void admitPatient();

#endif 


