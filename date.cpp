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
		cout << "�����������գ��ո���" << endl;
		cin >> year;
		cin >> month;
		if (month < 1 || month>12) {
			cout << "�·������д�����ȷ���룡����" << endl;
			continue;
		}
		cin >> day;
		if (day < 0 || day>32) {
			cout << "���������д�����ȷ���룡����" << endl;
			continue;
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (month == 2) {
				if (day > 29) {
					cout << "����������������ȷ���룡����" << endl;
					continue;
				}
			}
		}
		else {
			if (month == 2) {
				if (day > 28) {
					cout << "����������������ȷ���룡����" << endl;
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
	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	time(&now);      //��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
	cout << "����ʱ�䣺		" << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << endl;
}

Date* date::getdate()
{
	return &d;
}
