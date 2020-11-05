#pragma once
#include <istream>
#include <ostream>

class Memento
{
public:
	Memento();
	~Memento();
	virtual void saveToFile(std::ostream& file) = 0;
};

