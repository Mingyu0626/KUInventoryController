#include "KICManager.h"
#include <algorithm>
#include <typeinfo>
#include <iostream>
using namespace std;


void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "시작 날짜 입력 : ";
        getline(cin, date);
        result = checkDate(date);

        if (finalCheck == true) {
            todayDate = result;

            cout << todayDate << endl;
            break;
        }
    }
	init();
    addOrder(); //주문 추가
    //searchProds();
  //  sortDate();
    //sortAl();
  //sortStock();
    //addOrder();
}


// 날짜 입력 예외처리
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

    // dateCheck : 년도/월/일의 형식을 만족하고 범위 내에 있는지 확인
    // letterCheck : 정해진 위치에 특수문자가 존재하는지 확인 
    bool dateCheck = false, letterCheck = false;

    // letterCheck 시 '.' 처리 위함 
    string finalDate0 = "";
    string finalDate1 = "";
    string finalDate2 = "";

    while (true) {
        int z = 0;

        // 선행 공백 예외 처리 
        if (date[0] == ' ') {
            cout << "잘못된 입력입니다. 선행 공백을 허용하지 않습니다." << endl;
            return "";
        }
        // 6자리 입력 시(ex. 011028)
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

        // 8 자리 입력 시(ex.20011028, 01-10-28)
        else if (date.length() == 8) {
            a = date[0];
            b = date[1];
            c = date[2];
            d = date[3];
            e = date[4];
            f = date[5];
            g = date[6];
            h = date[7];

            // 20011028의 경우
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

            // 01-10-28의 경우 
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
                    cout << "날짜를 올바르게 입력하세요." << endl;
                    return "";
                }
            }
        }
        
        // 10 자리 입력 시 (ex.2021-03-29)
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
                    cout << "날짜를 올바르게 입력하세요." << endl;
                    return "";
                }
            }
        }
        else {
            cout << "날짜를 올바르게 입력하세요." << endl;
            return "";
        }
    }
}

void KICManager::init()
{
    fstream fin("source.txt");

    if (!fin.is_open()) {
        cerr << "파일 읽기 실패\n";
        exit(0);
    }
    while (!fin.eof()) {
        string buffer;
        fin >> this->count;
        getline(fin, buffer);
        cout << count << endl;

        if (count > 0) {
            product = new KICProduct * [100];
            sortprod = new KICProduct * [100]; //정렬위해 추가
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

    /* 주문을 위해 보유 잔액 출력  */
    cout << " 보유 잔액 : " << property << endl;

    cout << "********************주문 품목창*********************" << endl;
    sortAl();
    cout << "*****************************************************" << endl;

	/*주문 화면 출력*/
	string namePro="";
    int numPro=0;
    int price = 0;
    int k = 0; //반복문 탈출 위한 변수
    int productnum = -1; //주문할 물건의 인덱스번호

    while (true) {
	cout << " 주문할 제품명을 띄어쓰기 없이 입력(q누르면 종료.) : ";
	getline(cin, namePro);

    /*q누르면 종료*/
    //if (namePro.compare("q")) {
    //    cout << namePro << endl;
    //    //break;
    //}


    /*주문 상품 검색, 가격 계산*/
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
            cout << "잘못된 제품명입니다." << endl;
        }


        if (k == 1)
            break;
    }

    cout << " 주문할 제품 수량을 띄어쓰기 없이 입력  : ";
    cin >> numPro;

    cout <<" 결제금액 " << product[productnum]->getWPrice()*numPro <<"원, " << " 보유금액 " <<property<<"원" << "주문하시겠습니까? (y/n)" << endl;
    price = product[productnum]->getWPrice() * numPro; //결제금액_너무 길어서 price로 했습니당

    while (true) {  
        char yn;
        cin >> yn;

        if (yn == 'y') {
            /* 주문 상황 반영*/
        //    cout << "주문!" << endl;
            if (property < price) {
                cout << "결제 금액이 부족합니다." << endl;
                addOrder();
            }
            else {
                /*주문 성공*/
                property -= price;
                count++;

                /*product, sortprod 주문 내용 추가*/
                this->product[count] = new KICProduct(product[productnum]->getName(),numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                this->sortprod[count] = new KICProduct(product[productnum]->getName(), numPro, product[productnum]->getSalesVolume(), product[productnum]->getFixedExpDate(), product[productnum]->getWPrice(), product[productnum]->getRPrice());
                cout << "주문 완료했습니다" << endl;
                cout << "결제금액: " << price << ", 보유금액: " << property << endl;
            }
            break;
        }else if(yn == 'n') {
            cout << "주문이 취소되었습니다. " << endl;
            break;
        }
        else {
            cout << "잘못 입력하셨습니다. ";
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
        int k = 0; //search 갯수

        cout << "searchProds" << endl;
        cout << "검색하고자 하는 상품의 이름을 띄어쓰기 없이 입력 : ";
        getline(cin, namePro);

        cout << " =============== " << namePro << " 의 검색 결과" << " ============== " << endl;
        cout << endl;
        cout << endl;
        cout << "   상품명   " << "   재고   " << "  전날 판매량 " << "   유통기한   " << "   도매가   " << "   판매가   " << endl;
        cout << endl;

        for (int i = 0; i < count; i++)
            sortprod[i] = nullptr; // 비우기

        for (int i = 0; i < count; i++) {
            if ((product[i]->getName()).find(namePro) != string::npos) {
                if (product[i]->getStock() != 0) { // 재고 0인건 출력 안함
                    this->sortprod[k] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
                    k++;
                    //cout << "   " << product[j]->getName() << "      " << product[j]->getStock() << "           " << product[j]->getSalesVolume() << "         " << product[j]->getExpDate() << "         " << product[j]->getWPrice() << "        " << product[j]->getRPrice() << endl;
                }
            }
        }

        /*유통기한 임박순 출력*/
        for (int i = 0; i < count; i++) {
            if (sortprod[i] == nullptr)
                break;
            else {
                cout << "   " << sortprod[i]->getName() << "      " << sortprod[i]->getStock() << "           " << sortprod[i]->getSalesVolume() << "         " << sortprod[i]->getExpDate() << "         " << sortprod[i]->getWPrice() << "        " << sortprod[i]->getRPrice() << endl;
            }
        }
      //  cout << typeid(namePro[0]).name() << endl;  char임!
        int error = 0;
        cout << (int)namePro[0];

        /*입력 예외처리*/
        if (namePro[0] == ' ') {
            cout << "선행 공백은 불가능합니다. 다시 입력하세요" << endl;;
        }
      //  cout << namePro.size() << endl;
        else {
            cout << "여기야" << endl;
            //for (int i = 0; i < namePro.size() / 2; i++)
             //   cout << namePro.size()/2 << endl;
            if (namePro[0] == ' ') {
                cout << "선행 공백은 불가능합니다. 다시 입력하세요" << endl;;
            }
            //for (int i = 0; i < namePro.size() / 2; i++) {
            //    cout << (int)namePro[i];
            //    cout<<namePro.size()<<endl;
            //    if ((int)namePro[i] >= 33){ //&& (int)namePro[i] <= 47) {
            //        cout << "특수문자 입력은 불가능합니다" << endl;
            //        error = 1;
            //        break;
            //    }
            //}
        }
        
        
        //else if (namePro.find('~') != string::npos | namePro.find('!') != string::npos | namePro.find('@') != string::npos | namePro.find('#') != string::npos | namePro.find('$') != string::npos | namePro.find('%') != string::npos | namePro.find('^') != string::npos |
        //    namePro.find('&') != string::npos | namePro.find('*') != string::npos | namePro.find('(') != string::npos | namePro.find(')') != string::npos | namePro.find('-') != string::npos | namePro.find('+') != string::npos | namePro.find('_') != string::npos |
        //    namePro.find('=')) {
        //    cout << "특수문자 입력은 불가합니다. 다시 입력하세요" << endl;
        //    cout << namePro << endl;
        //}
        //else { // 오타 등 기획서에 명시한 예외 빼고는 모두 else로 처리
        //    cout << " 잘못된 입력입니다. " << endl;

        //}

    }
}


void KICManager::sortDate()
{
    //유통기한 임박순 정렬
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
    //ㄱㄴㄷ순 정렬
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

        
    /*addOrder 품목창에서 전날판매량*3 이상인것은 출력X*/
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() <= sortprod[i]->getSalesVolume() * 3) {
            cout << *sortprod[i] << endl;
        }
    }
   
    cout << endl;

}


void KICManager::sortStock()
{
    //재고 적은순 정렬

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
    } // discount 많은 순으로 정렬
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
    } // discount 같은 것들 중 disDate 순으로 정렬

    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0) {
            cout << sortprod[i] << endl;
        }
    } //discount 하는 것들 sorted 된대로 print
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
    } //  (같은제품, 유통기한 다른거 => 다른제품 취급 : 남은 재고 수 / 전날 판매량 순으로 정렬)
    bool accept = true;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() >= sortprod[i]->getSalesVolume() * 3 && sortprod[i]->getStock() != 0) {
            for (int j = 0; j < count; j++) {
                if (sortprod[i]->getName().compare(sortprod[j]->getName()) == 0) {
                    if (sortprod[i]->getExpDate() > sortprod[j]->getExpDate()) {
                        accept = false;
                        break;
                    } // expDate가 같은 제품 상에서 가장 최신꺼인지 확인
                }
            }
            if (accept) {
                cout << sortprod[i] << endl;
            }
        }
    }// 남은 재고 수 >= 전날 파매량 *3 인 제품만 sorted 된대로 출력
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
    cout << "할인 할 제품명을 입력하세요 : ";
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
    // 유통기한이 빠른 순으로 product는 정렬되어있을 가능성이 크다. 만약 그렇지 않으면 앞에 정렬 함수 추가

    if (status == -1) {
        cout << "그러한 제품명이 없습니다." << endl;
    }
    if (status == 0) {
        cout << "이미 할인 중인 제품입니다." << endl;
    }
    else if (status == 1) {
        cout << "선택하신 제품명은 할인할 수 있는 제품이 아닙니다." << endl;
    }
    else if (status == 2) {
        while(true){
            string line;
            int percentage = 0;
            cout << "할인할 %를 입력해주세요 (10 단위) (10 이상 90 이하) : ";
            getline(cin, line);
            if (line.compare("q") == 0) {
                exit(0);
            }
            try {
                percentage = stoi(line);
            }catch (const exception& e) {
                cerr << "입력하신 수가 정수가 아닙니다." << endl;
            }
            if (percentage < 10 && percentage > 90) {
                cout << "범위가 알맞지 않습니다." << endl;
            }
            else if (percentage % 10 != 0) {
                cout << "10 단위로 입력해야 합니다." << endl;
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
        int amountOfChange;                      // 판매량의 변화량.
        int plusOrMinus = (rand() + rand()) % 2; // 난수 두개 더해서 2로 나눈 나머지가 0이면 판매량 증가, 1이면 판매량 감소.

        if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
            amountOfChange = (rand() % 2);
            if (tempSalesVolume == 0) { // 판매량이 0인경우에서 판매량이 감소할 순 없으니까... 0혹은 1만큼 판매량 증가.
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

