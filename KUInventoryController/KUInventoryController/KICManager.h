#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "KICProduct.h"
#include <fstream>
#include <random>
#include "KICProduct.h"
#include <conio.h>
#include <Windows.h>
#include<iomanip>
#include <algorithm>
#include <typeinfo>
#include <fstream>

using namespace std;

class KICManager
{
	int property = 1000000;         // ���� �ڻ�
	string todayDate;            // ��¥
	int balance;                    // ���� �ܾ�
	int count = 0;               // ���ʷ� �ؽ�Ʈ ���Ͽ��� ��ǰ �������� ������ ��, ��ǰ�� ����
	KICProduct** product = nullptr; // ��ǰ ������ ��� ���� 1���� �迭

	KICProduct** sortprod = nullptr; //���� ���� ���� 1���� �迭
  //   KICProduct** fixedprod = nullptr; //���� ������ ����ִ� ���� 1���� �迭(������)

	void init();                                       // �ؽ�Ʈ ���� �о����   

	/*----- 5. ���� ȭ�� �� ���� ȭ��-----*/
	bool finalCheck = false;                                 // checkDate(string date)�� �������� �۵� ���� Ȯ�� 
	string checkDate(string date);                              // ��¥ �Է� ���� ó���� ���� 8�ڸ� ����(ex 20211023) ������ string ����
	vector<string> split(string str, char delimiter);               // Ư�� ���ڿ� ���� string ����

	void printMenu();                                    // ���� ȭ���� �޴� ���
	void noStockAlarm();                                 // ��� ���� �˸�
	void setDate();                                       // ���� ���� �� �������� ��¥ �̵�(��� ó���� �� �����ϱ�)
	void printDate();                                    // ��ܿ� ��¥ ����ϴ� �Լ�
	bool loadInfor();                                    // �ؽ�Ʈ ���Ͽ� ����Ǿ� �ִ� ������ �ҷ����� �Լ� 

	/*----- 6.1 ��ǰ �ֹ� -----*/
	void addOrder();                                       // �ֹ� �߰�

	/*----- 6.2 ��ǰ �˻� -----*/
	void searchProds();                                       // ��ǰ �˻�
	void sortStock();                                       // ����_����
	void sortDate();                                    // ����_������ӹڼ�
	void sortAl();                                          // ����_��������

	/*----- 6.3 �ǸŰ� ����-----*/
	void discountProds();												// ���� �������� ��ǰ ���
	void discountReqProds();											// ������ �ʿ��� ��ǰ �Ǻ�
	void selectDiscountProds();											// ���� ��ǰ ����
	void selectMarginRate();											// ������ ����
	
	/*----- 6.4 �߰�/���� -----*/
	void addlist();														//��ǰ �߰�
	void removelist();													//��ǰ ����

	/*----- 6.5 ���� ���� -----*/
	void closingWork();													// ���� ���� ����
	void searchScrap();													// ��� ��ǰ�� �Ǻ� �� ���
	void financeCalculate();											// ���� ��Ȳ ���(����sear ����, ���� ������, ���� �ڻ�)
	void randomSV();													// �Ǹŷ��� ���� �˰��� ���� ����
	int calTodaySales(int ts, int sorsv, int rp);
	int calTodayProfits(int tp, int sorsv, int rp, int wp);

	/*----- 6.6 ���α׷� ���� -----*/

	/*----- 6.7 getter. setter -----*/
	int getProperty();
	void setProperty();


public:
	KICManager();
	~KICManager();
	void start();
};