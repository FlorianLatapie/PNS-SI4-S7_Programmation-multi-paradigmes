//=======================================================================
// Basic C++: class Menu
//      Specification of class Walking_Menu
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Walking_Menu.h,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#ifndef _WALKING_ITEM_H_
#define _WALKING_ITEM_H_

#include "menu_item.h"
#include "menu.h"

// Class for walking menus
//      redefine text() (for adding label " ->")
//      redefine item execution (as menu execution)

class Walking_Menu : public Menu_Item, public Menu
{
public:
    Walking_Menu(const string& t, const vector<Menu_Item *> items)
        : Menu_Item(t), Menu(t, items)
    {}

    string text() const;

    virtual void execute() const {activate();}
};

#endif
