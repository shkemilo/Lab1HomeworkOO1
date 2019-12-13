#include <iostream>
#include <ctime>
#include <string>

#include "Karta.h"
#include "Borac.h"
#include "Zbirka.h"
#include "Igrac.h"
#include "Carobnjak.h"

using namespace std;

void outputPlayers(const Igrac& p1, const Igrac& p2)
{
	cout << "-------------------------------------------------" << endl;
	cout << p1.GetIme() << " " << p1.GetHp() << " " << p1.GetMp() << endl << p1.GetActive() << endl;
	cout << p2.GetIme() << " " << p2.GetHp() << " " << p2.GetMp() << endl << p2.GetActive() << endl;
	cout << "-------------------------------------------------" << endl;
}

int main()
{
	Borac b1("Zeleni polubrat od Hulka", 2, 100);
	Borac b2("Husein kapetan Gradasevic sa krvavih njiva", 6, 500);
	Borac b3("Avlijski glupan", 3, 400);
	Borac b4("Dijego Armadona", 4, 300);
	Carobnjak c1("Sibirski plavac", 5, 1000);
	Carobnjak c2("Dzedaj Muharem", 4, 700);

	srand(time(nullptr));
	Zbirka deck1;
	deck1.AddKarta(b1).AddKarta(b2).AddKarta(c2);

	Zbirka deck2;
	deck2.AddKarta(b3).AddKarta(b4).AddKarta(c1);

	Igrac p1("Jusuf", 4000, 10, deck1);
	Igrac p2("Kaiba", 4000, 10, deck2);

	cout << "Kopija Jusufovog decka nakon 2 random izbacivanja: " << endl;
	{
		Igrac p = p2;
		p = p1;
		p.GetDeck() = p1.GetDeck();

		cout << ~(~(p.GetDeck())) << endl;
	}
	
	cout << "Jusufov deck: " << endl << p1.GetDeck() << endl;
	cout << "Kaibin deck: " << endl << p2.GetDeck() << endl;

	p1.GetHand() = deck1;
	p2.GetHand() = deck2;

	p1.Activate(0);

	outputPlayers(p1, p2);

	p2.Activate(2);
	p2.GetActive()[0].Use(p2, p1);

	outputPlayers(p1, p2);

	p1.Activate(1);
	p1.GetActive()[1].Use(p1, p2);

	outputPlayers(p1, p2);

	p2.GetActive()[0].Use(p2, p1);

	outputPlayers(p1, p2);

	p1.GetActive()[0].Use(p1, p2);

	outputPlayers(p1, p2);

	cout << "Jusuf groblje: " << endl << p1.GetGraveyard() << endl;
	cout << "Kaiba groblje: " << endl << p2.GetGraveyard() << endl;

	Carobnjak bik("Kuvani bik", 100, 5000);

	cout << "Jusuf pokusava da aktivira " << bik << " ali mu ne ide..." << endl;
	p1.GetHand().AddKarta(bik);
	
	cout << p1.Activate(1) << endl;
	cout << p1.GetActive() << endl;

	cout << "Pokusaj izbacivanje random elementa i ispisivanje prazne zbirke: " << endl;
	Zbirka z;
	cout << ~z << endl;
	
	system("pause");
	return 0;
}