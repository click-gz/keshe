#include<iostream>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include "Personlocal.h"
#include"Code.h"
using namespace std;
Personlocal::Personlocal()
{
	char p[20] = "���ؾ���";
	strcpy_s(person.place, p);
}

void Personlocal::creat()
{
	while (true) {
		cout << "������������" << endl;
		cin >> person.name;
		cout << "���������䣺" << endl;
		cin >> person.age;
		cout << "������绰���룺" << endl;
		cin >> person.telephone;
		cout << "�������Ա�(F/M)��" << endl;
		cin >> s;
		if (s != 'F' && s != 'M') {
			cout << "����ȷ�����Ա𣡣���";
			continue;
		}
		cout << "������ְ��(W/C):" << endl;
		cin >> w;
		if (w != 'W' && w != 'C') {
			cout << "����ȷ����ְ�񣡣���" << endl;
			continue;
		}
		person.sex = s;
		person.work = w;
		break;
	}
}

Personlocal::~Personlocal()
{
	Code expcd;
	strcpy_s(person.Personcode, expcd.getcode());
	fstream L("Personlocal.dat", ios::app | ios::binary);
	if (!L) {
		cout << "��Personlocal.dat�ļ�ʧ��" << endl;
		exit(0);
	}
	L.write((char*)&person, sizeof(person));
	L.close();
	cout << "��Ǻ��Լ��ĵǼ��룺" << person.Personcode << endl;
	cout << "�����������...";
	char chh = getchar();
	system("cls");
}
