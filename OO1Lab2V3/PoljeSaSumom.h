#pragma once
#include "Polje.h"
#include <iostream>

class PoljeSaSumom : public Polje
{
public:
	explicit PoljeSaSumom(unsigned int gustina, int neprohodnost = 100);
	PoljeSaSumom(unsigned int gustina, const Polje& polje);

	Polje* clone() const override;

protected:
	char oznaka() const override;

	virtual std::ostream& output(std::ostream& os) const override;

private:
	unsigned int gustina;
};

