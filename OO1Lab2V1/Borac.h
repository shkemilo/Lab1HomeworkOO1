#pragma once
#include <iostream>
#include <string>

#include "Karta.h"

class Igrac;

class Borac : public Karta
{
public:
	Borac(std::string ime, int cost, int snaga);
	Borac(const Borac&) = delete;
	Borac(Borac&&) = delete;

	Borac& operator=(const Borac&) = delete;
	Borac& operator=(Borac&&) = delete;

	void Use(Igrac& user, Igrac& target) override;
	std::string GetCategory() const override;

	friend bool operator>(const Borac& borac1, const Borac& borac2);
protected:
	std::ostream& output(std::ostream& os) const override;
	
	int snaga;

	bool isUsed = false;
private:
};

