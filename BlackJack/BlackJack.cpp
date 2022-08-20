// Sakari Sorja 20.8.2022
// Konsolissa ajettava Blackjack-peli

#include "Kortti.h"
#include "Korttikenka.h"
#include "Kasi.h"
#include "Poyta.h"
#include "Pelaaja.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()			// P‰‰ohjelma
{
	// M‰‰ritell‰‰n muuttujat, luodaan oliot ja sekoitetaan korttikenk‰
	int valinta;
	char toisto = ' ';
	char uusijako = ' ';
	string jkarvo = "";
	string kadenarvo = "";
	string nimi = "";

	Pelaaja p1 = Pelaaja();
	Poyta poyta1 = Poyta();

	// Korttikeng‰ss‰ 4 pakkaa ja ne sekoitetaan
	Korttikenka kk1 = Korttikenka();
	kk1.SekoitaKorttikenka();

	Kasi kasi1 = Kasi();
	Kasi kasi8 = Kasi();

	//P‰‰silmukka
	do
	{
		// Ohjelman p‰‰valikko
		cout << "\n\nBlackjack - Valikko\n\n";
		cout << "1. Anna pelaajan nimi \n";
		cout << "2. Siirry pelip\x94yt\x84\x84n \n";
		cout << "3. Poistu pelist\x84 \n";
		cin >> valinta;
		
		// P‰‰valikon valinnat
		switch (valinta)
		{
		case 1:
			// Pelaaja voi antaa nimens‰, jolla menee pelipˆyt‰‰n
			system("cls");
			cout << "Ole hyv\x84 ja anna nimesi: \n";
			cin >> nimi;
			p1.AsetaNimi(nimi);
			cout << "Kiitos ett\x84 annoit nimesi! Onnea pelip\x94yt\x84\x84n!";
			break;
		case 2:
			// Pelipˆyt‰-silmukka
			system("cls");
			do
			{
				// Tarkistetaan onko nimi annettu, jos ei niin kutsutaan vain pelaajaksi
				if (nimi == "")
				{
					nimi = "Pelaaja";
					p1.AsetaNimi(nimi);
				}

				// Jaetaan korttikeng‰st‰ aloituskortit Jakajalle ja pelaajalle (K‰si 8 on jakajan k‰si, koska muita pelaajan
				// k‰si‰ voisi olla viel‰ 6 lis‰‰)
				kasi1.OtaKortti(kk1.AnnaPaalimmainenKortti());
				kasi8.OtaKortti(kk1.AnnaPaalimmainenKortti());
				kasi1.OtaKortti(kk1.AnnaPaalimmainenKortti());
				kasi8.OtaKortti(kk1.AnnaPaalimmainenKortti());
				//K‰sien arvojen laskentaa
				kadenarvo = kasi1.PalautaKadenArvo(kasi1.KadenArvo(kasi1.KadenArvo1(), kasi1.KadenArvo2()));
				jkarvo = kasi8.PalautaKadenArvo(kasi8.KadenArvo(kasi8.KadenArvo1(), kasi8.KadenArvo2()));
				
				//Korttienjako-silmukka
				do
				{
					// Tarkistetaan onko korttikeng‰ss‰ tarpeeksi kortteja j‰ljell‰, jos ei niin luodaan uusi korttikenk‰ ja sekoitetaan se
					if (kk1.PalautaKorttikenganKoko() < 20)
					{
						cout << "Kortit ovat loppumassa, soikoitetaan uusi korttikenka! Hetki..";
						kk1.LuoKorttikenkaUudelleen();
						kk1.SekoitaKorttikenka();
						system("cls");
					}
					// Varsinainen pelitilanne alkaa ja katsotaan onko pelaajalla Blackjack
					cout << "\n";
					cout << "                 " << "Jakaja" << "       \n\n";
					kasi8.TulostaKasiJakaja();
					poyta1.TulostaPoyta();
					cout << "             " << " " << p1.PalautaNimi() << " ";
					kasi1.TulostaKadenArvo(kasi1.KadenArvo(kasi1.KadenArvo1(), kasi1.KadenArvo2()));
					kasi1.TulostaKasi();
					cout << "--------------------------------------------------\n";
					if (kadenarvo == "yli") { break; }
					if (kadenarvo == "21") { break; }
					if (kadenarvo == "Blackjack") { break; }
					// Kysyt‰‰n ottaako pelaaja lis‰‰ kortteja ja toistetaan niin monta kertaa kun pelaaja ottaa kortin tai menee yli
					cout << "              Otatko uuden kortin (k/e)? ";
					cin >> toisto;
					if (toisto == 'k' || toisto == 'K') { kasi1.OtaKortti(kk1.AnnaPaalimmainenKortti()); }
					kadenarvo = kasi1.PalautaKadenArvo(kasi1.KadenArvo(kasi1.KadenArvo1(), kasi1.KadenArvo2()));
					system("cls");

				} while (toisto == 'k' || toisto == 'K');
				system("cls");
				// Katsotaan l‰pi jakajan k‰si ja jos k‰si ei ole Blackjack aletaan ottamaan jakalle kortteja jos k‰den arvo on alle 17,
				// mihin jakajan pit‰‰ j‰‰d‰
				if (jkarvo != "Blackjack")
				{
					while (stoi(jkarvo) < 17 && kadenarvo != "yli" && kadenarvo != "Blackjack")
					{
						kasi8.OtaKortti(kk1.AnnaPaalimmainenKortti());
						jkarvo = kasi8.PalautaKadenArvoJakaja(kasi8.KadenArvo(kasi8.KadenArvo1(), kasi8.KadenArvo2()));
					}
				}
				// P‰ivitet‰‰n pelin lopputilanne ruudulle ja k‰yd‰‰n l‰pi kumpi voittaa
				cout << "\n";
				cout << "                 " << "Jakaja" << "           ";
				if (kadenarvo.length() < 3 && jkarvo != "Blackjack")
				{
					if (stoi(jkarvo) > stoi(kadenarvo) && stoi(jkarvo) != 22) { cout << "Jakaja voittaa!"; }
					if (stoi(jkarvo) < stoi(kadenarvo)) { cout << "Pelaaja voittaa!"; }
					if (jkarvo == "22") { cout << "Pelaaja voittaa!"; }
					if (jkarvo == kadenarvo) { cout << "Tasapeli!"; }
				}
				if (jkarvo == "Blackjack") { cout << "Blackjack - Jakaja voittaa!"; }
				cout << "\n\n";
				kasi8.TulostaKasi();
				poyta1.TulostaPoyta();
				cout << "             " << " " << p1.PalautaNimi() << " ";
				kasi1.TulostaKadenArvo(kasi1.KadenArvo(kasi1.KadenArvo1(), kasi1.KadenArvo2()));
				kasi1.TulostaKasi();
				cout << "--------------------------------------------------\n";

				//Lopuksi tallennetaan pelin lopputulema logitiedostoon
				streambuf* psbuf, * backup;
				ofstream tiedosto;
				tiedosto.open("logitiedosto.txt", fstream::app);

				backup = cout.rdbuf();

				psbuf = tiedosto.rdbuf();
				cout.rdbuf(psbuf); 

				cout << "\n";
				cout << "                 " << "Jakaja" << "           ";
				if (kadenarvo.length() < 3 && jkarvo != "Blackjack")
				{
					if (stoi(jkarvo) > stoi(kadenarvo) && stoi(jkarvo) != 22) { cout << "Jakaja voittaa!"; }
					if (stoi(jkarvo) < stoi(kadenarvo)) { cout << "Pelaaja voittaa!"; }
					if (jkarvo == "22") { cout << "Pelaaja voittaa!"; }
					if (jkarvo == kadenarvo) { cout << "Tasapeli!"; }
				}
				if (jkarvo == "Blackjack") { cout << "Blackjack - Jakaja voittaa!"; }
				cout << "\n\n";
				kasi8.TulostaKasi();
				poyta1.TulostaPoyta();
				cout << "             " << " " << p1.PalautaNimi() << " ";
				kasi1.TulostaKadenArvo(kasi1.KadenArvo(kasi1.KadenArvo1(), kasi1.KadenArvo2()));
				kasi1.TulostaKasi();
				cout << "--------------------------------------------------\n";
				cout.rdbuf(backup);

				tiedosto.close();
				// Pelipˆyt‰ silmukka kysyy pelataanko viel‰ uusi kierros peli‰
				cout << "              Pelataanko uusi kierros (k/e)? ";
				cin >> uusijako;
				kasi1.TyhjennaKasi();
				kasi8.TyhjennaKasi();
				kadenarvo = "";
				system("cls");
			} while (uusijako == 'k' || uusijako == 'K');
			break;
		case 3:
			// P‰‰valikosta (P‰‰silmukka) poistuminen
			cout << "Kiitos k\x84ynnist\x84 ja N\x84kemiin!";
			return 3;
			break;
			// Tarkistetaan v‰‰r‰ valikkovalinta
		default:
			cout << "Vaara valinta, valitse uudelleen";
			break;
		}
	} while (valinta != 3);
}   