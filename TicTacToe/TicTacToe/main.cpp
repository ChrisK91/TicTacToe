#include "spiel.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	std::locale::global(std::locale("German_germany"));

	Spiel s = Spiel();

	pair<bool, string> status;

	do
	{
		s.spielen();
		status = s.gewonnen();
	} while (!status.first);

	cout << status.second << " hat gewonnen!" << endl;

	return 0;
}