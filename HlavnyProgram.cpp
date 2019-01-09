#include "Sutaziaci.h"
#include "ZoznamSutaziacich.h"
#include <iostream>
#include <exception>

using namespace std;

void VypisZoznam(Sutaziaci novy)
{
	//ked som zadala len cout << novy << endl; - pisalo mi to chybu, èiže ak to nevie vypísa tak vypíše chybu
	//musela som ís cez gettre
	cout << novy.getId() << " " << flush;
	cout << novy.getCeleMeno() << " " << flush;
	cout << novy.getCas() << endl;
}



int main() {
	try
	{
		//Sutaziaci novy("1 Juraj Mokry 50.25");
		ZoznamSutaziacich zoznam("zoznam.txt");
		if (zoznam.poleSutaziacich.size() == 0)
		{
			throw NoValedictorianException();
		}
		for (int i = 0; i < zoznam.poleSutaziacich.size(); i++)
		{
			Sutaziaci s = zoznam.poleSutaziacich.at(i);
			VypisZoznam(s);
		}

		VypisZoznam(zoznam.getValedictorian());
		cout << endl << "Sutaziaci, ktorych cas je pod 20 sekund." << endl;

		for (Sutaziaci s : zoznam.getCasPod10())
		{
			VypisZoznam(s);
		}

		cout << endl << "Sutaziaci, ktory mali cas nad 30 sekund." << endl;

		for (Sutaziaci s : zoznam.getSutaziacichOdPosledneho())
		{
			VypisZoznam(s);
		}
	}
	catch (exception &ex)
	{
		cout << "An exception was thrown." << endl;
		cout << "\t" << ex.what() << endl;
	}
	return 0;
}