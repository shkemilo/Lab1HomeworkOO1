#pragma once
#include <iostream>
#include <string>

#include "Karta.h"

class Zbirka
{
public:
	Zbirka() = default;
	Zbirka(const Zbirka& zbirka);
	Zbirka(Zbirka&& zbirka);

	Zbirka& AddKarta(Karta& karta);

	int GetLength() const;

	Zbirka& operator=(const Zbirka& zbirka);
	Zbirka& operator=(Zbirka&& zbirka);

	Karta& operator[](int index);
	const Karta& operator[](int index) const;

	Karta& operator[](unsigned int id);
	const Karta& operator[](unsigned int id) const;

	Karta& operator()(int index);
	Karta& operator()(unsigned int id);

	Zbirka& operator~();

	~Zbirka();

	friend std::ostream& operator<<(std::ostream& os, const Zbirka& zbirka);
private:
	struct Elem
	{
		Karta& karta;

		Elem* next = nullptr;

		Elem(Karta& karta) : karta(karta) { }
	};

	void copy(const Zbirka& zbirka);
	void move(Zbirka& zbirka);
	void destroy();
	Karta& findIndex(int index) const;
	Karta& findId(unsigned int id) const;
	Karta& remove(int index);
	Karta& remove(unsigned int id);
	Karta& remove(Elem*& prev, Elem*& curr);

	static int random(int high, int low = 0);

	Elem* head = nullptr;
	Elem* tail = nullptr;

	int length = 0;
};

