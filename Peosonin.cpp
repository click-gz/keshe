#ifndef D
#define D
#include<iostream>
#include<fstream>
#include "Peosonin.h"
#include<ctime>
#include<Windows.h>
#include"Checkcin.h"
#include"Code.h"

using namespace std;

Personin Personin::operator++()
{
	++num;
	cout << "������Ϊ��" << num << endl;
	return *this;
}

void Personin::creat()
{
	Checkcin ccin;
	char ch;
	cout << "�����������Ա������" << endl;
	cin >> person.name;
	cout << "�����������Ա���䣺" << endl;
	cin >> person.age;
	cout << "�����������Ա�绰���룺" << endl;
	cin >> person.telephone;
	cout << "�����������Ա�Ա�(F/M)��" << endl;
	person.sex =ccin.Checksex();
	cout << "�����������Ա��ְ��(W/C):" << endl;
	person.work=ccin.Checkwork();
	cout << "�����������Ա��Դ�أ�" << endl;
	cin >> person.place;
	cout << "�Ƿ�;������������(�人)(y/n):" << endl;
	ch=ccin.Checkchmain();
	if (ch == 'y') {
		fstream file("Apersonin.txt", ios::app);
		if (!file) {
			cout << "��Apersonin.txt�ļ�ʧ�ܣ���" << endl;
			exit(0);
		}
		file << person.name << endl;
		file.close();
	}
}

void Personin::getdate()
{
	date indate;
	indate.setdate();
	person.dat.year = indate.getdate()->year;
	person.dat.month = indate.getdate()->month;
	person.dat.day = indate.getdate()->day;
}

void Personin::savepersonin()
{
	Code expcd;
	strcpy_s(person.Personcode, expcd.getcode());
	fstream f("personin.dat", ios::app | ios::binary);
	if (!f) {
		cout << "���ļ�personin.datʧ�ܣ�" << endl;
		exit(0);
	}
	f.write((char*)&person, sizeof(person));
	f.close();
	cout << "��Ǻø��˵ĵǼ��룺" << person.Personcode << endl;
	Sleep(1000);
	system("cls");
}
void Personin::getTem()
{
	int y = person.dat.year, m = person.dat.month, d = person.dat.day;
	Tem PT;
	PT.getTname(person.name);
	PT.getTTdate(y,m,d);
	PT.gettemp();
	PT.savetemp();
}
void Personin::limitday()
{
	int i = 0;
	system("mode con cols=50 lines=20  ");
	time_t now;
	time(&now);
	struct tm ex;
	localtime_s(&ex, &now);
	fstream in("personin.dat", ios::in | ios::binary);
	if (!in) {
		cout << "��personin.dat�ļ�ʧ�ܣ�����" << endl;
		exit(0);
	}
	allperson temp;
	in.read((char*)&temp, sizeof(temp));
	while (!in.eof()) {
		if (ex.tm_year + 1900 - temp.dat.year>=2) {
			cout << "������" << temp.name << endl;
			cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
			cout << "�Ѹ���14�������������������" << endl;
			cout << endl;
			i++;
			if (i == 4) {
				cout << "�����������...";
				char chh = getchar();
				system("cls");
				i = 0;
			}
			in.read((char*)&temp, sizeof(temp));
			continue;
		}
		else if ((ex.tm_year + 1900) - temp.dat.year == 1) {
			if (ex.tm_mon + 1 == 1 && temp.dat.month == 12) {
				if (31 - temp.dat.day + ex.tm_mday - 1 >= 14) {
					cout << "������" << temp.name << endl;
					cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "�Ѹ���14�������������������" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "�����������...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
				else {
					cout << "������" << temp.name << endl;
					cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "����δ�����ޣ�����" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "�����������...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
			}
			else {
				cout << "������" << temp.name << endl;
				cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
				cout << "�Ѹ���14�������������������" << endl;
				cout << endl;
				i++;
				if (i == 4) {
					cout << "�����������...";
					char chh = getchar();
					system("cls");
					i = 0;
				}
				in.read((char*)&temp, sizeof(temp));
				continue;
			}
		}
		else if ((ex.tm_year + 1900) == temp.dat.year) {
			if ((ex.tm_mon + 1) == temp.dat.month) {
				if (ex.tm_mday - temp.dat.day >= 14) {
					cout << "������" << temp.name << endl;
					cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "�Ѹ���14�������������������" << endl;
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
				else {
					cout << "������" << temp.name << endl;
					cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "����δ�����ޣ�����" << 14 - (ex.tm_mday - temp.dat.day) << "��" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "�����������...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
			}
			else if (ex.tm_mon + 1 - temp.dat.month >= 2) {
				cout << "������" << temp.name << endl;
				cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
				cout << "�Ѹ���14�������������������" << endl;
				cout << endl;
				i++;
				if (i == 4) {
					cout << "�����������...";
					char chh = getchar();
					system("cls");
					i = 0;
				}
				in.read((char*)&temp, sizeof(temp));
				continue;
			}
			else {
				if ((((ex.tm_year + 1900) % 100 != 0) && ((ex.tm_year + 1900) % 4 == 0)) || ((ex.tm_year +1900) % 400 == 0)) {
					if (((ex.tm_mon + 1) == 2) || ((ex.tm_mon +1 ) == 4) || (( ex.tm_mon + 1) == 6) || ((ex.tm_mon + 1) == 8) || ((ex.tm_mon +1) == 9) || ((ex.tm_mon+1) == 11)) {
						if (31 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon +1 << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year +1900 << "-" << ex.tm_mon + 1  << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
					else if (ex.tm_mon + 1  == 3) {
						if (29 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year +1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year +1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (29 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
					else {
						if (30 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year << "-" << ex.tm_mon << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (30 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
				}
				else {
					if (((ex.tm_mon+1) == 2) || ((ex.tm_mon+1) == 4) || ((ex.tm_mon+1) == 6) || ((ex.tm_mon+1) == 8) || ((ex.tm_mon+1) == 9) || ((ex.tm_mon+1) == 11)) {
						if (31 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
					else if (ex.tm_mon+1 == 3) {
						if (28 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (28 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
					else {
						if (30 - temp.dat.day + ex.tm_mday - 1 >= 14) {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "�Ѹ���14�������������������" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "������" << temp.name << endl;
							cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "����δ�����ޣ�����" << 14 - (30 - temp.dat.day + ex.tm_mday - 1) << "��" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "�����������...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
					}
				}
			}
		}
		else {
			cout << "������" << temp.name << endl;
			cout << "��" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "��" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
			cout << "�Ѹ���14�������������������" << endl;
			cout << endl;
			i++;
			if (i == 4) {
				cout << "�����������...";
				char chh = getchar();
				system("cls");
				i = 0;
			}
			in.read((char*)&temp, sizeof(temp));
			continue;
		}
		in.read((char*)&temp, sizeof(temp));
	}
	in.close();
	cout << "�����������...";
	char chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
#endif 