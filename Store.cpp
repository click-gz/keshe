#ifndef E
#define E


#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include "Store.h"
#include"Checkcin.h"	

using namespace std;

Store::Store()
{
	getnum_patient();
	fstream store("store.txt", ios::in);
	if (!store) {
		fstream s("store.txt", ios::out);
		s << Masknum << endl;
		s << Respiratornum;
		s.close();
	}
	else {
		store >> Masknum;
		store >> Respiratornum;
		store.close();
	}
}

Store::~Store()
{
	fstream store("store.txt", ios::out);
	if (!store) {
		cout << "can not open this file!" << endl;
		exit(0);
	}
	store << Masknum << endl;
	store << Respiratornum;
	store.close();
}

void Store::check_Masknum()
{
	fstream store("store.txt", ios::in);
	if (!store) {
		cout << "can not open this file!" << endl;
		exit(0);
	}
	int n;
	store >> n;
	cout << "口罩剩余数量：" << n << endl;
	store.close();
	int j = n / num_patient;
	cout << num_patient << endl;
	if (j == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//设置红色
		cout << "口罩不足以支持配发给全部的病人，请及时添加口罩！！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
		
	}
	else {
		cout << "口罩还足以供给" << j << "天" << endl;
	}
	j = Respiratornum - num_patient;
	if (j < 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//设置红色
		cout << "呼吸机不够现有病人使用！！！还差" << -j << "台" << endl;
		cout << "请及时补充呼吸机数量！！！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
	}
}

void Store::add_num()
{
	Checkcin ccin;
	cout << "请选择添加口罩或是呼吸机" << endl;
	cout << "若选择添加口罩请输入:M\r若选择添加呼吸机请输入:R" << endl;
	char ch;
	ch = ccin.CheckchStore();
	if (ch == 'M') {
		int n;
		cout << "请输入添加的口罩的数量：" << endl;
		cin >> n;
		fstream store("store.txt", ios::in);
		if (!store) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		store >> Masknum;
		Masknum += n;
		store.close();
		fstream s("store.txt", ios::out);
		if (!s) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		s << Masknum << endl;
		s << Respiratornum;
		s.close();
	}
	else {
		int n;
		cout << "请输入添加的呼吸机的数量：" << endl;
		cin >> n;
		fstream store("store.txt", ios::in);
		if (!store) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		store >> Respiratornum;
		store >> Respiratornum;
		Respiratornum += n;
		store.close();
		fstream s("store.txt", ios::out);
		if (!s) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		s << Masknum << endl;
		s << Respiratornum;
		s.close();
	}
	cout << "按任意键退出..." << endl;
	char chhhh = getchar();
	system("cls");
}

void Store::del_Masknum()
{
	int chk = 0;
	struct tm t;   //tm结构指针
	time_t now;  //声明time_t类型变量
	time(&now);      //获取系统日期和时间
	localtime_s(&t, &now);   //获取当地日期和时间
	fstream Tdd("Takedate.dat", ios::in|ios::binary);
	Td exTd;
	if (!Tdd) {
		fstream Tddd("Takedate.dat", ios::out|ios::binary);
		exTd.Y = t.tm_year + 1990;
		exTd.M = t.tm_mon+1;
		exTd.D = t.tm_mday;
		Tddd.write((char*)&exTd, sizeof(exTd));
		Tddd.close();
		chk = 1;
	}
	else {
		chk = 1;
		Tdd.read((char*)&exTd, sizeof(exTd));
		while (!Tdd.eof()) {
			if ((exTd.Y == t.tm_year + 1990) && (exTd.M == t.tm_mon + 1) && (exTd.D == t.tm_mday)) {
				chk = 0;
				break;
			}
		}
		Tdd.close();
	}
	if (chk == 1) {
		fstream store("store.txt", ios::in);
		if (!store) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		store >> Masknum;
		cout << num_patient << endl;
		Masknum -= num_patient;
		store.close();
		fstream s("store.txt", ios::out);
		if (!s) {
			cout << "can not open this file!" << endl;
			exit(0);
		}
		s << Masknum << endl;
		s << Respiratornum;
		s.close();
		fstream Tddd("Takedate.dat", ios::out | ios::binary);
		exTd.Y = t.tm_year + 1990;
		exTd.M = t.tm_mon + 1;
		exTd.D = t.tm_mday;
		Tddd.write((char*)&exTd, sizeof(exTd));
		Tddd.close();
	}
}
void Store::show()
{
	cout << "口罩剩余：" << Masknum << "个" << endl;
	cout << "呼吸机剩余：" << Respiratornum << "台" << endl;
}
#endif // !E