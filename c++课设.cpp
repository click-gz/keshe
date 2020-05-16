#ifndef A
#define A
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include"windows.h"
#include"Store.h"
#include"Peosonin.h"
#include"Personout.h"
#include"Patient.h"
#include"Personlocal.h"
#include"Tem.h"
#include"load.h"
#include"Getmune.h"
#include"Checkcin.h"
#include"Code.h"

using namespace std;

int loadmanager(int i);
void patientmain();//程序开始时整理病人
void taketest();
void creatin();//添加进入人员
void creatout();//添加出去人员信息
void gettem_main();//获得日常体温
void showin();//显示所有进入人员的信息
void showout();//显示所有外出人员的信息
void showlocal();
void showtem(char n[10]);//显示体温(部分)
void showalltem();//单独显示所有的体温记录
void search();//查询功能
void stop();
void statistics();//统计功能

int main() {
	SetConsoleTitle("人员记录系统 1.0");// 设置窗口标题
	Checkcin ccin;
	mune MU;
	int i;
	while (true) {
		patientmain();
		i = ccin.Checkmaini();
		if (i == 1) {
			MU.GetmuneExplain();
		}
		else if (i == 2) {
			int cec;
			fstream ok("load.dat", ios::in | ios::binary);
			if (!ok) {
				system("cls");
				cec=loadmanager(0);
				if (cec == 1) {
					continue;
				}
			}
			else {
				system("cls");
				ok.close();
				cec = loadmanager(1);
				if (cec == 1) {
					continue;
				}
			}
		}
		else if (i == 3) {
			system("cls");
			MU.GetmuneRegister();
			int ik;
			ik = ccin.Checkmainik();
			if (ik == 1) {
				system("mode con cols=40 lines=30  ");
				system("cls");
				creatin();
			}
			else if (ik == 2) {
				system("cls");
				creatout();
			}
			else if (ik == 3) {
				system("cls");
				Personlocal p;
				p.creat();
				p.getdate();
				p.getTem();
			}
			else if (ik == 4) {
				system("cls");
				gettem_main();
			}
			else if(ik==5){
				system("cls");
				fstream f("test.dat", ios::in | ios::binary);
				if (!f) {
					fstream ff("test.dat", ios::out | ios::binary);
					ff.close();
				}
				f.close();
				taketest();
			}
			else {
				continue;
			}
		}
		else if (i == 4) {
			patient pmainn;
			pmainn.attention_patient();
		}
		else if(i == 5) {
			Personin wexp;
			wexp.limitday();
		}
		else if (i == 6) {
			Tem maintem;
			maintem.dairyTcheck();
		}
		else {
			exit(0);
		}
	}
}

void search()
{
	Checkcin ccin;
	mune MUN;
	char ch;
	cout << "\t请选择要查询的对象:" << endl;
	cout<<"外来人员(i)  外出人员(o)  本地人员(L)" << endl;
	ch=ccin.Checkchsearch();
	if (ch == 'i') {
		MUN.GetmuneSearchi();
		while (true) {
			int i=0;
			cout << "请选择查询功能(1--4):" << endl;
			i=ccin.Checksearchi();
			system("cls");
			if (i == 1) {
				int j = 0, y, m, d;
				cout << "请输入要查询的年月日，空格间隔" << endl;
				cin >> y >> m >> d;
				fstream in("personin.dat", ios::in | ios::binary);
				struct allperson p;
				if (!in) {
					fstream In("personin.dat", ios::out | ios::binary);
					if (!In) {
						cout << "读取personin.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外来人员登记" << endl;
						stop();
						continue;
					}
				}
				in.read((char*)&p, sizeof(p));
				while (!in.eof()) {
					if (p.dat.year == y && p.dat.month == m && p.dat.day == d) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "来源地：" << p.place << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonin.txt", ios::in);
						if (!file) {
							cout << "打开Apersonin.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					in.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此时间的进入人员信息。" << endl;
				}
				in.close();
				stop();
			}
			else if (i == 2) {
				int j = 0;
				char nam[20];
				cout << "请输入要查询的人名" << endl;
				cin >> nam;
				fstream in("personin.dat", ios::in | ios::binary);
				struct allperson p;
				if (!in) {
					fstream In("personin.dat", ios::out | ios::binary);
					if (!In) {
						cout << "读取personin.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外来人员登记" << endl;
						stop();
						continue;
					}
				}
				in.read((char*)&p, sizeof(p));
				while (!in.eof()) {
					if (strcmp(nam, p.name) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "来源地：" << p.place << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonin.txt", ios::in);
						if (!file) {
							cout << "打开Apersonin.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					in.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此时间的进入人员信息。" << endl;
				}
				in.close();
				stop();
			}
			else if (i == 3) {
				int j = 0;
				char tel[20];
				cout << "请输入要查询的目的地" << endl;
				cin >> tel;
				fstream in("personin.dat", ios::in | ios::binary);
				struct allperson p;
				if (!in) {
					fstream In("personin.dat", ios::out | ios::binary);
					if (!In) {
						cout << "读取personin.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外来人员登记" << endl;
						stop();
						continue;
					}
				}
				in.read((char*)&p, sizeof(p));
				while (!in.eof()) {
					if (strcmp(tel, p.telephone) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "来源地：" << p.place << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonin.txt", ios::in);
						if (!file) {
							cout << "打开Apersonin.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					in.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此进入人员信息。" << endl;
				}
				in.close();
				cout << "按任意键继续..." << endl;
				char chh = getchar();
				system("cls");
			}
			else if (i == 4) {
				int j = 0;
				char pla[20];
				cout << "请输入要查询的来源地" << endl;
				cin >> pla;
				fstream in("personin.dat", ios::in | ios::binary);
				struct allperson p;
				if (!in) {
					fstream In("personin.dat", ios::out | ios::binary);
					if (!In) {
						cout << "读取personin.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外来人员登记" << endl;
						continue;
					}
				}
				in.read((char*)&p, sizeof(p));
				while (!in.eof()) {
					if (strcmp(pla, p.place) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "来源地：" << p.place << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonin.txt", ios::in);
						if (!file) {
							cout << "打开Apersonin.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					in.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此进入人员信息。" << endl;
				}
				in.close();
				stop();
			}
			break;
		}
	}
	else if(ch=='o'){
		MUN.GetmuneSearcho();
		int i ;
		while (true) {
			cout << "请选择查询功能(1--4):" << endl;
			i = ccin.Checksearchi();
			system("cls");
			system("mode con cols=40 lines=30  ");
			if (i == 1) {
				int j = 0, y, m, d;
				cout << "请输入要查询的年月日，空格间隔" << endl;
				cin >> y >> m >> d;
				fstream out("personout.dat", ios::in | ios::binary);
				struct allperson p;
				if (!out) {
					fstream Out("personout.dat", ios::out | ios::binary);
					if (!Out) {
						cout << "读取personout.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外出人员登记" << endl;
						stop();
						continue;
					}
				}
				out.read((char*)&p, sizeof(p));
				while (!out.eof()) {
					if (p.dat.year == y && p.dat.month == m && p.dat.day == d) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "目的地：" << p.place << endl;
						cout << "外出原因：" << p.reason << endl;
						cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
						if (p.outcheck == 'i') {
							cout << "此人已返回" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonout.txt", ios::in);
						if (!file) {
							cout << "打开Apersonout.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								if (j > 0) {
									cout << "按任意键继续..." << endl;
									cin.ignore();
									char chh = getchar();
									system("cls");
								}
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					out.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此时间的外出人员信息。" << endl;
				}
				out.close();
				stop();
			}
			else if (i == 2) {
				int j = 0;
				char nam[20];
				cout << "请输入要查询的人名" << endl;
				cin >> nam;
				fstream out("personout.dat", ios::in | ios::binary);
				struct allperson p;
				if (!out) {
					fstream Out("personout.dat", ios::out | ios::binary);
					if (!Out) {
						cout << "读取personout.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外出人员登记" << endl;
						stop();
						continue;
					}
				}
				out.read((char*)&p, sizeof(p));
				while (!out.eof()) {
					if (strcmp(nam, p.name) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "目的地：" << p.place << endl;
						cout << "外出原因：" << p.reason << endl;
						cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
						if (p.outcheck == 'i') {
							cout << "此人已返回" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonout.txt", ios::in);
						if (!file) {
							cout << "打开Apersonout.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					out.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此外出人员信息。" << endl;
				}
				out.close();
				stop();
			}
			else if (i == 3) {
				int j = 0;
				char tel[20];
				cout << "请输入要查询的电话号码" << endl;
				cin >> tel;
				fstream out("personout.dat", ios::in | ios::binary);
				struct allperson p;
				if (!out) {
					fstream Out("personout.dat", ios::out | ios::binary);
					if (!Out) {
						fstream Out("personout.dat", ios::out | ios::binary);
						if (!Out) {
							cout << "读取personout.dat文件失败!!!" << endl;
							exit(0);
						}
						else {
							cout << "暂无外出人员登记" << endl;
							stop();
							continue;
						}
					}
					else {
						cout << "暂无外出人员登记" << endl;
						continue;
					}
				}
				out.read((char*)&p, sizeof(p));
				while (!out.eof()) {
					if (strcmp(tel, p.telephone) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "目的地：" << p.place << endl;
						cout << "外出原因：" << p.reason << endl;
						cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
						if (p.outcheck == 'i') {
							cout << "此人已返回" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonout.txt", ios::in);
						if (!file) {
							cout << "打开Apersonout.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					out.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此外出人员信息。" << endl;
				}
				out.close();
				stop();
			}
			else if (i == 4) {
				int j = 0;
				char pla[20];
				cout << "请输入要查询的目的地，空格间隔" << endl;
				cin >> pla;
				fstream out("personout.dat", ios::in | ios::binary);
				struct allperson p;
				if (!out) {
					fstream Out("personout.dat", ios::out | ios::binary);
					if (!Out) {
						cout << "读取personout.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无外出人员登记" << endl;
						stop();
						continue;
					}
				}
				out.read((char*)&p, sizeof(p));
				while (!out.eof()) {
					if (strcmp(pla, p.place) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						cout << "目的地：" << p.place << endl;
						cout << "外出原因：" << p.reason << endl;
						cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
						if (p.outcheck == 'i') {
							cout << "此人已返回" << endl;
						}
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						fstream file("Apersonout.txt", ios::in);
						if (!file) {
							cout << "打开Apersonout.txt文件失败！！！" << endl;
							exit(0);
						}
						char ch[10];
						file >> ch;
						while (!file.eof()) {
							if (strcmp(ch, p.name) == 0) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
								//设置红色
								cout << "此人途径过重灾区！！！请注意！！！" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
							}
							file >> ch;
						}
						file.close();
						cout << "-------------------" << endl;
						j++;
					}
					out.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此外出人员信息。" << endl;
				}
				out.close();
				stop();
			}
			break;
		}
	}
	else {
		MUN.GetmuneSearchL();
		int i;
		while (true) {
			cout << "请选择查询功能(1--3):" << endl;
			i = ccin.Checksearchi(1);
			system("cls");
			system("mode con cols=40 lines=30  ");
			if (i == 1) {
				int j = 0;
				char nam[20];
				cout << "请输入要查询的人名" << endl;
				cin >> nam;
				fstream loCal("Personlocal.dat", ios::in | ios::binary);
				struct allperson p;
				if (!loCal) {
					fstream Local("Personlocal.dat", ios::out | ios::binary);
					if (!Local) {
						cout << "读取Personlocal.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无本地人员登记" << endl;
						cin.ignore();
						stop();
						continue;
					}
				}
				loCal.read((char*)&p, sizeof(p));
				while (!loCal.eof()) {
					if (strcmp(nam, p.name) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
							fstream file("Apersonout.txt", ios::in);
							if (!file) {
								cout << "打开Apersonout.txt文件失败！！！" << endl;
								exit(0);
							}
							char ch[10];
							file >> ch;
							while (!file.eof()) {
								if (strcmp(ch, p.name) == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
									//设置红色
									cout << "此人途径过重灾区！！！请注意！！！" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
									break;
								}
								file >> ch;
							}
							file.close();
						}
						cout << "-------------------" << endl;
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						j++;
					}
					loCal.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此人员信息。" << endl;
				}
				loCal.close();
				cin.ignore();
				stop();
			}
			else if (i == 2) {
				int j = 0;
				char tel[20];
				cout << "请输入要查询的电话号码" << endl;
				cin >> tel;
				fstream loCal("Personoutlocal.dat", ios::in | ios::binary);
				struct allperson p;
				if (!loCal) {
					fstream Local("Personlocal.dat", ios::out | ios::binary);
					if (!Local) {
						cout << "读取Personlocal.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无本地人员登记" << endl;
						cin.ignore();
						stop();
						continue;
					}
				}
				loCal.read((char*)&p, sizeof(p));
				while (!loCal.eof()) {
					if (strcmp(tel, p.telephone) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
							fstream file("Apersonout.txt", ios::in);
							if (!file) {
								cout << "打开Apersonout.txt文件失败！！！" << endl;
								exit(0);
							}
							char ch[10];
							file >> ch;
							while (!file.eof()) {
								if (strcmp(ch, p.name) == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
									//设置红色
									cout << "此人途径过重灾区！！！请注意！！！" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
									break;
								}
								file >> ch;
							}
							file.close();
						}
						cout << "-------------------" << endl;
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						j++;
					}
					loCal.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此人员信息。" << endl;
				}
				loCal.close();
				cin.ignore();
				stop();
			}
			else if (i == 3) {
				int j = 0;
				char pla[20];
				cout << "请输入登记码：" << endl;
				cin >> pla;
				fstream loCal("Personlocal.dat", ios::in | ios::binary);
				struct allperson p;
				if (!loCal) {
					fstream Local("Personlocal.dat", ios::out | ios::binary);
					if (!Local) {
						cout << "读取Personlocal.dat文件失败!!!" << endl;
						exit(0);
					}
					else {
						cout << "暂无本地人员登记" << endl;
						cin.ignore();
						stop();
						continue;
					}
				}
				loCal.read((char*)&p, sizeof(p));
				while (!loCal.eof()) {
					if (strcmp(pla, p.place) == 0) {
						cout << "-------------------" << endl;
						cout << "姓名：" << p.name << endl;
						cout << "性别：" << p.sex << endl;
						cout << "年龄：" << p.age << endl;
						cout << "电话号码：" << p.telephone << endl;
						cout << "职务：" << p.work << endl;
						if (p.outcheck == 'o') {
							cout << "此人已外出" << endl;
							fstream file("Apersonout.txt", ios::in);
							if (!file) {
								cout << "打开Apersonout.txt文件失败！！！" << endl;
								exit(0);
							}
							char ch[10];
							file >> ch;
							while (!file.eof()) {
								if (strcmp(ch, p.name) == 0) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
									//设置红色
									cout << "此人途径过重灾区！！！请注意！！！" << endl;
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
									break;
								}
								file >> ch;
							}
							file.close();
						}
						cout << "-------------------" << endl;
						cout << "是否查看此人的体温记录？(y/n)" << endl;
						char cho = ccin.Checkchmain();
						if (cho == 'y') {
							system("cls");
							showtem(p.name);
						}
						j++;
					}
					loCal.read((char*)&p, sizeof(p));
					stop();
				}
				if (j == 0) {
					cout << "查无此人员信息。" << endl;
				}
				loCal.close();
				cin.ignore();
				stop();
			}
			break;
		}
	}
}
void stop()
{
	cout << "按任意键继续..." << endl;
	char chh;
	chh=getchar();
	system("cls");
}
void statistics()
{
	system("mode con cols=60 lines=10  ");
	fstream file("personin.dat", ios::in | ios::binary);
	if (!file) {
		cout << "打开personin.dat文件失败！！！" << endl;
		exit(0);
	}
	float i = 0;
	int num;
	allperson p;
	file.read((char*)&p, sizeof(p));
	while (!file.eof()) {
		i++;
		file.read((char*)&p, sizeof(p));
	}
	file.close();
	fstream f("Allperson.txt", ios::in);
	if (!f) {
		cout << "打开Allperson.txt文件失败！！！" << endl;
		exit(0);
	}
	f >> num;
	if (i == 0) {
		cout << "暂无外来人员记录" << endl;
	}
	else {
		cout << "外来人员占记录总人数的比例为：" << setprecision(4) << (i / num) * 100 << "%" << endl;
	}
	f.close();
	i = 0;
	float j = 0;
	char name[10];
	fstream T("Patient.txt", ios::in);
	if (!T) {
		cout << "打开Patient.txt失败！！！" << endl;
		exit(0);
	}
	if (T.getline(name, 10).good()) {
		while (!T.eof()) {
			j++;
			fstream file("personin.dat", ios::in | ios::binary);
			if (!file) {
				cout << "打开personin.dat文件失败！！！" << endl;
				exit(0);
			}
			allperson p;
			file.read((char*)&p, sizeof(p));
			while (!file.eof()) {
				if (strcmp(p.name, name) == 0) {
					i++;
				}
				file.read((char*)&p, sizeof(p));
			}
			file.close();
			if (T.getline(name, 10).good()) {
				continue;
			}
			else if (T.eof()) {
				break;
			}
			else {
				cout << "读取Patient.txt错误！！！" << endl;
				exit(0);
			}
		}
	}
	T.close();
	if (j == 0) {
		cout << "暂无记录在案的病人！！！" << endl;
	}
	else {
		cout << "体温不正常的人占记录在线的人数比例为：" << setprecision(4) << (j / num) * 100 << "%" << endl;
		if (i != 0) {
			cout << "其中外来人员占体温不正常总人数的比例为：";
			cout << setprecision(4) << (i / j) * 100 << "%" << endl;
		}
		cout << "其中本地人员占体温不正常总人数的比例为：";
		cout << setprecision(4) << 100 - (i / j) * 100 << "%" << endl;
	}
	stop();
	system("mode con cols=40 lines=20  ");
}
void taketest()
{
	test tpp;
	tpp.gettest();
}
void creatin() {
	int ci = 0, cki = 0;
	Checkcin ccin;
	Personin per;
	allperson al;
	cout << "是否是之前出去人员？(y/n)" << endl;
	char chh = ccin.Checkchmain();
	if (chh == 'y') {
		while (true) {
			cout << "请输入登记码：" << endl;
			char code[7];
			cin >> code;
			Code expcode;
			ci = expcode.checkCodein(code);
			if (ci == 0) {
				ci = expcode.checkCodelocal(code);
				if (ci != 0) {
					fstream f("Personlocal.dat", ios::in | ios::binary);
					fstream ff("Personlocal1.dat", ios::out | ios::binary);
					if (!f || !ff) {
						cout << "打开文件失败" << endl;
						exit(0);
					}
					f.read((char*)&al, sizeof(al));
					while (!f.eof()) {
						if (strcmp(al.Personcode ,code)==0) {
							al.outcheck = 'i';
							cki++;
						}
						ff.write((char*)&al, sizeof(al));
						f.read((char*)&al, sizeof(al));
					}
					f.close();
					ff.close();
					fstream f1("Personlocal.dat", ios::out | ios::binary);
					fstream f2("Personlocal1.dat", ios::in | ios::binary);
					if (!f1 || !f2) {
						cout << "打开文件失败" << endl;
						exit(0);
					}
					f2.read((char*)&al, sizeof(al));
					while (!f2.eof()) {
						f1.write((char*)&al, sizeof(al));
						f2.read((char*)&al, sizeof(al));
					}
					f1.close();
					f2.close();
					const char* savePath = "Personlocal1.dat";
					if (remove(savePath) != 0)
					{
						cout << "删除文件personin1.dat失败！！！" << endl;
						stop();
					}
				}
			}
			else {
				if (ci != 0) {
					fstream f("personin.dat", ios::in | ios::binary);
					fstream ff("personin1.dat", ios::out | ios::binary);
					if (!f || !ff) {
						cout << "打开文件失败" << endl;
						exit(0);
					}
					f.read((char*)&al, sizeof(al));
					while (!f.eof()) {
						if (strcmp(al.Personcode, code) == 0) {
							al.outcheck = 'i';
							cki++;
						}
						ff.write((char*)&al, sizeof(al));
						f.read((char*)&al, sizeof(al));
					}
					f.close();
					ff.close();
					fstream f1("personin.dat", ios::out | ios::binary);
					fstream f2("personin1.dat", ios::in | ios::binary);
					if (!f1 || !f2) {
						cout << "打开文件失败" << endl;
						exit(0);
					}
					f2.read((char*)&al, sizeof(al));
					while (!f2.eof()) {
						f1.write((char*)&al, sizeof(al));
						f2.read((char*)&al, sizeof(al));
					}
					f1.close();
					f2.close();
					const char* savePath = "personin1.dat";
					if (remove(savePath) != 0)
					{
						cout << "删除文件personin1.dat失败！！！" << endl;
						stop();
					}
				}
			}
			if(cki==0){
				cout << "未找到相关人员，请输入正确的登记码！" << endl;
				cout << "是否重新输入登记码？" << endl;
				char chho = ccin.Checkchmain();
				if (chho == 'y') {
					system("cls");
					continue;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
	}
	else {
		per.creat();
		per.getdate();
		per.savepersonin();
		per.getTem();
		++per;
	}
}
void creatout() {
	Personout per;
	per.creat();
	per.getdate();
	per.savepersonout();
}
void gettem_main()
{
	Checkcin ccin;
	int c = 0;
	char n[20],ch;
	cout << "请输入姓名：" << endl;
	cin >> n;
	fstream in("personin.dat", ios::in | ios::binary);
	struct allperson p;
	if (!in) {
		cout << "读取personin.dat文件失败!!!" << endl;
		exit(0);
	}
	in.read((char*)&p, sizeof(p));
	while (!in.eof()) {
		if (strcmp(p.name, n) == 0) {
			Tem ex;
			ex.getTname(n);
			ex.getTdate();
			ex.gettemp();
			ex.savetemp();
			in.close();
			c = 1;
			break;
		}
		in.read((char*)&p, sizeof(p));
	}
	in.close();
	if (c == 0) {
		cout << "是否为外来人员(y/n):" << endl;
		ch = ccin.Checkchmain();
		system("cls");
		if (ch == 'y') {
			system("mode con cols=40 lines=30  ");
			cout << "系统未录入您的信息，请先填报个人信息！！！" << endl;
			creatin();
		}
		else if (ch == 'n') {
			int c = 0;
			system("mode con cols=40 lines=30  ");
			fstream lo("Personlocal.dat", ios::in | ios::binary);
			struct allperson p;
			if (!lo) {
				cout << "读取Personlocal.dat文件失败!!!" << endl;
				exit(0);
			}
			lo.read((char*)&p, sizeof(p));
			while (!lo.eof()) {
				if (strcmp(p.name, n) == 0) {
					Tem ex;
					ex.getTname(n);
					ex.getTdate();
					ex.gettemp();
					ex.savetemp();
					in.close();
					c = 1;
					break;
				}
				lo.read((char*)&p, sizeof(p));
			}
			lo.close();
			if (c == 0) {
				cout << "未查到个人信息" << endl;
				cout << "请先进行本地人身份信息录入" << endl;
				Personlocal p;
				p.creat();
				p.getdate();
				p.getTem();
			}
		}
	}
}
void showin() {
	int c = 0;
	fstream in("personin.dat", ios::in | ios::binary);
	struct allperson p;
	if (!in) {
		fstream In("personin.dat", ios::out | ios::binary);
		if (!In) {
			cout << "读取personin.dat文件失败!!!" << endl;
			exit(0);
		}
		In.close();
		cout << "暂无外来人员登记！！！" << endl;
		stop();
	}
	else {
		in.read((char*)&p, sizeof(p));
		while (!in.eof()) {
			cout << "-------------------" << endl;
			cout << "姓名：" << p.name << endl;
			cout << "性别：" << p.sex << endl;
			cout << "年龄：" << p.age << endl;
			cout << "电话号码：" << p.telephone << endl;
			cout << "职务：" << p.work << endl;
			cout << "来源地：" << p.place << endl;
			c++;
			showtem(p.name);
			fstream file("Apersonin.txt", ios::in);
			if (!file) {
				fstream ffile("Apersonin.txt", ios::out);
				if (!ffile) {
					cout << "打开Apersonin.txt文件失败！！！" << endl;
					exit(0);
				}
				ffile.close();
				c = 10000;
			}
			if (c != 10000) {
				char ch[10];
				file >> ch;
				while (!file.eof()) {
					if (strcmp(ch, p.name) == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//设置红色
						cout << "此人途径过重灾区！！！请注意！！！" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
					}
					file >> ch;
				}
				file.close();
			}
			c = 0;
			in.read((char*)&p, sizeof(p));
			cout << "-------------------" << endl;
			stop();
		}
		in.close();
	}
}
void showout() {
	int c = 0;
	fstream out("personout.dat", ios::in | ios::binary);
	struct allperson p;
	if (!out) {
		fstream oout("personout.dat", ios::out | ios::binary);
		if (!oout) {
			cout << "读取personout.dat文件失败!!!" << endl;
			exit(0);
		}
		oout.close();
		c = 10000;
	}
	if (c != 10000) {
		out.read((char*)&p, sizeof(p));
		while (!out.eof()) {
			cout << "-------------------" << endl;
			cout << "姓名：" << p.name << endl;
			cout << "性别：" << p.sex << endl;
			cout << "年龄：" << p.age << endl;
			cout << "电话号码：" << p.telephone << endl;
			cout << "职务：" << p.work << endl;
			cout << "外出目的地：" << p.place << endl;
			cout << "外出原因：" << p.reason << endl;
			cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
			c++;
			out.read((char*)&p, sizeof(p));
			fstream file("Apersonout.txt", ios::in);
			if (!file) {
				fstream ffile("Apersonout.txt", ios::out);
				if (!ffile) {
					cout << "打开Apersonout.txt文件失败！！！" << endl;
					exit(0);
				}
				ffile.close();
				c = 100000;
			}
			if (c != 100000) {
				char ch[10];
				file >> ch;
				while (!file.eof()) {
					if (strcmp(ch, p.name) == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//设置红色
						cout << "此人途径过重灾区！！！请注意！！！" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
					}
					file >> ch;
				}
				file.close();
			}
			if (p.outcheck == 'i') {
				cout << "此人已外出归来" << endl;
			}
			else {
				cout << "此人外出仍未归回" << endl;
			}
			out.read((char*)&p, sizeof(p));
			cout << "-------------------" << endl;
			stop();
		}
		out.close();
		if (c == 0) {
			cout << "暂无外出人员信息记录" << endl;
			stop();
		}
	}
	else {
		cout << "暂无外出人员登记" << endl;
		stop();
	}
}
void showlocal() {
	int c = 0;
	fstream loc("Personlocal.dat", ios::in | ios::binary);
	struct allperson p;
	if (!loc) {
		fstream local("Personlocal.dat", ios::out | ios::binary);
		if (!local) {
			cout << "读取Personlocal.dat文件失败!!!" << endl;
			exit(0);
		}
		local.close();
		c = 10000;
	}
	if (c != 10000) {
		loc.read((char*)&p, sizeof(p));
		while (!loc.eof()) {
			cout << "-------------------" << endl;
			cout << "姓名：" << p.name << endl;
			cout << "性别：" << p.sex << endl;
			cout << "年龄：" << p.age << endl;
			cout << "电话号码：" << p.telephone << endl;
			cout << "职务：" << p.work << endl;
			c++;
			loc.read((char*)&p, sizeof(p));
			cout << "-------------------" << endl;
			stop();
		}
		loc.close();
		if (c == 0) {
			cout << "暂无本地人员信息记录" << endl;
			stop();
		}
	}
	else {
		cout << "暂无本地人员信息记录" << endl;
		stop();
	}
}
void showtem(char n[10]) {
	int i = 0;
	fstream T("temperature.dat", ios::in | ios::binary);
	Record_Tem ex;
	if (!T) {
		cout << "读取temperature.dat文件失败！！！" << endl;
		exit(0);
	}
	cout << "姓名：" << n << endl;
	cout << "体温记录为：" << endl;
	T.read((char*)&ex, sizeof(ex));
	while (!T.eof()) {
		if (strcmp(ex.name, n) == 0) {
			cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << "：" << endl;
			cout << ex.temp << endl;
			i++;
		}
		T.read((char*)&ex, sizeof(ex));
	}
	if (i == 0) {
		cout << "暂无此人的体温记录，请按时进行体温测量！！！" << endl;
	}
	T.close();
}
void showalltem()
{
	int i = 0;
	fstream T("temperature.dat", ios::in | ios::binary);
	Record_Tem ex;
	if (!T) {
		cout << "读取temperature.dat文件失败！！！" << endl;
		exit(0);
	}
	T.read((char*)&ex, sizeof(ex));
	while (!T.eof()) {
		cout << "-----------" << endl;
		cout << "姓名：" << ex.name << "  ";
		cout << "体温记录为：" << endl;
		cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << "：" ;
		cout << ex.temp << " 度" << endl;
		cout << "-----------" << endl;
		i++;
		T.read((char*)&ex, sizeof(ex));
		if (i % 3 == 0) {
			stop();
		}
	}
	if (i == 0) {
		cout << "暂无体温记录" << endl;
	}
	T.close();
	stop();
}
int loadmanager(int i) {
	int cec;
	Checkcin ccin;
	mune MU;
	loadperson fir;
	if (i == 0) {
		cec = fir.loadfirst(0);
	}
	else {
		cec = fir.loadfirst(1);
	}
	if (cec == 1) {
		int t;
		while (true) {
			MU.GetmuneManager();
			t = ccin.Checkmanager();
			system("cls");
			if (t == 1) {
				showin();
			}
			else if (t == 2) {
				showout();
			}
			else if (t == 3) {
				showlocal();
			}
			else if (t == 4) {
				showalltem();
			}
			else if (t == 5) {
				search();
				system("mode con cols=40 lines=20  ");
			}
			else if (t == 6) {
				char ch;
				int l;
				patient pa;
				pa.savepatient();
				pa.getnum_patient();
				pa.printnum_patient();
				while (true) {
					MU.GetmuneManagerP();
					l = ccin.Checkmanager();
					if (l == 1) {
						pa.savepatient();
						pa.getnum_patient();
						pa.printnum_patient();
						pa.show_patienttem();
					}
					else if (l == 2) {
						pa.check_patient();
					}
					else if (l == 3) {
						pa.delete_patient();//删除该信息后需要进一步保证之后不会再出现该信息
					}
					else {
						cout << "请正确输入！！！" << endl;
						continue;
					}
					cout << "是否需要继续在此页面操作(y/n):" << endl;
					ch = ccin.Checkchmain();
					if (ch == 'y') {
						continue;
					}
					else {
						break;
					}
				}
			}
			else if (t == 7) {
				Store sn;
				sn.show();
				cout << "是否需要添加物资？(y/n):";
				char ch;
				ch = ccin.Checkchmain();
				if (ch == 'y') {
					sn.add_num();
				}
			}
			else if (t == 8) {
				statistics();
			}
			else if (t == 9) {
				fir.changeload(1);
				fir.saveloadperson();
			}
			else {
				break;
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}
void patientmain()
{
	patient pmain;
	pmain.savepatient();
}
#endif