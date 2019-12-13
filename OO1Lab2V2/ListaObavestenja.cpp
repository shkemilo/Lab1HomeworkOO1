#include "ListaObavestenja.h"

ListaObavestenja::Elem::Elem(Obavestenje& obavestenje) : obavestenje(obavestenje)
{
}

ListaObavestenja& ListaObavestenja::operator+=(Obavestenje& obavestenje)
{
	Elem* temp = new Elem(obavestenje);
	if (head != nullptr)
	{
		temp->next = head;
	}

	head = temp;

	return *this;
}

void ListaObavestenja::operator()(std::ostream& os) const
{
	for (Elem* curr = head; curr != nullptr; curr = curr->next)
	{
		if (!curr->obavestenje.IsRead())
			os << curr->obavestenje << std::endl;
	}
}

int ListaObavestenja::operator+() const
{
	int count = 0;
	for (Elem* curr = head; curr != nullptr; curr = curr->next)
	{
		if (!curr->obavestenje.IsRead())
			count++;
	}

	return count;
}

ListaObavestenja& ListaObavestenja::operator!()
{
	for (Elem* curr = head; curr != nullptr; curr->obavestenje.Read(), curr = curr->next);
	
	return *this;
}

ListaObavestenja& ListaObavestenja::operator~()
{
	destroy();

	return *this;
}

Obavestenje& ListaObavestenja::operator[](const unsigned int id)
{
	for (Elem* curr = head; curr != nullptr; curr = curr->next)
	{
		if (curr->obavestenje.GetId() == id)
			return curr->obavestenje;
	}
	
	std::cout << "Nije pronadjeno obavestenje sa tim id-em" << std::endl;
	exit(1);
}

const Obavestenje& ListaObavestenja::operator[](const unsigned int id) const
{
	for (Elem* curr = head; curr != nullptr; curr = curr->next)
	{
		if (curr->obavestenje.GetId() == id)
			return curr->obavestenje;
	}

	std::cout << "Nije pronadjeno obavestenje sa tim id-em" << std::endl;
	exit(1);
}

ListaObavestenja::~ListaObavestenja()
{
	destroy();
}

void ListaObavestenja::destroy()
{
	Elem* curr = head;
	while (curr != nullptr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
	
	head = nullptr;
}

std::ostream& operator<<(std::ostream& os, const ListaObavestenja& listaObavestenja)
{
	for (ListaObavestenja::Elem* curr = listaObavestenja.head; curr != nullptr; curr = curr->next)
	{
		os << curr->obavestenje << std::endl;
	}

	return os;
}
