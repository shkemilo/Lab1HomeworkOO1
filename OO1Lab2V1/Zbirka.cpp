#include <cstdlib> 
#include <iostream>

#include "Zbirka.h"
#include "Karta.h"

Zbirka::Zbirka(const Zbirka& zbirka)
{
	copy(zbirka);
}

Zbirka::Zbirka(Zbirka&& zbirka)
{
	move(zbirka);
}

Zbirka& Zbirka::AddKarta(Karta& karta)
{
	if (head != nullptr)
		tail = tail->next = new Elem(karta);
	else
		head = tail = new Elem(karta);

	length++;

	return *this;
}

int Zbirka::GetLength() const
{
	return length;
}

Zbirka& Zbirka::operator=(const Zbirka& zbirka)
{
	destroy();

	copy(zbirka);

	return *this;
}

Zbirka& Zbirka::operator=(Zbirka&& zbirka)
{
	destroy();

	move(zbirka);

	return *this;
}

Karta& Zbirka::operator[](int index)
{
	return findIndex(index);
}

const Karta& Zbirka::operator[](int index) const
{
	return findIndex(index);
}

Karta& Zbirka::operator[](unsigned int id)
{
	return findId(id);
}

const Karta& Zbirka::operator[](unsigned int id) const
{
	return findId(id);
}

Karta& Zbirka::operator()(int index)
{
	return remove(index);
}

Karta& Zbirka::operator()(unsigned int id)
{
	return remove(id);
}

Zbirka& Zbirka::operator~()
{
	if (length == 0) 
		return *this;

	remove(random(length - 1));

	return *this;
}

Zbirka::~Zbirka()
{
	destroy();
}

void Zbirka::copy(const Zbirka& zbirka)
{
	length = zbirka.length;
	for (Elem* curr = zbirka.head; curr != nullptr; curr = curr->next)
	{
		tail = (head != nullptr ? tail->next : head) = new Elem(*curr);
	}
}

void Zbirka::move(Zbirka& zbirka)
{
	length = zbirka.length;
	head = zbirka.head;
	tail = zbirka.tail;

	zbirka.head = zbirka.tail = nullptr;
}

void Zbirka::destroy()
{
	Elem* curr = head;
	while (head != nullptr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
}

Karta& Zbirka::findIndex(int index) const
{
	if (length <= index)
	{
		std::cout << "Indeks je van opsega zbirke!" << std::endl;
		exit(1);
	}

	Elem* curr = head;
	for (int i = 0; i < index; i++, curr = curr->next);

	return curr->karta;
}

Karta& Zbirka::findId(unsigned int id) const
{
	Elem* curr;
	for (curr = head; curr->karta.GetId() != id && curr != nullptr; curr = curr->next);

	if (curr == nullptr)
	{
		std::cout << "Element sa tim id-em ne postoji!" << std::endl;
		exit(1);
	}

	return curr->karta;
}

Karta& Zbirka::remove(int index)
{
	if (length <= index)
	{
		std::cout << "Indeks je van opsega zbirke!" << std::endl;
		exit(1);
	}

	Elem* curr = head, * prev = nullptr;
	for (int i = 0; i < index; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	return remove(prev, curr);
}

Karta& Zbirka::remove(unsigned int id)
{
	Elem* curr = head, * prev = nullptr;
	for (; curr->karta.GetId() != id && curr != nullptr; prev = curr, curr = curr->next);

	if (curr == nullptr)
	{
		std::cout << "Element sa tim id-em ne postoji!" << std::endl;
		exit(1);
	}

	return remove(prev, curr);
}

Karta& Zbirka::remove(Elem*& prev, Elem*& curr)
{
	if (curr == head)
	{
		head = head->next;
	}
	if (curr == tail)
	{
		tail = prev;
	}

	if (prev != nullptr)
		prev->next = curr->next;

	curr->next = nullptr;

	Karta& karta = curr->karta;
	delete curr;
	length--;

	return karta;
}

int Zbirka::random(int high, int low)
{
	return (int)(((rand() * 1.0) / RAND_MAX) * (1.*high - low + 1) + low);
}

std::ostream& operator<<(std::ostream& os, const Zbirka& zbirka)
{
	for (Zbirka::Elem* curr = zbirka.head; curr != nullptr; curr = curr->next)
		os << curr->karta << std::endl;

	return os;
}
