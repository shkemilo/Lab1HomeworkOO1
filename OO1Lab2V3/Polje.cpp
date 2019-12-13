#include "Polje.h"

Polje::Polje(int neprohodnost)
{
	if (isInRange(neprohodnost))
	{
		this->neprohodnost = neprohodnost;
	}
}

int Polje::GetNeprohodnost() const
{
	return neprohodnost;
}

void Polje::SetNeprohodnost(int neprohodnost)
{
	this->neprohodnost = neprohodnost;
}

const Polje& Polje::operator++(int dummy)
{
	Polje* temp = clone();
	if (isInRange(neprohodnost + 1))
		neprohodnost = neprohodnost + 1;

	return *temp;
}

const Polje& Polje::operator--(int dummy)
{
	Polje* temp = clone();
	if (isInRange(neprohodnost - 1))
		neprohodnost = neprohodnost - 1;

	return *temp;
}

Polje* Polje::clone() const
{
	return new Polje(*this);
}

char Polje::oznaka() const
{
	return 'P';
}

std::ostream& Polje::output(std::ostream& os) const
{
	os << oznaka() << '_' << neprohodnost;

	return os;
}

std::ostream& operator<<(std::ostream& os, const Polje& polje)
{
	return polje.output(os);
}

bool Polje::isInRange(int neprohodnost) const
{
	return (neprohodnost >= 0 && neprohodnost <= 1000);
}
