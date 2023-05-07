#define  _CRT_SECURE_NO_WARNINGS
#include "Tram.h"
#include <iostream>
using namespace std;

int Tram::no_in_use = 0;
int Tram::max_id = 1;



Tram::Tram(const char* dn) : line_no(-1), tram_id(max_id++), state('o')
{
	strcpy_s(depot_name, dn);
}

void Tram::prepare(int n)
{
	line_no = n;
	state = 'r';
}

void Tram::returnDepot(const char* new_depot)
{
	strcpy_s(depot_name, new_depot);
}

void Tram::run()
{
	no_in_use++;
	if (tram_id % 2 == 0) {
		state = 'w';
	}
	else {
		state = 'f';
	}
}



int& Tram::getInUse()
{
	return no_in_use;
}



int Tram::getID() const
{
	return this->tram_id;
}

char Tram::getState() const
{
	return this->state;
}

const char* Tram::getDepot()
{
	return depot_name;
}

int Tram::getLineNo()
{
	return line_no;
}

ostream& operator<<(ostream& out, const Tram& tram)
{
	out << "Tram " << tram.tram_id << " (" << tram.depot_name;
	out << ") prepared on line " << tram.line_no;
	return out;
}

void check(Tram& tram)
{
	cout << "Check: Tram: Tram " << tram.getID() << " (";
	


	if (tram.getState() == 'f') {
		tram.returnDepot("Praga");
		cout << tram.getDepot() << ")  failure on line " << tram.getLineNo() << " redirected\n";
	}
	else {
		cout << tram.getDepot() << ")  working on line " << tram.getLineNo() << " OK!\n";
	}
}
