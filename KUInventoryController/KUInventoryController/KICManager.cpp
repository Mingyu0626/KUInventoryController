#include "KICManager.h"
#include <algorithm>
#include <typeinfo>


void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "���� ��¥ �Է� : ";
        getline(cin, date);
        result = checkDate(date);

        if (finalCheck == true) {
            todayDate = result;
            break;
        }
    }
    system("cls");
    init();
    printMenu();
    //addOrder(); //�ֹ� �߰�

    addOrder(); //�ֹ� �߰�

  //  sortDate();
    //sortStock();
    addOrder();
}


// ��¥ �Է� ����ó��
string KICManager::checkDate(string date)
{
    int year = 0, month = 0, day = 0;

    string a, b, c, d, e, f, g, h, i, j = "0";
    int num0, num1, num2, num3, num4, num5, num6, num7, num8, num9 = 0;

    // dateCheck : �⵵/��/���� ������ �����ϰ� ���� ���� �ִ��� Ȯ��
    // letterCheck : ������ ��ġ�� Ư�����ڰ� �����ϴ��� Ȯ�� 
    bool dateCheck = false, letterCheck = false;

    // letterCheck �� '.' ó�� ���� 
    string finalDate0 = "";
    string finalDate1 = "";
    string finalDate2 = "";

    while (true) {
        int z = 0;

        // ���� ���� ���� ó�� 
        if (date[0] == ' ') {
            cout << "�߸��� �Է��Դϴ�. ���� ������ ������� �ʽ��ϴ�." << endl;
            return "";
        }
        // 6�ڸ� �Է� ��(ex. 011028)
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

        // 8 �ڸ� �Է� ��(ex.20011028, 01-10-28)
        else if (date.length() == 8) {
            a = date[0];
            b = date[1];
            c = date[2];
            d = date[3];
            e = date[4];
            f = date[5];
            g = date[6];
            h = date[7];

            // 20011028�� ���
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

            // 01-10-28�� ��� 
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
                    cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                    return "";
                }
            }
        }

        // 10 �ڸ� �Է� �� (ex.2021-03-29)
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
                    cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                    return "";
                }
            }
        }
        else {
            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
            return "";
        }
    }
}

void KICManager::init()
{
    fstream fin("source.txt");

    if (!fin.is_open()) {
        cerr << "���� �б� ����\n";
        exit(0);
    }
    while (!fin.eof()) {

        string buffer;
        fin >> this->count;
        getline(fin, buffer);

        if (count > 0) {
            product = new KICProduct * [100];
            sortprod = new KICProduct * [100]; //�������� �߰�
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
            this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
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
    // �޴� �Է� ����ó��?
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  ���� �ڻ� : " << property << "��  " << endl;
        cout << "=================================================" << endl;
        cout << "  ��� ���� �˸�  " << endl;
        noStockAlarm();
        cout << "--------------- < �޴� > ---------------" << endl;
        cout << " 1) ��ǰ �ֹ� " << endl;
        cout << " 2) ��ǰ �˻� " << endl;
        cout << " 3) �ǸŰ� ���� " << endl;
        cout << " 4) ���� ���� " << endl;
        cout << "=================================================" << endl;
        cout << "�޴��� �����ϼ��� : ";
        cin >> menu;
        string buffer;
        getline(cin, buffer);
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();
        else if (menu == "3") {
            system("cls");
            cout << "--------------- < �޴� > ---------------" << endl;
            cout << " 1) ���� ��ǰ ���� " << endl;
            cout << " 2) �ǸŰ� ���� " << endl;
            cout << "=================================================" << endl;
            cout << "�޴��� �����ϼ��� : ";
            string subMenu;
            cin >> subMenu;
            getline(cin, buffer);
            if (menu == "1") {
                discountProds();												// ���� �������� ��ǰ ���
                discountReqProds();
                selectDiscountProds();
            }
            else if (menu == "2")
                selectMarginRate();
            else
                cout << "�ùٸ� ���ڸ� �Է��ϼ��� !" << endl;
        }
        else if (menu == "4")
            closingWork();
        else {
            cout << "�ùٸ� ���ڸ� �Է��ϼ��� !" << endl;
            system("pause");
        }
    }
}


void KICManager::noStockAlarm()
{
    // ��� 5�� ���ϸ� �˸� ���
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() <= 5) {
            cout << product[i]->getName() << " : ��� " << product[i]->getStock() << "��" << endl;
        }
    }
}

void KICManager::setDate()
{
    // ��� ó�� �ϰ� �Լ� �����ϱ�
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

    todayDate = "";

    switch (month) {
    case 2:
        if (day >= 1 && day <= 27) {
            day += 1;
        }
        else {
            month = 3;
            day = 1;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day >= 1 && day <= 29) {
            day += 1;
        }
        else {
            month += 1;
            day = 1;
        }
        break;
    case 12:
        if (day >= 1 && day <= 30) {
            day += 1;
        }
        else {
            year += 1;
            month = 1;
            day = 1;
        }
        break;
    default:
        if (day >= 1 && day <= 30) {
            day += 1;
        }
        else {
            month += 1;
            day = 1;
        }
        break;
    }
    todayDate = to_string(10000 * year + 100 * month + day);
    //cout << todayDate << endl;
}

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

    cout << " < " << year << "�� " << month << "�� " << day << "�� > \n" << endl;
}


void KICManager::addOrder()
{
    ///////////////////////////
    while (true) {

        /* �ֹ��� ���� ���� �ܾ� ���  */
        cout << " ���� �ܾ� : " << property << endl;

        cout << "********************�ֹ� ǰ��â*********************" << endl;
        sortAl();
        cout << "*****************************************************" << endl;

        /*�ֹ� ȭ�� ���*/
        string namePro = "";
        int numPro = 0;
        int price = 0;
        int k = 0; //�ݺ��� Ż�� ���� ����
        int productnum = -1; //�ֹ��� ������ �ε�����ȣ

        while (true) {
            cout << " �ֹ��� ��ǰ���� ���� ���� �Է�(q������ ����.) : ";
            getline(cin, namePro);
            //  cin.ignore();
              /*q������ ����*/
              if (namePro.compare("q")==0) {
                 // cout << "����" << endl;
                  printMenu();
              }


              /*�ֹ� ��ǰ �˻�, ���� ���*/
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
                cout << "�߸��� ��ǰ���Դϴ�." << endl;
            }

            if (k == 1)
                break;
        }

        cout << " �ֹ��� ��ǰ ������ ���� ���� �Է�  : ";
        cin >> numPro;

        cout << " �����ݾ� " << product[productnum]->getWPrice() * numPro << "��, " << " �����ݾ� " << property << "��" << "�ֹ��Ͻðڽ��ϱ�? (y/n)" << endl;
        price = product[productnum]->getWPrice() * numPro; //�����ݾ�_�ʹ� �� price�� �߽��ϴ�

        while (true) {
            char yn;
            cin >> yn;

            if (yn == 'y') {
                /* �ֹ� ��Ȳ �ݿ�*/
            //    cout << "�ֹ�!" << endl;
                if (property < price) {
                    cout << "���� �ݾ��� �����մϴ�." << endl;
                    addOrder();
                }
                else {
                    /*�ֹ� ����*/
                    property -= price;
                    count++;

                    /*product, sortprod �ֹ� ���� �߰�*/
                    this->product[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                    this->sortprod[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                    cout << "�ֹ� �Ϸ��߽��ϴ�" << endl;
                    cout << "�����ݾ�: " << price << ", �����ݾ�: " << property << endl;
                }
                break;
            }
            else if (yn == 'n') {
                cout << "�ֹ��� ��ҵǾ����ϴ�. " << endl;
                break;
            }
            else {
                cout << "�߸� �Է��ϼ̽��ϴ�. ";
                continue;
            }
        }
    }
    ////////////////
}



void KICManager::searchProds()
{
    sortAl();

    while (true) {

        string namePro;

        cout << "searchProds" << endl;
        cout << "�˻��ϰ��� �ϴ� ��ǰ�� �̸��� ���� ���� �Է� : ";
        getline(cin, namePro);

        /*q������ ����*/
        if (namePro.compare("q") == 0) {
            // cout << "����" << endl;
            printMenu();
        }

        cout << " =============== " << namePro << " �� �˻� ���" << " ============== " << endl;
        cout << endl;
        cout << endl;
        cout << "   ��ǰ��   " << "   ���   " << "  ���� �Ǹŷ� " << "   �������   " << "   ���Ű�   " << "   �ǸŰ�   " << endl;
        cout << endl;


        for (int j = 0; j < count; j++) {
            if ((product[j]->getName()).find(namePro) != string::npos) {
                if (product[j]->getStock() != 0) { // ��� 0�ΰ� ��� ����
                    cout << "   " << product[j]->getName() << "      " << product[j]->getStock() << "           " << product[j]->getSalesVolume() << "         " << product[j]->getExpDate() << "         " << product[j]->getWPrice() << "        " << product[j]->getRPrice() << endl;
                }
            }
        }

        if (namePro[0] == ' ') {
            cout << "���� ������ �Ұ����մϴ�. �ٽ� �Է��ϼ���" << endl;;
        }

        else if (namePro.find('~') != string::npos | namePro.find('!') != string::npos | namePro.find('@') != string::npos | namePro.find('#') != string::npos | namePro.find('$') != string::npos | namePro.find('%') != string::npos | namePro.find('^') != string::npos |
            namePro.find('&') != string::npos | namePro.find('*') != string::npos | namePro.find('(') != string::npos | namePro.find(')') != string::npos | namePro.find('-') != string::npos | namePro.find('+') != string::npos | namePro.find('_') != string::npos |
            namePro.find('=')) {
            cout << "Ư������ �Է��� �Ұ��մϴ�. �ٽ� �Է��ϼ���" << endl;
        }
        else { // ��Ÿ �� ��ȹ���� ����� ���� ����� ��� else�� ó��
            cout << " �߸��� �Է��Դϴ�. " << endl;

        }

    }
}

void KICManager::sortDate()
{
    //������� �ӹڼ� ����
    cout << "sortdate" << endl;

    /*for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }*/

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

    for (int i = 0; i < count; i++) {
        cout << *sortprod[i] << endl;
    }
}

void KICManager::sortAl()
{
    //�������� ����
    cout << "sortal" << endl;

    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }

    KICProduct temp = *sortprod[0];

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((sortprod[i]->getName().compare(sortprod[j]->getName())) > 0) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }

    /*addOrder ǰ��â���� �����Ǹŷ�*3 �̻��ΰ��� ���X*/
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() <= sortprod[i]->getSalesVolume() * 3) {
            cout << *sortprod[i] << endl;
        }
    }

    cout << endl;

}


void KICManager::sortStock()
{
    //��� ������ ����

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



void KICManager::discountProds()
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
    } // discount ���� ������ ����
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
    } // discount ���� �͵� �� disDate ������ ����
    bool check = false;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0) {
            cout << sortprod[i] << endl;
            check = true;
        }
    } //discount �ϴ� �͵� sorted �ȴ�� print
    if (!check) {
        cout << "���� discount�ϴ� ��ǰ ����" << endl;
    }

}


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
    } //  (������ǰ, ������� �ٸ��� => �ٸ���ǰ ��� : ���� ��� �� / ���� �Ǹŷ� ������ ����)
    bool accept = true;
    bool check = false;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() >= sortprod[i]->getSalesVolume() * 3 && sortprod[i]->getStock() != 0) {
            for (int j = 0; j < count; j++) {
                if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        accept = false;
                        break;
                    } // expDate�� ���� ��ǰ �󿡼� ���� �ֽŲ����� Ȯ��
                }
            }
            if (accept) {
                cout << sortprod[i] << endl;
                check = true;
            }
        }
    }// ���� ��� �� >= ���� �ĸŷ� *3 �� ��ǰ�� sorted �ȴ�� ���
    if (!check) {
        cout << "���� ���� ������ ��ǰ ����" << endl;
    }
}



void KICManager::selectDiscountProds()
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
    while (true) {
        cout << "���� �� ��ǰ���� �Է��ϼ��� : ";
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
        // ��������� ���� ������ product�� ���ĵǾ����� ���ɼ��� ũ��. ���� �׷��� ������ �տ� ���� �Լ� �߰�

        if (status == -1) {
            cout << "�׷��� ��ǰ���� �����ϴ�." << endl;
            system("cls");
            continue;
        }
        else if (status == 0) {
            cout << "�̹� ���� ���� ��ǰ�Դϴ�." << endl;
            system("cls");
            continue;
        }
        else if (status == 1) {
            cout << "�����Ͻ� ��ǰ���� ������ �� �ִ� ��ǰ�� �ƴմϴ�." << endl;
            system("cls");
            continue;
        }
        else if (status == 2) {
            bool check = false;
            while (true) {
                string line;
                int percentage = 0;
                cout << "������ %�� �Է����ּ��� (10 ����) (10 �̻� 90 ����) : ";
                getline(cin, line);
                if (line.compare("q") == 0) {
                    exit(0);
                }
                try {
                    percentage = stoi(line);
                }
                catch (const exception& e) {
                    cerr << "�Է��Ͻ� ���� ������ �ƴմϴ�." << endl;
                    system("cls");
                    continue;
                }
                if (percentage < 10 && percentage > 90) {
                    cout << "������ �˸��� �ʽ��ϴ�." << endl;
                    system("cls");
                    continue;
                }
                else if (percentage % 10 != 0) {
                    cout << "10 ������ �Է��ؾ� �մϴ�." << endl;
                    system("cls");
                    continue;
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
                    check = true;
                    break;
                }
            }
            if (check) {
                break;
            }
        }
    }
}



void KICManager::selectMarginRate()
{
}



void KICManager::closingWork()
{
    cout << "---------- <2021�� 10�� 24�� ��������> ----------\n";
    searchScrap();      // ��� ��ǰ �Ǻ� �� ��� �� �ʱ�ȭ(���)
    financeCalculate(); // �Ǹſ� ���� ��� �� ���� ��, ������ �����, ���� ������, ���� �ڻ� ���
    randomSV(); // ������ �Ǹŵ� ���� �Ǹŷ� ����
}



void KICManager::searchScrap()
{
    cout << "�ء���� �˸��ء�" << endl;
    int numOfScrapProds = 0;
    for (int i = 0; i < count; i++) {
        if (product[i]->getExpDate() == 0) { // ��������� ����� ��ǰ�� ��� �ش� ��ǰ�� ��� 0���� �������� �Ѵ�.
            numOfScrapProds++;
            cout << product[i]->getName() << " " << product[i]->getStock() << "�� ���" << endl;
            product[i]->setStock(0);
        }
        else { // ��������� ������� ���� ��ǰ�� ��� ��������� 1�� ���ҽ����ش�.
            product[i]->setExpDate(product[i]->getExpDate() - 1);
        }
    }
    if (numOfScrapProds == 0) {
        cout << "������ ���� ��ǰ�� �����ϴ�." << endl;
    }
}



void KICManager::financeCalculate()
{
    int tempStock = 0;
    int tempSalesVolume; // ��ǰ�� ���� �Ǹŷ�
    int remainSV;
    int tempWPrice;
    int tempRPrice;
    int todaySales = 0; // ���� ����� �հ�
    int todayProfits = 0; // ���� ������ �հ�
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() != 0) {
            tempStock = product[i]->getStock();
            tempSalesVolume = product[i]->getSalesVolume();
            tempWPrice = product[i]->getWPrice();
            tempRPrice = product[i]->getRPrice();

            if (tempStock < tempSalesVolume) { // ��ǰ�� ���� ��� ������ �Ǹŷ��� ���� ���
                string remainPN = product[i]->getName();

                todaySales = calTodaySales(todaySales, tempStock, tempRPrice);  // ��ǰ�� ���� ����� ��� �� �հ迡 �����ֱ�
                todayProfits = calTodayProfits(todayProfits, tempStock, tempRPrice, tempWPrice); // ��ǰ�� ���� ������ ��� �� �հ迡 �����ֱ�
                product[i]->setStock(0);
                remainSV = tempSalesVolume - tempStock;

                for (int j = 0; j < count; j++) {
                    if (remainPN.compare(product[j]->getName()) == 0 && product[j]->getStock() > 0) { // 1��° ��� ���� ���� ��ǰ ��ü Ž�� 
                        if (product[j]->getStock() < remainSV) { // ��ǰ�� ���� ��� ������ remainSV�� ���� ���
                            todaySales = calTodaySales(todaySales, product[j]->getStock(), tempRPrice);
                            todayProfits = calTodayProfits(todayProfits, product[j]->getStock(), tempRPrice, tempWPrice);
                            product[j]->setStock(0);
                            remainSV = remainSV - product[j]->getStock();

                            for (int k = 0; k < count; k++) {   // 2��° ��� ���� ���� ��ǰ ��ü Ž�� 
                                if (remainPN.compare(product[k]->getName()) == 0 && product[k]->getStock() > 0) {
                                    if (product[k]->getStock() < remainSV) { // ��ǰ�� ���� ��� ������ remainSV�� ���� ���
                                        todaySales = calTodaySales(todaySales, product[k]->getStock(), tempRPrice);
                                        todayProfits = calTodayProfits(todayProfits, product[k]->getStock(), tempRPrice, tempWPrice);
                                        product[j]->setStock(0);
                                        /* ������ǰ�� �ִ� 3ȸ�� �ֹ� �����ϹǷ� ���⼭ �� */
                                    }
                                    else { // // ��ǰ�� ���� ������ remainSV���� ���� ���
                                        todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                        todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                        product[k]->setStock(product[k]->getStock() - remainSV);
                                    }
                                }
                            }
                        }
                        else { // ��ǰ�� ���� ������ remainSV���� ���� ���
                            todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                            todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                            product[j]->setStock(product[j]->getStock() - remainSV);
                        }
                    }
                }

            }
            else { // ��ǰ�� ���� ��� ���� �Ǹŷ����� ���� ���
                todaySales = calTodaySales(todaySales, tempSalesVolume, tempRPrice); // ��ǰ�� ����� ��� �� �հ迡 �����ֱ�
                todayProfits = calTodayProfits(todayProfits, tempSalesVolume, tempRPrice, tempWPrice); // ��ǰ�� ������ ��� �� �հ迡 �����ֱ�
                product[i]->setStock(tempStock - tempSalesVolume);
            }
        }

    }
    property += todayProfits;
    cout << "---------------------------------------------------" << endl;
    cout << "���� ���� :" << todaySales << endl;
    cout << "���� ������ :" << todayProfits << endl;
    cout << "���� �ڻ� :" << property << endl;
}



void KICManager::randomSV()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++) {
        if (product[i]->getIsSVChanged() == false) {
            int tempSalesVolume = product[i]->getSalesVolume();
            string tempPN = product[i]->getName();
            int amountOfChange;                      // �Ǹŷ��� ��ȭ��.
            int plusOrMinus = (rand() + rand()) % 2; // ���� �ΰ� ���ؼ� 2�� ���� �������� 0�̸� �Ǹŷ� ����, 1�̸� �Ǹŷ� ����.

            if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
                amountOfChange = (rand() % 2);
                if (tempSalesVolume == 0) { // �Ǹŷ��� 0�ΰ�쿡�� �Ǹŷ��� ������ �� �����ϱ�... 0Ȥ�� 1��ŭ �Ǹŷ� ����.
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 5 && tempSalesVolume <= 15) {
                amountOfChange = (rand() % 3);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 15 && tempSalesVolume <= 25) {
                amountOfChange = (rand() % 5);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 25 && tempSalesVolume <= 35) {
                amountOfChange = (rand() % 7);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 35 && tempSalesVolume <= 50) {
                amountOfChange = (rand() % 10);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 50 && tempSalesVolume <= 65) {
                amountOfChange = (rand() % 13);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 65 && tempSalesVolume <= 85) {
                amountOfChange = (rand() % 16);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else if (tempSalesVolume > 85 && tempSalesVolume <= 110) {
                amountOfChange = (rand() % 21);
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            else {
                amountOfChange = (rand() % 25);
                if (tempSalesVolume >= 150) { // �Ǹŷ��� 150�̻��� �Ǹ� �Ǹŷ��� �����ϰԲ� ����
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                if (plusOrMinus == 0) {
                    tempSalesVolume += amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
                else {
                    tempSalesVolume -= amountOfChange;
                    product[i]->setSalesVolume(tempSalesVolume);
                }
            }

            product[i]->setSVChanged(true);
            /* ������ ���� �Ǹŷ��� ������ ��ǰ�� ������Ѹ� �ٸ� ���� ��ǰ�� ã�� ������ �Ǹŷ��� �������ִ� �۾� */
            for (int j = 0; j < count; j++) {
                if (tempPN.compare(product[j]->getName()) == 0 && product[j]->getIsSVChanged() == false) {
                    product[j]->setSalesVolume(tempSalesVolume);
                    product[j]->setSVChanged(true);
                }
            }
        }
    }
    /*���� ��ǰ�� ����� ���� �Ǹŷ� ���� �۾��� �Ϸ�Ǿ����Ƿ� �ٽ� IsSVChanged ������ false�� �������´�.*/
    for (int i = 0; i < count; i++) {
        product[i]->setSVChanged(false);
    }
}



int KICManager::calTodaySales(int ts, int sorsv, int rp)
{
    ts += (sorsv * rp);
    return ts;
}



int KICManager::calTodayProfits(int tp, int sorsv, int rp, int wp)
{
    tp += ((sorsv * rp) - (sorsv * wp));
    return tp;
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
