#pragma once

#include <iostream>
#include <string>

using namespace std;

class KICProduct
{
	string name;
	int stock;
	int expDate;
	int wPrice;
	int rPrice;

public:
	KICProduct();
	KICProduct(string name, int stock, int expDate, int wPrice, int rPrice);
	~KICProduct();
	string getName();
	void setName(string name);
	int getExpDate();
	void setExpDate(int expDate);
	int getWPrice();
	void setWPrice(int wPrice);
	int getRPrice();
	void setRPrice(int rPrice);
};