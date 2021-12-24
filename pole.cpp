#include "pole.h"


pole::pole()
{
	figuraNaPolu = NULL;
}

pole::~pole()
{
}

figura* pole::JakaFigura()
{
	return figuraNaPolu;
}

void pole::WstawFigure(figura* figura)
{
	this->figuraNaPolu = figura;
}