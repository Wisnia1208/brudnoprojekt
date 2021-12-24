#pragma once
#include "figura.h"
class goniec :
	public figura
{
public:

	goniec(koordynaty pozycja, bool czyBialy);
	~goniec();

	void Rysuj() override;
	bool CzyRuchPoprawny(koordynaty pozycja, koordynaty dopoz);
};

