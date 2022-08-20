#pragma once

#ifndef KORTTIKENKA_H
#define KORTTIKENKA_H

#include "Kortti.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector> 
#include <stdlib.h>
#include <time.h>

using namespace std;


class Korttikenka
{
private:
	 std::vector<Kortti> Kortit;

public:
	Korttikenka();
	void LuoKorttikenkaUudelleen();
	void SekoitaKorttikenka();
	void TulostaKortti(int p);
	void TulostaKorttikenka();
    Kortti AnnaPaalimmainenKortti();
	int PalautaKorttikenganKoko();
};

#endif // KORTTIKENKA_H

