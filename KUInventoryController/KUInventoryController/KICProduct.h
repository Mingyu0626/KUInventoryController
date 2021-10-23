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
	int wPrice;			// ���Ű�(�ֹ��� �� ��� �ݾ�)
	int rPrice;			// �ǸŰ�(�Ǹ��� �� ��� �ݾ�)

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