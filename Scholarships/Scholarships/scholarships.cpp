// Scholarships.cpp
// This program tutorial demonstrates arrays using vectors
// It also demonstrates file I/O techniques with vectors
//  and making arrays of objects
// The Datafile used in a CSV (Comma Seperated Values) file
//  named Scholarships.csv
// The structor of the data file is:
//  ID, Amount Awarded, Scholarship Type, Length of Scholarship, Date Starts, Last Name, First Name

#include "scholarships.h"


int main()
{
	string sFileLine;				// a string to read in each line of the file
	vector<string> sParsedLine;     // array to hold the parsed line from file
	vector<Scholarship> scholars;	// this array of objects is initialized using 
									// the default constructor

	// Open input and output files and test to make sure they openned correctly
	ifstream fin;
	ofstream fout;
	OpenFiles(fin, fout);

	while (!fin.eof())
	{
		scholars.push_back(readFile(sFileLine, sParsedLine, fin));
	}

	int sArraySize = scholars.size();
	for (int i = 0; i < sArraySize; i++)
	{
		writeFile(scholars[i], fout);
	}

	createReportSummary(scholars, fout);

	// Close the original output report to reuse its file handler
	// and not overwrite the original output report
	fout.close();
	fout.open("ScholarshipsByType.dat");

	displayMenu(scholars, fout); // Function replaces code commented below
	/*if (!fout)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}
	// Ask the user for the specific report
	string sType;
	cout << "What specific type of scholarship would you like a report on?\n";
	cin >> sType;
	cout << endl;
	for (int i = 0; i < sArraySize; i++)
	{
		writeFile(scholars[i], fout, sType); // Write a line to the output file
	}*/

	return 0;
}

void OpenFiles(ifstream &in, ofstream &out)  // must be passed in by reference
{
	in.open("Scholarships.csv");
	if(!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}

	out.open("ScholarshipsReport.dat");
	if(!out)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}

}

Scholarship readFile(string &sLine,           // Pass in by reference to change string in main()
			  vector<string> &sParsed, // Pass in by reference to change array in main()
			  ifstream &fin)           // Also pass in the input file buffer by ref to read from
{										 
	getline(fin,sLine);
	stringstream lineStream(sLine);    // A special string class for pre-output formatting
	string field;
	sParsed.clear();                  // Empty the Parsed Line for reuse

    while(getline(lineStream,field,','))  // While there are fields between the ,
    {
        sParsed.push_back(field);        // Push them onto the string array vector
    }
	// return a Scholarship object copy created with the initialization construction
	return Scholarship(sParsed[0], stoi(sParsed[1]), sParsed[2],
		               sParsed[3], sParsed[4], sParsed[5], sParsed[6]);
}

void writeFile(Scholarship s,    // Pass in by value- no need to change string in main()
			   ofstream &fout)  // Also pass in the output file buffer by ref to write to
{
	static int lineCount = 60;
	if (lineCount == 60)
	{
		fout << endl;
		createReportHeadings(fout);
		lineCount = 0;
	}
	fout << s.getID() << right << setw(10) << addCommas(s.getAmount()) 
		 << "    " << left << setw(12) << s.getType() 
		 << setw(10) << s.getLength() << right << setw(10) << s.getDate() 
		 << "   " << left << setw(15) << s.getFname() << s.getLname() << endl;
	lineCount++;
}

void createReportHeadings(ofstream &fout)
{
	fout << "******************************Scholarships Report*****************************\n"
		 << "******************************************************************************\n\n"
		 << "ID      Amount      Type      Length      Starts     First Name     Last Name\n"
		 << "------------------------------------------------------------------------------\n";
}

string addCommas(int num)
{
	string s = to_string(num);

	int sSize = s.size();
	if (sSize > 3)
	{
		for (int i = (sSize - 3); i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
	}

	return s;
}

void createReportSummary(vector<Scholarship> sArray, // Pass by value(copy) the entire array
						ofstream &fout)				 // Pass the output file by reference
{
	int total = 0;                          // Accumulator for total amount
	int sArraySize = sArray.size();         // Get the size of the array
											// Accumulators for type totals
	int baseTotal = 0, baskTotal = 0, dTotal = 0, fTotal = 0, gTotal = 0, softTotal = 0,
		swimTotal = 0, tTotal = 0, vTotal = 0;

	// Loop through the array to accumulate the total amount of all scholarships
	for (int i = 0; i < sArraySize; i++)
	{
		total += sArray[i].getAmount();    // Add the Amount of each scholarship to the total
		string sType = sArray[i].getType(); // Get the type of scholarship for this record
											// Add the Type's Amount to the appropriate accumulator
		if (sType == "Baseball") baseTotal += sArray[i].getAmount();
		else if (sType == "Basketball") baskTotal += sArray[i].getAmount();
		else if (sType == "Diving") dTotal += sArray[i].getAmount();
		else if (sType == "Football") fTotal += sArray[i].getAmount();
		else if (sType == "Golf") gTotal += sArray[i].getAmount();
		else if (sType == "Softball") softTotal += sArray[i].getAmount();
		else if (sType == "Swimming") swimTotal += sArray[i].getAmount();
		else if (sType == "Track") tTotal += sArray[i].getAmount();
		else if (sType == "Volleyball") vTotal += sArray[i].getAmount();
	}
	// Write the summary report output line
	fout << "\n\nSummary Report \n"
		<< "--------------\n"
		<< "        Total Number of Scholarships: "
		<< right << setw(12) << sArraySize << endl
		<< "        Baseball:                    $ "
		<< setw(11) << addCommas(baseTotal) << endl
		<< "        Basketball:                  $ "
		<< setw(11) << addCommas(baskTotal) << endl
		<< "        Diving:                      $ "
		<< setw(11) << addCommas(dTotal) << endl
		<< "        Football:                    $ "
		<< setw(11) << addCommas(fTotal) << endl
		<< "        Golf:                        $ "
		<< setw(11) << addCommas(gTotal) << endl
		<< "        Softball:                    $ "
		<< setw(11) << addCommas(softTotal) << endl
		<< "        Swimming:                    $ "
		<< setw(11) << addCommas(swimTotal) << endl
		<< "        Track:                       $ "
		<< setw(11) << addCommas(tTotal) << endl
		<< "        Volleyball:                  $ "
		<< setw(11) << addCommas(vTotal) << endl
		<< "        ===========================================\n"
		<< "        Total Scholarship Amount:    $ "
		<< setw(11) << addCommas(total);
}

// Overloaded function for report of specific type of scholarship
void writeFile(Scholarship s,    // Pass in by value- no need to change string in main()
						ofstream &fout,	// Also pass in the output file buffer by ref to write to
						string sType)	// Pass in by value the type of scholarship
{
	static int lineCount = 60;
	if (lineCount == 60) //Ready for next page
	{
		fout << endl;
		createReportHeadings(fout);
		lineCount = 0;
	}
	if (sType == s.getType())
	{
		fout << s.getID() << right << setw(10) << addCommas(s.getAmount())
			<< "    " << left << setw(12) << s.getType()
			<< setw(10) << s.getLength() << right << setw(10) << s.getDate()
			<< "   " << left << setw(15) << s.getFname() << s.getLname() << endl;
		lineCount++;
	}
}

void displayMenu(vector<Scholarship> scholars, ofstream &fout)
{
	
	if (!fout)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}
	// Ask the user for the specific report
	int num;
	cout << "1: Baseball"
		 << "\n2: Basketball"
		 << "\n3: Diving"
		 << "\n4: Football"
		 << "\n5: Golf"
		 << "\n6: Softball"
		 << "\n7: Swimming"
		 << "\n8: Track"
		 << "\n9: Volleyball"
		 << "\n\nWhat specific type of scholarship would you like a report on? ";
	cin >> num;
	cout << endl;

	string sType;
	switch(num)
	{
		case 1:
			sType = "Baseball";
			break;
		case 2:
			sType = "Basketball";
			break;
		case 3:
			sType = "Diving";
			break;
		case 4:
			sType = "Football";
			break;
		case 5:
			sType = "Golf";
			break;
		case 6:
			sType = "Softball";
			break;
		case 7:
			sType = "Swimming";
			break;
		case 8:
			sType = "Track";
			break;
		case 9:
			sType = "Volleyball";
			break;
		default:
			break;
	}

	for (int i = 0; i < scholars.size(); i++)
	{
		writeFile(scholars[i], fout, sType); // Write a line to the output file
	}
}