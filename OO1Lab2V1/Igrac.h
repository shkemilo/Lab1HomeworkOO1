#pragma once
#include <string>

#include "Zbirka.h"

class Igrac
{
public:
	Igrac(std::string ime, int hp, int mp, const Zbirka& deck);
	Igrac(const Igrac&) = default;
	Igrac(Igrac&&) = default;

	Igrac& operator=(const Igrac&) = default;
	Igrac& operator=(Igrac&&) = default;

	bool Activate(int index);
	bool Activate(unsigned int id);

	bool IsInShadowRealm() const;

	void ChangeHp(int change);
	void ChangeMp(int change);

	std::string GetIme() const;
	int GetHp() const;
	int GetMp() const;

	Zbirka& GetDeck();
	Zbirka& GetActive();
	Zbirka& GetHand();
	Zbirka& GetGraveyard();

	const Zbirka& GetDeck() const;
	const Zbirka& GetActive() const;
	const Zbirka& GetHand() const;
	const Zbirka& GetGraveyard() const;

	~Igrac() = default;
private:
	std::string ime;
	int hp;
	int mp;

	Zbirka deck;
	Zbirka active;
	Zbirka hand;
	Zbirka graveyard;
};

