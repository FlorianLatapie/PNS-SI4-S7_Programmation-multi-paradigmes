//=======================================================================
// Basic C++: class Menu
//      Specification of class Menu_Item
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Simple_Menu_Item.h,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#ifndef _SIMPLE_MENU_ITEM_H_
#define _SIMPLE_MENU_ITEM_H_

#include <string>
using namespace std;

#include "menu_item.h"

// The concrete class of simple menu items (text, action)

typedef void (*Menu_Action)();  // The type of a menu action

class Simple_Menu_Item : public Menu_Item
{
private:
    Menu_Action _action;        // The action

public:
    Simple_Menu_Item(const string& t, Menu_Action a)
        : Menu_Item(t), _action(a)
    {}

    virtual void execute() const {(*_action)();}
};

#endif
