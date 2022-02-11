#pragma once
#include "Automat.h"
#include <iostream>
#include <exception>
#include <limits>

using namespace std;

class Akcja
{
public:
	Akcja() : a(unique_ptr<Automat>(new Automat)), stan(true) {}
	bool get_stan() { return stan; }

	void akcja()
	{
		cout << endl;
		a->drukuj_zawartosc();

		again = 0;
		while (again <= 0)
		{
			try {
				cout << "Wpisz numer napoju: ";
				int x;
				cin >> x;
				
				if (!cin) { throw error; }
				if (x < 0) { throw - 1; }

				cena = a->podaj_cene(x);
				if (cena == 0) { throw 0.5; }

				cout << "Cena za wybrany napoj: " << cena << endl;

				while (kredyt <= cena)
				{
					cout << "Wrzuc monete (dostepne nominaly: 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01): " << endl;
					double y;
					cin >> y;

					if (!cin) { throw error; }
					if (y < 0) { throw - 1; }

					kredyt = a->wez_kredyt(kredyt, cena, y);
				}
				a->wydaj_napoj(x);

				kredyt = a->wydaj_reszte(cena, kredyt);

				again = 1;
			}
			catch (int)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wartosc musi byc dodatnia! Jesli chcesz przerwac wpisywanie to wpisz 'n'." << endl;
				cin >> yn;
				if (yn == "n")
					again = 1;
				else
					again = 0;
			}
			catch (double)
			{
				cout << "Nie ma takiego napoju." << endl;
				again = 1;
			}
			catch (...)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Wartosc musi byc liczba! Jesli chcesz przerwac wpisywanie to wpisz 'n'." << endl;
				cin >> yn;
				if (yn == "n")
					again = 1;
				else
					again = 0;
			}
		}
	}

private:
	int again = 0;
	string yn;
	string error;
	bool stan;
	unique_ptr <Automat> a;
	double kredyt = 0;
	double cena = 0;
};