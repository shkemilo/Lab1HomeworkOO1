#include "PoljeSaSumom.h"

PoljeSaSumom::PoljeSaSumom(unsigned int gustina, int neprohodnost) : Polje(neprohodnost), gustina(gustina)
{
}

PoljeSaSumom::PoljeSaSumom(unsigned int gustina, const Polje& polje) : Polje(polje), gustina(gustina)
{
}

std::ostream& PoljeSaSumom::output(std::ostream& os) const
{
	return Polje::output(os) << '(' << gustina << ')';
}

Polje* PoljeSaSumom::clone() const
{
	return new PoljeSaSumom(*this);
}

char PoljeSaSumom::oznaka() const
{
	return 'S';
}
