#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include "KICProduct.h"

using namespace std;

class KICManager
{
	int count = 0;
	KICProduct** product = nullptr;
	void init();													// �ؽ�Ʈ ���� �о����	
	void printMenu();												// ���� ȭ���� �޴� ���
	void noStockAlarm(KICProduct** kicp[]);							// ��� ���� �˸�


	/*----- 6.1 ��ǰ �ֹ� -----*/
	void addOrder();												// �ֹ� �߰�

	/*----- 6.2 ��ǰ �˻� -----*/
	void searchProds();												// ��ǰ �˻�
	void sortStock();												// ����

	/*----- 6.3 �ǸŰ� ����-----*/
	void changePrice();												// �ǸŰ� ����
	void discountProds(KICProduct** kicp[]);						// ���� �������� ��ǰ ���
	void discountReqProds(KICProduct** kicp[]);						// ������ �ʿ��� ��ǰ �Ǻ�
	void selectDiscountProds(KICProduct** kicp[]);					// ���� ��ǰ ����
	void selectMarginRate(KICProduct** kicp[]);						// ������ ����


	/*----- 6.4 ���� ���� -----*/
	void closingWork();												// ���� ����
	void searchScrap(KICProduct** kicp[]);							// ��� ��ǰ�� �Ǻ� �� ���
	void printFinance();											// ���� ��Ȳ ���(���� ����, ���� ������, ���� �ڻ�)
	void randomSV(KICProduct** kicp[]);								// �Ǹŷ��� ���� �˰��� ���� ����


public:
	KICManager();
	~KICManager();
	void start();
};