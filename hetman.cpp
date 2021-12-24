#include "hetman.h"


hetman::hetman(koordynaty pozycja, bool czyBialy)
	: figura(pozycja, czyBialy)
{
}

hetman::~hetman()
{
}

void hetman::Rysuj()
{
	cout << "H";
}

bool hetman::CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz)
{
	if (zpoz.x == dopoz.x or zpoz.y == dopoz.y)
	{
		return true;
	}
	if (zpoz.x - zpoz.y == dopoz.x - dopoz.y or zpoz.x + zpoz.y == dopoz.x + dopoz.y)
	{
		return true;
	}
	else

		return false;
}