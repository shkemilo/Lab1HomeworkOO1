#pragma once

#include <iostream>

#include "Polje.h"
#include "PoljeSaPutem.h"
#include "PoljeSaSumom.h"

class Mapa
{
public:
	Mapa(int n, int m);
	Mapa(const Mapa& map);
	Mapa(Mapa&& map);

	Mapa& operator=(const Mapa& map);
	Mapa& operator=(Mapa&& map);

	void ChangeField(int i, int j, VrstaPuta vrstaPuta);
	void ChangeField(int i, int j, unsigned int gustina);

	Mapa& operator+=(unsigned int inc);
	Mapa& operator-=(unsigned int dec);

	friend std::ostream& operator<<(std::ostream& os, const Mapa& map);

	~Mapa();
private:
	void allocate();
	void populate();
	void copy(const Mapa& map);
	void move(Mapa& map);
	void destroy();

	Polje*** mapMatrix;
	int n;
	int m;
};

