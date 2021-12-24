#include "funkcje.h"

koordynaty WpisaneNaPoz(string wpisane)
{
	char x;
	x = wpisane[0];
	int x2;
	x2 = x - 96;
	char y;
	y = wpisane[1];
	int y2;
	y2 = y - 48;

	koordynaty ruch = { x2,y2 };

	return ruch;
}

void JakGrac()
{
	cout << "SZACHY" << endl;
	cout << endl;
	cout << "Jak grac? To bardzo proste! " << endl;
	cout << endl;
	cout << "Aby wykonac ruch nalezy wpisac pole z ktorego chcemy sie ruczyc " << endl << "nastepnie znak '-' a potem miejsce na ktore chcemy sie ruszyc" << endl << endl;
	cout << "MILEJ ROZGRYWKI!" << endl << endl;
	cout << "Nacisnij dowolny przycisk aby rozpoczaczac gre." << endl << endl;

	system("pause");
}
