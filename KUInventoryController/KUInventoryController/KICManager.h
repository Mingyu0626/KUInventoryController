#pragma once

#include <iostream>
#include <string>

using namespace std;

class KICManager

{
	int balance;
	int randomSales();
	void init();
	void printMenu();
	void addOrder();
	void discountPrice();
	void changePrice();
	void noStockAlarm();
	void sortStock();
public:
	KICManager();
	~KICManager();
	void start();
};