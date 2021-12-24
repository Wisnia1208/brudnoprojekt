#include "krol.h"


krol::krol(koordynaty pozycja, bool czyBialy)
	: figura(pozycja, czyBialy)
{
}

krol::~krol()
{
}

void krol::Rysuj()
{
	cout << "K";
}

bool krol::CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz)
{
	if (zpoz.x + 1 == dopoz.x)
	{
		if (zpoz.y + 1 == dopoz.y or zpoz.y - 1 == dopoz.y or zpoz.y == dopoz.y)
		{
			return true;

		}
		else
			return false;

	}
	else if (zpoz.x - 1 == dopoz.x)
	{
		if (zpoz.y + 1 == dopoz.y or zpoz.y - 1 == dopoz.y or zpoz.y == dopoz.y)
			return true;

		else
			return false;
	}
	else if (zpoz.x == dopoz.x)
	{
		if (zpoz.y + 1 == dopoz.y or zpoz.y - 1 == dopoz.y)
			return true;
		else
			return false;
	}
	else
		return false;
}