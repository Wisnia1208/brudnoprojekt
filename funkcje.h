#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <cstdio>
#include <typeinfo>


using namespace std;

typedef struct koordynaty {
	int x; // [1-8]
	int y;


	bool CzyNieWyjdzie()
	{
		return x > 0 and x < 9 and y > 0 and y < 9;
	}
};

koordynaty WpisaneNaPoz(string wpisane);

void JakGrac();


#endif

