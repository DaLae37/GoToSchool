#pragma once
#include "ZeroIScene.h"
#include "ZeroApplication.h "
#include <iostream>
#include <string>
#include <fstream>
#define MAIN_PRICE 6000
#define SIDE_PRICE 4000
#define CAFE_PRICE 8000
#define GYM_PRICE 9000
class DataManager : public ZeroIScene
{
public:
	DataManager();
	~DataManager();
	void Reload();
	void Save();
	void Reset();
	void Entrance();
	void Graduate();
	void EndTurn();
	void EndYear();
	int endMoney;
	int Dupmoney;
	int Dmoney;
	int Dday;
	int Dhappy;
	int Dpeople;
	int Dfirst;
	int Dsecond;
	int Dthird;
	int Dpolicy[6];
	int Devent[2];
	int Dcon[5];
	int Dncon[5];
	int Dcanp;
};