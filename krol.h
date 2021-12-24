#pragma once
#include "figura.h"
class krol :
	public figura
{
public:

	krol(koordynaty pozycja, bool czyBialy);
	~krol();

	void Rysuj() override;
	bool CzyRuchPoprawny(koordynaty pozycja, koordynaty dopoz);
};

