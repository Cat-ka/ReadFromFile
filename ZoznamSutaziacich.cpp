#include "ZoznamSutaziacich.h"
#include <iostream>

#define CASOVY_LIMIT 20
#define HORNA_HRANICA 30

using namespace std;


ZoznamSutaziacich::ZoznamSutaziacich(string filePath)
{
	ifstream subor(filePath);

	string lineContents;

	//mÙûeme to urobiù aj cez for loop
	while (!subor.eof())
	{
		getline(subor, lineContents);
		Sutaziaci s(lineContents);
		poleSutaziacich.push_back(s);
	}
	subor.close();

	sort(poleSutaziacich.begin(), poleSutaziacich.end(), [](Sutaziaci &sut1, Sutaziaci &sut2)
	{
		return sut1.getCas() < sut2.getCas();
	});
}

Sutaziaci ZoznamSutaziacich::getValedictorian()
{
	//toto som musela daù, lebo aby vyhodilo v˝nimku
	//if ((poleSutaziacich.size() == 0) || (poleSutaziacich.at(0).getId() < 1))
	//{
		for (int i = 0; i < poleSutaziacich.size(); i++)
		{
			if ((poleSutaziacich.at(i).getCas() < 0) || (poleSutaziacich.size() == 0))
			{
				throw NoValedictorianException();
			}
		}
		
		
	//}
	
	cout << "\nNajrychlejsi sutaziaci je: " << flush;
	return poleSutaziacich.at(0);
}

vector<Sutaziaci> ZoznamSutaziacich::getCasPod10()
{
	vector<Sutaziaci> najlepsi;
	for (Sutaziaci s : poleSutaziacich)
	{
		if (s.getCas() < CASOVY_LIMIT)
		{
			najlepsi.push_back(s);
		}
	}
	return najlepsi;
}

vector<Sutaziaci> ZoznamSutaziacich::getSutaziacichOdPosledneho()
{
	vector<Sutaziaci> opacnePoradie;
	//vypÌöeme opaËnÈ poradie cez iterator a d·me tam podmienku, ûe ktorÌ dobehli nad limit 30 sekund
	for (vector<Sutaziaci>::reverse_iterator iter = poleSutaziacich.rbegin();iter < poleSutaziacich.rend(); iter++)
	{
		if (iter->getCas() < HORNA_HRANICA)
		{
			break;
		}
		opacnePoradie.push_back(*iter);		//musela som tam daù pointer... ale preËo, netuöÌm
	}

	return opacnePoradie;
}

ZoznamSutaziacich::~ZoznamSutaziacich()
{
}
