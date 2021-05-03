#pragma once

#include <iostream>
using namespace std;

class human {
	
public:
	string sMyName;
	int nMyMoney;
	
public:

	// 입력 받는 IMyMoney와 IMyName을 nMyMoney와 sMyName에 입력시킬 거야!
	human(int IMyMoney, string IMyName) : nMyMoney(IMyMoney), sMyName(IMyName)
	{

	}
	
	virtual void showinfo() = 0;

	virtual ~human()
	{
		
	}

};