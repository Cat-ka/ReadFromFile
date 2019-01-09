#pragma once

#include <string>

class Sutaziaci
{
public:
	Sutaziaci(std::string InfoOSutaziacom);
	//Sutaziaci(int pId, std::string pMeno, std::string pPriezvisko, double pCas) :
	//	id(pId), meno(pMeno), priezvisko(pPriezvisko), cas(pCas) {}
	~Sutaziaci() {};

	int getId() { return id; }
	std::string getMeno() { return meno; }
	std::string getPriezvisko() { return priezvisko; }
	std::string getCeleMeno() { return priezvisko + " " + meno; }
	double getCas() { return cas; }
	
	//void setId(int pCas) { cas = pCas; }
	//void setMeno(std::string pMeno) {meno = pMeno; }
	//void setPriezvisko(std::string pPriezvisko) { priezvisko = pPriezvisko; }
	//void setCas(double pCas) { cas = pCas; }

private:
	int id;
	std::string meno;
	std::string priezvisko;
	double cas;
};
