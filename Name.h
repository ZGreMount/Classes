/*================================================================
*   Copyright (C) 2017 GDUT. All rights reserved.
*   
*   文件名称：Name.h
*   创 建 者：zhaohuizhen
*   创建日期：2017年09月25日
*   描    述：
*
================================================================*/


#pragma once
#include "origin.h"

class Name
{
	const char *s;
	//...
};

class Table
{
	private:
		Name *p;
		size_t sz;

	public:
		Table(size_t s = 15) { p = new Name[sz =s];	} //constructor

		~Table() {	delete []p;}

		Name* lookup(const char *);
		bool insert(Name *);
}
