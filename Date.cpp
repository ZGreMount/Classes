/*================================================================
*   Copyright (C) 2017 GDUT. All rights reserved.
*   
*   文件名称：Date.cpp
*   创 建 者：zhaohuizhen
*   创建日期：2017年09月25日
*   描    述：
*
================================================================*/


#include "Date.h"

Date Date::default_date(22, dec, 1971);

inline int Date::day() const { return d; }
inline Date::Month Date::month() const { return Month(m); }
inline int Date::year() const { return y; }

Date::Date(int dd, Month mm, int yy)
{
	INFO(Date constructor)
	if(0 == yy) yy = default_date.year();
	if(0 == mm) mm = default_date.month();
	if(0 == dd) dd = default_date.day();

	int max;

	switch(mm)
	{
		case feb:
			max = 28 + leapyear(yy);	//undefined leapyear
			break;

		case apr:case jun:case sep:case nov:
			max = 30;
			break;

		case jan:case mar:case may:case jul:case aug:case oct:case dec:
			max = 31;
			break;

		default:
			throw Bad_date(); //someone cheated
	}

	if(dd < 1 || max < dd) throw Bad_date();

	y = yy;
	m = mm;
	d = dd;
}

string Date::string_rep() const
{
	return string();
}

void char_rep(char s[])
{

}

Date& Date::add_year(int n)
{
	if(0 == n)
	{
		return *this;
	}
}

Date& Date::add_month(int n)
{
	if(0 == n)
	{
		return *this;
	}

	if(n > 0)
	{
		int delta_y = n/12;
		int mm = m + n%12;
		if(12 < mm)	//note: int (dec) == 12
		{
			delta_y++;
			mm -= 12;
		}

		//handle the cases where Month(mm) doesn't have day d
		
		y += delta_y;
		m = Month(mm);
		return *this;
	}

	//handle negative n
	//
	
	return *this;
}

Date& Date::add_day(int n)
{
	if(0 == n)
	{
		return *this;
	}
}

int diff(Date a, Date b) //number of days in the range[a, b) or [b, a)
{
	return 0;
}

bool leapyear(int y)
{
	if((0 == y%4 && 0 != y%100) || !y%400)
	{
		return true;
	}
	else
	{
		return false;
	}
}
