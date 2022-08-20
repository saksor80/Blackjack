#include "Henkilo.h"

Henkilo::Henkilo()
{}

void Henkilo::AsetaNimi(string nimi)
{
	this->nimi = nimi;
}

string Henkilo::PalautaNimi()
{
	return nimi;
}