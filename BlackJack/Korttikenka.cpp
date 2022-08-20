#include "Korttikenka.h"
#include "Kortti.h"

Korttikenka::Korttikenka()
{
    for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++)
            for (int p = 2; p < 15; p++)
            {
                Kortti k;
                string temp;
                string n = "";

                if (m == 0)
                    temp = "Pata";
                else if (m == 1)
                    temp = "Risti";
                else if (m == 2)
                    temp = "Ruutu";
                else
                    temp = "Hertta";

                if (p < 11) { n = std::to_string(p); }
                if (p == 11) { n = "J"; }
                if (p == 12) { n = "Q"; }
                if (p == 13) { n = "K"; }
                if (p == 14) { n = "A"; }
                k.LaitaKorttitiedot(temp, n);

                Kortit.push_back(k);
            }
}

void Korttikenka::LuoKorttikenkaUudelleen()
{
    Kortit.clear();

    for (int l = 0; l < 4; l++)
        for (int m = 0; m < 4; m++)
            for (int p = 2; p < 15; p++)
            {
                Kortti k;
                string temp;
                string n = "";

                if (m == 0)
                    temp = "Pata";
                else if (m == 1)
                    temp = "Risti";
                else if (m == 2)
                    temp = "Ruutu";
                else
                    temp = "Hertta";

                if (p < 11) { n = std::to_string(p); }
                if (p == 11) { n = "J"; }
                if (p == 12) { n = "Q"; }
                if (p == 13) { n = "K"; }
                if (p == 14) { n = "A"; }
                k.LaitaKorttitiedot(temp, n);

                Kortit.push_back(k);
            }
}

void Korttikenka::SekoitaKorttikenka()
{
    srand((unsigned)time(NULL));

    int luku = rand();
    luku = luku % 10000;

    for (int i = 0; i < luku; i++)
    {
        std::random_shuffle(Kortit.begin(), Kortit.end());
    }
}

void Korttikenka::TulostaKortti(int p)
{
    cout << Kortit.at(p).KerroKorttitiedot();
}

void Korttikenka::TulostaKorttikenka()
{
    int n = Kortit.size();

    for (int k = 0; k < n; k++)
        cout<< Kortit.at(k).KerroKorttitiedot() + " ";
}

 Kortti Korttikenka::AnnaPaalimmainenKortti()
{
    Kortti k = Kortit.front();
    Kortit.erase(Kortit.begin());
    return k;
}

 int Korttikenka::PalautaKorttikenganKoko()
 {
     int koko = Kortit.size();
     return koko;
 }