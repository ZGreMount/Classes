/*================================================================
*   Copyright (C) 2017 GDUT. All rights reserved.
*   
*   文件名称：Date.h
*   创 建 者：LuZhenrong
*   创建日期：2017年09月24日
*   描    述：
*
================================================================*/


#pragma once
#include "origin.h"

#include <string>
using namespace std;

class Date
{
	public:		//public interface

		enum Month{jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

		class Bad_date{	};	//exception class

		Date(int dd = 0, Month mm = Month(0), int yy = 0); //0 means "pick a default"

	//functions for examining the Date
		int day() const;
		Month month() const;
		int year() const;
		
		string string_rep() const; //string representation
		void char_rep(char s[]) const; //C-style string representation

		static void set_default(int,  Month, int);

	// functions for changing the Date
		Date& add_year(int n); // add n years
		Date& add_month(int n); // add n months
		Date& add_day(int n); // add n days

	private:
		int d, m, y;			//representation
		static Date default_date;
};


//Helper Functions[class.helper]
int diff(Date a, Date b);
bool leapyear(int y);
Date next_weekday(Date d);
Date next_saturday(Date d);
