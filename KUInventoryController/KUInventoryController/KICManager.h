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
	bool finalCheck = false;										// checkDate(string date)�� �������� �۵� ���� Ȯ�� 
	string checkDate(string date);									// ��¥ �Է� ���� ó���� ���� 8�ڸ� ����(ex 20211023) ������ string ����
	vector<string> split(string str, char delimiter);				// Ư�� ���ڿ� ���� string ����

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
	void discountProds();						// ���� �������� ��ǰ ���
	void discountReqProds();						// ������ �ʿ��� ��ǰ �Ǻ�
	void selectDiscountProds();					// ���� ��ǰ ����
	void selectMarginRate();						// ������ ����


	/*----- 6.4 ���� ���� -----*/
	void closingWork();												// ���� ����
	void searchScrap();							// ��� ��ǰ�� �Ǻ� �� ���
	void printFinance();											// ���� ��Ȳ ���(���� ����, ���� ������, ���� �ڻ�)
	void randomSV();								// �Ǹŷ��� ���� �˰��� ���� ����

	/*----- 6.5 getter. setter -----*/
	int getProperty();
	void setProperty();


public:
	KICManager();
	~KICManager();
	void start();
};