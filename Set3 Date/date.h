#pragma once

class Date
{
	int day;
	int month;
	int year;
	
	bool format;

	bool ifLeap() const;

	

public:
	//constructors
	Date(int d = 9, int m = 3, int y = 2021);
	Date(const char* str);

	bool& SetFormat();
	void NextDay();
	void PrevDay();
	void SelectedDay(int n = 7);
	bool ifEqual(const Date& date) const;

	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in, Date& date);
	friend bool ifLess(const Date& a, const Date& b);
	
};

int CountDays(const Date& a, const Date& b);



