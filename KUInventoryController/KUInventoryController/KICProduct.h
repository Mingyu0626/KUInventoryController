#pragma once

#include <iostream>
#include <string>

using namespace std;

class KICProduct
{
	string name;		// ��ǰ �̸�
	int stock;			// ���� ��� ��
	int salesVolume;	// ���� �Ǹŷ�
	int expDate;		// �������
	int fixedExpDate;   // ó�� ������� ����
	int wPrice;			// ���Ű�(�ֹ��� �� ��� �ݾ�)
	int rPrice;			// �ǸŰ�(�Ǹ��� �� ��� �ݾ�)
	int discount = 0;
	int disDate = 0;
	bool isSVChanged = false;	// ���� �Ǹŷ��� ��ȭ�� ��ü���� �Ǵ��ϴ� �ο� ����
	bool isStockDeclined = false; // �Ǹŷ��� ���� ��� �ٿ������ �Ǵ��ϴ� �ο� ����

public:
	KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice);
	KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice, int discount, int disDate);
	~KICProduct();
	string getName();
	void setName(string name);
	int getStock();
	void setStock(int stock);
	int getSalesVolume();
	void setSalesVolume(int salesVolume);
	int getExpDate();
	void setExpDate(int expDate);
	int getFixedExpDate();
	void setFixedExpDate(int fiexedExpDate);
	int getWPrice();
	void setWPrice(int wPrice);
	int getRPrice();
	void setRPrice(int rPrice);
	int getDiscount();
	void setDiscount(int discount);
	bool getIsSVChanged();
	void setSVChanged(bool isSVChanged);
	int getDisDate();
	void setDisDate(int disDate);
	int getIsStockDeclined();
	void setIsStockDeclined(bool isStockDeclined);

	friend ostream& operator<<(ostream& out, const KICProduct& p);
};