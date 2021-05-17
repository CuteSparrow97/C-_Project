#pragma once

#include <iostream>
#include <string>

using namespace std;

class human {
	
public:
	string sMyName;
	int nMyMoney;
	string Name = "이름 : ";
	string Leftover = "남은";
	string fruit = "과일";
	string Leftover_fruit = Leftover + fruit + ": ";
	string Money = "소지금 : ";
	string apple_seller = "사과장수";
	
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