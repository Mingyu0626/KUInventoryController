#include "KICManager.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>
using namespace std;


void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "���� ��¥ �Է� : ";
        getline(cin, date);
        result = checkDate(date);

        if (finalCheck == true) {
            todayDate = result;

            cout << todayDate << endl;
            break;
        }
    }
	init();
    addOrder(); //�ֹ� �߰�
    //searchProds();
  //  sortDate();
    //sortAl();
  //sortStock();
    //addOrder();
}


// ��¥ �Է� ����ó��
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
        cout << count << endl;

        if (count > 0) {
            product = new KICProduct * [100];
            sortprod = new KICProduct * [100]; //�������� �߰�
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
}




/*void KICManager::noStockAlarm(KICProduct** kicp[])
{
}*/



void KICManager::addOrder()
{

    /* �ֹ��� ���� ���� �ܾ� ���  */
    cout << " ���� �ܾ� : " << property << endl;

    cout << "********************�ֹ� ǰ��â*********************" << endl;
    sortAl();
    cout << "*****************************************************" << endl;

	/*�ֹ� ȭ�� ���*/
	string namePro="";
    int numPro=0;
    int price = 0;
    int k = 0; //�ݺ��� Ż�� ���� ����
    int productnum = -1; //�ֹ��� ������ �ε�����ȣ

    while (true) {
	cout << " �ֹ��� ��ǰ���� ���� ���� �Է�(q������ ����.) : ";
	getline(cin, namePro);

    /*q������ ����*/
    //if (namePro.compare("q")) {
    //    cout << namePro << endl;
    //    //break;
    //}


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

        else{
            cout << "�߸��� ��ǰ���Դϴ�." << endl;
        }


        if (k == 1)
            break;
    }

    cout << " �ֹ��� ��ǰ ������ ���� ���� �Է�  : ";
    cin >> numPro;

    cout <<" �����ݾ� " << product[productnum]->getWPrice()*numPro <<"��, " << " �����ݾ� " <<property<<"��" << "�ֹ��Ͻðڽ��ϱ�? (y/n)" << endl;
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
                this->product[count] = new KICProduct(product[productnum]->getName(),numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                this->sortprod[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                cout << "�ֹ� �Ϸ��߽��ϴ�" << endl;
                cout << "�����ݾ�: " << price << ", �����ݾ�: " << property << endl;
            }
            break;
        }else if(yn == 'n') {
            cout << "�ֹ��� ��ҵǾ����ϴ�. " << endl;
            break;
        }
        else {
            cout << "�߸� �Է��ϼ̽��ϴ�. ";
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
        int k = 0; //search ����

        cout << "searchProds" << endl;
        cout << "�˻��ϰ��� �ϴ� ��ǰ�� �̸��� ���� ���� �Է� : ";
        getline(cin, namePro);

        cout << " =============== " << namePro << " �� �˻� ���" << " ============== " << endl;
        cout << endl;
        cout << endl;
        cout << "   ��ǰ��   " << "   ���   " << "  ���� �Ǹŷ� " << "   �������   " << "   ���Ű�   " << "   �ǸŰ�   " << endl;
        cout << endl;

        for (int i = 0; i < count; i++)
            sortprod[i] = nullptr; // ����

        for (int i = 0; i < count; i++) {
            if ((product[i]->getName()).find(namePro) != string::npos) {
                if (product[i]->getStock() != 0) { // ��� 0�ΰ� ��� ����
                    this->sortprod[k] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
                    k++;
                    //cout << "   " << product[j]->getName() << "      " << product[j]->getStock() << "           " << product[j]->getSalesVolume() << "         " << product[j]->getExpDate() << "         " << product[j]->getWPrice() << "        " << product[j]->getRPrice() << endl;
                }
            }
        }

        /*������� �ӹڼ� ���*/
        for (int i = 0; i < count; i++) {
            if (sortprod[i] == nullptr)
                break;
            else {
                cout << "   " << sortprod[i]->getName() << "      " << sortprod[i]->getStock() << "           " << sortprod[i]->getSalesVolume() << "         " << sortprod[i]->getExpDate() << "         " << sortprod[i]->getWPrice() << "        " << sortprod[i]->getRPrice() << endl;
            }
        }
      //  cout << typeid(namePro[0]).name() << endl;  char��!
        int error = 0;
        cout << (int)namePro[0];

        /*�Է� ����ó��*/
        if (namePro[0] == ' ') {
            cout << "���� ������ �Ұ����մϴ�. �ٽ� �Է��ϼ���" << endl;;
        }
      //  cout << namePro.size() << endl;
        else {
            cout << "�����" << endl;
            //for (int i = 0; i < namePro.size() / 2; i++)
             //   cout << namePro.size()/2 << endl;
            if (namePro[0] == ' ') {
                cout << "���� ������ �Ұ����մϴ�. �ٽ� �Է��ϼ���" << endl;;
            }
            //for (int i = 0; i < namePro.size() / 2; i++) {
            //    cout << (int)namePro[i];
            //    cout<<namePro.size()<<endl;
            //    if ((int)namePro[i] >= 33){ //&& (int)namePro[i] <= 47) {
            //        cout << "Ư������ �Է��� �Ұ����մϴ�" << endl;
            //        error = 1;
            //        break;
            //    }
            //}
        }
        
        
        //else if (namePro.find('~') != string::npos | namePro.find('!') != string::npos | namePro.find('@') != string::npos | namePro.find('#') != string::npos | namePro.find('$') != string::npos | namePro.find('%') != string::npos | namePro.find('^') != string::npos |
        //    namePro.find('&') != string::npos | namePro.find('*') != string::npos | namePro.find('(') != string::npos | namePro.find(')') != string::npos | namePro.find('-') != string::npos | namePro.find('+') != string::npos | namePro.find('_') != string::npos |
        //    namePro.find('=')) {
        //    cout << "Ư������ �Է��� �Ұ��մϴ�. �ٽ� �Է��ϼ���" << endl;
        //    cout << namePro << endl;
        //}
        //else { // ��Ÿ �� ��ȹ���� ����� ���� ����� ��� else�� ó��
        //    cout << " �߸��� �Է��Դϴ�. " << endl;

        //}

    }
}


void KICManager::sortDate()
{
    //������� �ӹڼ� ����
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
    //�������� ����
    cout << "sortal" << endl;
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }

    KICProduct temp = *sortprod[0];
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
    
   /* for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    } */
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

    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0) {
            cout << sortprod[i] << endl;
        }
    } //discount �ϴ� �͵� sorted �ȴ�� print
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
    } //  (������ǰ, ������� �ٸ��� => �ٸ���ǰ ��� : ���� ��� �� / ���� �Ǹŷ� ������ ����)
    bool accept = true;
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
            }
        }
    }// ���� ��� �� >= ���� �ĸŷ� *3 �� ��ǰ�� sorted �ȴ�� ���
}



void KICManager::selectDiscountProds()//(KICProduct** kicp[])
{

    /*KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }*/
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
    }
    if (status == 0) {
        cout << "�̹� ���� ���� ��ǰ�Դϴ�." << endl;
    }
    else if (status == 1) {
        cout << "�����Ͻ� ��ǰ���� ������ �� �ִ� ��ǰ�� �ƴմϴ�." << endl;
    }
    else if (status == 2) {
        while(true){
            string line;
            int percentage = 0;
            cout << "������ %�� �Է����ּ��� (10 ����) (10 �̻� 90 ����) : ";
            getline(cin, line);
            if (line.compare("q") == 0) {
                exit(0);
            }
            try {
                percentage = stoi(line);
            }catch (const exception& e) {
                cerr << "�Է��Ͻ� ���� ������ �ƴմϴ�." << endl;
            }
            if (percentage < 10 && percentage > 90) {
                cout << "������ �˸��� �ʽ��ϴ�." << endl;
            }
            else if (percentage % 10 != 0) {
                cout << "10 ������ �Է��ؾ� �մϴ�." << endl;
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
        int amountOfChange;                      // �Ǹŷ��� ��ȭ��.
        int plusOrMinus = (rand() + rand()) % 2; // ���� �ΰ� ���ؼ� 2�� ���� �������� 0�̸� �Ǹŷ� ����, 1�̸� �Ǹŷ� ����.

        if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
            amountOfChange = (rand() % 2);
            if (tempSalesVolume == 0) { // �Ǹŷ��� 0�ΰ�쿡�� �Ǹŷ��� ������ �� �����ϱ�... 0Ȥ�� 1��ŭ �Ǹŷ� ����.
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

