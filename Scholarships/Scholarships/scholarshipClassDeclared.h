// ScholarshipClassDeclared.h
// This file contains all member variable 
//   and member functions declarations
//   and prototypes only.
// Function definitions are found in the 
//     scholarshipClassDefined.cpp file
// The member variables match the
//   scholarships.csv data file
#pragma once
#include <string>
using namespace std;

class Scholarship
{
private:
	string ID;
	int    Amount;
	string Type;
	string Length;
	string DateStarts;
	string Lname;
	string Fname;

public:
	Scholarship();					// default constructor
	Scholarship(string id,			// Initializing constructor
				int a, 
				string t, 
				string len, 
				string d, 
				string ln, 
				string fn);

	bool setID(string id);			// Sets for private member variables
	bool setAmount(int a);
	bool setType(string t);
	bool setLength(string len);
	bool setDate(string d);
	bool setLname(string ln);
	bool setFname(string fn);

	string getID();			// Gets for private member variables
	int getAmount();
	string getType();
	string getLength();
	string getDate();
	string getLname();
	string getFname();
};