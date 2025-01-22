// Programmers: 
// Purpose: Declaration of patient admission functions.

#ifndef ADMISSION_HPP
#define ADMISSION_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <set>

using namespace std;

set<int> getAssignedWards();
int assignRandomWard(const set<int>& assignedWards);
void admitPatient();

#endif 

