#pragma once
#include "figura.h"
class skoczek :
	public figura
{
public:

	skoczek(koordynaty pozycja, bool czyBialy, bool Czypionek = 0);
	~skoczek();

	void Rysuj() override;
	bool CzyRuchPoprawny(koordynaty pozycja, koordynaty dopoz);
};

