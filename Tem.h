#pragma once
//记录体温
#include"date.h"
struct Record_Tem {
	char name[10];
	float temp;
	int percode;
	struct Date Tdate;
};
class Tem {
protected:
	Record_Tem extem;
public:
	void getTname(char n[10]);
	void getTdate();
	void getTTdate(int y=0,int m=0,int d=0);
	void gettemp();
	void savetemp();
	void dairyTcheck();//日常体温检查
};