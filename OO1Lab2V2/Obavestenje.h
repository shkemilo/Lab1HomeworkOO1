#pragma once
#include <iostream>
#include <ctime>

class Korisnik;

class Obavestenje
{
public:
	explicit Obavestenje(Korisnik& korisnik);

	unsigned int GetId() const;
	const Korisnik& GetKorisnik() const;
	Korisnik& GetKorisnik();
	bool IsRead() const;

	void Read();

	virtual Obavestenje* clone() const;

	friend std::ostream& operator<<(std::ostream& os, const Obavestenje& obavestenje);

	virtual ~Obavestenje() {}
protected:
	virtual std::ostream& output(std::ostream& os) const;

private:
	static unsigned int nextId;
	const unsigned int id = nextId++;

	struct tm localTime;

	bool read = false;

	Korisnik& korisnik;
};

