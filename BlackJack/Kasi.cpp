#include "Kasi.h"
#include "Kortti.h"
#include "Korttikenka.h"

using namespace std;

Kasi::Kasi()
{}

void Kasi::OtaKortti(Kortti k)
{
	Kasikortit.push_back(k);
}

void Kasi::TulostaKasi()
{
	int n = Kasikortit.size();

	cout << "              ";
	for (int k = 0; k < n; k++)

		cout << Kasikortit.at(k).KerroKorttitiedot() + " ";

	cout << "\n";
}

void Kasi::TulostaKasiJakaja()
{
	int n = Kasikortit.size();

	cout << "              ";
	for (int k = 0; k < n; k++)
		if (k > 0) { cout << Kasikortit.at(k).KerroKorttitiedot() + " "; }
		else { cout << "###### "; }

	cout << "\n";
}

int Kasi::KadenArvo1()
{
	int n = Kasikortit.size();
	int summa = 0;

	string kortti = "";

	for (int k = 0; k < n; k++)
	{
		kortti = Kasikortit.at(k).KerroKorttitiedot();
		string temp = kortti.substr(kortti.length() - 1, kortti.length());
		
		if (temp == "A")
			summa = summa + 1;
		else if (temp == "0" || temp == "J" || temp == "Q" || temp == "K")
			summa = summa + 10;
		else if (stoi(temp) < 10 && stoi(temp) > 1)
			summa = summa + stoi(temp);

		if (k > 1 && summa == 21) { summa = 21; }
		if (k > 1 && summa > 21) { summa = 0; }
	}
	return summa;
}

int Kasi::KadenArvo2()
{
	int n = Kasikortit.size();
	int summa = 0;
	int assa = 0;

	string kortti = "";

	for (int k = 0; k < n; k++)
	{
		kortti = Kasikortit.at(k).KerroKorttitiedot();
		string temp = kortti.substr(kortti.length() - 1, kortti.length());

		if (k > 1 && temp == "A")
			summa = summa + 1;
		else if (temp == "A")
			summa = summa + 11;
		else if (temp == "0" || temp == "J" || temp == "Q" || temp == "K")
			summa = summa + 10;
		else if (stoi(temp) < 10 && stoi(temp) > 1)
			summa = summa + stoi(temp);

		if (k == 1 && summa == 21) { summa = 99; }
		if (k == 1 && summa == 22) { summa = 12; }

		if (k > 1 && summa == 21) { summa = 21; }
		if (k > 1 && summa > 21) { summa = 0; }
	}
	return summa;
}

tuple <int, int> Kasi::KadenArvo(int arvo1, int arvo2)
{
	//cout << arvo1 << " tai " << arvo2 << "\n\n";

	return make_tuple(arvo1, arvo2);
}

void Kasi::TulostaKadenArvo(tuple <int, int> kadenarvo)
{
	if (get<0>(kadenarvo) == 0)
		cout << "(K\x84si on yli!)" << " H\x84visit!\n\n";
	else if (get<0>(kadenarvo) == 21 || get<1>(kadenarvo) == 21)
		cout << "(K\x84" << "den arvo on : 21)\n\n";
	else if (get<0>(kadenarvo) == 0 && get<1>(kadenarvo) == 0)
		cout << "(K\x84si on yli!)" << " H\x84visit!\n\n";
	else if (get<0>(kadenarvo) == (get<1>(kadenarvo)))
		cout << "(K\x84" << "den arvo on: " << get<0>(kadenarvo) << ")\n\n";
	else if (get<1>(kadenarvo) == 99)
		cout << "(Blackjack!)" << " Voitit!\n\n";
	else if (get<0>(kadenarvo) > get<1>(kadenarvo))
		cout << "(K\x84" << "den arvo on: " << get<0>(kadenarvo) << ")\n\n";
	else if (get<1>(kadenarvo) == 0)
		cout << "(K\x84" << "den arvo on: " << get<0>(kadenarvo) << ")\n\n";
	else if (get<1>(kadenarvo) != 0)
		cout << "(K\x84" << "den arvo on: " << get<0>(kadenarvo) << " tai " << get<1>(kadenarvo) << ")\n\n";
}

string Kasi::PalautaKadenArvo(tuple<int, int> kadenarvo)
{
	string arvo = "";

	if (get<0>(kadenarvo) == 0)
		arvo = "yli";
	else if (get<0>(kadenarvo) == 21 || get<1>(kadenarvo) == 21)
		arvo = "21";
	else if (get<0>(kadenarvo) == 0 && get<1>(kadenarvo) == 0)
		arvo = "yli";
	else if (get<0>(kadenarvo) == (get<1>(kadenarvo)))
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) == 99)
		arvo = "Blackjack";
	else if (get<0>(kadenarvo) > get<1>(kadenarvo))
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) == 0)
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) != 0)
		arvo = to_string(get<0>(kadenarvo)) + " tai " + to_string(get<1>(kadenarvo));

	return arvo;
}

string Kasi::PalautaKadenArvoJakaja(tuple<int, int> kadenarvo)
{
	string arvo = "";

	if (get<0>(kadenarvo) == 0)
		arvo = "22";
	else if (get<0>(kadenarvo) == 21 || get<1>(kadenarvo) == 21)
		arvo = "21";
	else if (get<0>(kadenarvo) == 0 && get<1>(kadenarvo) == 0)
		arvo = "22";
	else if (get<0>(kadenarvo) == (get<1>(kadenarvo)))
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) == 99)
		arvo = "Blackjack";
	else if (get<0>(kadenarvo) > get<1>(kadenarvo))
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) == 0)
		arvo = to_string(get<0>(kadenarvo));
	else if (get<1>(kadenarvo) != 0)
		arvo = to_string(get<0>(kadenarvo)) + " tai " + to_string(get<1>(kadenarvo));

	return arvo;
}

void Kasi::TyhjennaKasi()
{
	Kasikortit.clear();
}