#pragma once
#include "Obavestenje.h"
#include <iostream>

class ListaObavestenja
{
public:
	ListaObavestenja() = default;
	ListaObavestenja(const ListaObavestenja&) = delete;
	ListaObavestenja(ListaObavestenja&&) = delete;

	ListaObavestenja& operator=(const ListaObavestenja&) = delete;
	ListaObavestenja& operator=(ListaObavestenja&&) = delete;

	void operator()(std::ostream& os = std::cout) const; 
	const Obavestenje& operator[](const unsigned int id) const;
	int operator+() const; 

	ListaObavestenja& operator+=(Obavestenje& obavestenje);
	ListaObavestenja& operator!(); 
	ListaObavestenja& operator~(); 
	Obavestenje& operator[](const unsigned int id);

	friend std::ostream& operator<<(std::ostream& os, const ListaObavestenja& listaObavestenja);

	~ListaObavestenja();
private:
	void destroy();

	struct Elem
	{
		Elem(Obavestenje& obavestenje);
		
		Obavestenje& obavestenje;

		Elem* next = nullptr;
	};

	Elem* head = nullptr;
};

