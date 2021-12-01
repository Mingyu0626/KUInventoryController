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
        cout << "1. 새로 시작" << endl;
        cout << "2. 불러오기" << endl;
        cout << "=================================================" << endl;
        cout << "시작 방법을 선택하세요 : ";
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
                cout << "저장되어 있는 정보가 존재하지 않습니다. 다시 입력해주세요." << endl;
                system("pause");
                continue;
            }
        }
        else {
            cout << "올바른 숫자를 입력하세요. " << endl;
            system("pause");
        }

    }
    system("cls");
    printMenu();
}


// 날짜 입력 예외처리
string KICManager::checkDate(string date)
{
    int year = 0, month = 0, day = 0;

    string a, b, c, d, e, f, g, h, i, j = "0";
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
            system("pause");
            return "";
        }
        // 6자리 입력 시(ex. 011028)
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
                            cout << "날짜를 올바르게 입력하세요." << endl;
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
                            cout << "날짜를 올바르게 입력하세요." << endl;
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
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                        break;
                    }
                else {
                    cout << "날짜를 올바르게 입력하세요." << endl;
                    system("pause");
                    return "";
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
                            else {
                                cout << "날짜를 올바르게 입력하세요." << endl;
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
                                cout << "날짜를 올바르게 입력하세요." << endl;
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
                                cout << "날짜를 올바르게 입력하세요." << endl;
                                system("pause");
                                return "";
                            }
                            break;
                        }
                    }
                    else {
                        cout << "날짜를 올바르게 입력하세요." << endl;
                        system("pause");
                        return "";
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
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                    }
                }
                else {
                    cout << "날짜를 올바르게 입력하세요." << endl;
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
                    cout << "날짜를 올바르게 입력하세요." << endl;
                    system("pause");
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
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else if (month == 4 || month == 6 || month == 9 || month == 11) {
                        if (day >= 1 && day <= 30) {
                            dateCheck = true;
                        }
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
                            system("pause");
                            return "";
                        }
                    }
                    else {
                        if (day >= 1 && day <= 31) {
                            dateCheck = true;
                        }
                        else {
                            cout << "날짜를 올바르게 입력하세요." << endl;
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
                    cout << "날짜를 올바르게 입력하세요." << endl;
                    system("pause");
                    return "";
                }
            }
            else {
                cout << "날짜를 올바르게 입력하세요." << endl;
                system("pause");
                return "";
            }
        }
        else {
            cout << "날짜를 올바르게 입력하세요." << endl;
            system("pause");
            return "";
        }
    }
}


void KICManager::init()
{
    /*절대경로 필요한 친구들은 절대경로로 사용하시고 밑에 코드는 주석처리 해주세요.*/
     fstream fin("defaultprodsinfo.txt");
   //fstream fin("C:\\Users\\이하윤\\Source\\Repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\source.txt");

    if (!fin.is_open()) {
        cerr << "파일 읽기 실패\n";
        exit(0);
    }

    string date, result;

    while (true) {
        cout << "시작 날짜 입력 : ";
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
            sortprod = new KICProduct * [100]; //정렬위해 추가
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
    // 메뉴 입력 예외처리
    string menu;
    while (true) {
        system("cls");
        printDate();
        cout << "=================================================" << endl;
        cout << "  보유 자산 : " << property << "원  " << endl;
        cout << "=================================================" << endl;
        cout << "------------- ※※재고부족 알림※※ -------------" << endl;
        noStockAlarm();
        cout << "-------------------- <메뉴> ---------------------" << endl;
        cout << " 1) 제품 주문 " << endl;
        cout << " 2) 제품 검색 " << endl;
        cout << " 3) 판매가 지정 " << endl;
        cout << " 4) 제품 추가/삭제 " << endl;
        cout << " 5) 업무 마감 " << endl;
        cout << " 6) 프로그램 종료 " << endl;
        cout << "=================================================" << endl;
        cout << "메뉴를 선택하세요 : ";
        getline(cin, menu);
        if (menu == "1")
            addOrder();
        else if (menu == "2")
            searchProds();

        else if (menu == "3") {
            while (true) {
                system("cls");
                cout << "---------------------------------------- < 메뉴 > ----------------------------------------" << endl;
                cout << " 1) 할인 제품 지정 " << endl;
                cout << " 2) 마진율 지정 " << endl;
                cout << "===========================================================================================" << endl;
                cout << "메뉴를 선택하세요 (q : 메뉴 종료) : ";
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
                    cout << "올바른 숫자를 입력하세요." << endl;
                    system("pause");
                    continue;
                }
                break;
            }
        }
        else if (menu == "4") {
            while (true) {
                system("cls");
                cout << "---------------------------------------- < 메뉴 > ----------------------------------------" << endl;
                cout << " 1) 제품 추가 " << endl;
                cout << " 2) 제품 삭제 " << endl;
                cout << "===========================================================================================" << endl;
                cout << "메뉴를 선택하세요 (q : 메뉴 종료) : ";
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
                    cout << "올바른 숫자를 입력하세요." << endl;
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
            cout << "프로그램을 종료합니다.\n" << endl;
            exit(0);
        }
        else {
            cout << "올바른 숫자를 입력하세요." << endl;
            system("pause");
        }
    }
}


/*void KICManager::noStockAlarm()
{
   // 재고 <= 전날 판매량일 때 알람 출력
   bool check = false;
   int total = 0;
   int productNum = 0;


   //bool isRemove = false; //삭제된 제품인지 check
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
            cout << product[i]->getName() << " : 재고 " << total << "개" << endl;
         }
      }
   }

   if (!check) {
      cout << "재고 부족한 제품 없음" << endl;
   }
}
*/    // 업무마감 및 제품 삭제 반영될수있도록 수정했어요 혹시 보고서 이런식으로 하면안된다 싶음 알려주세영


void KICManager::noStockAlarm()
{
    // 재고 <= 전날 판매량일 때 알람 출력
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
                if (i != j) { // 같은 이름의 다른 유통기한 있으면 총 재고는 합해서 반영
                    total += product[j]->getStock();
                    dcheck++;
                }
                productNum = j;
            }
        }

        if (print) {
            if (0 <= total && total <= product[i]->getSalesVolume() && productNum == i) { // 삭제된 제품은 재고가 -1이므로 존재하는 제품 중 재고가 전날 판매량보다 작은 경우 알림
                check = true;
                cout << product[i]->getName() << " : 재고 " << total << "개" << endl;
            }
        }
    }

    if (!check) {
        cout << "재고 부족한 제품 없음" << endl;
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


bool KICManager::loadInfor() {
    /*절대경로 필요한 친구들은 절대경로로 사용하시고 밑에 코드는 주석처리 해주세요.*/
    // 임의로 해둔 파일임 
    fstream fin("C:\\Users\\samsung\\source\\repos\\Mingyu0626\\KUInventoryController\\KUInventoryController\\KUInventoryController\\test.txt");

    if (!fin.is_open()) {
        cerr << "파일 읽기 실패\n";
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
            sortprod = new KICProduct * [100]; //정렬위해 추가
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
        cout << " 보유 잔액 : " << property << "원" << endl;

        /* 주문을 위해 보유 잔액 출력  */
        cout << "*****************************************************주문 품목창*****************************************************" << endl;
        sortAl();
        cout << "********************************************************************************************************************" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

        /*주문 화면 출력*/
        string namePro = "";
        int numPro = 0;
        // string numPro="";
        int price = 0;
        int tmp = 0; //반복문 탈출 위한 변수
        int productnum = -1; //주문할 물건의 인덱스번호

        cout << "주문할 제품명을 띄어쓰기 없이 입력 (q : 메뉴 종료) : ";
        //  cin.ignore();
        getline(cin, namePro);

        /*q누르면 종료*/
        if (namePro.compare("q") == 0) {
            return;
        }

        /*주문 상품 검색, 가격 계산*/
        for (int i = 0; i < count; i++) {
            if (((product[i]->getName().compare(namePro)) == 0)) {
                productnum = i;
                break;
            }
        }

        if (productnum == -1) {
            cout << "잘못된 제품명입니다. 다시 입력하세요." << endl;
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
        cout << "주문할 제품 수량을 띄어쓰기 없이 입력 : ";
        cin >> numPro;
        string buffer;
        getline(cin, buffer);

        while (true) {
            if (numPro < 0) {
                cout << "0보다 큰 수를 입력하세요" << endl;
                system("pause");
                break;
            }
            if (numPro > 214748) {
                cout << "다시 입력하세요" << endl;
                system("pause");
                cin.clear();
                getline(cin, buffer);
                break;
            }
            if (cin.fail()) {
                cout << "다시 입력하세요" << endl;
                buffer = "";
                system("pause");
                numPro = 0;
                cin.clear();
                getline(cin, buffer);
                break;
            }

            price = product[productnum]->getWPrice() * numPro; //결제금액_너무 길어서 price로 했습니당
            if (property < price) {
                cout << "결제 금액이 부족합니다." << endl;
                system("pause");
                break;
            }
            cout << "-----------------------------------" << endl;
            cout << "결제금액 " << product[productnum]->getWPrice() * numPro << "원, " << " 보유금액 " << property << "원\n" << "주문하시겠습니까(q:메뉴 종료)? (y/n) ";
            string yn;
            getline(cin, yn);

            if (yn.compare("y") == 0) {

                /*주문 성공*/
                int k = 0; //주문 횟수
                for (int i = 0; i < count; i++) {
                    if (product[i]->getName().compare(namePro) == 0 && product[i]->getStock() != 0)
                        k++;
                }
                /*3번 이상 주문X*/
                if (k >= 3) {
                    cout << "해당 제품은 더 이상 주문할 수 없습니다." << endl;
                    system("pause");
                    break;
                }

                int p = 0; // 같은제품, 같은 유통기한인지 check

                /*같은 제품, 같은 유통기한이면 합치기*/
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
                    /*product, sortprod 주문 내용 추가*/
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
                cout << "주문이 완료되었습니다." << endl;
                cout << "-----------------------------------" << endl;
                /*if(p ==0)
                   cout << setw(15) << product[productnum]->getName() << setw(15) << product[productnum]->getStock() << setw(15) << product[productnum]->getSalesVolume() << setw(15) << product[productnum]->getExpDate() << setw(15) << product[productnum]->getWPrice() << setw(15) << product[productnum]->getRPrice() << setw(15) << product[productnum]->getDiscount() << setw(15) << product[productnum]->getDisDate() << endl;
                else if(p==1)
                   cout << setw(15) << product[count - 1]->getName() << setw(15) << product[count - 1]->getStock() << setw(15) << product[productnum]->getSalesVolume() << setw(15) << product[productnum]->getExpDate() << setw(15) << product[productnum]->getWPrice() << setw(15) << product[productnum]->getRPrice() << setw(15) << product[productnum]->getDiscount() << setw(15) << product[productnum]->getDisDate() << endl;*/

                cout << "결제금액 : " << price << ", 보유금액 : " << property << endl;
                cout << "-----------------------------------" << endl;
                system("pause");
                break;
            }
            else if (yn.compare("n") == 0) {
                cout << "주문이 취소되었습니다. " << endl;
                system("pause");
                break;
            }
            else if (yn.compare("q") == 0) {
                return;
            }
            else {
                cout << "잘못 입력하셨습니다." << endl;
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
        cout << "================================================== < 제품 검색 > ====================================================" << endl;
        cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "전날판매량" << setw(15) << "유통기한" << setw(15) << "도매가" << setw(15) << "판매가" << setw(15) << "할인율" << setw(15) << "할인남은기간" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
        // 검색 초기화면은 ㄱㄴㄷ 순 출력
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
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // 재고 0인거나 유통기한 0일이면 출력안함
                cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getWPrice() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getDiscount() << setw(15) << sortprod[i]->getDisDate() << endl;
            }
        }

        cout << endl;

        string namePro;
        cout << endl;
        cout << endl;
        cout << "검색할 제품 이름을 띄어쓰기 없이 입력 (q : 메뉴 종료) : ";
        getline(cin, namePro);
        cout << endl;

        /*q누르면 종료*/
        if (namePro.compare("q") == 0) {
            // cout << "종료" << endl;
            printMenu();
        }

        // 검색 결과 출력은 유통기한 짧은 순으로 정렬
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
            if (sortprod[j]->getExpDate() != 0 || sortprod[j]->getStock() > 0) { // 유통기한 0이거나 재고가 0이거나 삭제된 제품은 출력안함
                if ((sortprod[j]->getName()).find(namePro) != string::npos) {
                    status = 0;
                    break;
                }
            }
        }

        if (namePro[0] == ' ' || namePro.empty()) {
            cout << "선행 공백과 미입력은 불가능합니다. 다시 입력하세요." << endl;
            system("pause");
        }

        else if (namePro.find('~') != string::npos || namePro.find('!') != string::npos || namePro.find('@') != string::npos || namePro.find('#') != string::npos || namePro.find('$') != string::npos || namePro.find('%') != string::npos || namePro.find('^') != string::npos ||
            namePro.find('&') != string::npos || namePro.find('*') != string::npos || namePro.find('(') != string::npos || namePro.find(')') != string::npos || namePro.find('-') != string::npos || namePro.find('+') != string::npos || namePro.find('_') != string::npos ||
            namePro.find('=') != string::npos || namePro.find(':') != string::npos || namePro.find(';') != string::npos || namePro.find('"') != string::npos || namePro.find(',') != string::npos || namePro.find('<') != string::npos || namePro.find('>') != string::npos ||
            namePro.find('?') != string::npos || namePro.find('/') != string::npos || namePro.find('`') != string::npos || namePro.find('.') != string::npos || namePro.find('\'') != string::npos)
        {
            cout << "특수문자 입력은 불가능합니다. 다시 입력하세요." << endl;
            system("pause");
        }

        else if (status != 0) { // 오타 등 기획서에 명시한 예외 빼고는 모두 else로 처리
            cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
            system("pause");
        }
        else if (status == 0) {
            cout << "=========================================== " << namePro << " 의 검색 결과" << " ============================================\n" << endl;
            cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "전날판매량" << setw(15) << "유통기한" << setw(15) << "도매가" << setw(15) << "판매가" << setw(15) << "할인율" << setw(15) << "할인남은기간" << endl;
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
    //유통기한 임박순 정렬

    /*for (int i = 0; i < count; i++) {
       this->sortprod[i] = new KICProduct(product[i]->getName(), product[i]->getStock(), product[i]->getSalesVolume(), product[i]->getExpDate(), product[i]->getWPrice(),product[i]->getRPrice());
    }*/

    KICProduct temp = *sortprod[0];
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // 재고 0인거나 유통기한 0일이면 출력안함
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
    //ㄱㄴㄷ순 정렬
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
    cout << setw(15) << "상품명" << setw(10) << "총재고" << setw(15) << "빠른유통기한" << setw(10) << "의재고" << setw(15) << "전날판매량" << setw(15) << "도매가" << setw(15) << "판매가" << setw(8) << "할인율" << setw(8) << "할인남은기간" << endl;
    //  cout << " 상품명 " << " 재고 " << " 전날 판매량 " << " 유통기한 " << " 도매가 " << " 판매가 " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    /*addOrder 품목창에서 전날판매량*3 이상인것은 출력X*/
    /*유통기한 0인것도 출력X*/
    int k = 0;
    /*for (int i = 0; i < count; i++) {
       if (sortprod[i]->getExpDate() != 0 || sortprod[i]->getStock() != 0) { // 재고 0인거나 유통기한 0일이면 출력안함
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
    //재고 적은순 정렬

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
            if (sortprod[i]->getExpDate() != 0 && sortprod[i]->getStock() != 0) { // 재고 0인거나 유통기한 0일이면 출력안함
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

/* 현재 할인 중인 제품 출력 함수*/
void KICManager::discountProds() // 현재 할인 중인 제품 출력
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
    bool check = false;
    cout << endl;
    cout << "현재 discount 하는 제품들 : " << endl;
    cout << endl;
    cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "유통기한" << setw(15) << "할인판매가" << setw(15) << "원래판매가" << setw(15) << "할인남은기간" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < count; i++) {
        if (sortprod[i]->getDiscount() != 0 && sortprod[i]->getStock() != 0) {
            cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getExpDate() << setw(15) << sortprod[i]->getRPrice() << setw(15) << sortprod[i]->getRPrice() * 100 / (100 - sortprod[i]->getDiscount()) << setw(15) << sortprod[i]->getDisDate() << endl;
            check = true;
        }
    }//discount 하는 것들 sorted 된대로 print
    if (!check) {
        cout << "현재 discount하는 제품 없음" << endl;
        cout << endl;
    }

} // 현재 할인중인 제품을 출력하는 함수 // 현재 할인중인 제품을 출력하는 함수

/* 현재 할인 필요(가능) 제품 출력 함수*/
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
    } //  (같은제품, 유통기한 다른거 => 다른제품 취급 : 남은 재고 수 / 전날 판매량 순으로 정렬)
    cout << endl;
    cout << "현재 discount 가능한 제품들 : " << endl;
    cout << endl;
    cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "전날판매량" << setw(15) << "유통기한" << endl;
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
                    } // expDate가 같은 제품 상에서 가장 최신꺼인지 확인
                }
            }
            if (accept) {
                cout << setw(15) << sortprod[i]->getName() << setw(15) << sortprod[i]->getStock() << setw(15) << sortprod[i]->getSalesVolume() << setw(15) << sortprod[i]->getExpDate() << endl;
                check = true;
            }
        }
    } // 남은 재고 수 >= 전날 판매량 *3 인 제품만 sorted 된대로 출력
    if (!check) {
        cout << "현재 할인 가능한 제품 없음" << endl;
        cout << endl;
    }
}

/* 할인 제품 지정 후 할인율 설정 함수*/
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
        cout << "할인 할 제품명을 입력하세요 (q : 메뉴 종료) : ";
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
        // 유통기한이 빠른 순으로 product는 정렬되어있을 가능성이 크다. 만약 그렇지 않으면 앞에 정렬 함수 추가

        if (status == -1) {
            cout << "그러한 제품명이 없습니다." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 0) {
            cout << "이미 할인 중인 제품입니다." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 1) {
            cout << "선택하신 제품명은 할인할 수 있는 제품이 아닙니다." << endl;
            system("pause");
            system("cls");
            continue;
        }
        else if (status == 2) {
            bool check = false;
            while (true) {
                string buffer;
                int percentage;
                cout << "할인할 %를 입력해주세요 (10 단위) (10 이상 90 이하) (q : 메뉴 종료)  : ";
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
                        cout << "다시 입력하세요" << endl;
                    }
                    cout << buffer << endl;
                    break;
                }
				
                if (percentage < 10 || percentage > 90) {
                    cout << "범위가 알맞지 않습니다." << endl;
                    continue;
                }
                else if (percentage % 10 != 0) {
                    cout << "10 단위로 입력해야 합니다." << endl;
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
                            cout << "다음과 같이 할인이 적용되었습니다." << endl;
                            cout << endl;
                            cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "유통기한" << setw(15) << "할인판매가" << setw(15) << "원래판매가" << setw(15) << "할인남은기간" << endl;
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

/* 마진율 변경 함수 */
void KICManager::selectMarginRate()
{
    int tempRPrice = 0;
    int tempWPrice = 0;
    int margin = 0;
    double marginRate; // 마진율
    while (true) { // 올바른 값의 마진율을 입력할때까지 무한루프
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
            cout << "현재 마진율: " << (int)(marginRate * 100) << "%" << endl;
            int temp;
            string buffer;
            cout << "변경할 마진율을 입력하세요(10% 단위의 숫자만 입력가능) : ";
            cin >> temp;
            getline(cin, buffer);

            if (cin.fail()) {
                cin.clear();
                getline(cin, buffer);
                if (buffer.compare("q") == 0) {
                    break;
                }
                else {
                    cout << "숫자를 입력해주세요." << endl;
                    system("pause");
                }
            }
            else if (temp % 10 != 0) {
                cout << "마진율은 10% 단위로 10%~90%까지 변경 가능합니다. 다시 입력해주세요." << endl;
                system("pause");
            } 
            else if (temp % 10 == 0) {
                if (10 <= temp && temp <= 90) {
                    marginRate = (double)temp / (double)100;
                    cout << "마진율이 " << (int)(marginRate * 100) << "%로 변경되었습니다." << endl;
                    system("pause");
                    break;
                }
                else {
                    cout << "마진율은 10% 단위로 10%~90%까지 변경 가능합니다. 다시 입력해주세요." << endl;
                    system("pause");
                }
            }
        }
        break;
    }
    for (int i = 0; i < count; i++) {
        if (product[i]->getDiscount() == 0 && product[i]->getStock() != 0) { // 할인을 하지않는 제품의 경우
            double changedRP = (double)product[i]->getWPrice() / (1.0 - marginRate); //  변경된 마진율 바로 적용
            product[i]->setRPrice((int)changedRP);
        }
        else if (product[i]->getDiscount() != 0 && product[i]->getStock() != 0) { // 할인 진행중인 제품의 경우
            double originRP = (double)product[i]->getWPrice() / (1.0 - marginRate); // 할인 이전 판매가에 마진율 적용
            double dcAppliedRP = originRP * ((100.0 - (double)product[i]->getDiscount()) / 100.0); // originRP에 다시 할인을 적용
            product[i]->setRPrice((int)dcAppliedRP);
        }
        // 재고가 0인 product는 이미 다 팔린 친구들이므로 아무것도 해줄 필요가 없다.  
    }
}

/* 제품 정보 추가 함수 */
void KICManager::addlist()
{
    fstream fin("defualtaddlist.txt");
    if (!fin.is_open()) {
        cerr << "파일 읽기 실패\n";
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
    cout << "================================================== < 제품 검색 > ====================================================" << endl;
    cout << setw(15) << "상품명" << setw(15) << "재고" << setw(15) << "전날판매량" << setw(15) << "유통기한" << setw(15) << "도매가" << setw(15) << "판매가" << setw(15) << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < cnt; i++) {
        cout << setw(15) << addList[i]->getName() << setw(15) << addList[i]->getStock() << setw(15) << addList[i]->getSalesVolume() << setw(15) << addList[i]->getExpDate() << setw(15) << addList[i]->getWPrice() << setw(15) << addList[i]->getRPrice() << endl;
    }

    while (true) {

        cout << "추가할 제품명을 입력하세요 : ";
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
                cout << "주문할 제품 수량을 띄어쓰기 없이 입력 : ";
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
                        cout << "숫자를 입력해주세요." << endl;
                        system("pause");
                    }
                }

                if (numOfPro <= 0) {
                    cout << "0보다 큰 숫자를 입력해주세요." << endl;
                }
                else {
                    price = addList[flag]->getWPrice() * numOfPro;
                    if (property < price) {
                        cout << "결제 금액이 부족합니다." << endl;
                        system("pause");
                    }
                    else {
                        cout << "-----------------------------------" << endl;
                        cout << "결제금액 " << addList[flag]->getWPrice() * numOfPro << "원, " << "보유금액 " << property << "원\n" << "주문하시겠습니까(q:메뉴 종료)? (y/n) ";
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
                            cout << addList[flag]->getName() << " " << numOfPro << "개 주문 완료되었습니다." << endl;
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
                            cout << "잘못 입력하셨습니다." << endl;
                            system("pause");
                            continue;
                        }
                    }
                }
            }

        }
        else {
            cout << "해당 제품이 추가 가능 리스트에 존재하지 않습니다." << endl;
        }
    }
}

/* 제품 정보 삭제 함수 */
void KICManager::removelist()
{

    fstream fin("changedaddlist.txt");
    if (!fin.is_open()) {
        cerr << "파일 읽기 실패\n";
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
        for (int i = 0; i < count; i++) { //총재고 0인거 검사 & 출력
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
        cout << "삭제할 제품명을 입력하세요 : ";
        string removeproduct;
        getline(cin, removeproduct);
        int flag = 1; //재고 0인 제품인지

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
            cout << "재고가 0인 제품이 아닙니다." << endl;
            system("pause");
			system("cls");
		}
		else {
			for (int i = 0; i < count; i++) {
				if (sortprod[i]->getStock() == 0 && ((sortprod[i]->getName().compare(removeproduct)) == 0)) {
					cout << "삭제하시겠습니까?(y/n) : ";
					string yn;
					getline(cin, yn);

					if (yn.compare("y") == 0) {
						string name = sortprod[i]->getName();
						out << *sortprod[i] << endl;

						sortprod[i]->setStock(-1);
						// product[i]->setStock(-1);

						cout << "삭제되었습니다." << endl;
						*product[i] = *sortprod[i];
						cout << product[i]->getName() << "      " << product[i]->getStock() << endl;


						system("pause");
						return;
					}
					else if (yn.compare("n") == 0) {
						cout << "삭제가 취소되었습니다." << endl;
						system("pause");
						//return;
					}
					else {
						cout << "잘못 입력하셨습니다." << endl;
						system("pause");
						//break;
					}
                }
            }
        }

        
    }
}

/* 업무 마감 함수*/
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

        if (total == 0) { //총재고 0
            isZero = true;
            cout << endl;
            cout << sortprod[i]->getStock() << endl;
            cout << sortprod[i]->getName() << endl;
        }
    }
    if (isZero == true) {
        cout << count << endl;
        cout << "총 재고가 0인 제품이 존재하므로 업무 마감이 불가능합니다." << endl;
        system("pause");
        return;
    }
    else if (isZero == false) {
        cout << "업무를 마감합니다." << endl;
        deleteArray();
        randomSV(); // 제품별 랜덤 판매량 지정
        searchScrap();      // 할인 마감 제품 판매가 복구 및 남은 할인 날짜 조정, 폐기 제품 판별 및 남은 유통기한 조정
        setDate();
        cout << "다음날 영업으로 넘어갑니다..." << endl;
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

/* 폐기 제품 판별 후 폐기, 남은 유통기한 조정 함수*/
void KICManager::searchScrap()
{
    financeCalculate(); // 당일 판매된 제품 재고 조정, 당일 매출, 순이익, 현재 보유 자산 출력

    /*할인 마감 제품 판매가 복구 및 남은 할인 날짜 조정*/
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

    /*폐기 제품 판별 및 남은 유통기한 조정*/
    int numOfScrapProds = 0;
    cout << "-----------------※※폐기 알림※※-----------------" << endl;
    for (int i = 0; i < count; i++) {
        if (product[i]->getExpDate() <= 1 && product[i]->getStock() > 0) { // 유통기한이 0일이고 남은 재고가 0이 아닌 제품의 경우 폐기해줘야 한다. // 삭제한제품의경우 재고를 -1로 만들어줬기때문에 0보다 큰 경우로 변경
            numOfScrapProds++;
            cout << numOfScrapProds << ") " << product[i]->getName() << " " << product[i]->getStock() << "개 폐기" << endl;
            product[i]->setExpDate(0);
            product[i]->setStock(0);
        }
        else if (product[i]->getExpDate() >= 2 && product[i]->getStock() != 0) { // 유통기한이 만료되지 않은 제품의 경우 유통기한을 1일 감소시켜준다.
            product[i]->setExpDate(product[i]->getExpDate() - 1);
        }
    }
    if (numOfScrapProds == 0) {
        cout << "오늘은 폐기된 제품이 없습니다." << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

/* 판매된 제품 재고량 조정, 당일 매출과 순이익 계산 후 출력 */
void KICManager::financeCalculate()
{
    int tempStock = 0;
    int tempSalesVolume; // 제품의 당일 판매량
    int remainSV = 0;
    int tempWPrice = 0;
    int tempRPrice = 0;
    int todaySales = 0; // 당일 매출액 합계
    int todayProfits = 0; // 당일 순이익 합계
    for (int i = 0; i < count; i++) {
        if (product[i]->getStock() != 0 && product[i]->getExpDate() != 0) {
            tempStock = product[i]->getStock();
            tempSalesVolume = product[i]->getSalesVolume();
            tempWPrice = product[i]->getWPrice();
            tempRPrice = product[i]->getRPrice();

            if (tempStock < tempSalesVolume) { // 제품의 판매량이 남은 재고 수보다 많을 경우
                string remainPN = product[i]->getName();
                todaySales = calTodaySales(todaySales, tempStock, tempRPrice);  // 제품의 당일 매출액 계산 후 합계에 더해주기
                todayProfits = calTodayProfits(todayProfits, tempStock, tempRPrice, tempWPrice); // 제품의 당일 순이익 계산 후 합계에 더해주기
                product[i]->setStock(0);
                product[i]->setExpDate(0);
                product[i]->setIsStockDeclined(true);
                remainSV = tempSalesVolume - tempStock; // 남은 판매량

                for (int j = 0; j < count; j++) {
                    if (i != j) {
                        if (remainPN.compare(product[j]->getName()) == 0 && product[j]->getStock() > 0) { // 1번째 재고가 남은 동일 제품 객체 탐색 
                            if (product[j]->getStock() < remainSV) { // 제품의 남은 재고 수보다 remainSV가 많을 경우
                                todaySales = calTodaySales(todaySales, product[j]->getStock(), tempRPrice);
                                todayProfits = calTodayProfits(todayProfits, product[j]->getStock(), tempRPrice, tempWPrice);
                                remainSV = remainSV - product[j]->getStock();
                                product[j]->setStock(0);
                                product[j]->setExpDate(0);
                                product[j]->setIsStockDeclined(true);

                                for (int k = 0; k < count; k++) {   // 2번째 재고가 남은 동일 제품 객체 탐색
                                    if (i != k && j != k) {
                                        if (remainPN.compare(product[k]->getName()) == 0 && product[k]->getStock() > 0) {
                                            if (product[k]->getStock() < remainSV) { // 제품의 남은 재고 수보다 remainSV가 많을 경우
                                                todaySales = calTodaySales(todaySales, product[k]->getStock(), tempRPrice);
                                                todayProfits = calTodayProfits(todayProfits, product[k]->getStock(), tempRPrice, tempWPrice);
                                                product[k]->setStock(0);
                                                product[k]->setExpDate(0);
                                                product[k]->setIsStockDeclined(true);
                                                /* 동일제품은 최대 3회만 주문 가능하므로 여기서 끝 */
                                            }
                                            else { // // 제품의 남은 재고 수가 remainSV보다 많은 경우
                                                todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                                todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                                product[k]->setStock(product[k]->getStock() - remainSV);
                                                product[k]->setIsStockDeclined(true);
                                            }
                                        }
                                    }
                                }
                            }
                            else { // 제품의 남은 재고수가 remainSV보다 많은 경우
                                todaySales = calTodaySales(todaySales, remainSV, tempRPrice);
                                todayProfits = calTodayProfits(todayProfits, remainSV, tempRPrice, tempWPrice);
                                product[j]->setStock(product[j]->getStock() - remainSV);
                                product[j]->setIsStockDeclined(true);
                            }
                        }
                    }
                }
            }
            else { // 제품의 남은 재고 수가 판매량보다 많을 경우
                if (product[i]->getIsStockDeclined() == false) {
                    todaySales = calTodaySales(todaySales, tempSalesVolume, tempRPrice); // 제품의 매출액 계산 후 합계에 더해주기
                    todayProfits = calTodayProfits(todayProfits, tempSalesVolume, tempRPrice, tempWPrice); // 제품의 순이익 계산 후 합계에 더해주기
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
    cout << "당일 매출 :" << todaySales << "원" << endl;
    cout << "당일 순이익 :" << todayProfits << "원" << endl;
    cout << "보유 자산 :" << property << "원" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        product[i]->setIsStockDeclined(false);
    }
}

/* 판매량 변화 랜덤 알고리즘 함수 */
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
            int amountOfChange;                      // 판매량의 변화량.
            int plusOrMinus = (dis(gen) + dis(gen)) % 2; // 난수 두개 더해서 2로 나눈 나머지가 0이면 판매량 증가, 1이면 판매량 감소.

            if (tempSalesVolume >= 0 && tempSalesVolume <= 5) {
                amountOfChange = (dis(gen) % 2);
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