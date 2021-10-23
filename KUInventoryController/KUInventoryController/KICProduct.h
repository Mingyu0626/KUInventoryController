#pragma once

#include <iostream>
#include <string>

using namespace std;

class KICProduct
{
	string name;		// 제품 이름
	int stock;			// 남은 재고 수
	int salesVolume;	// 전날 판매량
	int expDate;		// 유통기한
	int wPrice;			// 도매가(주문할 때 드는 금액)
	int rPrice;			// 판매가(판매할 때 얻는 금액)

public:
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