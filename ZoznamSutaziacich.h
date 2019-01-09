#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>

#include "Sutaziaci.h"

class ZoznamSutaziacich
{
public:
	ZoznamSutaziacich(std::string filePath);

	Sutaziaci getValedictorian();
	std::vector<Sutaziaci> getCasPod10();
	std::vector<Sutaziaci> getSutaziacichOdPosledneho();

	~ZoznamSutaziacich();

//private:
	std::vector<Sutaziaci> poleSutaziacich;
};

class NoValedictorianException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Zoznam sutaziacich: No Valedictorian";
	}
};

