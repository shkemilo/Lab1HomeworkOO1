#include <string>
#include <iostream>

#include "Borac.h"
#include "Karta.h"

Borac::Borac(std::string ime, int cost, int snaga) : Karta(ime, cost), snaga(snaga)
{
}

void Borac::Use(Igrac& user, Igrac& target)
{
	if (!isUsed)
		isUsed = true;
}

std::string Borac::GetCategory() const
{
	return "BORAC";
}

std::ostream& Borac::output(std::ostream& os) const
{
	return Karta::output(os) << " (snaga: " << snaga << ")";
}

bool operator>(const Borac& borac1, const Borac& borac2)
{
	return borac1.snaga > borac2.snaga;
}
