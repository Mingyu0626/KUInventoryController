#include "KICManager.h"
#include <algorithm>
#include <typeinfo>


void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "시작 날짜 입력 : ";
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
    //addOrder(); //주문 추가
    
    addOrder(); //주문 추가

  //  sortDate();
    //sortStock();
    addOrder();
}


// 날짜 입력 예외처리
string KICManager::checkDate(string date) 
{
    int year = 0, month = 0, day = 0;

    string a, b, c, d, e, f, g, h, i ,j = "0";
    int num0, num1, num2, num3, num4, num5, num6, num7, num8, num9 = 0;

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
    fstream fin("C:\\Users\\USER\\Source\\Repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\source.txt");

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
            product = new KICProduct * [count];
            sortprod = new KICProduct * [count]; //정렬위해 추가
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
    // 메뉴 입력 예외처리?
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  보유 자산 : " << property << "원  " << endl;
        cout << "=================================================" << endl;
        cout << "  재고 부족 알림  " << endl;
        noStockAlarm();
        cout << "--------------- < 메뉴 > ---------------" << endl;
        cout << " 1) 제품 주문 " << endl;
        cout << " 2) 제품 검색 " << endl;
        cout << " 3) 할인 제품 지정 " << endl;
        cout << " 4) 업무 마감 " << endl;
        cout << "=================================================" << endl;
        cout << "메뉴를 선택하세요 : ";
        cin >> menu;
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();
        else if (menu == "3")
            selectDiscountProds(&product);
        else if (menu == "4")
            closingWork();
        else {
            cout << "올바른 숫자를 입력하세요 !" << endl;
            system("pause");
        }
    }
}

void KICManager::noStockAlarm()
{
    // 재고 5개 이하면 알림 출력
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() <= 5) {
            cout << product[i]->getName() << " : 재고 " << product[i]->getStock() << "개" << endl;
        }
    }
}

void KICManager::setDate()
{
    // 폐기 처리 하고 함수 실행하기
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

    cout << " < " << year << "년 " << month << "월 " << day << "일 > \n" << endl;
}


void KICManager::addOrder()
{

    /* 주문을 위해 보유 잔액 출력  */
    cout << " 보유 잔액 : " << property << endl;

    sortAl();

	/*주문 화면 출력*/

	string namePro;
    int numPro;
	cout << " 주문할 제품명을 띄어쓰기 없이 입력 : ";
	getline(cin, namePro);
	/*검색함수 들어가면돼*/

	cout << " 주문할 제품 수량을 띄어쓰기 없이 입력  : ";
    cin >> numPro;

    /*주문 상품 찾아서 가격 보여주기*/
 

    cout <<" 결제금액 " << property <<"원 " << " 보유금액 " << "원" << "주문하시겠습니까? (y/n)" << endl;
    
    while (true) {  
        char yn;
        cin >> yn;
        cout << yn << endl;

        if (yn == 'y') {
            /* 주문 상황 반영*/
            cout << "주문!" << endl;
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
    cout << "searchProds" << endl;
    cout << "searchProds" << endl;
}

void KICManager::sortDate()
{
    //유통기한 임박순 정렬
    cout << "sortdate" << endl;

    /*for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }*/

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for(int j=i+1;j<count;j++){
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
    //ㄱㄴㄷ순 정렬
    cout << "sortal" << endl;

    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
           // cout << (*sortprod[i]->getName() < *sortprod[j]->getName()) << endl;
            if ((sortprod[i]->getName().compare(sortprod[j]->getName()))>0) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }
    cout << "********************주문 품목창*********************" << endl;
    /*addOrder 품목창에서 전날판매량*3 이상인것은 출력X*/
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getStock() <= sortprod[i]->getSalesVolume() * 3) {
            cout << *sortprod[i] << endl;
        }
    }
    cout << "*****************************************************" << endl;
    cout << endl;

}


void KICManager::sortStock()
{
    //재고 적은순 정렬

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
}



void KICManager::discountReqProds()
{
}



void KICManager::selectDiscountProds()
{
}



void KICManager::selectMarginRate()
{
    int tempRPrice, tempWPrice, margin;
    double marginRate; // 마진율
    for (int i = 0; i < count; i++) {
        if (product[i]->getDiscount() == 0) {
            tempRPrice = product[i]->getRPrice();
            tempWPrice = product[i]->getWPrice();
        }
    }
    margin = tempRPrice - tempWPrice;
    marginRate = 100 * (margin / tempRPrice);
    cout << "현재 마진율 : " << marginRate << endl;
    cout << "변경할 마진율을 입력해주세요 : " << endl;

}



void KICManager::closingWork()
{
    cout << "---------- <2021년 10월 24일 업무마감> ----------\n";
    searchScrap();      // 폐기 제품 판별 및 재고 수 초기화(폐기)
    financeCalculate(); // 판매에 따른 재고 수 줄인 후, 감당일 매출액, 당일 순이익, 보유 자산 출력
    randomSV(); // 다음날 판매될 랜덤 판매량 결정
}



void KICManager::searchScrap()
{
    cout << "※※폐기 알림※※" << endl;
    int numOfScrapProds = 0;
    for (int i = 0; i < count; i++) {
        if (product[i]->getExpDate() == 0) { // 유통기한이 만료된 제품의 경우 해당 제품의 재고를 0으로 만들어줘야 한다.
            numOfScrapProds++;
            cout << product[i]->getName() << " " << product[i]->getStock() << "개 폐기" << endl;
            product[i]->setStock(0);
        }
        else { // 유통기한이 만료되지 않은 제품의 경우 유통기한을 1일 감소시켜준다.
            product[i]->setExpDate(product[i]->getExpDate() - 1);
        }
    }
    if (numOfScrapProds == 0) {
        cout << "오늘은 폐기된 제품이 없습니다." << endl;
    }
}



void KICManager::financeCalculate()
{
    int tempStock = 0;
    int tempSalesVolume; // 제품의 당일 판매량
    int remainSV;
    int tempWPrice;
    int tempRPrice;
    int todaySales = 0; // 당일 매출액 합계
    int todayProfits = 0; // 당일 순이익 합계
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() != 0) {
            tempStock = product[i]->getStock();
            tempSalesVolume = product[i]->getSalesVolume();
            tempWPrice = product[i]->getWPrice();
            tempRPrice = product[i]->getRPrice();

            if (tempStock < tempSalesVolume) { // 제품의 남은 재고 수보다 판매량이 많을 경우
                string remainPN = product[i]->getName();

                todaySales = calTodaySales(todaySales, tempStock, tempRPrice);  // 제품의 당일 매출액 계산 후 합계에 더해주기
                todayProfits = calTodayProfits(todayProfits, tempStock, tempRPrice, tempWPrice); // 제품의 당일 순이익 계산 후 합계에 더해주기
                product[i]->setStock(0);
                remainSV = tempSalesVolume - tempStock;

                for (int j = 0; j < count; j++) {
                    if (remainPN.compare(product[j]->getName()) == 0 && product[j]->getStock() > 0) { // 1번째 재고가 남은 동일 제품 객체 탐색 
                        if (product[j]->getStock() < remainSV) { // 제품의 남은 재고 수보다 remainSV가 많을 경우
                            todaySales = calTodaySales(todaySales, product[j]->getStock(), tempRPrice);
                            todayProfits = calTodayProfits(todayProfits, product[j]->getStock(), tempRPrice, tempWPrice);
                            product[j]->setStock(0);
                            remainSV = remainSV - product[j]->getStock();

                            for (int k = 0; k < count; k++) {   // 2번째 재고가 남은 동일 제품 객체 탐색 
                                if (remainPN.compare(product[k]->getName()) == 0 && product[k]->getStock() > 0) {
                                    if (product[k]->getStock() < remainSV) { // 제품의 남은 재고 수보다 remainSV가 많을 경우
                                        todaySales = calTodaySales(todaySales, product[k]->getStock(), tempRPrice);
                                        todayProfits = calTodayProfits(todayProfits, product[k]->getStock(), tempRPrice, tempWPrice);
                                        product[j]->setStock(0);
                                        /* 동일제품은 최대 3회만 주문 가능하므로 여기서 끝 */
                                    }
                                    else { // // 제품의 남은 재고수가 remainSV보다 많은 경우
                                        todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                        todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                        product[k]->setStock(product[k]->getStock() - remainSV);
                                    }
                                }
                            }
                        }
                        else { // 제품의 남은 재고수가 remainSV보다 많은 경우
                            todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                            todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                            product[j]->setStock(product[j]->getStock() - remainSV);
                        }
                    }
                }

            }
            else { // 제품의 남은 재고 수가 판매량보다 많을 경우
                todaySales = calTodaySales(todaySales, tempSalesVolume, tempRPrice); // 제품의 매출액 계산 후 합계에 더해주기
                todayProfits = calTodayProfits(todayProfits, tempSalesVolume, tempRPrice, tempWPrice); // 제품의 순이익 계산 후 합계에 더해주기
                product[i]->setStock(tempStock - tempSalesVolume);
            }
        }
   
    }
    property += todayProfits;
    cout << "---------------------------------------------------" << endl;
    cout << "당일 매출 :" << todaySales << endl;
    cout << "당일 순이익 :" << todayProfits << endl;
    cout << "보유 자산 :" << property << endl;
}



void KICManager::randomSV()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++) {
        if (product[i]->getIsSVChanged() == false) {
            int tempSalesVolume = product[i]->getSalesVolume();
            string tempPN = product[i]->getName();
            int amountOfChange;                      // 판매량의 변화량.
            int plusOrMinus = (rand() + rand()) % 2; // 난수 두개 더해서 2로 나눈 나머지가 0이면 판매량 증가, 1이면 판매량 감소.

            if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
                amountOfChange = (rand() % 2);
                if (tempSalesVolume == 0) { // 판매량이 0인경우에서 판매량이 감소할 순 없으니까... 0혹은 1만큼 판매량 증가.
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
                if (tempSalesVolume >= 150) { // 판매량이 150이상이 되면 판매량이 감소하게끔 설정
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
            /* 위에서 랜덤 판매량을 대입한 제품과 유통기한만 다른 동일 제품을 찾아 동일한 판매량을 대입해주는 작업 */
            for (int j = 0; j < count; j++) {
                if (tempPN.compare(product[j]->getName()) == 0 && product[j]->getIsSVChanged() == false) {
                    product[j]->setSalesVolume(tempSalesVolume);
                    product[j]->setSVChanged(true);
                }
            }
        }
    }
    /*동일 제품을 고려한 랜덤 판매량 대입 작업이 완료되었으므로 다시 IsSVChanged 변수를 false로 돌려놓는다.*/
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

