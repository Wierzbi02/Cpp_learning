#pragma once

#include "Tram.h"

const int MAX_TRAMS = 20;

class Depot{

	Tram * atbase[MAX_TRAMS];
	int num;
	char depot_id[32];

public:
 //fill missing
	Depot(const char* depot_name);

	void operator+=(Tram& tram);
	void send_first();
	friend ostream& operator<<(ostream& out, const Depot& depot);
	int atBase() const;

	
};
