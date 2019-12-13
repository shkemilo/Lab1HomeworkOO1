#include "Objava.h"

Objava::Objava(Korisnik& korisnik, std::string tekst) : Obavestenje(korisnik), tekst(tekst)
{
}

Obavestenje* Objava::clone() const
{
	return new Objava(*this);
}

std::ostream& Objava::output(std::ostream& os) const
{
	return Obavestenje::output(os) << std::endl << tekst;
}
