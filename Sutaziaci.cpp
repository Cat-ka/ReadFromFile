#include "Sutaziaci.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>

#pragma once

using namespace std;

Sutaziaci::Sutaziaci(string InfoOSutaziacom)
{
	stringstream sutaziaciStream(InfoOSutaziacom);
	sutaziaciStream >> id;
	sutaziaciStream >> meno;
	sutaziaciStream >> priezvisko;
	sutaziaciStream >> cas;
}