#pragma once

class CreditCard {
	char card_n[17]; //carn number
	int exp_m; //expiration month
	int exp_y; //expiration year
	int balance;
	char lbi[31]; //last bought item

public:
	CreditCard(const char* cn, const char* exp_d, int b = 100);
	CreditCard(const char* cn, CreditCard card0, int b = 100);

	friend std::ostream& operator<<(std::ostream& out, const CreditCard& card);
	friend std::istream& operator>>(std::istream& in, CreditCard& card);

	bool operator<(CreditCard c1);
	bool operator>=(CreditCard c1);

	void BuyItem(const char* item);
	void BuyItem(int n);

	CreditCard& operator+=(int i);
	CreditCard& operator+=(const CreditCard& card);
};