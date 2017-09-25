/*************************************************************************
    > File Name: CData.h
    > Author: zhaohuizhen
    > Mail: 1534612574@qq.com 
    > Created Time: 2017年09月23日 星期六 21时36分56秒
 ************************************************************************/

#include "origin.h"
#include <string>
using namespace std;

struct cache
{
	bool valid;
	string rep;
};

class CDate
{
	public:
		CDate(int dd = 0, int mm = 0,  int yy = 0);

		//copy constructor
		
		//= operator
	
		CDate& add_year(int n);
		CDate& add_month(int n);
		CDate& add_day(int n);

		int day() const;// { return d; }
		int month() const;// {	return m; }
		int year() const;// { return d; }

		string string_rep() const;

		static void set_default(int d, int m, int y);
	private:
		int d, m, y;

		static CDate default_date;

		//mutable bool cache_valid;
		//mutable string cache;

		cache *c;
		void compute_cache_value() const;
};
