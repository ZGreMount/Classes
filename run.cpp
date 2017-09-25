/*************************************************************************
    > File Name: run.cpp
    > Author: zhaohuizhen
    > Mail: 1534612574@qq.com 
    > Created Time: 2017年09月24日 星期日 13时39分44秒
 ************************************************************************/

#include "run.h"
#include "CDate.h"
#include "Date.h"
#include <vector>
using namespace std;

int run()
{
	Date date;
    return 0;
}

bool midnight()
{
	return true;
}

void f(Date &d)
{
	Date lvb_day = Date(16,  Date::dec,  d.year());
	if(d.day() == 29 && d.month() == Date::feb)
	{
		//...
	}

	if(midnight()) d.add_day(1);

	//cout << "day after: " << d+1 << 'n';
}

void fill(vector<Date>& aa)
{
	while(cin)
	{
		Date d;
		try
		{
		//	cin >> d;
		}
		catch(Date::Bad_date)
		{
			//my error handling
			continue;
		}
		aa.push_back(d);
	}
}
