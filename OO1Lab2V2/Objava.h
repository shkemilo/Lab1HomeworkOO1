#pragma once
#include "Obavestenje.h"
#include <string>

class Objava : public Obavestenje
{
public:
	Objava(Korisnik& korisnik, std::string tekst);

	Obavestenje* clone() const override;

protected:
	std::ostream& output(std::ostream& os) const override;

private:
	std::string tekst;
};

