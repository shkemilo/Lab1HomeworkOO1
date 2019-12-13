#pragma once
#include "Korisnik.h"

class TestKorisnik : public Korisnik
{
public:
	explicit TestKorisnik(std::string username) : Korisnik(username) {}

	void SendObavestenje(Korisnik& reciver, Obavestenje& obavestenje) override { }
	void AcceptObavestenje(Obavestenje& obavestenje) override { } 
};

