#include "szachownica.h"


using namespace std;

szachownica::szachownica()
{

	koordynaty wiezy1B = { 1,1 };
	tablica[0][0].WstawFigure(new wieza(wiezy1B, true));
	koordynaty skoczka1B = { 2,1 };
	tablica[1][0].WstawFigure(new skoczek(skoczka1B, true));
	koordynaty gonca1B = { 3,1 };
	tablica[2][0].WstawFigure(new goniec(gonca1B, true));
	koordynaty hetmanaB = { 4,1 };
	tablica[3][0].WstawFigure(new hetman(hetmanaB, true));
	koordynaty krolaB = { 5,1 };
	tablica[4][0].WstawFigure(new krol(krolaB, true));
	koordynaty gonca2B = { 6,1 };
	tablica[5][0].WstawFigure(new goniec(gonca2B, true));
	koordynaty skoczka2B = { 7,1 };
	tablica[6][0].WstawFigure(new skoczek(skoczka2B, true));
	koordynaty wiezy2B = { 8,1 };
	tablica[7][0].WstawFigure(new wieza(wiezy2B, true));


	for (int j = 0; j < 8; j++)
	{
		koordynaty pionkowB = { j + 1,2 };
		tablica[j][1].WstawFigure(new pionek((pionkowB), true));
	}



	for (int j = 0; j < 8; j++)
	{
		koordynaty pionkowC = { (j + 1),7 };
		tablica[j][6].WstawFigure(new pionek((pionkowC), false));
	}

	koordynaty wiezy1C = { 1,8 };
	tablica[0][7].WstawFigure(new wieza(wiezy1C, false));
	koordynaty skoczka1C = { 2,8 };
	tablica[1][7].WstawFigure(new skoczek(skoczka1C, false));
	koordynaty gonca1C = { 3,8 };
	tablica[2][7].WstawFigure(new goniec(gonca1C, false));
	koordynaty hetmanaC = { 4,8 };
	tablica[3][7].WstawFigure(new hetman(hetmanaC, false));
	koordynaty krolaC = { 5,8 };
	tablica[4][7].WstawFigure(new krol(krolaC, false));
	koordynaty gonca2C = { 6,8 };
	tablica[5][7].WstawFigure(new goniec(gonca2C, false));
	koordynaty skoczka2C = { 7,8 };
	tablica[6][7].WstawFigure(new skoczek(skoczka2C, false));
	koordynaty wiezy2C = { 8,8 };
	tablica[7][7].WstawFigure(new wieza(wiezy2C, false));

}

szachownica::~szachownica()
{
}


figura* szachownica::JakaFigura(koordynaty poz)
{
	return tablica[poz.x][poz.y].JakaFigura();
}

void szachownica::WstawFigury()
{
}

bool szachownica::CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz, bool czyjRuch)
{
	if (!zpoz.CzyNieWyjdzie() or !dopoz.CzyNieWyjdzie())
	{
		return false;
	}

	figura* zfigura = tablica[zpoz.x - 1][zpoz.y - 1].JakaFigura();

	if (zfigura == NULL)
		return false;

	if (zfigura->czyBialy != czyjRuch)
		return false;

	if (!zfigura->CzyRuchPoprawny(zpoz, dopoz))
		return false;


	figura* dofigura = tablica[dopoz.x - 1][dopoz.y - 1].JakaFigura();

	if (dofigura != NULL and dofigura->OgarnijKolor() == zfigura->OgarnijKolor())
		return false;

	// czy nie przeskoczy nad innym
	if (zpoz.x == dopoz.x)
	{
		if (dopoz.y > zpoz.y)
		{
			int i;
			i = zpoz.y;
			for (i; i < dopoz.y - 1; i++)
			{
				figura* pomiedzy = tablica[zpoz.x - 1][i].JakaFigura();
				if (pomiedzy != NULL)
					return false;
			}
		}
		if (dopoz.y < zpoz.y)
		{
			int i;
			i = dopoz.y;
			for (i; i < zpoz.y - 1; i++)
			{
				figura* pomiedzy = tablica[dopoz.x - 1][i].JakaFigura();
				if (pomiedzy != NULL)
					return false;
			}
		}
	}
	if (zpoz.y == dopoz.y)
	{
		if (dopoz.x > zpoz.x)
		{
			int i;
			i = zpoz.x;
			for (i; i < dopoz.x - 1; i++)
			{
				figura* pomiedzy = tablica[i][zpoz.y - 1].JakaFigura();
				if (pomiedzy != NULL)
					return false;
			}
		}
		if (dopoz.x < zpoz.x)
		{
			int i;
			i = dopoz.x;
			for (i; i < zpoz.x - 1; i++)
			{
				figura* pomiedzy = tablica[i][dopoz.y - 1].JakaFigura();
				if (pomiedzy != NULL)
					return false;
			}
		}
	}
	if (zpoz.y - zpoz.x == dopoz.y - dopoz.x)
	{
		if (dopoz.x > zpoz.x)
		{
			int i;
			int j;
			i = zpoz.x;
			j = zpoz.y;
			for (i; i < dopoz.x - 1; i++)
			{
				figura* pomiedzy = tablica[i][j].JakaFigura();
				if (pomiedzy != NULL)
					return false;
				j++;
			}
		}
		if (dopoz.x < zpoz.x)
		{
			int i;
			int j;
			i = dopoz.x;
			j = dopoz.y;
			for (i; i < zpoz.x - 1; i++)
			{
				figura* pomiedzy = tablica[i][j].JakaFigura();
				if (pomiedzy != NULL)
					return false;
				j++;
			}
		}
	}
	if (zpoz.y + zpoz.x == dopoz.y + dopoz.x)
	{
		if (dopoz.x > zpoz.x)
		{
			int i;
			int j;
			i = zpoz.x;
			j = zpoz.y - 1;
			for (i; i < dopoz.x - 1; i++)
			{
				j--;
				figura* pomiedzy = tablica[i][j].JakaFigura();
				if (pomiedzy != NULL)
					return false;

			}
		}
		if (dopoz.x < zpoz.x)
		{
			int i;
			int j;
			i = zpoz.x - 1;
			j = zpoz.y;
			for (j; j < dopoz.y - 1; j++)
			{
				i--;
				figura* pomiedzy = tablica[i][j].JakaFigura();
				if (pomiedzy != NULL)
					return false;

			}
		}
	}

	// do pionkow

	if (typeid(*zfigura).name() == typeid(pionek).name())
	{
		if (zpoz.y + zpoz.x == dopoz.y + dopoz.x or zpoz.y - zpoz.x == dopoz.y - dopoz.x)
		{
			if (dofigura == NULL)
				return false;
		}
		if (zpoz.x == dopoz.x)
		{
			if (dofigura != NULL)
				return false;
		}
	}
	else
		return true;
}

bool szachownica::CzyJestSzach(bool kolor)
{
	int xkrola;
	int ykrola;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			figura* gdziekrol = tablica[j][i].JakaFigura();
			if (gdziekrol != NULL)
			{
				if (typeid(*gdziekrol).name() == typeid(krol).name() and gdziekrol->czyBialy == kolor)
				{
					xkrola = j;
					ykrola = i;
					i = 8;
					j = 8;
				}
			}
		}
	}
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (CzyRuchPoprawny({ j,i }, { xkrola + 1,ykrola + 1 }, !kolor))
			{
				return true;
			}

		}
	}
	return false;
}

bool szachownica::PrubujRusz(koordynaty zpoz, koordynaty dopoz, bool& czyjRuch)
{
	if (CzyRuchPoprawny(zpoz, dopoz, czyjRuch))
	{
		if (Rusz(zpoz, dopoz, czyjRuch))
		{
			czyjRuch = (czyjRuch + 1) % 2;

			return true;
		}
	}

	cout << "Ruch niepoprawny!" << endl;

	system("pause");
	return false;
}

bool szachownica::Rusz(koordynaty zpoz, koordynaty dopoz, bool kolor)
{
	figura* zfigura = tablica[(zpoz.x) - 1][(zpoz.y) - 1].JakaFigura();

	figura* dofigura = tablica[(dopoz.x) - 1][(dopoz.y) - 1].JakaFigura();

	zfigura->UstawPozycje(dopoz);
	tablica[(dopoz.x) - 1][(dopoz.y) - 1].WstawFigure(zfigura);
	tablica[(zpoz.x) - 1][(zpoz.y) - 1].WstawFigure(NULL);
	if (CzyJestSzach(kolor))
	{
		zfigura->UstawPozycje(zpoz);
		tablica[(dopoz.x) - 1][(dopoz.y) - 1].WstawFigure(dofigura);
		tablica[(zpoz.x) - 1][(zpoz.y) - 1].WstawFigure(zfigura);


		return false;
	}
	else
		return true;
}

int szachownica::IleMozliwychRuchow(bool kolor)
{
	int liczbaRuchow = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			figura* zfigura = tablica[j][i].JakaFigura();
			if (zfigura != NULL and zfigura->czyBialy == kolor)
			{
				for (int k = 0; k < 8; k++)
				{
					for (int m = 0; m < 8; m++)
					{
						if (CzyRuchPoprawny({ j + 1,i + 1 }, { m + 1,k + 1 }, kolor))
						{
							liczbaRuchow++;

							figura* dofigura = tablica[m][k].JakaFigura();
							zfigura->UstawPozycje({ m,k });
							tablica[m][k].WstawFigure(zfigura);
							tablica[j][i].WstawFigure(NULL);
							if (CzyJestSzach(kolor))
							{
								liczbaRuchow -= 1;
							}
							zfigura->UstawPozycje({ j,i });

							tablica[m][k].WstawFigure(dofigura);
							tablica[j][i].WstawFigure(zfigura);

						}
					}
				}
			}
		}
	}
	return liczbaRuchow;
}

bool szachownica::Roszkr(bool& kolor)
{
	if (!CzyJestSzach(kolor))
	{
		if (kolor)
		{
			figura* czykrol = tablica[4][0].JakaFigura();


			if (typeid(*czykrol).name() == typeid(krol).name() and czykrol->czyBialy)
			{
				figura* czywieza = tablica[7][0].JakaFigura();

				if (typeid(*czywieza).name() == typeid(wieza).name() and czywieza->czyBialy)
				{
					figura* czypuste1 = tablica[5][0].JakaFigura();
					figura* czypuste2 = tablica[6][0].JakaFigura();
					if (czypuste1 == NULL and czypuste2 == NULL)
					{
						Rusz({ 5,1 }, { 7,1 }, kolor);
						Rusz({ 8,1 }, { 6,1 }, kolor);

						kolor = (kolor + 1) % 2;

						return true;
					}
				}
			}
		}
		if (!kolor)
		{
			figura* czykrol = tablica[4][7].JakaFigura();


			if (typeid(*czykrol).name() == typeid(krol).name() and !czykrol->czyBialy)
			{
				figura* czywieza = tablica[7][7].JakaFigura();

				if (typeid(*czywieza).name() == typeid(wieza).name() and !czywieza->czyBialy)
				{
					figura* czypuste1 = tablica[5][7].JakaFigura();
					figura* czypuste2 = tablica[6][7].JakaFigura();
					if (czypuste1 == NULL and czypuste2 == NULL)
					{
						Rusz({ 5,8 }, { 7,8 }, kolor);
						Rusz({ 8,8 }, { 6,8 }, kolor);

						kolor = (kolor + 1) % 2;

						return true;
					}
				}
			}
		}
	}
	return false;
}

bool szachownica::Roszdl(bool& kolor)
{
	if (!CzyJestSzach(kolor))
	{
		if (kolor)
		{
			figura* czykrol = tablica[4][0].JakaFigura();


			if (typeid(*czykrol).name() == typeid(krol).name() and czykrol->czyBialy)
			{
				figura* czywieza = tablica[0][0].JakaFigura();

				if (typeid(*czywieza).name() == typeid(wieza).name() and czywieza->czyBialy)
				{
					figura* czypuste1 = tablica[1][0].JakaFigura();
					figura* czypuste2 = tablica[2][0].JakaFigura();
					figura* czypuste3 = tablica[3][0].JakaFigura();

					if (czypuste1 == NULL and czypuste2 == NULL and czypuste3 == NULL)
					{
						Rusz({ 5,1 }, { 3,1 }, kolor);
						Rusz({ 1,1 }, { 4,1 }, kolor);

						kolor = (kolor + 1) % 2;

						return true;
					}
				}
			}
		}
		if (!kolor)
		{
			figura* czykrol = tablica[4][7].JakaFigura();


			if (typeid(*czykrol).name() == typeid(krol).name() and !czykrol->czyBialy)
			{
				figura* czywieza = tablica[7][7].JakaFigura();

				if (typeid(*czywieza).name() == typeid(wieza).name() and !czywieza->czyBialy)
				{
					figura* czypuste1 = tablica[1][7].JakaFigura();
					figura* czypuste2 = tablica[2][7].JakaFigura();
					figura* czypuste3 = tablica[3][7].JakaFigura();

					if (czypuste1 == NULL and czypuste2 == NULL and czypuste3 == NULL)
					{
						Rusz({ 5,8 }, { 3,8 }, kolor);
						Rusz({ 1,8 }, { 4,8 }, kolor);

						kolor = (kolor + 1) % 2;

						return true;
					}
				}
			}
		}
	}
	return false;
}

bool szachownica::Czyremis(bool kolor)
{
	int n = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			figura* zfigura = tablica[j][i].JakaFigura();
			if (zfigura != NULL)
			{
				n++;
			}
		}
	}
	if (n == 2)
		return true;
	else
		return false;
}

void szachownica::Rysuj() // skonczone
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);




	SetConsoleTextAttribute(h, 8);
	cout << "   A  B  C  D  E  F  G  H" << endl;


	for (int i = 8; i > 0; i--)
	{

		SetConsoleTextAttribute(h, 8);

		std::cout << i << " ";


		for (int j = 0; j < 8; j++)
		{

			figura* figura = tablica[j][i - 1].JakaFigura();

			if (figura != NULL)
			{
				if (figura->OgarnijKolor())
				{
					if ((j + i) % 2 == 0)
					{
						SetConsoleTextAttribute(h, 111);
						cout << " ";
						figura->Rysuj();
						cout << " ";
					}
					if ((j + i) % 2 == 1)
					{
						SetConsoleTextAttribute(h, 143);
						cout << " ";
						figura->Rysuj();
						cout << " ";
					}

				}
				if (!figura->OgarnijKolor())
				{
					if ((j + i) % 2 == 0)
					{
						SetConsoleTextAttribute(h, 96);
						cout << " ";
						figura->Rysuj();
						cout << " ";
					}
					if ((j + i) % 2 == 1)
					{
						SetConsoleTextAttribute(h, 128);
						cout << " ";
						figura->Rysuj();
						cout << " ";
					}


				}
			}
			else
			{
				if ((j + i) % 2 == 0)
				{
					SetConsoleTextAttribute(h, 102);
					cout << "   ";
				}
				else
				{
					SetConsoleTextAttribute(h, 136);
					cout << "   ";
				}
			}

		}
		cout << endl;

	}
	SetConsoleTextAttribute(h, 8);
}
