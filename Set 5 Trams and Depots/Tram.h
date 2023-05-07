#pragma once

#include <iostream>
using namespace std;

const int NAME_SIZE = 16;

class Tram{
    //fill missing

	static int no_in_use;
	static int max_id;
	char depot_name[NAME_SIZE];
	int line_no;
	const int tram_id;

	char state;//ready, work, failure, off

public:
//fill missing
	Tram(const char* dn);

	void prepare(int n);
	void returnDepot(const char* new_depot);
	void run();
	static int& getInUse();
	int getID() const;
	char getState() const;
	const char* getDepot();
	int getLineNo();

	

	friend ostream& operator<<(ostream& out, const Tram& tram);
		
};
//fill missing
void check(Tram& tram);