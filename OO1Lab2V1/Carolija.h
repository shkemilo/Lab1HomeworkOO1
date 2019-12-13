#pragma once
#include <string>

#include "Karta.h"

class Carolija : public Karta
{
public:
	Carolija(std::string ime, int cost);
	Carolija(const Carolija&) = delete;
	Carolija(Carolija&&) = delete;

	Carolija& operator=(const Carolija&) = delete;
	Carolija& operator=(Carolija&&) = delete;

	std::string GetCategory() const override;
};

