#pragma once

#include <iostream>
#include <string>

using namespace std;

class human {
	
public:
	string sMyName;
	int nMyMoney;
	string Name = "�̸� : ";
	string Leftover = "����";
	string fruit = "����";
	string Leftover_fruit = Leftover + fruit + ": ";
	string Money = "������ : ";
	string apple_seller = "������";
	
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