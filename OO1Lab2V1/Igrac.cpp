#include <string>

#include "Igrac.h"

Igrac::Igrac(std::string ime, int hp, int mp, const Zbirka& deck) : ime(ime), hp(hp), mp(mp), deck(deck)
{
}

bool Igrac::Activate(int index)
{
	int cost = hand[index].GetCost();
	if (mp >= cost)
	{
		ChangeMp(-cost);
		active.AddKarta(hand(index));

		return true;
	}

	return false;
}

bool Igrac::Activate(unsigned int id)
{
	int cost = hand[id].GetCost();
	if (mp >= cost)
	{
		ChangeMp(-cost);
		active.AddKarta(hand(id));

		return true;
	}

	return false;
}

bool Igrac::IsInShadowRealm() const
{
	return hp <= 0;
}

void Igrac::ChangeHp(int change)
{
	hp += change;
}

void Igrac::ChangeMp(int change)
{
	mp += change;
}

std::string Igrac::GetIme() const
{
	return ime;
}

int Igrac::GetHp() const
{
	return hp;
}

int Igrac::GetMp() const
{
	return mp;
}

Zbirka& Igrac::GetDeck()
{
	return deck;
}

Zbirka& Igrac::GetActive()
{
	return active;
}

Zbirka& Igrac::GetHand()
{
	return hand;
}

Zbirka& Igrac::GetGraveyard()
{
	return graveyard;
}

const Zbirka& Igrac::GetDeck() const
{
	return deck;
}

const Zbirka& Igrac::GetActive() const
{
	return active;
}

const Zbirka& Igrac::GetHand() const
{
	return hand;
}

const Zbirka& Igrac::GetGraveyard() const
{
	return graveyard;
}
