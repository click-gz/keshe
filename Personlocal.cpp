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
	char p[20] = "���ؾ���";
	strcpy_s(person.place, p);
}

void Personlocal::creat()
{
	Checkcin ccin;
	cout << "������������" << endl;
	cin >> person.name;
	cout << "���������䣺" << endl;
	cin >> person.age;
	cout << "������绰���룺" << endl;
	cin >> person.telephone;
	cout << "�������Ա�(F/M)��" << endl;
	person.sex = ccin.Checksex();
	cout << "������ְ��(W/C):" << endl;
	person.work = ccin.Checkwork();
	Code expcd;
	strcpy_s(person.Personcode, expcd.getcode());
	cout << "��Ǻ��Լ��ĵǼ��룺" << person.Personcode << endl;
	cout << "�����������...";
	char chh = getchar();
	system("cls");
}

Personlocal::~Personlocal()
{
	fstream L("Personlocal.dat", ios::app | ios::binary);
	if (!L) {
		cout << "��Personlocal.dat�ļ�ʧ��" << endl;
		exit(0);
	}
	L.write((char*)&person, sizeof(person));
	L.close();
	cout << "�����������...";
	char chh = getchar();
	system("cls");
}
