#include "Mapa.h"

Mapa::Mapa(int n, int m) : n(n), m(m)
{
	allocate();

	populate();
}

Mapa::Mapa(const Mapa& map)
{
	copy(map);
}

Mapa::Mapa(Mapa&& map)
{
	move(map);
}

Mapa& Mapa::operator=(const Mapa& map)
{
	if (this != &map)
	{
		destroy();

		copy(map);
	}

	return *this;
}

Mapa& Mapa::operator=(Mapa&& map)
{
	if (this != &map)
	{
		destroy();

		move(map);
	}

	return *this;
}

void Mapa::ChangeField(int i, int j, VrstaPuta vrstaPuta)
{
	Polje temp = *mapMatrix[i][j];
	delete mapMatrix[i][j];

	mapMatrix[i][j] = new PoljeSaPutem(vrstaPuta, temp);
}

void Mapa::ChangeField(int i, int j, unsigned int gustina)
{
	Polje temp = *mapMatrix[i][j];
	delete mapMatrix[i][j];

	mapMatrix[i][j] = new PoljeSaSumom(gustina, temp);
}

Mapa& Mapa::operator+=(unsigned int inc)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (unsigned int k = 0; k < inc; k++)
				(*mapMatrix[i][j])++;

	return *this;
}

Mapa& Mapa::operator-=(unsigned int dec)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (unsigned int k = 0; k < dec; k++)
				(*mapMatrix[i][j])--;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Mapa& map)
{
	for (int i = 0; i < map.n; i++)
	{
		for (int j = 0; j < map.m; j++)
			os << *(map.mapMatrix[i][j]) << '|';
		os << std::endl;
	}
	
	return os;
}

Mapa::~Mapa()
{
	destroy();
}

void Mapa::copy(const Mapa& map)
{
	n = map.n;
	m = map.m;
	allocate();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mapMatrix[i][j] = map.mapMatrix[i][j]->clone();
}

void Mapa::move(Mapa& map)
{
	n = map.n;
	m = map.m;
	allocate();

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			mapMatrix[i][j] = map.mapMatrix[i][j];
			map.mapMatrix[i][j] = nullptr;
		}
}

void Mapa::destroy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			delete mapMatrix[i][j];

	for (int i = 0; i < n; i++)
		delete[] mapMatrix[i];

	delete[] mapMatrix;
}

void Mapa::allocate()
{
	mapMatrix = new Polje**[n];
	for (int i = 0; i < n; i++)
		mapMatrix[i] = new Polje*[m];
}

void Mapa::populate()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mapMatrix[i][j] = new Polje();
}

