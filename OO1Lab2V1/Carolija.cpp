#include <string>

#include "Carolija.h"

Carolija::Carolija(std::string ime, int cost) : Karta(ime, cost)
{
}

std::string Carolija::GetCategory() const
{
	return "CAROLIJA";
}
