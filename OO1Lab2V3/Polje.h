#pragma once
#include <iostream>

class Polje
{
public:
	explicit Polje(int neprohodnost = 100);

	int GetNeprohodnost() const;
	void SetNeprohodnost(int neprohodnost);

	const Polje& operator++(int dummy);
	const Polje& operator--(int dummy);

	friend std::ostream& operator<<(std::ostream& os, const Polje& polje);

	virtual Polje* clone() const;

	virtual ~Polje() {}

protected:
	virtual char oznaka() const;

	virtual std::ostream& output(std::ostream& os) const;

private:
	bool isInRange(int neprohodnost) const;

	int neprohodnost;
};

