//=======================================================================
// Basic C++: procedural programming
//      The bookmaker exercise
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: bookmaker1.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// The structure defining the bookmaker's individual record
struct Bookrecord
{
    string _name;
    double _amount;
};

ostream& operator<<(ostream& os, const Bookrecord& br)
{
    return os << br._name << '\t' << br._amount;
}
istream& operator>>(istream& is, Bookrecord& br)
{
    return is >> br._name >> br._amount;
}

// A vector to store the transactions
vector<Bookrecord> records;

int main()
{
    string name;
    ifstream is("records.txt");
    Bookrecord rec;

    // Read the individual records from the istream is
    while (is >> rec)
    {
        records.push_back(rec); 
    }

    // Print them out
    cout << "Records read" << endl;
    cout << "------------" << endl;
    for (unsigned i = 0; i < records.size(); ++i)
        cout << records[i] << endl;

    cout << "\nEnter a name: " << flush;
    while (cin >> name)
    {
        double sum = 0.0;
        bool found = false;
        for (unsigned i = 0; i < records.size(); ++i)
        {
            if (records[i]._name == name)
            {
                found = true;
                sum += records[i]._amount;
            }
        }
        if (not found)
            cerr << "*** " << name << " not found" << endl;
        else
            cout << "Result for " << name << ": " << sum << endl;

        cout << "\nEnter a name: " << flush;    
    }    
}

