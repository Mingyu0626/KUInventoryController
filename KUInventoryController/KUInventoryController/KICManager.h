#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "KICProduct.h"
#include <fstream>
#include <random>
#include "KICProduct.h"
#include <conio.h>
#include <Windows.h>
#include<iomanip>
#include <algorithm>
#include <typeinfo>
#include <fstream>

using namespace std;

class KICManager
{
	int property = 1000000;         // 보유 자산
	string todayDate;            // 날짜
	int balance;                    // 보유 잔액
	int count = 0;               // 최초로 텍스트 파일에서 제품 정보들을 가져올 때, 제품의 개수
	KICProduct** product = nullptr; // 제품 정보를 담는 동적 1차원 배열

	KICProduct** sortprod = nullptr; //정렬 위한 동적 1차원 배열
  //   KICProduct** fixedprod = nullptr; //기존 정보를 담고있는 동적 1차원 배열(고정됨)

	void init();                                       // 텍스트 파일 읽어오기   

	/*----- 5. 시작 화면 및 메인 화면-----*/
	bool finalCheck = false;                                 // checkDate(string date)의 정상적인 작동 여부 확인 
	string checkDate(string date);                              // 날짜 입력 예외 처리를 통해 8자리 숫자(ex 20211023) 형식의 string 형성
	vector<string> split(string str, char delimiter);               // 특수 문자에 따른 string 분할

	void printMenu();                                    // 메인 화면의 메뉴 출력
	void noStockAlarm();                                 // 재고 부족 알림
	void setDate();                                       // 업무 마감 시 다음날로 날짜 이동(폐기 처리한 후 실행하기)
	void printDate();                                    // 상단에 날짜 출력하는 함수
	bool loadInfor();                                    // 텍스트 파일에 저장되어 있는 정보를 불러오는 함수 

	/*----- 6.1 제품 주문 -----*/
	void addOrder();                                       // 주문 추가

	/*----- 6.2 제품 검색 -----*/
	void searchProds();                                       // 제품 검색
	void sortStock();                                       // 정렬_재고순
	void sortDate();                                    // 정렬_유통기임박순
	void sortAl();                                          // 정렬_ㄱㄴㄷ순

	/*----- 6.3 판매가 지정-----*/
	void discountProds();												// 현재 할인중인 제품 출력
	void discountReqProds();											// 할인이 필요한 제품 판별
	void selectDiscountProds();											// 할인 제품 지정
	void selectMarginRate();											// 마진율 지정
	
	/*----- 6.4 추가/삭제 -----*/
	void addlist();														//제품 추가
	void removelist();													//제품 삭제

	/*----- 6.5 업무 마감 -----*/
	void closingWork();													// 당일 업무 마감
	void searchScrap();													// 폐기 제품을 판별 후 출력
	void financeCalculate();											// 재정 상황 출력(당일sear 매출, 당일 순이익, 보유 자산)
	void randomSV();													// 판매량을 랜덤 알고리즘에 의해 지정
	int calTodaySales(int ts, int sorsv, int rp);
	int calTodayProfits(int tp, int sorsv, int rp, int wp);

	/*----- 6.6 프로그램 종료 -----*/

	/*----- 6.7 getter. setter -----*/
	int getProperty();
	void setProperty();


public:
	KICManager();
	~KICManager();
	void start();
};