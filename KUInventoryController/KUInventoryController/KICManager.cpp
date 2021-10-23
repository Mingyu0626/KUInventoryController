#include "KICManager.h"
#include <algorithm>

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
    
  //  sortDate();
    //sortStock();
    //addOrder();
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
                //cout << dateCheck << endl;

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
       /* for (int i = 0; i < count; i++) {
            cout << *product[i] << endl;
            
        } */
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
    balance = 10000; /* balance 나오는 부분 없길래 일단 임의로 했어요 */

    /* 주문을 위해 보유 잔액 출력  */
    cout << " 보유 잔액 : " << balance << endl;

   
   // cout << count << endl;

    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }
    /* 재고가 전날 판매량 *3 보다 적은 제품만 제품 재고 적은 순 출력*/

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getStock() <= sortprod[j]->getSalesVolume()*3) {
                temp = *sortprod[i];
                *sortprod[i] = *sortprod[j];
                *sortprod[j] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        cout << *sortprod[i] << endl;
    }

	/*주문 화면 출력*/

	string namePro;
    int numPro;
	cout << " 주문할 제품명을 띄어쓰기 없이 입력 : ";
	getline(cin, namePro);
	/*검색함수 들어가면돼 */

	cout << " 주문할 제품 수량을 띄어쓰기 없이 입력  : ";
    cin >> numPro;





    

    cout <<" 결제금액 " << "원 " << " 보유금액 " << "원" << "주문하시겠습니까? (y/n)" << endl;

    while (true) {
        char yn = _getch();
        if (yn != 89 | yn != 78) {
            cout << "잘못 입력하셨습니다. ";
            continue;
        }
        else if (yn == 89) {
            /* 주문 상황 반영*/
        }

        else if (yn == 78) {
            cout << "주문이 취소되었습니다. " << endl;
            break;
        }


    }

}



void KICManager::searchProds()
{
    cout << "searchProds" << endl;
}

void KICManager::sortDate()
{
    //여기서 sortprod는 유통기한 임박순!
    cout << "sortdate" << endl;

    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }

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
    
   // sort(product[0]->getExpDate(), product[41]->getExpDate());


}

void KICManager::sortAl()
{
    //ㄱㄴㄷ순
    cout << "sortal" << endl;
}


void KICManager::sortStock()
{
    //여기서 sortprod는 재고 적은순

    cout << "sortstock" << endl;

    for (int i = 0; i < count; i++) {
        this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(), product[i]->getRPrice());
    }

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
    
    //1. ㄱㄴㄷ순
    //2. 
}



void KICManager::changePrice()
{
}



void KICManager::discountProds(KICProduct** kicp[])
{
}



void KICManager::discountReqProds(KICProduct** kicp[])
{
}



void KICManager::selectDiscountProds(KICProduct** kicp[])
{
}



void KICManager::selectMarginRate(KICProduct** kicp[])
{
}



void KICManager::closingWork()
{
}



void KICManager::searchScrap(KICProduct** kicp[])
{
}



void KICManager::printFinance()
{
}



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

