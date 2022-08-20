#pragma once

#ifndef KASI_H
#define KASI_H

#include "Kortti.h"
#include "Korttikenka.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Kasi
{
private:
	std::vector<Kortti> Kasikortit;

public:
	Kasi();
	void OtaKortti(Kortti k);
	void TulostaKasi();
	void TulostaKasiJakaja();
	int KadenArvo1();
	int KadenArvo2();
	tuple<int,int> KadenArvo(int arvo1, int arvo2);
	string PalautaKadenArvo(tuple <int, int>);
	string PalautaKadenArvoJakaja(tuple <int, int>);
	void TulostaKadenArvo(tuple <int,int>);
	void TyhjennaKasi();
};

#endif // KASI_H