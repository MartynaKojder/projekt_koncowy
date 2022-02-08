#pragma once
#include <iostream>
using namespace std;

class Napoj
{
public:
	virtual void print() = 0;
	virtual double getcena() = 0;
	int getid() { return id; }
	virtual ~Napoj() = default;
	Napoj() : id{ 0 } {}
	Napoj(int i) : id{ move(i) } {}
	int id;
};

class CocaCola : public Napoj
{
public:
	CocaCola(int i) : Napoj{ i } {}
	void print() override
	{
		cout << this->id << ". CocaCola, cena: " << cena << endl;
	}
	double getcena() override { return cena; }

private:
	double cena = 3.50;
	//bool czyzero;
};

class Pepsi : public Napoj
{
public:
	Pepsi(int i) : Napoj{ i } {}
	virtual void print() override
	{
		cout << this->id << ". Pepsi, cena: " << cena << endl;
	}
	double getcena() override { return cena; }

private:
	double cena = 3.40;
	//string typetykiety;
};

class Sprite : public Napoj
{
public:
	Sprite(int i) : Napoj{ i } {}
	virtual void print() override
	{
		cout << this->id << ". Spirte, cena: " << cena << endl;
	}
	double getcena() override { return cena; }

private:
	double cena = 3.60;
	//bool czyszklanabutelka;
};

class Cappy : public Napoj
{
public:
	Cappy(int i) : Napoj{ i } {}
	virtual void print() override
	{
		cout << this->id << ". Cappy, cena: " << cena << endl;
	}
	double getcena() override { return cena; }

private:
	double cena = 4;
	//string smak;
};

class Woda : public Napoj
{
public:
	Woda(int i) : Napoj{ i } {}
	virtual void print() override
	{
		cout << this->id << ". Woda, cena: " << cena << endl;
	}
	double getcena() override { return cena; }

private:
	double cena = 2.50;
	//bool czygazowana;
};