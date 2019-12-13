#include "PoljeSaPutem.h"

PoljeSaPutem::PoljeSaPutem(VrstaPuta vrstaPuta, int neprohodnost) : Polje(neprohodnost), vrstaPuta(vrstaPuta)
{
}

PoljeSaPutem::PoljeSaPutem(VrstaPuta vrstaPuta, const Polje& polje) : Polje(polje), vrstaPuta(vrstaPuta)
{
}

Polje* PoljeSaPutem::clone() const
{
	return new PoljeSaPutem(*this);
}

char PoljeSaPutem::oznaka() const
{
	switch (vrstaPuta)
	{
	case ZEMLJANI:
		return 'Z';
	case KAMENI:
		return 'K';
	default:
		exit(1);
	}
}
