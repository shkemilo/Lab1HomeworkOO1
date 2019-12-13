#include <iostream>

#include "Polje.h"
#include "PoljeSaPutem.h"
#include "PoljeSaSumom.h"
#include "Mapa.h"

using namespace std;

int main()
{
	Polje p;
	PoljeSaSumom ps(100, p);

	cout << ps++ << endl;
	cout << ps << endl;

	Mapa m(4, 4);

	m += 10;

	cout << m << endl;

	m.ChangeField(0, 0, KAMENI);
	m.ChangeField(1, 1, 50);
	m.ChangeField(2, 2, ZEMLJANI);
	m.ChangeField(3, 3, 100);

	Mapa m1 = m;
	m -= 5;

	cout << m1 << endl;

	m1 = m;

	cout << m1 << endl;

	cout << (m += 15) << endl;

	system("pause");
	return 0;
}