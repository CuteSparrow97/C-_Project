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
	// ������ ���� �� �Է¹޾Ƽ� human�� �����ڿ� money�� name�� ������ ������.
	// human(int IMyMoney, string IMyName) IMyMoney�� IMyName�� �ְڴٴ°���.
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
		cout << "--��� ���--" << endl;
		cout << "�̸�: " << MyName << endl;
		cout << "���� ���: "<< numOfApples << endl;
		cout << "������: "<< myMoney << endl <<endl;
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
	// ������ ���� �� �Է¹޾Ƽ� human�� �����ڿ� money�� name�� ������ ������.
	// human(int IMyMoney, string IMyName) IMyMoney�� IMyName�� �ְڴٴ°���.
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
		cout << "--�ٳ��� ���--" << endl;
		cout << "�̸�: " << MyName << endl;
		cout << "���� �ٳ���: " << numOfBananas << endl;
		cout << "������: " << myMoney << endl << endl;
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
		cout << "--��ͻ�� ���--" << endl;
		cout << "�̸�: " << MyName << endl;
		cout << "���� ��ͻ��: " << numOfSpApples << endl;
		cout << "������: " << myMoney << endl << endl;
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
		std::cout << "1 : ���, 2 : �ٳ���, 3 ��ͻ�� �� ������ ��(�����Է�)�� �����Ͻÿ�." << endl;
		while (true)
		{
			std::cin >> choice;
			if ((choice <= SellerNumber) && (choice > 0))
				return choice;
			else
				std::cout << "�߸��� �Է°� �Դϴ�." << endl;
		}

	}

	void BuyApples(AppleSeller &seller, int money)
	{
		int Apples_number = seller.SaleApples(money);
		if (Apples_number == 0)
		{
			std::cout << "����� �����ϰų� ���� �ʹ� ���� �Է��ϼ̽��ϴ�." << endl;
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
			std::cout << "�ٳ����� �����ϰų� ���� �ʹ� ���� �Է��ϼ̽��ϴ�." << endl;
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
			std::cout << "��ͻ���� �����ϰų� ���� �ʹ� ���� �Է��ϼ̽��ϴ�." << endl;
			return;
		}

		numOfSpApples += SpApples_number;
		myMoney -= money;
	}

	void showinfo()
	{
		cout << "--���� ������--" << endl;
		cout << "�̸�: " << MyName << endl;
		cout << "���� �ܾ�: "<<myMoney<<endl;
		cout << "��� ����: " << numOfApples << endl;
		cout << "�ٳ��� ����: " << numOfBananas << endl;
		cout << "��ͻ�� ����: " << numOfSpApples << endl << endl;
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

		std::cout << "���� ����, ���� ����, ���� ��, �̸��� �Է��ϼ���.(�����ڷ� ���� ���!)" << endl;
		std::cin >> fruit_price >> fruit_num >> seller_money >> seller_name;
		std::cout << "���� ���� : " << fruit_price << "  ���� ���� : " << fruit_num << "  ���� �� : " << seller_money << " �̸� : " << seller_name << " �� �Է��ϼ̽��ϴ�" << endl;
		std::cout << "������ Y Ʋ���� N �� �Է����ּ���." << endl;
		std::cin >> isinput;
		if (isinput == "Y" || isinput == "y")
			break;

	}

	while (binput) {

		std::cout << "���� �������� ���� ������ �ִ� ����, �̸��� �Է��ϼ���.(�����ڷ� ���� ���!)" << endl;
		std::cin >> buyer_money >> buyer_name;
		std::cout << "�����ڰ� ������ �ִ� �� : " << buyer_money << " �̸� : " << buyer_name << endl;
		std::cout << "������ Y Ʋ���� N �� �Է����ּ���." << endl;
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
		std::cout << "��ġ ������ ������ �����̽ʴϱ�? (�� : 2000)" << endl;
		std::cin >> buy_fruit;
		std::cout << "������ Y Ʋ���� N �� �Է����ּ���." << endl;
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
		std::cout << "�߸��� �Է��� �޾ҽ��ϴ�. cpp ���� ����Ȯ�� ��Ź�帳�ϴ�." << endl;
	
	seller1.showinfo();
	seller2.showinfo();
	seller3.showinfo();
	buyer.showinfo();

	//seller1.~FruitSeller();
	//seller2.~FruitSeller();
	//buyer.~FruitBuyer();

	return 0;
}
