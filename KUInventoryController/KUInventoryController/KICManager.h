#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "KICProduct.h"
#include <fstream>
#include "KICProduct.h"

using namespace std;

class KICManager
{
	int property = 1000000;			// ���� �ڻ�
	string todayDate;				// ��¥
	int count = 0;					// ���ʷ� �ؽ�Ʈ ���Ͽ��� ��ǰ �������� ������ ��, ��ǰ�� ����
	KICProduct** product = nullptr; // ��ǰ ������ ��� ���� 1���� �迭

	KICProduct** sortprod = nullptr; //���� ���� ���� 1���� �迭

	void init();													// �ؽ�Ʈ ���� �о����	

	/*----- 5. ���� ȭ�� �� ���� ȭ��-----*/
	bool finalCheck = false;
	string checkDate(string date);
	vector<string> split(string str, char delimiter);

	void printMenu();												// ���� ȭ���� �޴� ���
	void noStockAlarm(KICProduct** kicp[]);							// ��� ���� �˸�

	/*----- 6.1 ��ǰ �ֹ� -----*/
	void addOrder();												// �ֹ� �߰�

	/*----- 6.2 ��ǰ �˻� -----*/
	void searchProds();												// ��ǰ �˻�
	void sortStock();												// ����_����
	void sortDate();												// ����_������ӹڼ�
	void sortAl();													// ����_��������

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

	/*----- 6.5 getter. setter -----*/
	int getProperty();
	void setProperty();


public:
	KICManager();
	~KICManager();
	void start();
};