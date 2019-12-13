#pragma once
#include "Polje.h"

enum VrstaPuta { ZEMLJANI, KAMENI };

class PoljeSaPutem : public Polje
{
public:	
	explicit PoljeSaPutem(VrstaPuta vrstaPuta, int neprohodnost = 100);
	PoljeSaPutem(VrstaPuta vrstaPuta, const Polje& polje);

	Polje* clone() const override;

protected:
	char oznaka() const override;

private:
	VrstaPuta vrstaPuta;
};

