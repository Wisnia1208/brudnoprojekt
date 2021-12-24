#include "skoczek.h"

skoczek::skoczek(koordynaty pozycja, bool czyBialy, bool czypionek)
	: figura(pozycja, czyBialy)
{
}

skoczek::~skoczek()
{
}

void skoczek::Rysuj()
{
	cout << "S";
}

bool skoczek::CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz)
{
	if (zpoz.x + 2 == dopoz.x)
	{
		if (zpoz.y + 1 == dopoz.y)
			return true;

		if (zpoz.y - 1 == dopoz.y)
			return true;
	}
	if (zpoz.x - 2 == dopoz.x)
	{
		if (zpoz.y + 1 == dopoz.y)
			return true;

		if (zpoz.y - 1 == dopoz.y)
			return true;
	}
	if (zpoz.x + 1 == dopoz.x)
	{
		if (zpoz.y + 2 == dopoz.y)
			return true;

		if (zpoz.y - 2 == dopoz.y)
			return true;
	}
	if (zpoz.x - 1 == dopoz.x)
	{
		if (zpoz.y + 2 == dopoz.y)
			return true;

		if (zpoz.y - 2 == dopoz.y)
			return true;
	}
	return false;
}
