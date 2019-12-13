#include "Obavestenje.h"
#include "Korisnik.h"
#include <iomanip>
#include <ctime>

unsigned int Obavestenje::nextId = 0;

Obavestenje::Obavestenje(Korisnik& korisnik) : korisnik(korisnik)
{
	time_t now = time(0);
	localtime_s(&localTime, &now);
}

unsigned int Obavestenje::GetId() const
{
	return id;
}

const Korisnik& Obavestenje::GetKorisnik() const
{
	return korisnik;
}

Korisnik& Obavestenje::GetKorisnik()
{
	return korisnik;
}

bool Obavestenje::IsRead() const
{
	return read;
}

void Obavestenje::Read()
{
	read = true;
}

Obavestenje* Obavestenje::clone() const
{
	return new Obavestenje(*this);
}

std::ostream& operator<<(std::ostream& os, const Obavestenje& obavestenje)
{
	return obavestenje.output(os);
}

std::ostream& Obavestenje::output(std::ostream& os) const
{
	return os << id << '|' << korisnik << '-' 
		<< std::setfill('0')
		<< std::setw(2) << localTime.tm_hour << ':'
		<< std::setw(2) << localTime.tm_min << ':'
		<< std::setw(2) << localTime.tm_sec;
}

