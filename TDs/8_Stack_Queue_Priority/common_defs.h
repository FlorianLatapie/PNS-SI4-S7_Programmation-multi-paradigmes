//=======================================================================
// Basic C++: Common definitions for test programs
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: common_defs.h,v 1.1.1.1 2004/11/01 13:39:47 jpr Exp $
//=======================================================================

#ifndef _COMMON_DEFS_H_
#define _COMMON_DEFS_H_

#include <cassert>
#include <iostream>
using namespace std;

// Useful test macros

#define OUT(expr) cout << #expr" : " << (expr) << endl
#define OUTNL(expr) cout << #expr" : \n" << (expr) << endl
#define EXEC(expr) (cout << #expr";" << endl), (expr)
#define MSG(msg) cout << "\n********* "#msg" *********\n" << endl; 

#endif
