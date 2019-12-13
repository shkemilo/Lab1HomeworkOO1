#include <iostream>
#include <string>

#include "Carobnjak.h"
#include "Igrac.h"
#include "Borac.h"

Carobnjak::Carobnjak(std::string ime, int cost, int snaga) : Borac(ime, cost, snaga)
{
}

void Carobnjak::Use(Igrac& user, Igrac& target)
{
	if (!isUsed)
	{
		isUsed = true;
		return;
	}

	Borac* minBorac = findMinBorac(target);
	if (minBorac != nullptr)
	{
		target.GetGraveyard().AddKarta(target.GetActive()(minBorac->GetId()));
	}

	target.ChangeHp(-2 * snaga);
}

std::ostream& Carobnjak::output(std::ostream& os) const
{
	return Borac::output(os) << " - " << "CAROBNJAK";
}

Borac* Carobnjak::findMinBorac(Igrac& target)
{
	Borac* minBorac = nullptr;
	for (int i = 0; i < target.GetActive().GetLength(); i++)
	{
		Borac* borac = dynamic_cast<Borac*>(&target.GetActive()[i]);
		if (borac != nullptr)
		{
			if (minBorac == nullptr)
				minBorac = borac;
			else if (* minBorac > * borac)
				minBorac = borac;
		}
	}

	return minBorac;
}
