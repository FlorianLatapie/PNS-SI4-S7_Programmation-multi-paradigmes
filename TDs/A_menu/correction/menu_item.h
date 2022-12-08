//=======================================================================
// Basic C++: class Menu
//      Specification of class Menu_Item
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Menu_Item.h,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#ifndef _MENU_ITEM_H_
#define _MENU_ITEM_H_

#include <string>
using namespace std;

// The abstract class of Menu items

class Menu_Item
{
private:
   string _text;                // Selection message

public:
    Menu_Item(const string& t) : _text(t) {}
    virtual ~Menu_Item() {}

    virtual string text() const {return _text;}
    virtual void execute() const = 0;
};

#endif
