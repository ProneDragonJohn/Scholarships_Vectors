// scholarshipClassDefined.cpp
// Member Function definitions for the Scholarship class

#include "scholarshipClassDeclared.h"


Scholarship::Scholarship()					// default constructor
{
	ID = "";
	Amount = 0;
	Type = "";
	Length = "";
	DateStarts = "";
	Lname = "";
	Fname = "";

}
Scholarship::Scholarship(string id,			// Initializing constructor
						 int a, 
						 string t, 
						 string len, 
						 string d, 
						 string ln, 
						 string fn)
{
	setID(id);
	setAmount(a);
	setType(t);
	setLength(len);
	setDate(d);
	setLname(ln);
	setFname(fn);
}

bool Scholarship::setID(string id)		// Sets for private member variables
{
	if (id.empty())
	{
		ID = "invalid";
		return false;
	}
	ID = id;
	return true;
}
bool Scholarship::setAmount(int a)
{
	if (a < 0)
	{
		Amount = 0;
		return false;
	}
	Amount = a;
	return true;
}
bool Scholarship::setType(string t)
{
	if (t.empty())
	{
		Type = "invalid";
		return false;
	}
	Type = t;
	return true;
}
bool Scholarship::setLength(string len)
{
	if(len.empty())
	{
		Length = "invalid";
		return false;
	}
	Length = len;
	return true;
}
bool Scholarship::setDate(string d)
{
	if (d.empty())
	{
		DateStarts = "invalid";
		return false;
	}
	DateStarts = d;
	return true;
}
bool Scholarship::setLname(string ln)
{
	if (ln.empty())
	{
		Lname = "invalid";
		return false;
	}
	Lname = ln;
	return true;
}
bool Scholarship::setFname(string fn)
{
	if (fn.empty())
	{
		Fname = "invalid";
		return false;
	}
	Fname = fn;
	return true;
}

string Scholarship::getID()			// Gets for private member variables
{
	return ID;
}
int Scholarship::getAmount()
{
	return Amount;
}
string Scholarship::getType()
{
	return Type;
}
string Scholarship::getLength()
{
	return Length;
}
string Scholarship::getDate()
{
	return DateStarts;
}
string Scholarship::getLname()
{
	return Lname;
}
string Scholarship::getFname()
{
	return Fname;
}