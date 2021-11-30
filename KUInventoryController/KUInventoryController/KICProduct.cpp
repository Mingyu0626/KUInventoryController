#include "KICProduct.h"

KICProduct::KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice)
    : name(name), stock(stock), salesVolume(salesVolume), expDate(expDate), fixedExpDate(expDate), wPrice(wPrice), rPrice(rPrice)
{
}

KICProduct::KICProduct(string name, int stock, int salesVolume, int expDate, int wPrice, int rPrice, int discount, int disDate)
    : name(name), stock(stock), salesVolume(salesVolume), expDate(expDate), fixedExpDate(expDate), wPrice(wPrice), rPrice(rPrice), discount(discount), disDate(disDate)
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

int KICProduct::getFixedExpDate()
{
    return this->fixedExpDate;
}

void KICProduct::setFixedExpDate(int fiexedExpDate)
{
    this->fixedExpDate = fixedExpDate;
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

int KICProduct::getDiscount()
{
    return this->discount;
}

void KICProduct::setDiscount(int discount)
{
    this->discount = discount;
}

bool KICProduct::getIsSVChanged()
{
    return this->isSVChanged;
}

void KICProduct::setSVChanged(bool isSVChanged)
{
    this->isSVChanged = isSVChanged;
}

int KICProduct::getDisDate()
{
    return this->disDate;
}

void KICProduct::setDisDate(int disDate)
{
    this->disDate = disDate;
}

int KICProduct::getIsStockDeclined()
{
    return this->isStockDeclined;
}

void KICProduct::setIsStockDeclined(bool isStockDeclined)
{
    this->isStockDeclined = isStockDeclined;
}


ostream& operator<<(ostream& out, const KICProduct& p)
{
    out << p.name << '\n' << p.stock << ' ' << p.salesVolume << ' ' << p.expDate << ' ' << p.wPrice << ' ' << p.rPrice;
    if (p.discount != 0) {
        out << ' ' << p.rPrice * 100 / (100 - p.discount) << ' ' << p.disDate;
    }
    return out;
}