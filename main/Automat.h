#pragma once
#include "Napoj.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Automat
{
public:
	Automat() : l_napoje{ 0 }
	{
		uzupelnij(make_unique<CocaCola>(1));
		uzupelnij(make_unique<CocaCola>(2));
		uzupelnij(make_unique<Pepsi>(3));
		uzupelnij(make_unique<Pepsi>(4));
		uzupelnij(make_unique<Sprite>(5));
		uzupelnij(make_unique<Sprite>(6));
		uzupelnij(make_unique<Cappy>(7));
		uzupelnij(make_unique<Cappy>(8));
		uzupelnij(make_unique<Woda>(9));
		uzupelnij(make_unique<Woda>(10));
	}

	const void drukuj_zawartosc()
	{
		for_each(napoje.begin(), napoje.end(), [](const auto& i) { i->print(); });
	}

	void uzupelnij(unique_ptr <Napoj> n)
	{
		napoje.emplace_back(move(n));
		l_napoje++;
	}

	const double podaj_cene(int n)
	{
		double k = 0;
		for_each(napoje.begin(), napoje.end(), [&](const auto& i)
			{
				int m = i->getid();
				if (m == n)
				{
					k = i->getcena();
				}
				return k;
			});
		return k;
	}

	double wrzuc_monete(double n)
	{
		for (int i = 0; i < 9; i++)
		{
			if (n * 100 == nominal[i])
			{
				return n;
			}
		}
		cout << "Nie ma takiej monety!" << endl;
		return 0;
	}

	double wez_kredyt(double k, double c, double y)
	{
		y = wrzuc_monete(y);
		k = k + y;
		cout << "Obecny kredyt: " << k << " Cena napoju: " << c << endl;
		return k;
	}

	void wydaj_napoj(int n)
	{
		napoje.erase(remove_if(napoje.begin(), napoje.end(), [&](const auto& i)
			{
				int a = i->getid();
				return n == a;
			}));
		cout << "Wydano napoj " << n << endl;
	}

	double wydaj_reszte(double c, double k)
	{
		cout << "Reszta: " << endl;
		int r;
		r = int(100 * (k - c) + 0.5);
		for (int i = 0; r > 0; i++)
		{
			int n = r / nominal[i];
			if (n > 0)
			{
				if (nominal[i] >= 100)
					cout << "Nominal monety: " << nominal[i] / 100 << " zl, liczba monet: " << n << endl;
				else
					cout << "Nominal monety: " << nominal[i] << " gr, liczba monet: " << n << endl;
				r %= nominal[i];
			}
		};
		return k = 0;
	}

private:
	vector < unique_ptr <Napoj> >napoje;
	int nominal[9] = {500,200,100,50,20,10,5,2,1};
	int l_napoje;
};