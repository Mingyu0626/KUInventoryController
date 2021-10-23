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
	int fixedExpDate;   // 처음 유통기한 저장
	int wPrice;			// 도매가(주문할 때 드는 금액)
	int rPrice;			// 판매가(판매할 때 얻는 금액)
	int discount = 0;
	int disDate = 0;

	bool isSVChanged = false;	// 전날 판매량이 변화한 객체인지 판단하는 부울 변수

public:
	KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice);
	~KICProduct();
	string getName();
	void setName(string name);
	int getStock();
	void setStock(int stock);
	int getSalesVolume();
	void setSalesVolume(int salesVolume);
	int getExpDate();
	void setExpDate(int expDate);
	int getWPrice();
	void setWPrice(int wPrice);
	int getRPrice();
	void setRPrice(int rPrice);
	bool getIsSVChanged();
	void setSVChanged(bool isSVChanged);

	friend ostream& operator<<(ostream& out, const KICProduct& p);
};