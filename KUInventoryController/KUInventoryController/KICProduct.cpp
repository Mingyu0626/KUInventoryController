#include "KICProduct.h"

KICProduct::KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice) 
    : name(name), stock(stock), salesVolume(salesVolume), expDate(expDate), wPrice(wPrice), rPrice(rPrice)
{
}

KICProduct::~KICProduct()
{
}

string KICProduct::getName()
{
    return this->name;
}

void KICProduct::setName(string name)
{
    this->name = name;
}

int KICProduct::getStock()
{
    return this->stock;
}

void KICProduct::setStock(int stock)
{
    this->stock = stock;
}

int KICProduct::getSalesVolume()
{
    return this->salesVolume;
}

void KICProduct::setSalesVolume(int salesVolume)
{
    this->salesVolume = salesVolume;
}

int KICProduct::getExpDate()
{
    return this->expDate;
}

void KICProduct::setExpDate(int expDate)
{
    this->expDate = expDate;
}

int KICProduct::getWPrice()
{
    return this->wPrice;
}

void KICProduct::setWPrice(int wPrice)
{
    this->wPrice = wPrice;
}

int KICProduct::getRPrice()
{
    return this->rPrice;
}

void KICProduct::setRPrice(int rPrice)
{
    this->rPrice = rPrice;
}

bool KICProduct::getIsSVChanged()
{
    return this->isSVChanged;
}

void KICProduct::setSVChanged(bool isSVChanged)
{
    this->isSVChanged = isSVChanged;
}


ostream& operator<<(ostream& out, const KICProduct& p)
{
    out << p.name << ' ' << p.stock << ' ' << p.salesVolume << ' ' << p.expDate << ' ' << p.wPrice << ' ' << p.rPrice;
    return out;
}
