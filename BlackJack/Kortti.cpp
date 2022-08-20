#include "Kortti.h"

void Kortti::LaitaKorttitiedot(string m, string n)
{
    this->maa = m;
    this->pisteluku = n;
}

string Kortti::OtaKortti(Kortti k)
{
    return k.KerroKorttitiedot();
}

string Kortti::KerroKorttitiedot()
{
    string info = maa + pisteluku;
    return info;
}