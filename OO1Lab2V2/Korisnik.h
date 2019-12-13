#pragma once
#include <iostream>
#include <string>

#include "Obavestenje.h"

class Korisnik
{
public:
	explicit Korisnik(std::string username);
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;

	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

	std::string GetUsername() const;

	virtual void SendObavestenje(Korisnik& reciver, Obavestenje& obavestenje) = 0;
	virtual void AcceptObavestenje(Obavestenje& obavestenje) = 0;

	friend std::ostream& operator<<(std::ostream& os, const Korisnik& korisnik);
protected:
	virtual std::ostream& output(std::ostream& os) const;

private:
	std::string username;
};

