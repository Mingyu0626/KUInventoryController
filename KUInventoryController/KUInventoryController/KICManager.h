#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class KICManager
{
	int property = 1000000;   // 보유 자산
	string todayDate;
	bool finalCheck = false;
	int randomSales();
	void init();
	string checkDate(string date);
	void printMenu();
	void addOrder();
	void discountPrice();
	void changePrice();
	void noStockAlarm();
	void sortStock();
	vector<string> split(string str, char delimiter);
	
public:
	KICManager();
	~KICManager();
	void start();
	int getProperty();
	void setProperty(int p);
	
};