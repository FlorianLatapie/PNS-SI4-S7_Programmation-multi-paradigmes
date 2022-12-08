//=======================================================================
// Basic C++: class Menu
//      Specification of class Menu
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Menu.h,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#ifndef _MENU_H_
#define _MENU_H_

#include <string>
#include <vector>
using namespace std;

#include "menu_item.h"

class Menu
{
private:
    string _title;              // Title of the menu
    vector<Menu_Item *> _items; // Pointeurs to Menu items

public:
    Menu(const string& t, const vector<Menu_Item *> items) 
        : _title(t), _items(items)
    {}

    const string& title() const {return _title;}

    int nitems() const {return _items.size();}

    void activate() const;
};

#endif
