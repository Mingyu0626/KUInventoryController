#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include "KICProduct.h"

using namespace std;

class KICManager
{
	int property = 1000000;			// 보유 자산
	string todayDate;				// 날짜
	int count = 0;					// 최초로 텍스트 파일에서 제품 정보들을 가져올 때, 제품의 개수
	KICProduct** product = nullptr; // 제품 정보를 담는 동적 1차원 배열


	void init();													// 텍스트 파일 읽어오기	

	/*----- 5. 시작 화면 및 메인 화면-----*/
	void start();
	bool finalCheck = false;
	string checkDate(string date);
	vector<string> split(string str, char delimiter);

	void printMenu();												// 메인 화면의 메뉴 출력
	void noStockAlarm(KICProduct** kicp[]);							// 재고 부족 알림

	/*----- 6.1 제품 주문 -----*/
	void addOrder();												// 주문 추가

	/*----- 6.2 제품 검색 -----*/
	void searchProds();												// 제품 검색
	void sortStock();												// 정렬

	/*----- 6.3 판매가 지정-----*/
	void changePrice();												// 판매가 지정
	void discountProds(KICProduct** kicp[]);						// 현재 할인중인 제품 출력
	void discountReqProds(KICProduct** kicp[]);						// 할인이 필요한 제품 판별
	void selectDiscountProds(KICProduct** kicp[]);					// 할인 제품 지정
	void selectMarginRate(KICProduct** kicp[]);						// 마진율 지정


	/*----- 6.4 업무 마감 -----*/
	void closingWork();												// 업무 마감
	void searchScrap(KICProduct** kicp[]);							// 폐기 제품을 판별 후 출력
	void printFinance();											// 재정 상황 출력(당일 매출, 당일 순이익, 보유 자산)
	void randomSV(KICProduct** kicp[]);								// 판매량을 랜덤 알고리즘에 의해 지정


public:
	KICManager();
	~KICManager();
	int getProperty();
	void setProperty();
};