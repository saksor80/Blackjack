#pragma once
#ifndef HENKILO_H
#define HENKILO_H

#include <iostream>

using namespace std;

class Henkilo
{
private:
	string nimi = string();

public:
	Henkilo();
	void AsetaNimi(string nimi);
	string PalautaNimi();
};

#endif // HENKILO_H