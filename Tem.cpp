#include<iostream>
#include<string.h>
#include<fstream>
#include<ctime>
#include"windows.h"
#include "Tem.h"
#include"Peosonin.h"
#include"Checkcin.h"
using namespace std;

void Tem::getTname(char n[10])
{
	strcpy_s(extem.name, n);
	cout << "请输入个人登记码" << endl;
	cout << extem.name << ":  ";
	cin >> extem.percode;
}

void Tem::getTdate()
{
	date d;
	d.setdate();
	extem.Tdate.year = d.getdate()->year;
	extem.Tdate.month = d.getdate()->month;
	extem.Tdate.day = d.getdate()->day;
}

void Tem::getTTdate(int y, int m, int d)
{
	extem.Tdate.year = y;
	extem.Tdate.month = m;
	extem.Tdate.day = d;
}

void Tem::gettemp()
{
	cout << "请输入今日的体温测量度数：" << endl;
	cin >> extem.temp;
	if (extem.temp >= 37.3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//设置红色
		cout << "体温过高，请配合医院进行核酸检测！！！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
	}
	cout << "按任意键继续...";
	char ch = getchar();
	system("cls");
}

void Tem::savetemp()
{
	fstream T("temperature.dat", ios::app | ios::binary);
	if (!T) {
		cout << "打开temperature.dat失败！！！" << endl;
		exit(0);
	}
	T.write((char*)&extem, sizeof(extem));
	T.close();
}

void Tem::dairyTcheck()
{
	system("mode con cols=60 lines=20  ");
	int k = 0;
	time_t now;
	time(&now);
	struct tm ex; 
	localtime_s(&ex,&now);
	cout << "今日日期为：" << 1900 + ex.tm_year << "-";
	cout << 1 + ex.tm_mon << "-";
	cout << ex.tm_mday << endl;
	fstream T("temperature.dat", ios::in | ios::binary);
	if (!T) {
		cout << "打开temperature.dat失败！！！" << endl;
		exit(0);
	}
	cout << "今日，外来人员中还未测量体温的有:" << endl;
	fstream in("personin.dat", ios::in | ios::binary);
	if (!in) {
		cout << "打开personin.dat文件失败！！！" << endl;
		exit(0);
	}
	allperson indairyT;
	in.read((char*)&indairyT, sizeof(indairyT));
	while (!in.eof()) {
		int i = 0;
		Record_Tem dairyT;
		T.read((char*)&dairyT, sizeof(dairyT));
		while (!T.eof()) {
			if (strcmp(dairyT.name, indairyT.name) == 0) {
				if (dairyT.Tdate.year == (1900 + ex.tm_year) && dairyT.Tdate.month == (1 + ex.tm_mon) && dairyT.Tdate.day == ex.tm_mday) {
					i = 1;
					break;
				}
			}
			T.read((char*)&dairyT, sizeof(dairyT));
		}
		T.close();
		if (i == 0) {
			cout << indairyT.name << "：" << indairyT.Personcode << endl;
			k++;
			if (k % 7 == 0) {
				cout << "按任意键继续...";
				char chh = getchar();
				system("cls");
				cout << "今日，本地人员中还未测量体温的有:" << endl;
			}
		}
		in.read((char*)&indairyT, sizeof(indairyT));
	}
	in.close();
	if (k == 0) {
		cout << "0人" << endl;
	}
	else {
		cout << endl;
		cout << "请及时安排体温检查！！！" << endl;
	}
	k = 0;
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
	cout << "今日，本地人员中还未测量体温的有:" << endl;
	fstream local("Personlocal.dat", ios::in | ios::binary);
	if (!local) {
		cout << "打开Personlocal.dat文件失败！！！" << endl;
		exit(0);
	}
	local.read((char*)&indairyT, sizeof(indairyT));
	while (!local.eof()) {
		int i = 0;
		Record_Tem dairyT;
		T.read((char*)&dairyT, sizeof(dairyT));
		while (!T.eof()) {
			if (strcmp(dairyT.name, indairyT.name) == 0) {
				if (dairyT.Tdate.year == (1900 + ex.tm_year) && dairyT.Tdate.month == (1 + ex.tm_mon) && dairyT.Tdate.day == ex.tm_mday) {
					i = 1;
					break;
				}
			}
			T.read((char*)&dairyT, sizeof(dairyT));
		}
		T.close();
		if (i == 0) {
			cout << indairyT.name << "：" << indairyT.Personcode << endl;
			k++;
			if (k % 7==0) {
				cout << "按任意键继续...";
				char chh = getchar();
				system("cls");
				cout << "今日，本地人员中还未测量体温的有:" << endl;
			}
		}
		local.read((char*)&indairyT, sizeof(indairyT));
	}
	local.close();
	if (k == 0) {
		cout << "0人" << endl;
	}
	else {
		cout << endl;
		cout << "请及时安排体温检查！！！" << endl;
	}
	cout << "按任意键继续...";
	chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
