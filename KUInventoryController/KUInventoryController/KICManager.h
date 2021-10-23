#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "KICProduct.h"

using namespace std;

class KICManager
{
	int count = 0;
	KICProduct** product = nullptr;
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