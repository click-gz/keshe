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
	cout << "����ʣ��������" << n << endl;
	store.close();
	int j = n / num_patient;
	cout << num_patient << endl;
	if (j == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//���ú�ɫ
		cout << "���ֲ�����֧���䷢��ȫ���Ĳ��ˣ��뼰ʱ��ӿ��֣���" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
		
	}
	else {
		cout << "���ֻ����Թ���" << j << "��" << endl;
	}
	j = Respiratornum - num_patient;
	if (j < 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		//���ú�ɫ
		cout << "�������������в���ʹ�ã���������" << -j << "̨" << endl;
		cout << "�뼰ʱ�������������������" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
	}
}

void Store::add_num()
{
	Checkcin ccin;
	cout << "��ѡ����ӿ��ֻ��Ǻ�����" << endl;
	cout << "��ѡ����ӿ���������:M\r��ѡ����Ӻ�����������:R" << endl;
	char ch;
	ch = ccin.CheckchStore();
	if (ch == 'M') {
		int n;
		cout << "��������ӵĿ��ֵ�������" << endl;
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
		cout << "��������ӵĺ�������������" << endl;
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
	cout << "��������˳�..." << endl;
	char chhhh = getchar();
	system("cls");
}

void Store::del_Masknum()
{
	int chk = 0;
	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	time(&now);      //��ȡϵͳ���ں�ʱ��
	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
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
	cout << "����ʣ�ࣺ" << Masknum << "��" << endl;
	cout << "������ʣ�ࣺ" << Respiratornum << "̨" << endl;
}
#endif // !E