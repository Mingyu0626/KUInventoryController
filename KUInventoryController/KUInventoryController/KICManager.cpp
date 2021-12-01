#include "KICManager.h"
#include <string>

using namespace std;

void KICManager::start()
{
    while (true) {
        system("cls");

        string menuNum;

        cout << "[KU Inventory Controller]" << endl;
        cout << "=================================================" << endl;
        cout << "1. ���� ����" << endl;
        cout << "2. �ҷ�����" << endl;
        cout << "=================================================" << endl;
        cout << "���� ����� �����ϼ��� : ";
        getline(cin, menuNum);

        if (menuNum == "1") {
            system("cls");
            init();
        }
        else if (menuNum == "2") {
            if (loadInfor()) {
                break;
            }
            else {
                cout << "����Ǿ� �ִ� ������ �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
                system("pause");
                continue;
            }
        }
        else {
            cout << "�ùٸ� ���ڸ� �Է��ϼ���. " << endl;
            system("pause");
        }

    }
    system("cls");
    printMenu();
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
            system("pause");
            return "";
        }
        // 6�ڸ� �Է� ��(ex. 011028)
        if (date.length() == 6) {
            for (int k = 0; k < (int)date.length(); k++) {
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
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
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
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
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
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                        break;
                    }
                else {
                    cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                    system("pause");
                    return "";
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
                            else {
                                cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                                system("pause");
                                return "";
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
                            else {
                                cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                                system("pause");
                                return "";
                            }
                            break;
                        default:
                            if (day >= 1 && day <= 31) {
                                finalCheck = true;
                                return date;
                            }
                            else {
                                cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                                system("pause");
                                return "";
                            }
                            break;
                        }
                    }
                    else {
                        cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                        system("pause");
                        return "";
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
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                    }
                }
                else {
                    cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                    system("pause");
                    return "";
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
                    system("pause");
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
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                        else {
                            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                            system("pause");
                            return "";
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
                    system("pause");
                    return "";
                }
            }
            else {
                cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
                system("pause");
                return "";
            }
        }
        else {
            cout << "��¥�� �ùٸ��� �Է��ϼ���." << endl;
            system("pause");
            return "";
        }
    }
}


void KICManager::init()
{
    /*������ �ʿ��� ģ������ �����η� ����Ͻð� �ؿ� �ڵ�� �ּ�ó�� ���ּ���.*/
     fstream fin("defaultprodsinfo.txt");
   //fstream fin("C:\\Users\\������\\Source\\Repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\source.txt");

    if (!fin.is_open()) {
        cerr << "���� �б� ����\n";
        exit(0);
    }

    string date, result;

    while (true) {
        cout << "���� ��¥ �Է� : ";
        getline(cin, date);
        result = checkDate(date);

        if (finalCheck == true) {
            todayDate = result;
            break;
        }
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
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            int stock, salesVolume, expDate, wPrice, rPrice;
            fin >> stock >> salesVolume >> expDate >> wPrice >> rPrice;
            this->product[i] = new KICProduct(str, stock, salesVolume, expDate, wPrice, rPrice);
            getline(fin, buffer);
        }
        for (int i = 0; i < count; i++) {
            this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
        }
    }

   

    printMenu();
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
    // �޴� �Է� ����ó��
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  ���� �ڻ� : " << property << "��  " << endl;
        cout << "=================================================" << endl;
        cout << "------------- �ء������� �˸��ء� -------------" << endl;
        noStockAlarm();
        cout << "-------------------- <�޴�> ---------------------" << endl;
        cout << " 1) ��ǰ �ֹ� " << endl;
        cout << " 2) ��ǰ �˻� " << endl;
        cout << " 3) �ǸŰ� ���� " << endl;
        cout << " 4) ��ǰ �߰�/���� " << endl;
        cout << " 5) ���� ���� " << endl;
        cout << " 6) ���α׷� ���� " << endl;
        cout << "=================================================" << endl;
        cout << "�޴��� �����ϼ��� : ";
        getline(cin, menu);
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();

        else if (menu == "3") {
            while (true) {
                system("cls");
                cout << "---------------------------------------- < �޴� > ----------------------------------------" << endl;
                cout << " 1) ���� ��ǰ ���� " << endl;
                cout << " 2) ������ ���� " << endl;
                cout << "===========================================================================================" << endl;
                cout << "�޴��� �����ϼ��� (q : �޴� ����) : ";
                string subMenu;
                getline(cin, subMenu);
                if (subMenu == "1") {
                    selectDiscountProds();
                    break;
                }
                else if (subMenu == "2") {
                    selectMarginRate();
                    break;
                }
                else if (subMenu == "q")
                    break;
                else {
                    cout << "�ùٸ� ���ڸ� �Է��ϼ���." << endl;
                    system("pause");
                    continue;
                }
                break;
            }
        }
        else if (menu == "4") {
            while (true) {
                system("cls");
                cout << "---------------------------------------- < �޴� > ----------------------------------------" << endl;
                cout << " 1) ��ǰ �߰� " << endl;
                cout << " 2) ��ǰ ���� " << endl;
                cout << "===========================================================================================" << endl;
                cout << "�޴��� �����ϼ��� (q : �޴� ����) : ";
                string subMenu;
                getline(cin, subMenu);
                if (subMenu == "1") {
                    addlist();
                    break;
                }
                else if (subMenu == "2") {
                    removelist();
                    break;
                }
                else if (subMenu == "q")
                    break;
                else {
                    cout << "�ùٸ� ���ڸ� �Է��ϼ���." << endl;
                    system("pause");
                    continue;
                }
                break;
            }
        }
        else if (menu == "5") {
            closingWork();
        }
        else if (menu == "6") {
            cout << "���α׷��� �����մϴ�.\n" << endl;
            exit(0);
        }
        else {
            cout << "�ùٸ� ���ڸ� �Է��ϼ���." << endl;
            system("pause");
        }
    }
}


/*void KICManager::noStockAlarm()
{
   // ��� <= ���� �Ǹŷ��� �� �˶� ���
   bool check = false;
   int total = 0;
   int productNum = 0;


   //bool isRemove = false; //������ ��ǰ���� check
   for (int i = 0; i < count; i++) {
      bool print = true;
      int dcheck = 0;
      if (product[i]->getStock() < 0) {
         total = 0;

      }
      else
         total = product[i]->getStock();

      for (int j = 0; j < count; j++) {
         if (product[i]->getName().compare(product[j]->getName()) == 0) {
            if (product[i]->getExpDate() > product[j]->getExpDate()) {
               print = false;
            }
            if (i != j) {
               total += product[j]->getStock();
               dcheck++;
            }
            productNum = j;
         }
      }

      if (print) {
         if (total <= product[i]->getSalesVolume() && productNum == i) {
            check = true;
            cout << product[i]->getName() << " : ��� " << total << "��" << endl;
         }
      }
   }

   if (!check) {
      cout << "��� ������ ��ǰ ����" << endl;
   }
}
*/    // �������� �� ��ǰ ���� �ݿ��ɼ��ֵ��� �����߾�� Ȥ�� ���� �̷������� �ϸ�ȵȴ� ���� �˷��ּ���


void KICManager::noStockAlarm()
{
    // ��� <= ���� �Ǹŷ��� �� �˶� ���
    bool check = false;
    int total = 0;
    int productNum = 0;
    for (int i = 0; i < count; i++) {
        *sortprod[i] = *product[i];
    }

    for (int i = 0; i < count; i++) {
        bool print = true;
        int dcheck = 0;

        int total = product[i]->getStock();


        for (int j = 0; j < count; j++) {
            if (product[i]->getName().compare(product[j]->getName()) == 0) {
                if (product[i]->getExpDate() > product[j]->getExpDate()) {
                    print = false;
                }
                if (i != j) { // ���� �̸��� �ٸ� ������� ������ �� ���� ���ؼ� �ݿ�
                    total += product[j]->getStock();
                    dcheck++;
                }
                productNum = j;
            }
        }

        if (print) {
            if (0 <= total && total <= product[i]->getSalesVolume() && productNum == i) { // ������ ��ǰ�� ��� -1�̹Ƿ� �����ϴ� ��ǰ �� ��� ���� �Ǹŷ����� ���� ��� �˸�
                check = true;
                cout << product[i]->getName() << " : ��� " << total << "��" << endl;
            }
        }
    }

    if (!check) {
        cout << "��� ������ ��ǰ ����" << endl;
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


bool KICManager::loadInfor() {
    /*������ �ʿ��� ģ������ �����η� ����Ͻð� �ؿ� �ڵ�� �ּ�ó�� ���ּ���.*/
    // ���Ƿ� �ص� ������ 
    fstream fin("C:\\Users\\samsung\\source\\repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\test.txt");

    if (!fin.is_open()) {
        cerr << "���� �б� ����\n";
        exit(0);
    }

    while (!fin.eof()) {

        string buffer;
        fin >> this->count;
        getline(fin, buffer);

        if (buffer.empty()) {

            return false;

        }

        if (count > 0) {
            product = new KICProduct * [100];
            sortprod = new KICProduct * [100]; //�������� �߰�
        }

        for (int i = 0; i < count; i++) {
            string str;
            getline(fin, str);
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            int stock, salesVolume, expDate, wPrice, rPrice;
            fin >> stock >> salesVolume >> expDate >> wPrice >> rPrice;
            this->product[i] = new KICProduct(str, stock, salesVolume, expDate, wPrice, rPrice);
            getline(fin, buffer);
        }
        for (int i = 0; i < count; i++) {
            this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
        }
    }

    return true;
}


void KICManager::addOrder()
{

    while (true) {
        system("cls");
        cout << " ���� �ܾ� : " << property << "��" << endl;

        /* �ֹ��� ���� ���� �ܾ� ���  */
        cout << "*****************************************************�ֹ� ǰ��â*****************************************************" << endl;
        sortAl();
        cout << "********************************************************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

        /*�ֹ� ȭ�� ���*/
        string namePro = "";
        int numPro = 0;
        // string numPro="";
        int price = 0;
        int tmp = 0; //�ݺ��� Ż�� ���� ����
        int productnum = -1; //�ֹ��� ������ �ε�����ȣ

        cout << "�ֹ��� ��ǰ���� ���� ���� �Է� (q : �޴� ����) : ";
        //  cin.ignore();
        getline(cin, namePro);

        /*q������ ����*/
        if (namePro.compare("q") == 0) {
            return;
        }

        /*�ֹ� ��ǰ �˻�, ���� ���*/
        for (int i = 0; i < count; i++) {
            if (((product[i]->getName().compare(namePro)) == 0)) {
                productnum = i;
                break;
            }
        }

        if (productnum == -1) {
            cout << "�߸��� ��ǰ���Դϴ�. �ٽ� �Է��ϼ���." << endl;
            system("pause");
            continue;
        }

        cout << endl;
        for (int i = 0; i < count; i++) {
            if (((product[i]->getName().compare(namePro)) == 0) && product[i]->getStock() >= 0) {
                cout << setw(15) << product[i]->getName() << setw(15) << product[i]->getStock() << setw(15) << product[i]->getSalesVolume() << setw(15) << product[i]->getExpDate() << setw(15) << product[i]->getWPrice() << setw(15) << product[i]->getRPrice() << setw(15) << product[i]->getDiscount() << setw(15) << product[i]->getDisDate() << endl;
            }
        }
        cout << endl;
        cout << "�ֹ��� ��ǰ ������ ���� ���� �Է� : ";
        cin >> numPro;
        string buffer;
        getline(cin, buffer);

        while (true) {
            if (numPro < 0) {
                cout << "0���� ū ���� �Է��ϼ���" << endl;
                system("pause");
                break;
            }
            if (numPro > 214748) {
                cout << "�ٽ� �Է��ϼ���" << endl;
                system("pause");
                cin.clear();
                getline(cin, buffer);
                break;
            }
            if (cin.fail()) {
                cout << "�ٽ� �Է��ϼ���" << endl;
                buffer = "";
                system("pause");
                numPro = 0;
                cin.clear();
                getline(cin, buffer);
                break;
            }

            price = product[productnum]->getWPrice() * numPro; //�����ݾ�_�ʹ� �� price�� �߽��ϴ�
            if (property < price) {
                cout << "���� �ݾ��� �����մϴ�." << endl;
                system("pause");
                break;
            }
            cout << "-----------------------------------" << endl;
            cout << "�����ݾ� " << product[productnum]->getWPrice() * numPro << "��, " << " �����ݾ� " << property << "��\n" << "�ֹ��Ͻðڽ��ϱ�(q:�޴� ����)? (y/n) ";
            string yn;
            getline(cin, yn);

            if (yn.compare("y") == 0) {

                /*�ֹ� ����*/
                int k = 0; //�ֹ� Ƚ��
                for (int i = 0; i < count; i++) {
                    if (product[i]->getName().compare(namePro) == 0 && product[i]->getStock() != 0)
                        k++;
                }
                /*3�� �̻� �ֹ�X*/
                if (k >= 3) {
                    cout << "�ش� ��ǰ�� �� �̻� �ֹ��� �� �����ϴ�." << endl;
                    system("pause");
                    break;
                }

                int p = 0; // ������ǰ, ���� ����������� check

                /*���� ��ǰ, ���� ��������̸� ��ġ��*/
                for (int i = 0; i < count; i++) {
                    if (product[i]->getName().compare(namePro) == 0 && product[i]->getExpDate() == product[i]->getFixedExpDate())
                    {
                        product[i]->setStock(product[i]->getStock() + numPro);
                        sortprod[i]->setStock(product[i]->getStock() + numPro);

                        p = 1;
                        break;
                    }
                }

                property -= price;
                if (p == 0) {
                    count++;
                    /*product, sortprod �ֹ� ���� �߰�*/
                    this->product[count - 1] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice(), product[productnum]->getDiscount(), product[productnum]->getDisDate());
                    this->sortprod[count - 1] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice(), product[productnum]->getDiscount(), product[productnum]->getDisDate());

                    for (int i = 0; i < count; i++) {
                        if (product[i]->getName().compare(namePro) == 0) {
                            if (product[i]->getStock() == 0) {
                                product[i]->setStock(-1);
                                sortprod[i]->setStock(-1);
                            }
                        }
                    }

                }
                cout << "�ֹ��� �Ϸ�Ǿ����ϴ�." << endl;
                cout << "-----------------------------------" << endl;
                /*if(p ==0)
                   cout << setw(15) << product[productnum]->getName() << setw(15) << product[productnum]->getStock() << setw(15) << product[productnum]->getSalesVolume() << setw(15) << product[productnum]->getExpDate() << setw(15) << product[productnum]->getWPrice() << setw(15) << product[productnum]->getRPrice() << setw(15) << product[productnum]->getDiscount() << setw(15) << product[productnum]->getDisDate() << endl;
                else if(p==1)
                   cout << setw(15) << product[count - 1]->getName() << setw(15) << product[count - 1]->getStock() << setw(15) << product[productnum]->getSalesVolume() << setw(15) << product[productnum]->getExpDate() << setw(15) << product[productnum]->getWPrice() << setw(15) << product[productnum]->getRPrice() << setw(15) << product[productnum]->getDiscount() << setw(15) << product[productnum]->getDisDate() << endl;*/

                cout << "�����ݾ� : " << price << ", �����ݾ� : " << property << endl;
                cout << "-----------------------------------" << endl;
                system("pause");
                break;
            }
            else if (yn.compare("n") == 0) {
                cout << "�ֹ��� ��ҵǾ����ϴ�. " << endl;
                system("pause");
                break;
            }
            else if (yn.compare("q") == 0) {
                return;
            }
            else {
                cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
                system("pause");
                break;
            }
        }
        cout << "break" << endl;
    }
}


void KICManager::searchProds()
{
    cout.setf(ios::left);
    while (true) {
        system("cls");
        cout << "================================================== < ��ǰ �˻� > ====================================================" << endl;
        cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�����Ǹŷ�" << setw(15) << "�������" << setw(15) << "���Ű�" << setw(15) << "�ǸŰ�" << setw(15) << "������" << setw(15) << "���γ����Ⱓ" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
        // �˻� �ʱ�ȭ���� ������ �� ���
        for (int i = 0; i < count; i++) {
            *sortprod[i] = *product[i];
        }

        KICProduct temp_ = *sortprod[0];

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if ((sortprod[i]->getName().compare(sortprod[j]->getName())) > 0) {
                    temp_ = *sortprod[i];
                    *sortprod[i] = *sortprod[j];
                    *sortprod[j] = temp_;
                }
            }
        }


        for (int i = 0; i < count; i++) {
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // ��� 0�ΰų� ������� 0���̸� ��¾���
                cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getWPrice() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getDiscount() << setw(15) << sortprod[i]->getDisDate() << endl;
            }
        }

        cout << endl;

        string namePro;
        cout << endl;
        cout << endl;
        cout << "�˻��� ��ǰ �̸��� ���� ���� �Է� (q : �޴� ����) : ";
        getline(cin, namePro);
        cout << endl;

        /*q������ ����*/
        if (namePro.compare("q") == 0) {
            // cout << "����" << endl;
            printMenu();
        }

        // �˻� ��� ����� ������� ª�� ������ ����
        KICProduct temp = *sortprod[0];
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (sortprod[i]->getName() == sortprod[j]->getName()) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        temp = *sortprod[i];
                        *sortprod[i] = *sortprod[j];
                        *sortprod[j] = temp;
                    }
                }
            }
        }

        int status = -1;

        for (int j = 0; j < count; j++) {
            if (sortprod[j]->getExpDate() != 0 || sortprod[j]->getStock() > 0) { // ������� 0�̰ų� ��� 0�̰ų� ������ ��ǰ�� ��¾���
                if ((sortprod[j]->getName()).find(namePro) != string::npos) {
                    status = 0;
                    break;
                }
            }
        }

        if (namePro[0] == ' ' || namePro.empty()) {
            cout << "���� ����� ���Է��� �Ұ����մϴ�. �ٽ� �Է��ϼ���." << endl;
            system("pause");
        }

        else if (namePro.find('~') != string::npos || namePro.find('!') != string::npos || namePro.find('@') != string::npos || namePro.find('#') != string::npos || namePro.find('$') != string::npos || namePro.find('%') != string::npos || namePro.find('^') != string::npos ||
            namePro.find('&') != string::npos || namePro.find('*') != string::npos || namePro.find('(') != string::npos || namePro.find(')') != string::npos || namePro.find('-') != string::npos || namePro.find('+') != string::npos || namePro.find('_') != string::npos ||
            namePro.find('=') != string::npos || namePro.find(':') != string::npos || namePro.find(';') != string::npos || namePro.find('"') != string::npos || namePro.find(',') != string::npos || namePro.find('<') != string::npos || namePro.find('>') != string::npos ||
            namePro.find('?') != string::npos || namePro.find('/') != string::npos || namePro.find('`') != string::npos || namePro.find('.') != string::npos || namePro.find('\'') != string::npos)
        {
            cout << "Ư������ �Է��� �Ұ����մϴ�. �ٽ� �Է��ϼ���." << endl;
            system("pause");
        }

        else if (status != 0) { // ��Ÿ �� ��ȹ���� ����� ���� ����� ��� else�� ó��
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
            system("pause");
        }
        else if (status == 0) {
            cout << "=========================================== " << namePro << " �� �˻� ���" << " ============================================\n" << endl;
            cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�����Ǹŷ�" << setw(15) << "�������" << setw(15) << "���Ű�" << setw(15) << "�ǸŰ�" << setw(15) << "������" << setw(15) << "���γ����Ⱓ" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < count; j++) {

                if ((sortprod[j]->getName()).find(namePro) != string::npos) {
                    cout << setw(15) << sortprod[j]->getName() << setw(15) << sortprod[j]->getStock() << setw(15) << sortprod[j]->getSalesVolume() << setw(15) << sortprod[j]->getExpDate() << setw(15) << sortprod[j]->getWPrice() << setw(15) << sortprod[j]->getRPrice() << setw(15) << sortprod[j]->getDiscount() << setw(15) << sortprod[j]->getDisDate() << endl;
                }
            }
            cout << endl;
            system("pause");
        }
    }
}


void KICManager::sortDate()
{
    //������� �ӹڼ� ����

    /*for (int i = 0; i < count; i++) {
       this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }*/

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // ��� 0�ΰų� ������� 0���̸� ��¾���
                if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                    temp = *sortprod[i];
                    *sortprod[i] = *sortprod[j];
                    *sortprod[j] = temp;
                }
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
    for (int i = 0; i < count; i++) {
        *sortprod[i] = *product[i];
    }

    KICProduct temp = *sortprod[0];

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((sortprod[i]->getName().compare(sortprod[j]->getName())) >= 0) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }

    cout.setf(ios::left);
    cout << setw(15) << "��ǰ��" << setw(10) << "�����" << setw(15) << "�����������" << setw(10) << "�����" << setw(15) << "�����Ǹŷ�" << setw(15) << "���Ű�" << setw(15) << "�ǸŰ�" << setw(8) << "������" << setw(8) << "���γ����Ⱓ" << endl;
    //  cout << " ��ǰ�� " << " ��� " << " ���� �Ǹŷ� " << " ������� " << " ���Ű� " << " �ǸŰ� " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    /*addOrder ǰ��â���� �����Ǹŷ�*3 �̻��ΰ��� ���X*/
    /*������� 0�ΰ͵� ���X*/
    int k = 0;
    /*for (int i = 0; i < count; i++) {
       if (sortprod[i]->getExpDate() != 0 || sortprod[i]->getStock() != 0) { // ��� 0�ΰų� ������� 0���̸� ��¾���
          if (sortprod[i]->getStock() <= sortprod[i]->getSalesVolume() * 3) {
             cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getWPrice() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getDiscount() << setw(15) << sortprod[i]->getDisDate() << endl;
             // cout << *sortprod[i] << endl;
          }
       }
    }*/

    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getExpDate() != 0 || sortprod[i]->getStock() >= 0) {
            bool print = true;
            int total = sortprod[i]->getStock();
            for (int j = 0; j < count; j++) {
                if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        print = false;
                    }
                    if (i != j) {
                        total += sortprod[j]->getStock();
                    }
                }
            }
            if (print) {
                if (sortprod[i]->getStock() >= 0) {
                    if (total < sortprod[i]->getSalesVolume() * sortprod[i]->getExpDate()) {
                        cout << setw(15) << sortprod[i]->getName() << setw(10) << total << setw(15) << sortprod[i]->getExpDate() << setw(10) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getWPrice() << setw(15) << sortprod[i]->getRPrice() << setw(8) << sortprod[i]->getDiscount() << setw(8) << sortprod[i]->getDisDate() << endl;
                        // cout << *sortprod[i] << endl;
                    }
                }
            }
        }
    }

    cout << endl;
}


void KICManager::sortStock()
{
    //��� ������ ����

    int t = 0;

    for (int i = 0; i < count; i++) {
        *sortprod[i] = *product[i];
    }
    cout << typeid(product[3]->getName()).name() << endl;
    char str = 'd';
    char str1 = 'e';

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // ��� 0�ΰų� ������� 0���̸� ��¾���
                if (sortprod[i]->getStock() > sortprod[j]->getStock()) {
                    temp = *sortprod[i];
                    *sortprod[i] = *sortprod[j];
                    *sortprod[j] = temp;
                }
            }
        }
    }

    for (int i = 0; i < count; i++) {
        cout << *sortprod[i] << endl;
    }

}

/* ���� ���� ���� ��ǰ ��� �Լ�*/
void KICManager::discountProds() // ���� ���� ���� ��ǰ ���
{
    cout.setf(ios::left);
    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getDiscount() != 0) {
                if (sortprod[i]->getDiscount() < sortprod[j]->getDiscount()) {
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
    cout << endl;
    cout << "���� discount �ϴ� ��ǰ�� : " << endl;
    cout << endl;
    cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "�����ǸŰ�" << setw(15) << "�����ǸŰ�" << setw(15) << "���γ����Ⱓ" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0 && sortprod[i]->getStock() != 0) {
            cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getRPrice() * 100 / (100 - sortprod[i]->getDiscount()) << setw(15) << sortprod[i]->getDisDate() << endl;
            check = true;
        }
    }//discount �ϴ� �͵� sorted �ȴ�� print
    if (!check) {
        cout << "���� discount�ϴ� ��ǰ ����" << endl;
        cout << endl;
    }

} // ���� �������� ��ǰ�� ����ϴ� �Լ� // ���� �������� ��ǰ�� ����ϴ� �Լ�

/* ���� ���� �ʿ�(����) ��ǰ ��� �Լ�*/
void KICManager::discountReqProds() 
{
    cout.setf(ios::left);
    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getStock() - (sortprod[i]->getSalesVolume() * (sortprod[i]->getExpDate() + 1)) < sortprod[j]->getStock() - (sortprod[j]->getSalesVolume() * (sortprod[j]->getExpDate() + 1))) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    } //  (������ǰ, ������� �ٸ��� => �ٸ���ǰ ��� : ���� ��� �� / ���� �Ǹŷ� ������ ����)
    cout << endl;
    cout << "���� discount ������ ��ǰ�� : " << endl;
    cout << endl;
    cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�����Ǹŷ�" << setw(15) << "�������" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    bool check = false;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() - (sortprod[i]->getSalesVolume() * (sortprod[i]->getExpDate() + 1)) > 0 && sortprod[i]->getStock() != 0 && sortprod[i]->getDiscount() == 0) {
            bool accept = true;
            for (int j = 0; j < count; j++) {
                if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        accept = false;
                        break;
                    } // expDate�� ���� ��ǰ �󿡼� ���� �ֽŲ����� Ȯ��
                }
            }
            if (accept) {
                cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << endl;
                check = true;
            }
        }
    } // ���� ��� �� >= ���� �Ǹŷ� *3 �� ��ǰ�� sorted �ȴ�� ���
    if (!check) {
        cout << "���� ���� ������ ��ǰ ����" << endl;
        cout << endl;
    }
}

/* ���� ��ǰ ���� �� ������ ���� �Լ�*/
void KICManager::selectDiscountProds()
{
    cout.setf(ios::left);
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
        cout << "===========================================================================================" << endl;
        discountProds();
        cout << "===========================================================================================" << endl;
        discountReqProds();
        cout << "===========================================================================================" << endl;
        cout << "���� �� ��ǰ���� �Է��ϼ��� (q : �޴� ����) : ";
        string select;
        getline(cin, select);
        if (select.compare("q") == 0) {
            break;
        }
        int status = -1;
        for (int i = 0; i < count; i++) {
            if (select.compare(product[i]->getName()) == 0 && status == -1) {
                if (product[i]->getStock() != 0) {
                    if (product[i]->getDiscount() != 0) {
                        status = 0;
                        break;
                    }
                    else {
                        if ((product[i]->getStock() - (product[i]->getSalesVolume() * (product[i]->getExpDate() + 1))) > 0) {
                            status = 2;
                            break;
                        }
                        else {
                            status = 1;
                            break;
                        }
                    }
                }
            }
        }
        // ��������� ���� ������ product�� ���ĵǾ����� ���ɼ��� ũ��. ���� �׷��� ������ �տ� ���� �Լ� �߰�

        if (status == -1) {
            cout << "�׷��� ��ǰ���� �����ϴ�." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 0) {
            cout << "�̹� ���� ���� ��ǰ�Դϴ�." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 1) {
            cout << "�����Ͻ� ��ǰ���� ������ �� �ִ� ��ǰ�� �ƴմϴ�." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 2) {
            bool check = false;
            while (true) {
                string buffer;
                int percentage;
                cout << "������ %�� �Է����ּ��� (10 ����) (10 �̻� 90 ����) (q : �޴� ����)  : ";
                cin >> percentage;
                if (cin.fail()) {
                    system("pause");
                    cin.clear();
                    getline(cin, buffer);
                    if (buffer.compare("q") == 0) {
                        check = true;
                        break;
                    }
                    else {
                        cout << "�ٽ� �Է��ϼ���" << endl;
                    }
                    cout << buffer << endl;
                    break;
                }
				
                if (percentage < 10 || percentage > 90) {
                    cout << "������ �˸��� �ʽ��ϴ�." << endl;
                    continue;
                }
                else if (percentage % 10 != 0) {
                    cout << "10 ������ �Է��ؾ� �մϴ�." << endl;
                    continue;
                }
                else {
                    for (int i = 0; i < count; i++) {
                        if (select.compare(product[i]->getName()) == 0 && product[i]->getStock() != 0) {
                            product[i]->setDiscount(percentage);
                            product[i]->setDisDate(3);
                            int newPrice = product[i]->getRPrice() * (100 - percentage) / 100;
                            product[i]->setRPrice(newPrice);
                            int newSalesVolume = product[i]->getSalesVolume() * (100 + percentage) / 100;
                            product[i]->setSalesVolume(newSalesVolume);
                            cout << "������ ���� ������ ����Ǿ����ϴ�." << endl;
                            cout << endl;
                            cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "�����ǸŰ�" << setw(15) << "�����ǸŰ�" << setw(15) << "���γ����Ⱓ" << endl;
                            cout << "-------------------------------------------------------------------------------------------" << endl;
                            cout << setw(15) << product[i]->getName() << setw(15) << product[i]->getStock() << setw(15) << product[i]->getExpDate() << setw(15) << product[i]->getRPrice() << setw(15) << product[i]->getRPrice() * 100 / (100 - product[i]->getDiscount()) << setw(15) << product[i]->getDisDate() << endl;
                            system("pause");
                        }
                    }
                    for (int i = 0; i < count; i++) {
                        *sortprod[i] = *product[i];
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

/* ������ ���� �Լ� */
void KICManager::selectMarginRate()
{
    int tempRPrice = 0;
    int tempWPrice = 0;
    int margin = 0;
    double marginRate; // ������
    while (true) { // �ùٸ� ���� �������� �Է��Ҷ����� ���ѷ���
        for (int i = 0; i < count; i++) {
            if (product[i]->getDiscount() == 0 && product[i]->getStock() != 0) {
                tempRPrice = product[i]->getRPrice();
                tempWPrice = product[i]->getWPrice();
            }
        }
        margin = tempRPrice - tempWPrice;
        marginRate = (double)margin / (double)tempRPrice;

        while (true) {
            system("cls");
            cout << "���� ������: " << (int)(marginRate * 100) << "%" << endl;
            int temp;
            string buffer;
            cout << "������ �������� �Է��ϼ���(10% ������ ���ڸ� �Է°���) : ";
            cin >> temp;
            getline(cin, buffer);

            if (cin.fail()) {
                cin.clear();
                getline(cin, buffer);
                if (buffer.compare("q") == 0) {
                    break;
                }
                else {
                    cout << "���ڸ� �Է����ּ���." << endl;
                    system("pause");
                }
            }
            else if (temp % 10 != 0) {
                cout << "�������� 10% ������ 10%~90%���� ���� �����մϴ�. �ٽ� �Է����ּ���." << endl;
                system("pause");
            } 
            else if (temp % 10 == 0) {
                if (10 <= temp && temp <= 90) {
                    marginRate = (double)temp / (double)100;
                    cout << "�������� " << (int)(marginRate * 100) << "%�� ����Ǿ����ϴ�." << endl;
                    system("pause");
                    break;
                }
                else {
                    cout << "�������� 10% ������ 10%~90%���� ���� �����մϴ�. �ٽ� �Է����ּ���." << endl;
                    system("pause");
                }
            }
        }
        break;
    }
    for (int i = 0; i < count; i++) {
        if (product[i]->getDiscount() == 0 && product[i]->getStock() != 0) { // ������ �����ʴ� ��ǰ�� ���
            double changedRP = (double)product[i]->getWPrice() / (1.0 - marginRate); //  ����� ������ �ٷ� ����
            product[i]->setRPrice((int)changedRP);
        }
        else if (product[i]->getDiscount() != 0 && product[i]->getStock() != 0) { // ���� �������� ��ǰ�� ���
            double originRP = (double)product[i]->getWPrice() / (1.0 - marginRate); // ���� ���� �ǸŰ��� ������ ����
            double dcAppliedRP = originRP * ((100.0 - (double)product[i]->getDiscount()) / 100.0); // originRP�� �ٽ� ������ ����
            product[i]->setRPrice((int)dcAppliedRP);
        }
        // ��� 0�� product�� �̹� �� �ȸ� ģ�����̹Ƿ� �ƹ��͵� ���� �ʿ䰡 ����.  
    }
}

/* ��ǰ ���� �߰� �Լ� */
void KICManager::addlist()
{
    fstream fin("defualtaddlist.txt");
    if (!fin.is_open()) {
        cerr << "���� �б� ����\n";
        exit(0);
    }

    KICProduct** addList = nullptr;
    int cnt = 0;
    while (!fin.eof()) {

        string buffer;
        fin >> cnt;
        getline(fin, buffer);

        if (cnt > 0) {
            addList = new KICProduct * [100];
        }

        for (int i = 0; i < cnt; i++) {
            string str;
            getline(fin, str);
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            int stock, salesVolume, expDate, wPrice, rPrice;
            fin >> stock >> salesVolume >> expDate >> wPrice >> rPrice;
            addList[i] = new KICProduct(str, stock, salesVolume, expDate, wPrice, rPrice);
            getline(fin, buffer);
        }
    }
    fin.close();
    ofstream out("changedaddlist.txt");

    system("cls");
    cout << "================================================== < ��ǰ �˻� > ====================================================" << endl;
    cout << setw(15) << "��ǰ��" << setw(15) << "���" << setw(15) << "�����Ǹŷ�" << setw(15) << "�������" << setw(15) << "���Ű�" << setw(15) << "�ǸŰ�" << setw(15) << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << setw(15) << addList[i]->getName() << setw(15) << addList[i]->getStock() << setw(15) << addList[i]->getSalesVolume() << setw(15) << addList[i]->getExpDate() << setw(15) << addList[i]->getWPrice() << setw(15) << addList[i]->getRPrice() << endl;
    }

    while (true) {

        cout << "�߰��� ��ǰ���� �Է��ϼ��� : ";
        string prodsName;
        getline(cin, prodsName);

        if (prodsName.compare("q") == 0) {
            break;
        }

        bool existProds = false;
        int price = 0;
        int flag = 0;
        for (int i = 0; i < cnt; i++) {
            if (prodsName.compare(addList[i]->getName()) == 0) {
                existProds = true;
                flag = i;
            }
        }

        if (existProds == true) {
            while (true) {
                int numOfPro;
                string buffer;
                system("cls");
                cout << "�ֹ��� ��ǰ ������ ���� ���� �Է� : ";
                cin >> numOfPro;
                getline(cin, buffer);

                if (cin.fail()) {
                    cin.clear();
                    getline(cin, buffer);
                    if (buffer.compare("q") == 0) {
                        for (int i = 0; i < cnt; i++) {
                            delete addList[i];
                        }
                        delete[] addList;
                        break;
                    }
                    else {
                        cout << "���ڸ� �Է����ּ���." << endl;
                        system("pause");
                    }
                }

                if (numOfPro <= 0) {
                    cout << "0���� ū ���ڸ� �Է����ּ���." << endl;
                }
                else {
                    price = addList[flag]->getWPrice() * numOfPro;
                    if (property < price) {
                        cout << "���� �ݾ��� �����մϴ�." << endl;
                        system("pause");
                    }
                    else {
                        cout << "-----------------------------------" << endl;
                        cout << "�����ݾ� " << addList[flag]->getWPrice() * numOfPro << "��, " << "�����ݾ� " << property << "��\n" << "�ֹ��Ͻðڽ��ϱ�(q:�޴� ����)? (y/n) ";
                        string yn;
                        getline(cin, yn);

                        if (yn.compare("q") == 0) {
                            for (int i = 0; i < cnt; i++) {
                                delete addList[i];
                            }
                            delete[] addList;
                            return;
                        }
                        else if (yn.compare("y") == 0) {
                            this->product[count] = new KICProduct(addList[flag]->getName(), numOfPro, addList[flag]->getSalesVolume(), addList[flag]->getExpDate(), addList[flag]->getWPrice(), addList[flag]->getRPrice());
                            this->sortprod[count] = new KICProduct(addList[flag]->getName(), numOfPro, addList[flag]->getSalesVolume(), addList[flag]->getExpDate(), addList[flag]->getWPrice(), addList[flag]->getRPrice());
                            cout << addList[flag]->getName() << " " << numOfPro << "�� �ֹ� �Ϸ�Ǿ����ϴ�." << endl;
                            count++;
                            int temp = cnt - 1;
                            out << temp << endl;
                            for (int i = 0; i < cnt; i++) {
                                if (flag != i) {
                                    if (i == temp) {
                                        out << *addList[i];
                                    }
                                    else {
                                        out << *addList[i] << endl;
                                    }
                                }
                            }
                            for (int i = 0; i < cnt; i++) {
                                delete addList[i];
                            }
                            delete[] addList;
                            system("pause");
                            return;
                        }
                        else if (yn.compare("n") == 0) {
                            break;
                        }
                        else {
                            cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
                            system("pause");
                            continue;
                        }
                    }
                }
            }

        }
        else {
            cout << "�ش� ��ǰ�� �߰� ���� ����Ʈ�� �������� �ʽ��ϴ�." << endl;
        }
    }
}

/* ��ǰ ���� ���� �Լ� */
void KICManager::removelist()
{

    fstream fin("changedaddlist.txt");
    if (!fin.is_open()) {
        cerr << "���� �б� ����\n";
        return;
    }

    string buffer;
    while (!fin.eof()) {
        //fin >> this->count;
        getline(fin, buffer);

        //cout << buffer << endl;
    }
    fin.close();

    ofstream out("changedaddlist.txt", ios::app);

    for (int i = 0; i < count; i++) {
        *sortprod[i] = *product[i];
    }

    while (true) {
        bool isZero = false;
        for (int i = 0; i < count; i++) { //����� 0�ΰ� �˻� & ���
            int total = -1;
            if (sortprod[i]->getStock() == 0) {
                isZero = true;
                total = 0;
                for (int j = i + 1; j < count; j++) {
                    if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                        total += sortprod[j]->getStock();
                    }
                }
            }
            if (total == 0 && isZero == true) {
                cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getWPrice() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getDiscount() << setw(15) << sortprod[i]->getDisDate() << endl;
            }
        }
        cout << "������ ��ǰ���� �Է��ϼ��� : ";
        string removeproduct;
        getline(cin, removeproduct);
        int flag = 1; //��� 0�� ��ǰ����

        if (removeproduct.compare("q") == 0) {
            cout << "q" << endl;
            break;
        }

        for (int i = 0; i < count; i++) {
            int total = 0;
            if (sortprod[i]->getName().compare(removeproduct) == 0) {
                if (sortprod[i]->getStock() == 0) {
                    for (int j = i + 1; j < count; j++) {
                        if (sortprod[j]->getName().compare(removeproduct))
                            total += sortprod[i]->getStock();
                    }

                }

                if (total == 0)
                    flag = 0;
                break;
            }
        }

        if (flag == 1) {
            cout << "��� 0�� ��ǰ�� �ƴմϴ�." << endl;
            system("pause");
			system("cls");
		}
		else {
			for (int i = 0; i < count; i++) {
				if (sortprod[i]->getStock() == 0 && ((sortprod[i]->getName().compare(removeproduct)) == 0)) {
					cout << "�����Ͻðڽ��ϱ�?(y/n) : ";
					string yn;
					getline(cin, yn);

					if (yn.compare("y") == 0) {
						string name = sortprod[i]->getName();
						out << *sortprod[i] << endl;

						sortprod[i]->setStock(-1);
						// product[i]->setStock(-1);

						cout << "�����Ǿ����ϴ�." << endl;
						*product[i] = *sortprod[i];
						cout << product[i]->getName() << "      " << product[i]->getStock() << endl;


						system("pause");
						return;
					}
					else if (yn.compare("n") == 0) {
						cout << "������ ��ҵǾ����ϴ�." << endl;
						system("pause");
						//return;
					}
					else {
						cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
						system("pause");
						//break;
					}
                }
            }
        }

        
    }
}

/* ���� ���� �Լ�*/
void KICManager::closingWork()
{

    for (int i = 0; i < count; i++) {
        *sortprod[i] = *product[i];
    }
    system("cls");
    printDate();

    bool isZero = false;

    for (int i = 0; i < count; i++) {
        int total = -1;
        if (sortprod[i]->getStock() == 0) {
            total = sortprod[i]->getStock();

            for (int j = i + 1; j < count; j++) { //0
                if (sortprod[j]->getStock() != -1) {

                    if (sortprod[j]->getName().compare(sortprod[i]->getName()) == 0 // && j != i 
                        ) {
                        total += sortprod[j]->getStock();

                    }
                }
            }
        }

        if (total == 0) { //����� 0
            isZero = true;
            cout << endl;
            cout << sortprod[i]->getStock() << endl;
            cout << sortprod[i]->getName() << endl;
        }
    }
    if (isZero == true) {
        cout << count << endl;
        cout << "�� ��� 0�� ��ǰ�� �����ϹǷ� ���� ������ �Ұ����մϴ�." << endl;
        system("pause");
        return;
    }
    else if (isZero == false) {
        cout << "������ �����մϴ�." << endl;
        deleteArray();
        randomSV(); // ��ǰ�� ���� �Ǹŷ� ����
        searchScrap();      // ���� ���� ��ǰ �ǸŰ� ���� �� ���� ���� ��¥ ����, ��� ��ǰ �Ǻ� �� ���� ������� ����
        setDate();
        cout << "������ �������� �Ѿ�ϴ�..." << endl;
        system("pause");
        system("cls");
    }
}


void KICManager::deleteArray()
{
    int cnt = 0;
    KICProduct** temp = new KICProduct * [100];
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() == 0 || product[i]->getStock() == -1) {
        }
        else {
            temp[cnt] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = cnt; i < count; i++) {
        delete product[i];
        delete sortprod[i];
    }
    for (int i = 0; i < cnt; i++) {
        *product[i] = *temp[i];
        *sortprod[i] = *temp[i];
    }
    count = cnt;
    for (int i = 0; i < cnt; i++) {
        delete temp[i];
    }
    delete[] temp;
}

/* ��� ��ǰ �Ǻ� �� ���, ���� ������� ���� �Լ�*/
void KICManager::searchScrap()
{
    financeCalculate(); // ���� �Ǹŵ� ��ǰ ��� ����, ���� ����, ������, ���� ���� �ڻ� ���

    /*���� ���� ��ǰ �ǸŰ� ���� �� ���� ���� ��¥ ����*/
    for (int i = 0; i < count; i++) {
        if (product[i]->getDisDate() <= 1 && product[i]->getStock() != 0) {
            double tempRP = (double)product[i]->getRPrice();
            double tempDis = (double)product[i]->getDiscount() / 100.0;
            product[i]->setRPrice((int)(tempRP * (1.0 + tempDis)));
            product[i]->setDiscount(0);
        }
        else if (product[i]->getDisDate() >= 2 && product[i]->getStock() != 0) {
            product[i]->setDisDate(product[i]->getDisDate() - 1);
        }
    }

    /*��� ��ǰ �Ǻ� �� ���� ������� ����*/
    int numOfScrapProds = 0;
    cout << "-----------------�ء���� �˸��ء�-----------------" << endl;
    for (int i = 0; i < count; i++) {
        if (product[i]->getExpDate() <= 1 && product[i]->getStock() > 0) { // ��������� 0���̰� ���� ��� 0�� �ƴ� ��ǰ�� ��� �������� �Ѵ�. // ��������ǰ�ǰ�� ��� -1�� �������⶧���� 0���� ū ���� ����
            numOfScrapProds++;
            cout << numOfScrapProds << ") " << product[i]->getName() << " " << product[i]->getStock() << "�� ���" << endl;
            product[i]->setExpDate(0);
            product[i]->setStock(0);
        }
        else if (product[i]->getExpDate() >= 2 && product[i]->getStock() != 0) { // ��������� ������� ���� ��ǰ�� ��� ��������� 1�� ���ҽ����ش�.
            product[i]->setExpDate(product[i]->getExpDate() - 1);
        }
    }
    if (numOfScrapProds == 0) {
        cout << "������ ���� ��ǰ�� �����ϴ�." << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

/* �Ǹŵ� ��ǰ ��� ����, ���� ����� ������ ��� �� ��� */
void KICManager::financeCalculate()
{
    int tempStock = 0;
    int tempSalesVolume; // ��ǰ�� ���� �Ǹŷ�
    int remainSV = 0;
    int tempWPrice = 0;
    int tempRPrice = 0;
    int todaySales = 0; // ���� ����� �հ�
    int todayProfits = 0; // ���� ������ �հ�
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() != 0 && product[i]->getExpDate() != 0) {
            tempStock = product[i]->getStock();
            tempSalesVolume = product[i]->getSalesVolume();
            tempWPrice = product[i]->getWPrice();
            tempRPrice = product[i]->getRPrice();

            if (tempStock < tempSalesVolume) { // ��ǰ�� �Ǹŷ��� ���� ��� ������ ���� ���
                string remainPN = product[i]->getName();
                todaySales = calTodaySales(todaySales, tempStock, tempRPrice);  // ��ǰ�� ���� ����� ��� �� �հ迡 �����ֱ�
                todayProfits = calTodayProfits(todayProfits, tempStock, tempRPrice, tempWPrice); // ��ǰ�� ���� ������ ��� �� �հ迡 �����ֱ�
                product[i]->setStock(0);
                product[i]->setExpDate(0);
                product[i]->setIsStockDeclined(true);
                remainSV = tempSalesVolume - tempStock; // ���� �Ǹŷ�

                for (int j = 0; j < count; j++) {
                    if (i != j) {
                        if (remainPN.compare(product[j]->getName()) == 0 && product[j]->getStock() > 0) { // 1��° ��� ���� ���� ��ǰ ��ü Ž�� 
                            if (product[j]->getStock() < remainSV) { // ��ǰ�� ���� ��� ������ remainSV�� ���� ���
                                todaySales = calTodaySales(todaySales, product[j]->getStock(), tempRPrice);
                                todayProfits = calTodayProfits(todayProfits, product[j]->getStock(), tempRPrice, tempWPrice);
                                remainSV = remainSV - product[j]->getStock();
                                product[j]->setStock(0);
                                product[j]->setExpDate(0);
                                product[j]->setIsStockDeclined(true);

                                for (int k = 0; k < count; k++) {   // 2��° ��� ���� ���� ��ǰ ��ü Ž��
                                    if (i != k && j != k) {
                                        if (remainPN.compare(product[k]->getName()) == 0 && product[k]->getStock() > 0) {
                                            if (product[k]->getStock() < remainSV) { // ��ǰ�� ���� ��� ������ remainSV�� ���� ���
                                                todaySales = calTodaySales(todaySales, product[k]->getStock(), tempRPrice);
                                                todayProfits = calTodayProfits(todayProfits, product[k]->getStock(), tempRPrice, tempWPrice);
                                                product[k]->setStock(0);
                                                product[k]->setExpDate(0);
                                                product[k]->setIsStockDeclined(true);
                                                /* ������ǰ�� �ִ� 3ȸ�� �ֹ� �����ϹǷ� ���⼭ �� */
                                            }
                                            else { // // ��ǰ�� ���� ��� ���� remainSV���� ���� ���
                                                todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                                todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                                product[k]->setStock(product[k]->getStock() - remainSV);
                                                product[k]->setIsStockDeclined(true);
                                            }
                                        }
                                    }
                                }
                            }
                            else { // ��ǰ�� ���� ������ remainSV���� ���� ���
                                todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                product[j]->setStock(product[j]->getStock() - remainSV);
                                product[j]->setIsStockDeclined(true);
                            }
                        }
                    }
                }
            }
            else { // ��ǰ�� ���� ��� ���� �Ǹŷ����� ���� ���
                if (product[i]->getIsStockDeclined() == false) {
                    todaySales = calTodaySales(todaySales, tempSalesVolume, tempRPrice); // ��ǰ�� ����� ��� �� �հ迡 �����ֱ�
                    todayProfits = calTodayProfits(todayProfits, tempSalesVolume, tempRPrice, tempWPrice); // ��ǰ�� ������ ��� �� �հ迡 �����ֱ�
                    product[i]->setStock(tempStock - tempSalesVolume);
                    product[i]->setIsStockDeclined(true);

                    string tempPN = product[i]->getName();
                    for (int j = 0; j < count; j++) {
                        if (i != j) {
                            if (tempPN.compare(product[j]->getName()) == 0 && product[j]->getIsStockDeclined() == false) {
                                /*if (product[i]->getExpDate() <= product[j]->getExpDate()) {
                                   product[j]->setIsStockDeclined(true);
                                }*/
                                product[j]->setIsStockDeclined(true);
                            }
                        }
                    }
                }
            }
        }

    }
    property += todaySales;
    cout << "---------------------------------------------------" << endl;
    cout << "���� ���� :" << todaySales << "��" << endl;
    cout << "���� ������ :" << todayProfits << "��" << endl;
    cout << "���� �ڻ� :" << property << "��" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        product[i]->setIsStockDeclined(false);
    }
}

/* �Ǹŷ� ��ȭ ���� �˰��� �Լ� */
void KICManager::randomSV()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1000000);
    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++) {
        if (product[i]->getIsSVChanged() == false) {
            int tempSalesVolume = product[i]->getSalesVolume();
            string tempPN = product[i]->getName();
            int amountOfChange;                      // �Ǹŷ��� ��ȭ��.
            int plusOrMinus = (dis(gen) + dis(gen)) % 2; // ���� �ΰ� ���ؼ� 2�� ���� �������� 0�̸� �Ǹŷ� ����, 1�̸� �Ǹŷ� ����.

            if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
                amountOfChange = (dis(gen) % 2);
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
                amountOfChange = (dis(gen) % 3);
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
                amountOfChange = (dis(gen) % 5);
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
                amountOfChange = (dis(gen) % 7);
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
                amountOfChange = (dis(gen) % 10);
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
                amountOfChange = (dis(gen) % 13);
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
                amountOfChange = (dis(gen) % 16);
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
                amountOfChange = (dis(gen) % 21);
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
                amountOfChange = (dis(gen) % 25);
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