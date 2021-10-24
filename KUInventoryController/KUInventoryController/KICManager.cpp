#include "KICManager.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>
using namespace std;


void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "½ÃÀÛ ³¯Â¥ ÀÔ·Â : ";
        getline(cin, date);
        result = checkDate(date);

        if (finalCheck == true) {
            todayDate = result;

            cout << todayDate << endl;
            break;
        }
    }
	init();
 //   printMenu();
    // addOrder(); //ÁÖ¹® Ãß°¡
    //searchProds();
  //  sortDate();
    //sortAl();
  //sortStock();
    //addOrder();
}


// ³¯Â¥ ÀÔ·Â ¿¹¿ÜÃ³¸®
string KICManager::checkDate(string date) 
{
    int year = 0, month = 0, day = 0;

    string a, b = "0";
    int num0, num1 = 0;

    string c, d = "0";
    int num2, num3 = 0;

    string e, f = "0";
    int num4, num5 = 0;

    string g, h = "0";
    int num6, num7 = 0;

    string i, j = "0";
    int num8, num9 = 0;

    // dateCheck : ³âµµ/¿ù/ÀÏÀÇ Çü½ÄÀ» ¸¸Á·ÇÏ°í ¹üÀ§ ³»¿¡ ÀÖ´ÂÁö È®ÀÎ
    // letterCheck : Á¤ÇØÁø À§Ä¡¿¡ Æ¯¼ö¹®ÀÚ°¡ Á¸ÀçÇÏ´ÂÁö È®ÀÎ 
    bool dateCheck = false, letterCheck = false;

    // letterCheck ½Ã '.' Ã³¸® À§ÇÔ 
    string finalDate0 = "";
    string finalDate1 = "";
    string finalDate2 = "";

    while (true) {
        int z = 0;

        // ¼±Çà °ø¹é ¿¹¿Ü Ã³¸® 
        if (date[0] == ' ') {
            cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù. ¼±Çà °ø¹éÀ» Çã¿ëÇÏÁö ¾Ê½À´Ï´Ù." << endl;
            return "";
        }
        // 6ÀÚ¸® ÀÔ·Â ½Ã(ex. 011028)
        if (date.length() == 6) {
            for (int k = 0; k < date.length(); k++) {
                string tmp = "0";
                tmp = date[k];
                if (stoi(tmp) < 0 || stoi(tmp) > 9) {
                    z = 1;
                }
            }
            if (z == 1)
                continue;

            a = date[0];
            b = date[1];
            c = date[2];
            d = date[3];
            e = date[4];
            f = date[5];

            num0 = stoi(a);
            num1 = stoi(b);
            num2 = stoi(c);
            num3 = stoi(d);
            num4 = stoi(e);
            num5 = stoi(f);

            year = 10 * num0 + num1;
            month = 10 * num2 + num3;
            day = 10 * num4 + num5;

            if (date.find("-") == string::npos && date.find("/") == string::npos
                && date.find(".") == string::npos && date.find("_") == string::npos) {

                if (month >= 1 && month <= 12)
                    switch (month) {
                    case 2:
                        if (day >= 1 && day <= 28) {
                            if (year >= 0 && year <= 21) {
                                string n = "20";
                                finalCheck = true;
                                return n.insert(2, date);

                            }
                            else {
                                string n = "19";
                                finalCheck = true;
                                return n.insert(2, date);
                            }
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if (day >= 1 && day <= 30) {
                            if (year >= 0 && year <= 21) {
                                string n = "20";
                                finalCheck = true;
                                return n.insert(2, date);
                            }
                            else {
                                string n = "19";
                                finalCheck = true;
                                return n.insert(2, date);
                            }
                        }
                        break;
                    default:
                        if (day >= 1 && day <= 31) {
                            if (year >= 0 && year <= 21) {
                                string n = "20";
                                finalCheck = true;
                                return n.insert(2, date);
                            }
                            else {
                                string n = "19";
                                finalCheck = true;
                                return n.insert(2, date);
                            }
                        }
                        break;
                    }
            }
            else {
                continue;
            }
        }

        // 8 ÀÚ¸® ÀÔ·Â ½Ã(ex.20011028, 01-10-28)
        else if (date.length() == 8) {
            a = date[0];
            b = date[1];
            c = date[2];
            d = date[3];
            e = date[4];
            f = date[5];
            g = date[6];
            h = date[7];

            // 20011028ÀÇ °æ¿ì
            if (date.find("-") == string::npos && date.find("/") == string::npos
                && date.find(".") == string::npos && date.find("_") == string::npos) {
                num0 = stoi(a);
                num1 = stoi(b);
                num2 = stoi(c);
                num3 = stoi(d);
                num4 = stoi(e);
                num5 = stoi(f);
                num6 = stoi(g);
                num7 = stoi(h);

                year = 1000 * num0 + 100 * num1 + 10 * num2 + num3;
                month = 10 * num4 + num5;
                day = 10 * num6 + num7;

                if (year >= 1921 && year <= 2021) {
                    if (month >= 1 && month <= 12) {
                        switch (month) {
                        case 2:
                            if (day >= 1 && day <= 28) {
                                finalCheck = true;
                                return date;
                            }
                            break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            if (day >= 1 && day <= 30) {
                                finalCheck = true;
                                return date;
                            }
                            break;
                        default:
                            if (day >= 1 && day <= 31) {
                                finalCheck = true;
                                return date;
                            }
                            break;
                        }
                    }
                }
            }

            // 01-10-28ÀÇ °æ¿ì 
            else if (date.find("-") != string::npos || date.find("/") != string::npos || date.find(".") != string::npos || date.find("_") != string::npos) {
                num0 = stoi(a);
                num1 = stoi(b);
                // num2 = stoi(c);
                num3 = stoi(d);
                num4 = stoi(e);
                // num5 = stoi(f);
                num6 = stoi(g);
                num7 = stoi(h);

                year = 10 * num0 + num1;
                month = 10 * num3 + num4;
                day = 10 * num6 + num7;

                // dateCheck 
                if (month >= 1 && month <= 12) {
                    if (month == 2) {
                        if (day >= 1 && day <= 28) {
                            dateCheck = true;
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                    }
                }

                // letterCheck
                if ((date[2] == '-') && (date[5] == '-'))
                    letterCheck = true;
                else if ((date[2] == '/') && (date[5] == '/'))
                    letterCheck = true;
                else if ((date[2] == '.') && (date[5] == '.'))
                    letterCheck = true;
                else if ((date[2] == '_') && (date[5] == '_'))
                    letterCheck = true;

                if (dateCheck && letterCheck) {
                    if (date[2] == '-') {
                        vector<string> finalDate = split(date, '-');
                        date = finalDate[0] + finalDate[1] + finalDate[2];

                        if (year >= 0 && year <= 21) {
                            string n = "20";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                        else {
                            string n = "19";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                    }
                    else if (date[2] == '/') {
                        vector<string> finalDate = split(date, '/');
                        date = finalDate[0] + finalDate[1] + finalDate[2];

                        if (year >= 0 && year <= 21) {
                            string n = "20";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                        else {
                            string n = "19";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                    }
                    else if (date[2] == '.') {

                        for (int k = 0; k < 2; k++) {
                            finalDate0 += date[k];
                        }
                        for (int k = 3; k < 5; k++) {
                            finalDate1 += date[k];
                        }
                        for (int k = 6; k < 8; k++) {
                            finalDate2 += date[k];
                        }
                        date = finalDate0 + finalDate1 + finalDate2;

                        if (year >= 0 && year <= 21) {
                            string n = "20";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                        else {
                            string n = "19";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                    }
                    else if (date[2] == '_') {
                        vector<string> finalDate = split(date, '_');
                        date = finalDate[0] + finalDate[1] + finalDate[2];

                        if (year >= 0 && year <= 21) {
                            string n = "20";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                        else {
                            string n = "19";
                            finalCheck = true;
                            return n.insert(2, date);
                        }
                    }
                }
                else {
                    cout << "³¯Â¥¸¦ ¿Ã¹Ù¸£°Ô ÀÔ·ÂÇÏ¼¼¿ä." << endl;
                    return "";
                }
            }
        }
        
        // 10 ÀÚ¸® ÀÔ·Â ½Ã (ex.2021-03-29)
        else if (date.length() == 10) {
            if (date.find("-") != string::npos || date.find("/") != string::npos 
                || date.find(".") != string::npos || date.find("_") != string::npos) {
                a = date[0];
                b = date[1];
                c = date[2];
                d = date[3];
                e = date[4];
                f = date[5];
                g = date[6];
                h = date[7];
                i = date[8];
                j = date[9];

                num0 = stoi(a);
                num1 = stoi(b);
                num2 = stoi(c);
                num3 = stoi(d);
                //num4 = stoi(e);
                num5 = stoi(f);
                num6 = stoi(g);
                //num7 = stoi(h);
                num8 = stoi(i);
                num9 = stoi(j);

                year = 1000 * num0 + 100 * num1 + 10 * num2 + num3;
                month = 10 * num5 + num6;
                day = 10 * num8 + num9;

                // dateCheck
                if (month >= 1 && month <= 12) {
                    if (month == 2) {
                        if (day >= 1 && day <= 28) {
                            dateCheck = true;
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                    }
                }
                else {
                    dateCheck = false;
                }

                // letterCheck
                if ((date[4] == '-') && (date[7] == '-'))
                    letterCheck = true;
                else if ((date[4] == '/') && (date[7] == '/'))
                    letterCheck = true;
                else if ((date[4] == '.') && (date[7] == '.'))
                    letterCheck = true;
                else if ((date[4] == '_') && (date[7] == '_'))
                    letterCheck = true;
                else
                    letterCheck = false;

                if (dateCheck && letterCheck) {
                    if (date[4] == '-') {
                        vector<string> finalDate = split(date, '-');
                        date = finalDate[0] + finalDate[1] + finalDate[2];
                        finalCheck = true;
                        return date;
                    }
                    else if (date[4] == '/') {
                        vector<string> finalDate = split(date, '/');
                        date = finalDate[0] + finalDate[1] + finalDate[2];
                        finalCheck = true;
                        return date;
                    }
                    else if (date[4] == '.') {
                        for (int k = 0; k < 4; k++) {
                            finalDate0 += date[k];
                        }
                        for (int k = 5; k < 7; k++) {
                            finalDate1 += date[k];
                        }
                        for (int k = 8; k < 10; k++) {
                            finalDate2 += date[k];
                        }
                        date = finalDate0 + finalDate1 + finalDate2;
                        finalCheck = true;
                        return date;
                    }
                    else if (date[4] == '_') {
                        vector<string> finalDate = split(date, '_');
                        date = finalDate[0] + finalDate[1] + finalDate[2];
                        finalCheck = true;
                        return date;
                    }
                }
                else {
                    cout << "³¯Â¥¸¦ ¿Ã¹Ù¸£°Ô ÀÔ·ÂÇÏ¼¼¿ä." << endl;
                    return "";
                }
            }
        }
        else {
            cout << "³¯Â¥¸¦ ¿Ã¹Ù¸£°Ô ÀÔ·ÂÇÏ¼¼¿ä." << endl;
            return "";
        }
    }
}

void KICManager::init()
{
    fstream fin("source.txt");

    if (!fin.is_open()) {
        cerr << "ÆÄÀÏ ÀÐ±â ½ÇÆÐ\n";
        exit(0);
    }
    while (!fin.eof()) {
        string buffer;
        fin >> this->count;
        getline(fin, buffer);
      //  cout << count << endl;

        if (count > 0) {
            product = new KICProduct * [100];
            sortprod = new KICProduct * [100]; //Á¤·ÄÀ§ÇØ Ãß°¡
           // sortdateprod = new KICProduct * [100];
        }

        for (int i = 0; i < count; i++) {
            string str;
            getline(fin, str);
            int stock, salesVolume, expDate, wPrice, rPrice;
            fin >> stock >> salesVolume >> expDate >> wPrice >> rPrice;
            this->product[i] = new KICProduct(str, stock, salesVolume, expDate, wPrice, rPrice);
            getline(fin, buffer);
        }
    }
}


vector<string> KICManager::split(string str, char delimiter)
{
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;

}



void KICManager::printMenu()
{
    // ¸Þ´º ÀÔ·Â ¿¹¿ÜÃ³¸®?
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  º¸À¯ ÀÚ»ê : " << property << "¿ø  " << endl;
        cout << "=================================================" << endl;
        cout << "  Àç°í ºÎÁ· ¾Ë¸²  " << endl;
        noStockAlarm();
        cout << "--------------- < ¸Þ´º > ---------------" << endl;
        cout << " 1) Á¦Ç° ÁÖ¹® " << endl;
        cout << " 2) Á¦Ç° °Ë»ö " << endl;
        cout << " 3) ÇÒÀÎ Á¦Ç° ÁöÁ¤ " << endl;
        cout << " 4) ¾÷¹« ¸¶°¨ " << endl;
        cout << "=================================================" << endl;
        cout << "¸Þ´º¸¦ ¼±ÅÃÇÏ¼¼¿ä : ";
        cin >> menu;
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();
        else if (menu == "3")
            selectDiscountProds();
        else if (menu == "4")
            closingWork();
        else {
            cout << "¿Ã¹Ù¸¥ ¼ýÀÚ¸¦ ÀÔ·ÂÇÏ¼¼¿ä !" << endl;
            system("pause");
        }
    }
}


/*void KICManager::noStockAlarm(KICProduct** kicp[])
=======
    // ë©”ë‰´ ?…ë ¥ ?ˆì™¸ì²˜ë¦¬?
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  ë³´ìœ  ?ì‚° : " << property << "?? " << endl;
        cout << "=================================================" << endl;
        cout << "  ?¬ê³  ë¶€ì¡??Œë¦¼  " << endl;
        noStockAlarm();
        cout << "--------------- < ë©”ë‰´ > ---------------" << endl;
        cout << " 1) ?œí’ˆ ì£¼ë¬¸ " << endl;
        cout << " 2) ?œí’ˆ ê²€??" << endl;
        cout << " 3) ? ì¸ ?œí’ˆ ì§€??" << endl;
        cout << " 4) ?…ë¬´ ë§ˆê° " << endl;
        cout << "=================================================" << endl;
        cout << "ë©”ë‰´ë¥?? íƒ?˜ì„¸??: ";
        cin >> menu;
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();
        else if (menu == "3")
            selectDiscountProds();
        else if (menu == "4")
            closingWork();
        else {
            cout << "?¬ë°”ë¥??«ìžë¥??…ë ¥?˜ì„¸??!" << endl;
            system("pause");
        }
    }
}


void KICManager::noStockAlarm()
>>>>>>> main
{
}*/


void KICManager::printDate()
{
    int year = 0, month = 0, day = 0;

    string a, b, c, d, e, f, g, h = "0";
    int num0, num1, num2, num3, num4, num5, num6, num7 = 0;

    a = todayDate[0];
    b = todayDate[1];
    c = todayDate[2];
    d = todayDate[3];
    e = todayDate[4];
    f = todayDate[5];
    g = todayDate[6];
    h = todayDate[7];

    num0 = stoi(a);
    num1 = stoi(b);
    num2 = stoi(c);
    num3 = stoi(d);
    num4 = stoi(e);
    num5 = stoi(f);
    num6 = stoi(g);
    num7 = stoi(h);

    year = 1000 * num0 + 100 * num1 + 10 * num2 + num3;
    month = 10 * num4 + num5;
    day = 10 * num6 + num7;

    cout << " < " << year << "³â " << month << "¿ù " << day << "ÀÏ > \n" << endl;
}


void KICManager::addOrder()
{

    /* ÁÖ¹®À» À§ÇØ º¸À¯ ÀÜ¾× Ãâ·Â  */
    cout << " º¸À¯ ÀÜ¾× : " << property << endl;

    cout << "********************ÁÖ¹® Ç°¸ñÃ¢*********************" << endl;
    sortAl();
    cout << "*****************************************************" << endl;

    /*ÁÖ¹® È­¸é Ãâ·Â*/
    string namePro = "";
    int numPro = 0;
    int price = 0;
    int k = 0; //¹Ýº¹¹® Å»Ãâ À§ÇÑ º¯¼ö
    int productnum = -1; //ÁÖ¹®ÇÒ ¹°°ÇÀÇ ÀÎµ¦½º¹øÈ£

    while (true) {
        cout << " ÁÖ¹®ÇÒ Á¦Ç°¸íÀ» ¶ç¾î¾²±â ¾øÀÌ ÀÔ·Â(q´©¸£¸é Á¾·á.) : ";
        getline(cin, namePro);

        /*q´©¸£¸é Á¾·á*/
        //if (namePro.compare("q")) {
        //    cout << namePro << endl;
        //    //break;
        //}


        /*ÁÖ¹® »óÇ° °Ë»ö, °¡°Ý °è»ê*/
        for (int i = 0; i < count; i++) {
            if (((product[i]->getName().compare(namePro)) == 0)) {
                productnum = i;
                k = 1;
                break;
            }
        }
        if (productnum != -1)
            ;

        else {
            cout << "Àß¸øµÈ Á¦Ç°¸íÀÔ´Ï´Ù." << endl;
        }


        if (k == 1)
            break;
    }

    cout << " ÁÖ¹®ÇÒ Á¦Ç° ¼ö·®À» ¶ç¾î¾²±â ¾øÀÌ ÀÔ·Â  : ";
    cin >> numPro;

    cout << " °áÁ¦±Ý¾× " << product[productnum]->getWPrice() * numPro << "¿ø, " << " º¸À¯±Ý¾× " << property << "¿ø" << "ÁÖ¹®ÇÏ½Ã°Ú½À´Ï±î? (y/n)" << endl;
    price = product[productnum]->getWPrice() * numPro; //°áÁ¦±Ý¾×_³Ê¹« ±æ¾î¼­ price·Î Çß½À´Ï´ç

    while (true) {
        char yn;
        cin >> yn;

        if (yn == 'y') {
            /* ÁÖ¹® »óÈ² ¹Ý¿µ*/
        //    cout << "ÁÖ¹®!" << endl;
            if (property < price) {
                cout << "°áÁ¦ ±Ý¾×ÀÌ ºÎÁ·ÇÕ´Ï´Ù." << endl;
                addOrder();
            }
            else {
                /*ÁÖ¹® ¼º°ø*/
                property -= price;
                count++;

                /*product, sortprod ÁÖ¹® ³»¿ë Ãß°¡*/
                this->product[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                this->sortprod[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                cout << "ÁÖ¹® ¿Ï·áÇß½À´Ï´Ù" << endl;
                cout << "°áÁ¦±Ý¾×: " << price << ", º¸À¯±Ý¾×: " << property << endl;
            }
            break;
        }
        else if (yn == 'n') {
            cout << "ÁÖ¹®ÀÌ Ãë¼ÒµÇ¾ú½À´Ï´Ù. " << endl;
            break;
        }
        else {
            cout << "Àß¸ø ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù. ";
            continue;
        }
    }

}





void KICManager::searchProds()
{
    cout << product[8]->getName() << endl;
    sortAl();

    while (true) {

        string namePro;
        int k = 0; //search °¹¼ö

        cout << "searchProds" << endl;
        cout << "°Ë»öÇÏ°íÀÚ ÇÏ´Â »óÇ°ÀÇ ÀÌ¸§À» ¶ç¾î¾²±â ¾øÀÌ ÀÔ·Â : ";
        getline(cin, namePro);

        cout << " =============== " << namePro << " ÀÇ °Ë»ö °á°ú" << " ============== " << endl;
        cout << endl;
        cout << endl;
        cout << "   »óÇ°¸í   " << "   Àç°í   " << "  Àü³¯ ÆÇ¸Å·® " << "   À¯Åë±âÇÑ   " << "   µµ¸Å°¡   " << "   ÆÇ¸Å°¡   " << endl;
        cout << endl;

        for (int i = 0; i < count; i++)
            sortprod[i] = nullptr; // ºñ¿ì±â

        for (int i = 0; i < count; i++) {
            if ((product[i]->getName()).find(namePro) != string::npos) {
                if (product[i]->getStock() != 0) { // Àç°í 0ÀÎ°Ç Ãâ·Â ¾ÈÇÔ
                    this->sortprod[k] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
                    k++;
                    //cout << "   " << product[j]->getName() << "      " << product[j]->getStock() << "           " << product[j]->getSalesVolume() << "         " << product[j]->getExpDate() << "         " << product[j]->getWPrice() << "        " << product[j]->getRPrice() << endl;
                }
            }
        }

        /*À¯Åë±âÇÑ ÀÓ¹Ú¼ø Ãâ·Â*/
        for (int i = 0; i < count; i++) {
            if (sortprod[i] == nullptr)
                break;
            else {
                cout << "   " << sortprod[i]->getName() << "      " << sortprod[i]->getStock() << "           " << sortprod[i]->getSalesVolume() << "         " << sortprod[i]->getExpDate() << "         " << sortprod[i]->getWPrice() << "        " << sortprod[i]->getRPrice() << endl;
            }
        }
      //  cout << typeid(namePro[0]).name() << endl;  charÀÓ!
        int error = 0;
        cout << (int)namePro[0];

        /*ÀÔ·Â ¿¹¿ÜÃ³¸®*/
        if (namePro[0] == ' ') {
            cout << "¼±Çà °ø¹éÀº ºÒ°¡´ÉÇÕ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;;
        }
      //  cout << namePro.size() << endl;
        else {
            cout << "¿©±â¾ß" << endl;
            //for (int i = 0; i < namePro.size() / 2; i++)
             //   cout << namePro.size()/2 << endl;
            if (namePro[0] == ' ') {
                cout << "¼±Çà °ø¹éÀº ºÒ°¡´ÉÇÕ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;;
            }
            //for (int i = 0; i < namePro.size() / 2; i++) {
            //    cout << (int)namePro[i];
            //    cout<<namePro.size()<<endl;
            //    if ((int)namePro[i] >= 33){ //&& (int)namePro[i] <= 47) {
            //        cout << "Æ¯¼ö¹®ÀÚ ÀÔ·ÂÀº ºÒ°¡´ÉÇÕ´Ï´Ù" << endl;
            //        error = 1;
            //        break;
            //    }
            //}
        }
        
        
        //else if (namePro.find('~') != string::npos | namePro.find('!') != string::npos | namePro.find('@') != string::npos | namePro.find('#') != string::npos | namePro.find('$') != string::npos | namePro.find('%') != string::npos | namePro.find('^') != string::npos |
        //    namePro.find('&') != string::npos | namePro.find('*') != string::npos | namePro.find('(') != string::npos | namePro.find(')') != string::npos | namePro.find('-') != string::npos | namePro.find('+') != string::npos | namePro.find('_') != string::npos |
        //    namePro.find('=')) {
        //    cout << "Æ¯¼ö¹®ÀÚ ÀÔ·ÂÀº ºÒ°¡ÇÕ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        //    cout << namePro << endl;
        //}
        //else { // ¿ÀÅ¸ µî ±âÈ¹¼­¿¡ ¸í½ÃÇÑ ¿¹¿Ü »©°í´Â ¸ðµÎ else·Î Ã³¸®
        //    cout << " Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù. " << endl;

        //}

    }
}


void KICManager::sortDate()
{
    //À¯Åë±âÇÑ ÀÓ¹Ú¼ø Á¤·Ä
    cout << "sortdate" << endl;
   // cout << sortprod[0]->getName() << endl;
    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for(int j=i+1;j<count;j++){
            if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                if (sortprod[j] != nullptr) {
                    temp = *sortprod[i];
                    *sortprod[i] = *sortprod[j];
                    *sortprod[j] = temp;
                }
            }
        }
    }
    cout << "dd" << endl;
    for (int i = 0; i < count; i++) {
        //if (sortprod[i] = nullptr)
        //    break;
        cout << *sortprod[i] << endl;
    }
}

void KICManager::sortAl()
{
    //¤¡¤¤¤§¼ø Á¤·Ä
    cout << "sortal" << endl;
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }


    KICProduct temp = *sortprod[0];

    cout << "hi" << endl;

   // cout << sortprod[3]->getName() << endl;

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            // cout << (*sortprod[i]->getName() < *sortprod[j]->getName()) << endl;
            if ((sortprod[i]->getName().compare(sortprod[j]->getName())) > 0) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }

        
    /*addOrder Ç°¸ñÃ¢¿¡¼­ Àü³¯ÆÇ¸Å·®*3 ÀÌ»óÀÎ°ÍÀº Ãâ·ÂX*/
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() <= sortprod[i]->getSalesVolume() * 3) {
            cout << *sortprod[i] << endl;
        }
    }
   
    cout << endl;

}


void KICManager::sortStock()
{
    //Àç°í ÀûÀº¼ø Á¤·Ä

    cout << "sortstock" << endl;
    int t = 0;
    
   for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    } 
    cout << typeid(product[3]->getName()).name() << endl;
    int result;
    char str = 'd';
    char str1 = 'e';

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getStock() > sortprod[j]->getStock()) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        cout << *sortprod[i] << endl;
    }

}



void KICManager::changePrice()
{

}


/*void KICManager::discountProds(KICProduct** kicp[])
{
    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getDiscount() != 0) {
                if (sortprod[i]->getDiscount() > sortprod[j]->getDiscount()) {
                    temp = *sortprod[i];
                    *sortprod[i] = *sortprod[j];
                    *sortprod[j] = temp;
                }
            }
        }
    } // discount ¸¹Àº ¼øÀ¸·Î Á¤·Ä
    temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getDiscount() != 0) {
                if (sortprod[i]->getDiscount() == sortprod[j]->getDiscount()) {
                    if (sortprod[i]->getDisDate() > sortprod[j]->getDisDate()) {
                        temp = *sortprod[i];
                        *sortprod[i] = *sortprod[j];
                        *sortprod[j] = temp;
                    }
                }
            }
        }
    } // discount °°Àº °Íµé Áß disDate ¼øÀ¸·Î Á¤·Ä

    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0) {
            cout << sortprod[i] << endl;
        }
    } //discount ÇÏ´Â °Íµé sorted µÈ´ë·Î print
}*/


void KICManager::discountReqProds()
{
    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getStock() / sortprod[i]->getSalesVolume() > sortprod[j]->getStock() / sortprod[j]->getSalesVolume()) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    } //  (°°ÀºÁ¦Ç°, À¯Åë±âÇÑ ´Ù¸¥°Å => ´Ù¸¥Á¦Ç° Ãë±Þ : ³²Àº Àç°í ¼ö / Àü³¯ ÆÇ¸Å·® ¼øÀ¸·Î Á¤·Ä)
    bool accept = true;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() >= sortprod[i]->getSalesVolume() * 3 && sortprod[i]->getStock() != 0) {
            for (int j = 0; j < count; j++) {
                if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        accept = false;
                        break;
                    } // expDate°¡ °°Àº Á¦Ç° »ó¿¡¼­ °¡Àå ÃÖ½Å²¨ÀÎÁö È®ÀÎ
                }
            }
            if (accept) {
                cout << sortprod[i] << endl;
            }
        }
    }// ³²Àº Àç°í ¼ö >= Àü³¯ ÆÄ¸Å·® *3 ÀÎ Á¦Ç°¸¸ sorted µÈ´ë·Î Ãâ·Â
}



void KICManager::selectDiscountProds()//(KICProduct** kicp[])
{

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }

    }
    cout << "ÇÒÀÎ ÇÒ Á¦Ç°¸íÀ» ÀÔ·ÂÇÏ¼¼¿ä : ";

    //}
    cout << "? ì¸ ???œí’ˆëª…ì„ ?…ë ¥?˜ì„¸??: ";

    string select;
    getline(cin, select);
    if (select.compare("q") == 0) {
        exit(0);
    }
    int status = -1;
    for (int i = 0; i < count; i++) {
        if (select.compare(product[i]->getName()) == 0 && status == -1) {
            if (product[i]->getStock() != 0) {
                if (sortprod[i]->getDiscount() != 0) {
                    status = 0;
                    break;
                }
                else {
                    if (sortprod[i]->getStock() >= sortprod[i]->getSalesVolume() * 3) {
                        status = 2;
                    }
                    else {
                        status = 1;
                    }
                }
            }
        }
    }
    // À¯Åë±âÇÑÀÌ ºü¸¥ ¼øÀ¸·Î product´Â Á¤·ÄµÇ¾îÀÖÀ» °¡´É¼ºÀÌ Å©´Ù. ¸¸¾à ±×·¸Áö ¾ÊÀ¸¸é ¾Õ¿¡ Á¤·Ä ÇÔ¼ö Ãß°¡

    if (status == -1) {
        cout << "±×·¯ÇÑ Á¦Ç°¸íÀÌ ¾ø½À´Ï´Ù." << endl;
    }
    if (status == 0) {
        cout << "ÀÌ¹Ì ÇÒÀÎ ÁßÀÎ Á¦Ç°ÀÔ´Ï´Ù." << endl;
    }
    else if (status == 1) {
        cout << "¼±ÅÃÇÏ½Å Á¦Ç°¸íÀº ÇÒÀÎÇÒ ¼ö ÀÖ´Â Á¦Ç°ÀÌ ¾Æ´Õ´Ï´Ù." << endl;
    }
    else if (status == 2) {
        while(true){
            string line;
            int percentage = 0;
            cout << "ÇÒÀÎÇÒ %¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä (10 ´ÜÀ§) (10 ÀÌ»ó 90 ÀÌÇÏ) : ";
            getline(cin, line);
            if (line.compare("q") == 0) {
                exit(0);
            }
            try {
                percentage = stoi(line);
            }catch (const exception& e) {
                cerr << "ÀÔ·ÂÇÏ½Å ¼ö°¡ Á¤¼ö°¡ ¾Æ´Õ´Ï´Ù." << endl;
            }
            if (percentage < 10 && percentage > 90) {
                cout << "¹üÀ§°¡ ¾Ë¸ÂÁö ¾Ê½À´Ï´Ù." << endl;
            }
            else if (percentage % 10 != 0) {
                cout << "10 ´ÜÀ§·Î ÀÔ·ÂÇØ¾ß ÇÕ´Ï´Ù." << endl;
            }
            else {
                for (int i = 0; i < count; i++) {
                    if (select.compare(product[i]->getName()) == 0 && product[i]->getStock() != 0) {
                        product[i]->setDiscount(percentage);
                        product[i]->setDisDate(3);
                        int newprice = product[i]->getRPrice() * (100 + percentage / 100);
                        product[i]->setRPrice(newprice);
                    }
                }
                break;
            }
        }
    }
}



/*void KICManager::selectMarginRate(KICProduct** kicp[])
{
}*/



void KICManager::closingWork()
{
}



/*void KICManager::searchScrap(KICProduct** kicp[])
{
}



void KICManager::printFinance()
{
}*/



void KICManager::randomSV()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++) {

        int tempSalesVolume = product[i]->getSalesVolume();
        int amountOfChange;                      // ÆÇ¸Å·®ÀÇ º¯È­·®.
        int plusOrMinus = (rand() + rand()) % 2; // ³­¼ö µÎ°³ ´õÇØ¼­ 2·Î ³ª´« ³ª¸ÓÁö°¡ 0ÀÌ¸é ÆÇ¸Å·® Áõ°¡, 1ÀÌ¸é ÆÇ¸Å·® °¨¼Ò.

        if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
            amountOfChange = (rand() % 2);
            if (tempSalesVolume == 0) { // ÆÇ¸Å·®ÀÌ 0ÀÎ°æ¿ì¿¡¼­ ÆÇ¸Å·®ÀÌ °¨¼ÒÇÒ ¼ø ¾øÀ¸´Ï±î... 0È¤Àº 1¸¸Å­ ÆÇ¸Å·® Áõ°¡.
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 5 && tempSalesVolume <= 15) {
            amountOfChange = (rand() % 3);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        } 

        else if (tempSalesVolume > 15 && tempSalesVolume <= 25) {
            amountOfChange = (rand() % 5);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 25 && tempSalesVolume <= 35) {
            amountOfChange = (rand() % 7);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 35 && tempSalesVolume <= 50) {
            amountOfChange = (rand() % 10);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 50 && tempSalesVolume <= 65) {
            amountOfChange = (rand() % 13);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 65 && tempSalesVolume <= 85) {
            amountOfChange = (rand() % 16);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else if (tempSalesVolume > 85 && tempSalesVolume <= 110) {
            amountOfChange = (rand() % 21);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }

        else {
            amountOfChange = (rand() % 25);
            if (plusOrMinus == 0) {
                tempSalesVolume = tempSalesVolume + amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
            else {
                tempSalesVolume = tempSalesVolume - amountOfChange;
                product[i]->setSalesVolume(tempSalesVolume);
            }
        }
    }
}



KICManager::KICManager()
{
}



KICManager::~KICManager()
{
}



int KICManager::getProperty()
{
    return 0;
}



void KICManager::setProperty()
{
}

