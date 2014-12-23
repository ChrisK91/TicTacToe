#include "spiel.h"
#include "spielfeld.h"
#include <iostream>
#include <string>

using namespace std;

Spiel::Spiel()
{
	cout << "Willkommen zu TicTacToe" << endl;
	cout << "Gib den Namen von Spieler 1 ein:" << endl;
	cin >> spieler1name;
	cout << "Gib den Namen von Spieler 2 ein:" << endl;
	cin >> spieler2name;

	amZug = aktuellerSpieler::Spieler1;
}

void Spiel::spielen()
{
	system("cls");

	switch (amZug)
	{
	case aktuellerSpieler::Spieler1:
		cout << spieler1name << " ist dran. (Symbol: " << Spielfeld::SPIELER1 << ")" << endl << endl;
		break;
	case aktuellerSpieler::Spieler2:
		cout << spieler2name << " ist dran. (Symbol: " << Spielfeld::SPIELER2 << ")" << endl << endl;
		break;
	}

	feld.Ausgeben();

	int auswahl;

	do{
		cout << "Auf welches Feld möchtest du setzen?" << endl;
		cin >> auswahl;
	} while (!feld.IstFeldLeer(auswahl));

	feld.FeldStatusSetzen(auswahl, (amZug == aktuellerSpieler::Spieler1) ? Spielfeld::feldStatus::spieler1 : Spielfeld::feldStatus::spieler2);

	if (amZug == aktuellerSpieler::Spieler1)
		amZug = aktuellerSpieler::Spieler2;
	else
		amZug = aktuellerSpieler::Spieler1;
}

pair<bool,string> Spiel::gewonnen()
{
	Spielfeld::feldStatus vorheriger;

	for (int y = 0; y < feld.höhe(); ++y)
	{
		for (int x = 0; x < feld.breite(); ++x)
		{
			if (feld.feld(x, y) == Spielfeld::feldStatus::leer)
				break;
			else if (x == feld.breite() - 1 && vorheriger == feld.feld(x, y))
				return (vorheriger == Spielfeld::feldStatus::spieler1) ? pair<bool, string>(true, spieler1name) : pair<bool, string>(true, spieler2name);
			else
				vorheriger = feld.feld(x, y);
		}
	}

	for (int x = 0; x < feld.breite(); ++x)
	{
		for (int y = 0; y < feld.höhe(); ++y)
		{
			if (feld.feld(x, y) == Spielfeld::feldStatus::leer)
				break;
			else if (y == feld.höhe() - 1 && vorheriger == feld.feld(x, y))
				return (vorheriger == Spielfeld::feldStatus::spieler1) ? pair<bool, string>(true, spieler1name) : pair<bool, string>(true, spieler2name);
			else
				vorheriger = feld.feld(x, y);
		}
	}

	return pair<bool, string>(false, "");
}