#include "Korisnik.h"

Korisnik::Korisnik(std::string username) : username(username)
{
}

std::string Korisnik::GetUsername() const
{
	return username;
}

std::ostream& Korisnik::output(std::ostream& os) const
{
	return os << username;
}

std::ostream& operator<<(std::ostream& os, const Korisnik& korisnik)
{
	return korisnik.output(os);
}
