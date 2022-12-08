//=======================================================================
// Basic C++: class Menu
//      Utilization of class Menu
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_Menu.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

#include "menu_item.h"
#include "menu.h"
#include "simple_menu_item.h"
#include "walking_item.h"

// On veut écrire un ensemble de classes permettant de simuler (en mode texte)
// le fonctionnement des menus déroulants:
//
// la classe Menu_Item correspond aux "items" du menu: ces items sont simples
// (ils correspondent à l'exécution d'une action) ou "walking" (ils correspondent
// a des sous-menus deroulants)

// ON COMMENCERA PAR UTILISER DES MENUS NE CONTENANT QUE DES ITEMS SIMPLES

// Un menu contient un titre et une vector de Menu_Item et une fonction activate
// un Menu_Item contient un nom et une fonction execute qui est appelée lorsqu'il est selectionne
// Un Simple_Menu_Item contient un pointeur sur une fonction (l'action) sa fonction execute appelle cette action


// INDICATION : pour les items simples, on definira le type pointeur sur une fonction void avec :
// typedef void (*foncPtr)();
// Et l'on déclarera une donnee-membre de type "foncPtr" (l'action qui doit être exécutée par l'item simple)
//
// REM : simple_menu_item herite de menu_item
//
// simple sample functions associated to actions (for Simple_Menu_Items)

void new_action() { cout << "************** Execution of NEW item" << endl; }

void open_action() { cout << "************** Execution of OPEN item" << endl; }

void close_action() { cout << "************** Execution of CLOSE item" << endl; }

void quit_action()
{
    cout << "************** Execution of QUIT item" << endl;
    exit(0); // end of program
}

void general_prefs_action() { cout << "************** Execution of GENERAL item" << endl; }

void battery_prefs_action() { cout << "************** Execution of BATTERY item" << endl; }

void recently_action() { cout << "************** Open recent file " << endl; }


// A sample menu : The_Menu
// First Step : comment all Walking_Menus (menu deroulants)
//
int main()
{

	vector<Menu_Item *> prefs_sub_items;
    prefs_sub_items.push_back( new Simple_Menu_Item("general", general_prefs_action) );
    prefs_sub_items.push_back( new Simple_Menu_Item("battery", battery_prefs_action) );

	vector<Menu_Item *> items;
	items.push_back( new Simple_Menu_Item("new", new_action)	);
    items.push_back( new Simple_Menu_Item("open...", open_action)	);
    items.push_back( new Simple_Menu_Item("close", close_action)	);
    items.push_back( new Walking_Menu("preferences", prefs_sub_items)	);
    items.push_back( new Simple_Menu_Item("quit", quit_action)	);

	Menu The_Menu("Fichier", items);

	// Displaying the menu in an infinite loop
    for (;;) The_Menu.activate();
    return 0;
}


