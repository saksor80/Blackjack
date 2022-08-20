#pragma once

#ifndef KORTTI_H
#define KORTTI_H

#include <iostream>
#include <string>

using namespace std;

class Kortti
{
private:
	string maa = string();
	string pisteluku = "";

public:
	void LaitaKorttitiedot(string m, string n);
	string OtaKortti(Kortti);
	string KerroKorttitiedot();
};

#endif // KORTTI_H
