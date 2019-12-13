#include <string>
#include <iostream>

#include "Karta.h"
#include "Igrac.h"

unsigned int Karta::nextId = 0;

Karta::Karta(std::string ime, int cost) : ime(ime), cost(cost)
{
}

std::string Karta::GetIme() const
{
	return ime;
}

int Karta::GetCost() const
{
	return cost;
}

unsigned int Karta::GetId() const
{
	return id;
}

std::ostream& Karta::output(std::ostream& os) const
{
	return os << '[' << id << "] \"" 
		<< ime << "\" (cena: " << cost << ')';
}

std::ostream& operator<<(std::ostream& os, const Karta& karta)
{
	return karta.output(os);
}
