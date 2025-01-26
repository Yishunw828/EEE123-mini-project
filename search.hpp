#ifndef SEARCH_HPP
#define SEARCH_HPP

using namespace std;

// Programmers: Divyadarrshini A/P Loganathan
// Matric No. : 23303060
// Purpose: Declare functions for searching patient records by name, ward number or admission date.
void searchMenu();
void searchByName();
void searchByWard();
bool ValidDate(const string& date);
void searchByDate();

#endif
