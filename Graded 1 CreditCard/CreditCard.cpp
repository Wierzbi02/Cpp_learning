#include<iostream>
#include "CreditCard.h"

int CharToInt(char c) { 
	return c - '0';
}

CreditCard::CreditCard(const char* cn, const char* exp_d, int b) : balance(b)
{
	//carn number
	int n = 0;
	for (size_t i = 0; cn[i] != '\0'; ++i)
	{
		if (cn[i] >= '0' && cn[i] <= '9') {
			card_n[n] = cn[i];
			n++;
		}
		
	}
	card_n[n] = '\0';

	//expiration date
	exp_m = CharToInt(exp_d[0]) * 10 + CharToInt(exp_d[1]);
	exp_y = CharToInt(exp_d[3]) * 1000 + CharToInt(exp_d[4]) * 100 + CharToInt(exp_d[5]) * 10 + CharToInt(exp_d[6]);
	//setting last bought item to ""
	strcpy_s(lbi, "");
}

CreditCard::CreditCard(const char* cn, CreditCard card0, int b) : balance(b)
{
	//carn number
	int n = 0;
	for (size_t i = 0; cn[i] != '\0'; ++i)
	{
		if (cn[i] >= '0' && cn[i] <= '9') {
			card_n[n] = cn[i];
			++n;
		}
		
	}
	card_n[n] = '\0';

	//copying expiration date
	exp_m = card0.exp_m;
	exp_y = card0.exp_y;

	//copying last bought item
	strcpy_s(lbi, card0.lbi);
}

bool CreditCard::operator<(CreditCard c1)
{
	if (this->exp_y > c1.exp_y) {
		return false;
	}
	else if (this->exp_y < c1.exp_y) {
		return true;
	}
	else {
		if (this->exp_m >= c1.exp_m) {
			return false;
		}
		else {
			return true;
		}
	}
}

bool CreditCard::operator>=(CreditCard c1)
{
	return !(*this < c1);
}

void CreditCard::BuyItem(const char* item)
{
	int cost = strlen(item);
	if (cost > 30) {
		std::cout << "Too long name of an item!";
		return;
	}
	else {
		strcpy_s(lbi, item);
	}
	balance -= cost;
}

void CreditCard::BuyItem(int n)
{
	int cost = strlen(lbi);
	balance -= n * cost;
}

CreditCard& CreditCard::operator+=(int i)
{
	for (size_t n = 0; n < i; ++n)
	{
		if (exp_m != 12) {
			++exp_m;
		}
		else {
			exp_m = 1;
			++exp_y;
		}
	}
	return *this;
}

CreditCard& CreditCard::operator+=(const CreditCard& card)
{
	if (*this >= card) {
		return *this;
	}
	else {
		this->exp_m = card.exp_m;
		this->exp_y = card.exp_y;
	}
}

std::ostream& operator<<(std::ostream& out, const CreditCard& card)
{
	out << card.card_n << " - " << card.exp_m << "/" << card.exp_y << std::endl;
	out << "Balance: " << card.balance << std::endl;
	out << "Last bought item: " << card.lbi << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, CreditCard& card)
{
	int m = 0;
	int y = 0;
	std::cout << "New expiration date: month: ";
	in >> m;
	std::cout << "\nyear: ";
	in >> y;
	if (y < card.exp_y) {
		return in;
	}
	else if (y == card.exp_y) {
		if (card.exp_m > m) {
			return in;
		}
		else {
			card.exp_m = m;
		}
	}
	else {
		card.exp_y = y;
		card.exp_m = m;
	}
	
	return in;
}
