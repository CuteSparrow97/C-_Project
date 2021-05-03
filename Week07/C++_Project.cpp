#include <iostream>
#include "human.h"
using namespace std;

int SellerNumber = 0;

class AppleSeller : human
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney = nMyMoney;
	string MyName = sMyName;
	
public:
	// 생성자 받을 때 입력받아서 human의 생성자에 money와 name을 가져다 쓸꺼야.
	// human(int IMyMoney, string IMyName) IMyMoney와 IMyName에 넣겠다는거임.
	AppleSeller(int price, int num, int money, string name) : human(money, name)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		SellerNumber++;
	}
	int SaleApples(int money)  
	{
		int num=money/APPLE_PRICE;
		if ((numOfApples - num) < 0)
			return 0;
		numOfApples -= num;
		myMoney+=money;
		return num;
	}
	void showinfo()
	{	
		cout << "--사과 장수--" << endl;
		cout << "이름: " << MyName << endl;
		cout << "남은 사과: "<< numOfApples << endl;
		cout << "소지금: "<< myMoney << endl <<endl;
	}

	int GetmyMoney()
	{
		return myMoney;
	}

	string GetMyName()
	{
		return MyName;
	}

};

class BananaSeller : human
{
private:
	int BANANA_PRICE;
	int numOfBananas;
	int myMoney = nMyMoney;
	string MyName = sMyName;

public:
	// 생성자 받을 때 입력받아서 human의 생성자에 money와 name을 가져다 쓸꺼야.
	// human(int IMyMoney, string IMyName) IMyMoney와 IMyName에 넣겠다는거임.
	BananaSeller(int price, int num, int money, string name) : human(money, name)
	{
		BANANA_PRICE = price;
		numOfBananas = num;
		SellerNumber++;
	}
	int SaleBananas(int money)
	{
		int num = money / BANANA_PRICE;
		if ((numOfBananas - num) < 0)
			return 0;
		numOfBananas -= num;
		myMoney += money;
		return num;
	}
	void showinfo()
	{
		cout << "--바나나 장수--" << endl;
		cout << "이름: " << MyName << endl;
		cout << "남은 바나나: " << numOfBananas << endl;
		cout << "소지금: " << myMoney << endl << endl;
	}

};

class SpApplesSeller : AppleSeller
{
private:
	int SpApple_PRICE;
	int numOfSpApples;
	int myMoney = AppleSeller::GetmyMoney();
	string MyName = AppleSeller::GetMyName();

public:
	SpApplesSeller(int price, int num, int money, string name) : AppleSeller(price, num, money, name)
	{
		SpApple_PRICE = price;
		numOfSpApples = num;
		SellerNumber++;
	}

	int SaleApples(int money)
	{
		return AppleSeller::SaleApples(money);
	}
	
	void showinfo()
	{
		cout << "--희귀사과 장수--" << endl;
		cout << "이름: " << MyName << endl;
		cout << "남은 희귀사과: " << numOfSpApples << endl;
		cout << "소지금: " << myMoney << endl << endl;
	}

};

class FruitBuyer : human
{
private:
	int numOfApples;
	int numOfBananas;
	int numOfSpApples;
	int myMoney = nMyMoney;
	string MyName = sMyName;

public:
	FruitBuyer(int money, string name) : human(money,name)
	{
		numOfApples=0;
		numOfBananas = 0;
		numOfSpApples = 0;
	}

	int choice_seller()
	{
		int choice;
		std::cout << "1 : 사과, 2 : 바나나, 3 희귀사과 중 구매할 것(숫자입력)을 선택하시오." << endl;
		while (true)
		{
			std::cin >> choice;
			if ((choice <= SellerNumber) && (choice > 0))
				return choice;
			else
				std::cout << "잘못된 입력값 입니다." << endl;
		}

	}

	void BuyApples(AppleSeller &seller, int money)
	{
		int Apples_number = seller.SaleApples(money);
		if (Apples_number == 0)
		{
			std::cout << "사과가 부족하거나 돈을 너무 많이 입력하셨습니다." << endl;
			return;
		}
		
		numOfApples += Apples_number;
		myMoney-=money;
	}

	void BuyBananas(BananaSeller& seller, int money)
	{
		int Banana_number = seller.SaleBananas(money);
		if (Banana_number == 0)
		{
			std::cout << "바나나가 부족하거나 돈을 너무 많이 입력하셨습니다." << endl;
			return;
		}

		numOfBananas += Banana_number;
		myMoney -= money;
	}

	void BuySpApples(SpApplesSeller& seller, int money)
	{
		int SpApples_number = seller.SaleApples(money);
		if (SpApples_number == 0)
		{
			std::cout << "희귀사과가 부족하거나 돈을 너무 많이 입력하셨습니다." << endl;
			return;
		}

		numOfSpApples += SpApples_number;
		myMoney -= money;
	}

	void showinfo()
	{
		cout << "--과일 구매자--" << endl;
		cout << "이름: " << MyName << endl;
		cout << "현재 잔액: "<<myMoney<<endl;
		cout << "사과 개수: " << numOfApples << endl;
		cout << "바나나 개수: " << numOfBananas << endl;
		cout << "희귀사과 개수: " << numOfSpApples << endl << endl;
	}

};

int main(void)
{	
	int fruit_price, fruit_num, seller_money;
	string seller_name, buyer_name;
	int buyer_money, buyer_choice, buy_fruit;
	string isinput;
	bool binput = true;

	while (binput) {

		std::cout << "과일 가격, 과일 개수, 현재 돈, 이름을 입력하세요.(구문자로 띄어쓰기 사용!)" << endl;
		std::cin >> fruit_price >> fruit_num >> seller_money >> seller_name;
		std::cout << "과일 가격 : " << fruit_price << "  과일 개수 : " << fruit_num << "  현재 돈 : " << seller_money << " 이름 : " << seller_name << " 을 입력하셨습니다" << endl;
		std::cout << "맞으면 Y 틀리면 N 를 입력해주세요." << endl;
		std::cin >> isinput;
		if (isinput == "Y" || isinput == "y")
			break;

	}

	while (binput) {

		std::cout << "과일 구매자의 현재 가지고 있는 현금, 이름을 입력하세요.(구문자로 띄어쓰기 사용!)" << endl;
		std::cin >> buyer_money >> buyer_name;
		std::cout << "구매자가 가지고 있는 돈 : " << buyer_money << " 이름 : " << buyer_name << endl;
		std::cout << "맞으면 Y 틀리면 N 를 입력해주세요." << endl;
		std::cin >> isinput;
		if (isinput == "Y" || isinput == "y")
			break;

	}

	AppleSeller seller1(fruit_price, fruit_num, seller_money, seller_name);
	BananaSeller seller2(fruit_price, fruit_num, seller_money, seller_name);
	SpApplesSeller seller3(fruit_price, fruit_num, seller_money, seller_name);
	FruitBuyer buyer(buyer_money, buyer_name);
	buyer_choice = buyer.choice_seller();

	while (binput)
	{
		std::cout << "얼마치 과일을 구매할 예정이십니까? (예 : 2000)" << endl;
		std::cin >> buy_fruit;
		std::cout << "맞으면 Y 틀리면 N 를 입력해주세요." << endl;
		std::cin >> isinput;
		if (isinput == "Y" || isinput == "y")
			break;
	}

	if (buyer_choice == 1)
	{
		buyer.BuyApples(seller1, buy_fruit);
	}

	else if (buyer_choice == 2)
	{
		buyer.BuyBananas(seller2, buy_fruit);
	}

	else if (buyer_choice == 3)
	{
		buyer.BuySpApples(seller3, buy_fruit);
	}

	else
		std::cout << "잘못된 입력을 받았습니다. cpp 파일 내용확인 부탁드립니다." << endl;
	
	seller1.showinfo();
	seller2.showinfo();
	seller3.showinfo();
	buyer.showinfo();

	//seller1.~FruitSeller();
	//seller2.~FruitSeller();
	//buyer.~FruitBuyer();

	return 0;
}
