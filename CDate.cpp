/*************************************************************************
    > File Name: CDate.cpp
    > Author: zhaohuizhen
    > Mail: 1534612574@qq.com 
    > Created Time: 2017年09月23日 星期六 21时39分53秒
 ************************************************************************/

#include "CDate.h"
#include <iostream>

inline int CDate::day() const {	return d;}
inline int CDate::month() const{ return m;}
inline int CDate::year() const { return y;}

CDate::CDate(int dd, int mm, int yy)
{
	std::cout << "CDate constructor" << std::endl;
	d = dd ? dd : default_date.d;
	m = mm ? mm : default_date.m;
	y = yy ? yy : default_date.y;

	c = new cache;
	c->valid = false;
	c->rep = string();
}

CDate CDate::default_date(22, 12, 1971);

void CDate::set_default(int d, int m, int y)
{
	default_date = CDate(d, m, y);
}

CDate& CDate::add_year(int n)
{
	y += n;
	
	return *this;
}

CDate& CDate::add_month(int n)
{
	m += n;

	return *this;
}

CDate& CDate::add_day(int n)
{
	d += n;

	return *this;
}

void CDate::compute_cache_value() const
{
	//fill string cache
	c->rep = "";
}

string CDate::string_rep() const
{
	if(!c->valid)
	{
		compute_cache_value();
		c->valid = true;
	}

	return c->rep;
}
