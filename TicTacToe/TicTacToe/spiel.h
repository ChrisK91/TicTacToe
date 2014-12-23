#pragma once
#include "spielfeld.h"
#include <string>

class Spiel
{
public:
	Spiel();
	void spielen();
	std::pair<bool, std::string> gewonnen();
private:
	Spielfeld feld = Spielfeld(3, 3);
	std::string spieler1name, spieler2name;
	enum class aktuellerSpieler {
		Spieler1,
		Spieler2
	};
	aktuellerSpieler amZug;
};