#pragma once
#include <vector>
#include <string>

class Spielfeld
{
public:
	enum class feldStatus
	{
		leer,
		spieler1,
		spieler2
	};
	Spielfeld(int h�he, int breite);
	feldStatus feld(int x, int y);
	int h�he();
	int breite();
	void Ausgeben();
	bool IstFeldLeer(int index);
	void FeldStatusSetzen(int index, feldStatus status);
	const static std::string SPIELER1;
	const static std::string SPIELER2;
private:
	std::vector<std::vector<feldStatus>> felder;
	int feldH�he, feldBreite;
	void trennzeileAusgeben(int breite);
	std::pair<int, int> koordinatenFinden(int i);
};