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
	cout << "��������˵Ǽ���" << endl;
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
	cout << "��������յ����²���������" << endl;
	cin >> extem.temp;
	if (extem.temp >= 37.3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//���ú�ɫ
		cout << "���¹��ߣ������ҽԺ���к����⣡����" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
	}
	cout << "�����������...";
	char ch = getchar();
	system("cls");
}

void Tem::savetemp()
{
	fstream T("temperature.dat", ios::app | ios::binary);
	if (!T) {
		cout << "��temperature.datʧ�ܣ�����" << endl;
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
	cout << "��������Ϊ��" << 1900 + ex.tm_year << "-";
	cout << 1 + ex.tm_mon << "-";
	cout << ex.tm_mday << endl;
	fstream T("temperature.dat", ios::in | ios::binary);
	if (!T) {
		cout << "��temperature.datʧ�ܣ�����" << endl;
		exit(0);
	}
	cout << "���գ�������Ա�л�δ�������µ���:" << endl;
	fstream in("personin.dat", ios::in | ios::binary);
	if (!in) {
		cout << "��personin.dat�ļ�ʧ�ܣ�����" << endl;
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
			cout << indairyT.name << "��" << indairyT.Personcode << endl;
			k++;
			if (k % 7 == 0) {
				cout << "�����������...";
				char chh = getchar();
				system("cls");
				cout << "���գ�������Ա�л�δ�������µ���:" << endl;
			}
		}
		in.read((char*)&indairyT, sizeof(indairyT));
	}
	in.close();
	if (k == 0) {
		cout << "0��" << endl;
	}
	else {
		cout << endl;
		cout << "�뼰ʱ�������¼�飡����" << endl;
	}
	k = 0;
	cout << "�����������...";
	char chh = getchar();
	system("cls");
	cout << "���գ�������Ա�л�δ�������µ���:" << endl;
	fstream local("Personlocal.dat", ios::in | ios::binary);
	if (!local) {
		cout << "��Personlocal.dat�ļ�ʧ�ܣ�����" << endl;
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
			cout << indairyT.name << "��" << indairyT.Personcode << endl;
			k++;
			if (k % 7==0) {
				cout << "�����������...";
				char chh = getchar();
				system("cls");
				cout << "���գ�������Ա�л�δ�������µ���:" << endl;
			}
		}
		local.read((char*)&indairyT, sizeof(indairyT));
	}
	local.close();
	if (k == 0) {
		cout << "0��" << endl;
	}
	else {
		cout << endl;
		cout << "�뼰ʱ�������¼�飡����" << endl;
	}
	cout << "�����������...";
	chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
