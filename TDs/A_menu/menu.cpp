//=======================================================================
// Basic C++: class Menu
//      Implementation of class Menu
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Menu.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

#include "menu.h"

// Execution of a menu : 
//      display , the menu
//      ask for user selection (loop in case of selection not correct)
//      execute user selection

void Menu::activate() const
{
    unsigned i;

    // Display menu

    cout << "\n\t" << title() << endl;
    for (i = 0; i < _items.size(); i++) 
        cout << i << "- " << _items[i]->text() << endl;

    // Selection : loop while selection incorrect
    // stop everything on EOF

    cout << "Your choice? " << flush;
    cin >> i;
    if (cin.eof()) exit(0);
    while ( i >= _items.size() )
    {
        cout << "Error: try again!" << endl;
        cout << "Your choice? " << flush;
        cin >> i;
        if (cin.eof()) exit(0);
    }

    // Execute selected action

    _items[i]->execute();
}
