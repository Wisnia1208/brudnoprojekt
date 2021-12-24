#pragma once
#include "funkcje.h"
#include "figura.h"
#include "szachownica.h"


class pionek :public figura
{
private:

	bool CzySkacze2(koordynaty);


public:
	static int ilepionkow;
	pionek(koordynaty pozycja, bool czyBialy);
	//pionek(koordynaty pozycja, bool czyBialy, string name);
	~pionek();

	static int usun1();
	static int dod1();
	void Rysuj() override;
	bool CzyRuchPoprawny(koordynaty zpoz, koordynaty dopoz);
	static int LiczbaPionkow();
};