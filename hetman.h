#pragma once
#include "figura.h"
class hetman :
	public figura
{
public:

	hetman(koordynaty pozycja, bool czyBialy);
	~hetman();

	void Rysuj() override;
	bool CzyRuchPoprawny(koordynaty pozycja, koordynaty dopoz);
};