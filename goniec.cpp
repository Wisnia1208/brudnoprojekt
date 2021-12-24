#include "goniec.h"


goniec::goniec(koordynaty pozycja, bool czyBialy)
	: figura(pozycja, czyBialy)
{
}

goniec::~goniec()
{
}

void goniec::Rysuj()
{
	cout << "G";
}

bool goniec::CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz)
{
	if (zpoz.x - zpoz.y == dopoz.x - dopoz.y or zpoz.x + zpoz.y == dopoz.x + dopoz.y)
	{
		return true;
	}
	else

		return false;
}