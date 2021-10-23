
#include "KICmanager.h"

void KICManager::sortStock()
{
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

KICManager::KICManager()
{
}

KICManager::~KICManager()
{
}

void KICManager::start()
{
    while (true) {
        string date, result;
        cout << "시작 날짜 입력 : ";
        getline(cin, date);
        result = checkDate(date);
        
        if (finalCheck) {
            todayDate = result;

            cout << todayDate << endl;
            break;
        }
        else
            continue;

    }

    printMenu();
}

// 날짜 입력 예외처리
string KICManager::checkDate(string date)
{
    int year = 0, month = 0, day = 0;
    bool dateCheck = false, letterCheck = false;
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

    while (true) {
        int z = 0;

        if (date[0] == ' ') {
            cout << "잘못된 입력입니다. 선행 공백을 허용하지 않습니다." << endl;
            return NULL;
        }

        // 011028 같이 숫자 6자리
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

        // 20201028    01-10-28
        else if (date.length() == 8) {

            a = date[0];
            b = date[1];
            c = date[2];
            d = date[3];
            e = date[4];
            f = date[5];
            g = date[6];
            h = date[7];

            // 20011028
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

            // 01-10-28
            else if (date.find("-") != string::npos || date.find("/") != string::npos
                || date.find(".") != string::npos || date.find("_") != string::npos) {

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
                else {
                    dateCheck = false;
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
                    string finalDate;
                    for (int k = 0; k < 2; k++) {
                        finalDate[0] += date[k];
                    }
                    for (int k = 3; k < 5; k++) {
                        finalDate[1] += date[k];
                    }
                    for (int k = 6; k < 8; k++) {
                        finalDate[2] += date[k];
                    }
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
        }

        // 2021-03-29
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
                        string finalDate;
                        for (int k = 0; k < 4; k++) {
                            finalDate[0] += date[k];
                        }
                        for (int k = 5; k < 7; k++) {
                            finalDate[1] += date[k];
                        }
                        for (int k = 8; k < 10; k++) {
                            finalDate[2] += date[k];
                        }
                        date = finalDate[0] + finalDate[1] + finalDate[2];
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

            }
        }

        else {
        cout << "날짜를 올바르게 입력하세요." << endl;
        return NULL;       
    }
}

int KICManager::getProperty()
{
    return property;
}

void KICManager::setProperty(int p)
{
    property = p;
}

int KICManager::randomSales()
{
    return 0;
}

void KICManager::init()
{

}


void KICManager::printMenu()
{

}

void KICManager::addOrder()
{
}

void KICManager::discountPrice()
{
}

void KICManager::changePrice()
{
}

void KICManager::noStockAlarm()
{
}