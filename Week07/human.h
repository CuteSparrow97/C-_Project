#pragma once

#include <iostream>
using namespace std;

class human {
	
public:
	string sMyName;
	int nMyMoney;
	
public:

	// �Է� �޴� IMyMoney�� IMyName�� nMyMoney�� sMyName�� �Է½�ų �ž�!
	human(int IMyMoney, string IMyName) : nMyMoney(IMyMoney), sMyName(IMyName)
	{

	}
	
	virtual void showinfo() = 0;

	virtual ~human()
	{
		
	}

};