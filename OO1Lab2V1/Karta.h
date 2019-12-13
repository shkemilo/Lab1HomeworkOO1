#pragma once
#include <iostream>
#include <string>

class Igrac;

class Karta
{
public:
	Karta(std::string ime, int cost);
	Karta(const Karta&) = delete;
	Karta(Karta&&) = delete;

	Karta& operator=(const Karta&) = delete;
	Karta& operator=(Karta&&) = delete;

	std::string GetIme() const;
	int GetCost() const;
	unsigned int GetId() const;

	virtual void Use(Igrac& user, Igrac& target) = 0;
	virtual std::string GetCategory() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Karta& karta);

	virtual ~Karta() { }
protected:
	virtual std::ostream& output(std::ostream& os) const;

	std::string ime;
	int cost;

	unsigned int id = nextId++;

private:
	static unsigned int nextId;
};

