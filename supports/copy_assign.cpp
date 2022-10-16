// char * and one-step conversion
// Copy constructor
// Assignment

#include <iostream>
#include <vector>
#include "common_defs.h"
using namespace std;

/*
   1. Le programme suivant compile-t'il ? Pourquoi ?
   2. On modifie la classe A en déclarant la donnée membre s <<const>> : même question.
*/

class A
{

	string s;
	int i;

	friend ostream &operator<<(ostream &os, A a) { return os<<"s="<<a.s<<", i="<<a.i<<endl; }
	public:
	A(const string &ss="", int ii=0)
	{
		s = ss;
		i = ii;
	}
};

int main()
{
	A a1;
	A a2("hello",2);
	OUT(a2);
	A a3 = a2;
	string s = "bonjour";
	a2 = s;
	OUT(a2);
	a2 = "bonjour";
	return 0;
}
