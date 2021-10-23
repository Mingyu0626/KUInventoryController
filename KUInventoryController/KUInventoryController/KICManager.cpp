#include "KICManager.h"
#include <fstream>

void KICManager::start()
{
	init();
}

int KICManager::randomSales()
{
    return 0;
}

void KICManager::init()
{  
	fstream fin("C:\\Users\\������\\Source\\Repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\source.txt");

	if (!fin.is_open()) {
		cerr << "���� �б� ����\n";
		exit(0);
	}
	while (!fin.eof()) {

		string buffer;
		fin >> this->count;
		getline(fin, buffer);
		cout << count << endl;

		if (count > 0) {
			product = new KICProduct * [count];
		}


		for (int i = 0; i < count; i++) {
			string str;
			getline(fin, str);
			int stock, salesVolume, expDate, wPrice, rPrice;
			fin >> stock >> salesVolume >> expDate >> wPrice >> rPrice;
			this->product[i] = new KICProduct(str, stock, salesVolume, expDate, wPrice, rPrice);
			getline(fin, buffer);
		}
		for (int i = 0; i < count; i++) {
			cout << *product[i] << endl;
		}
	}
}

void KICManager::printMenu()
{
}

void KICManager::addOrder()
{
}

void KICManager::discountPrice()
{
}

void KICManager::changePrice()
{
}

void KICManager::noStockAlarm()
{
}

void KICManager::sortStock()
{
}

KICManager::KICManager()
{
}

KICManager::~KICManager()
{
}
