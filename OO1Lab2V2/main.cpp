#include <iostream>
#include "TestKorisnik.h"
#include "Objava.h"
#include"Obavestenje.h"
#include"ListaObavestenja.h"

using namespace std;

int main()
{
	TestKorisnik test1("Jusuf");
	TestKorisnik test2("Bobek");
	TestKorisnik test3("Mile");
	
	Obavestenje ob1(test1);
	Objava ob2(test2, "Deste bre ljudi");
	Objava ob3(test3, "Bobane budi govedo");

	ListaObavestenja list;
	((list += ob2) += ob1) += ob3;
	cout << "Ispis neprocitanih i broj neprocitanih: " << endl;
	list();
	cout << +list << endl;
	cout << endl;

	cout << "Obavestenje sa id-em 2: " << endl;
	cout << list[2] << endl;
	cout << endl;

	cout << "Citanje svih obavestenja, ispisivanje broja neprocitnah kao i ispisivanje procitanih: " << endl;
	!list;
	cout << +list << endl;
	list();
	cout << endl;

	cout << "Lista je: " << endl;
	cout << list << endl;
	cout << endl;

	cout << "Brisanje cele liste i ispis prazne liste: " << endl;
	cout << ~list << endl;

	system("pause");
	return 0;
}