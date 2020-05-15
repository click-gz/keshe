#include<iostream>
#include<time.h>
#include "date.h"
using namespace std;
date::date()
{
	year = 0;
	month = 0;
	day = 0;
}
void date::setdate()
{
	while (true) {
		cout << "请输入年月日，空格间隔" << endl;
		cin >> year;
		cin >> month;
		if (month < 1 || month>12) {
			cout << "月份输入有错，请正确输入！！！" << endl;
			continue;
		}
		cin >> day;
		if (day < 0 || day>32) {
			cout << "日期输入有错，请正确输入！！！" << endl;
			continue;
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (month == 2) {
				if (day > 29) {
					cout << "日期输入有误，请正确输入！！！" << endl;
					continue;
				}
			}
		}
		else {
			if (month == 2) {
				if (day > 28) {
					cout << "日期输入有误，请正确输入！！！" << endl;
					continue;
				}
			}
		}
		d.year = year;
		d.month = month;
		d.day = day;
		break;
	}
}

void date::todaydate()
{
	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间
	cout << "本地时间：		" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << endl;
}

Date* date::getdate()
{
	return &d;
}
