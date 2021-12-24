#pragma once
#include "figura.h"
#include "funkcje.h"


class pole
{
private:

	figura* figuraNaPolu;

public:

	pole();
	~pole();


	void WstawFigure(figura* figura);

	figura* JakaFigura();


};