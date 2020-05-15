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
	cout << "总人数为：" << num << endl;
	return *this;
}

void Personin::creat()
{
	Checkcin ccin;
	char ch;
	cout << "请输入进来人员姓名：" << endl;
	cin >> person.name;
	cout << "请输入进来人员年龄：" << endl;
	cin >> person.age;
	cout << "请输入进来人员电话号码：" << endl;
	cin >> person.telephone;
	cout << "请输入进来人员性别(F/M)：" << endl;
	person.sex =ccin.Checksex();
	cout << "请输入进来人员的职务(W/C):" << endl;
	person.work=ccin.Checkwork();
	cout << "请输入进入人员来源地：" << endl;
	cin >> person.place;
	cout << "是否途径疫情重灾区(武汉)(y/n):" << endl;
	ch=ccin.Checkchmain();
	if (ch == 'y') {
		fstream file("Apersonin.txt", ios::app);
		if (!file) {
			cout << "打开Apersonin.txt文件失败！！" << endl;
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
		cout << "打开文件personin.dat失败！" << endl;
		exit(0);
	}
	f.write((char*)&person, sizeof(person));
	f.close();
	cout << "请记好个人的登记码：" << person.Personcode << endl;
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
		cout << "打开personin.dat文件失败！！！" << endl;
		exit(0);
	}
	allperson temp;
	in.read((char*)&temp, sizeof(temp));
	while (!in.eof()) {
		if (ex.tm_year + 1900 - temp.dat.year>=2) {
			cout << "姓名：" << temp.name << endl;
			cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
			cout << "已隔离14天满，可以外出！！！" << endl;
			cout << endl;
			i++;
			if (i == 4) {
				cout << "按任意键继续...";
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
					cout << "姓名：" << temp.name << endl;
					cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "已隔离14天满，可以外出！！！" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "按任意键继续...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
				else {
					cout << "姓名：" << temp.name << endl;
					cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "隔离未满期限，还差" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "按任意键继续...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
			}
			else {
				cout << "姓名：" << temp.name << endl;
				cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
				cout << "已隔离14天满，可以外出！！！" << endl;
				cout << endl;
				i++;
				if (i == 4) {
					cout << "按任意键继续...";
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
					cout << "姓名：" << temp.name << endl;
					cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "已隔离14天满，可以外出！！！" << endl;
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
				else {
					cout << "姓名：" << temp.name << endl;
					cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
					cout << "隔离未满期限，还差" << 14 - (ex.tm_mday - temp.dat.day) << "天" << endl;
					cout << endl;
					i++;
					if (i == 4) {
						cout << "按任意键继续...";
						char chh = getchar();
						system("cls");
						i = 0;
					}
					in.read((char*)&temp, sizeof(temp));
					continue;
				}
			}
			else if (ex.tm_mon + 1 - temp.dat.month >= 2) {
				cout << "姓名：" << temp.name << endl;
				cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
				cout << "已隔离14天满，可以外出！！！" << endl;
				cout << endl;
				i++;
				if (i == 4) {
					cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon +1 << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year +1900 << "-" << ex.tm_mon + 1  << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year +1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year +1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (29 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year << "-" << ex.tm_mon << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year + 1900 << "-" << ex.tm_mon + 1 << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (30 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (31 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (28 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "已隔离14天满，可以外出！！！" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
								char chh = getchar();
								system("cls");
								i = 0;
							}
							in.read((char*)&temp, sizeof(temp));
							continue;
						}
						else {
							cout << "姓名：" << temp.name << endl;
							cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
							cout << "隔离未满期限，还差" << 14 - (30 - temp.dat.day + ex.tm_mday - 1) << "天" << endl;
							cout << endl;
							i++;
							if (i == 4) {
								cout << "按任意键继续...";
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
			cout << "姓名：" << temp.name << endl;
			cout << "由" << temp.dat.year << "-" << temp.dat.month << "-" << temp.dat.day << "到" << ex.tm_year+1900 << "-" << ex.tm_mon+1 << "-" << ex.tm_mday << ",";
			cout << "已隔离14天满，可以外出！！！" << endl;
			cout << endl;
			i++;
			if (i == 4) {
				cout << "按任意键继续...";
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
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
#endif 