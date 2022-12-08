//=======================================================================
// Basic C++: class Menu
//      Implementation of class Walking_Menu
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Walking_Menu.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include "walking_item.h"

const string SUB_MENU_MARK = " ->";

string Walking_Menu::text() const
{
    return Menu_Item::text() + SUB_MENU_MARK;
}
