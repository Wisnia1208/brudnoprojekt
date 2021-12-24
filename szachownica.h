#pragma once

#include "funkcje.h"
#include "figura.h"
#include "wieza.h"
#include "pole.h"
#include "pionek.h"
#include "skoczek.h"
#include "goniec.h"
#include "hetman.h"
#include "krol.h"

class szachownica
{
private:
	pole tablica[8][8];

	void WstawFigury();
	bool Rusz(koordynaty zpoz, koordynaty dopoz, bool czyjRuch);

public:

	szachownica();
	~szachownica();

	bool CzyJestSzach(bool kolor);

	figura* JakaFigura(koordynaty poz);
	void Rysuj();
	bool CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz, bool czyjRuch);
	bool PrubujRusz(koordynaty zpoz, koordynaty dopoz, bool& czyjRuch);
	int IleMozliwychRuchow(bool kolor);
	bool Roszkr(bool& kolor);
	bool Roszdl(bool& kolor);
	bool Czyremis(bool kolor);

};


