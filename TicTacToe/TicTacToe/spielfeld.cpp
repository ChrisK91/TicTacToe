#include "spielfeld.h"
#include <iostream>
#include <string>

using namespace std;

const string Spielfeld::SPIELER1 = "X";
const string Spielfeld::SPIELER2 = "O";

Spielfeld::Spielfeld(int h�he, int breite)
{
	feldH�he = h�he;
	feldBreite = breite;

	for (int x = 0; x < breite; ++x)
	{
		felder.push_back(vector<feldStatus>());
		for (int y = 0; y < h�he; ++y)
		{
			felder[x].push_back(feldStatus::leer);
		}
	}
}

int Spielfeld::h�he()
{
	return feldH�he;
}

int Spielfeld::breite()
{
	return feldBreite;
}

Spielfeld::feldStatus Spielfeld::feld(int x, int y)
{
	return felder[x][y];
}

void Spielfeld::trennzeileAusgeben(int breite)
{
	for (int j = 0; j < breite; j++)
	{
		if (j % 2 == 0)
			cout << "+";
		else
			cout << "-";
	}
	cout << endl;
}

bool Spielfeld::IstFeldLeer(int i)
{
	try
	{
		pair<int, int> koordinaten = koordinatenFinden(i);
		return felder[koordinaten.first][koordinaten.second] == feldStatus::leer;
	}
	catch (out_of_range)
	{
		return false;
	}
}

void Spielfeld::FeldStatusSetzen(int index, Spielfeld::feldStatus status)
{
	pair<int, int> koordinaten = koordinatenFinden(index);
	felder[koordinaten.first][koordinaten.second] = status;
}

pair<int, int> Spielfeld::koordinatenFinden(int index)
{
	int i = 0;
	for (int y = 0; y < h�he(); ++y)
	{
		for (int x = 0; x < breite(); ++x)
		{
			if (felder[x][y] == feldStatus::leer)
			{
				if (index == i)
					return pair<int, int>(x, y);
				++i;
			}
		}
	}

	throw out_of_range("index nicht gefunden");
}

void Spielfeld::Ausgeben()
{
	//TODO: f�r felder > 9 felder die feldbreite und h�he richtig berechnen
	int ausgabebreite = breite() * 2 + 1;
	int ausgabeh�he = h�he() * 2 + 1;

	int i = 0;

	for (int y = 0; y < h�he(); ++y)
	{
		trennzeileAusgeben(ausgabebreite);

		for (int x = 0; x < breite(); ++x)
		{
			cout << "|";

			switch (felder[x][y])
			{
			case feldStatus::spieler1:
				cout << Spielfeld::SPIELER1;
				break;
			case feldStatus::spieler2:
				cout << Spielfeld::SPIELER2;
				break;
			case feldStatus::leer:
				cout << i;
				++i;
				break;
			}
		}

		cout << "|" << endl;
	}
	trennzeileAusgeben(ausgabebreite);

	cout << endl;
}