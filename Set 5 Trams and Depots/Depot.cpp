#define  _CRT_SECURE_NO_WARNINGS
#include "Depot.h"

Depot::Depot(const char* depot_name) : num(0)
{
	strcpy_s(depot_id, depot_name);
	for (size_t i = 0; i < MAX_TRAMS; i++) {
		this->atbase[i] = nullptr;
	}
}

void Depot::operator+=(Tram& tram)
{
	int i = 0;
	while (this->atbase[i] != nullptr && i < MAX_TRAMS) {
		++i;
	}

	if (i == MAX_TRAMS) {
		return;
	}
	this->atbase[i] = &tram;
	++num;
	Tram::getInUse()--;
}

void Depot::send_first()
{
	int i = 0;
	while (i < MAX_TRAMS && this->atbase[i] == nullptr) {
		++i;
	}
	if (i == MAX_TRAMS) {
		return;
	}

	static int line_number = 1;

	Tram* tram = this->atbase[i];
	tram->prepare(line_number++);
	tram->run();
	this->atbase[i] = nullptr;
	--num;
	cout << "From " << this->depot_id << " Depot :" << *tram << endl;
}

int Depot::atBase() const
{
	return num;
}

ostream& operator<<(ostream& out, const Depot& depot)
{
	out << "Currently in " << depot.depot_id << " depot:\n";
	for (size_t i = 0; i < depot.num; ++i) {
		out << *depot.atbase[i] << endl;
	}

	return out;
}
