#include<iostream>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include "Personlocal.h"
#include"Code.h"
#include"Checkcin.h"
using namespace std;
Personlocal::Personlocal()
{
	char p[20] = "本地居民";
	strcpy_s(person.place, p);
}

void Personlocal::creat()
{
	Checkcin ccin;
	cout << "请输入姓名：" << endl;
	cin >> person.name;
	cout << "请输入年龄：" << endl;
	cin >> person.age;
	cout << "请输入电话号码：" << endl;
	cin >> person.telephone;
	cout << "请输入性别(F/M)：" << endl;
	person.sex = ccin.Checksex();
	cout << "请输入职务(W/C):" << endl;
	person.work = ccin.Checkwork();
	Code expcd;
	strcpy_s(person.Personcode, expcd.getcode());
	cout << "请记好自己的登记码：" << person.Personcode << endl;
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
}

Personlocal::~Personlocal()
{
	fstream L("Personlocal.dat", ios::app | ios::binary);
	if (!L) {
		cout << "打开Personlocal.dat文件失败" << endl;
		exit(0);
	}
	L.write((char*)&person, sizeof(person));
	L.close();
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
}
