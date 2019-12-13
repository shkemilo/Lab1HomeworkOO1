#pragma once
#include <iostream>
#include <string>

#include "Borac.h"

class Igrac;

class Carobnjak : public Borac
{
public:
	Carobnjak(std::string ime, int cost, int snaga);
	Carobnjak(const Carobnjak&) = delete;
	Carobnjak(Carobnjak&&) = delete;

	Carobnjak& operator=(const Carobnjak&) = delete;
	Carobnjak& operator=(Carobnjak&&) = delete;

	void Use(Igrac& user, Igrac& target) override;

protected:
	std::ostream& output(std::ostream& os) const override;

private:
	static Borac* findMinBorac(Igrac& target);
};

