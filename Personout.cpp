#include<iostream>
#include<fstream>
#include "Personout.h"
#include"Checkcin.h"
#include"Personlocal.h"
#include<Windows.h>
#include"Code.h"
using namespace std;

Personout Personout::operator++()
{
	++num;
	cout << "������Ϊ��" << num << endl;
	return *this;
}
void Personout::creat()
{
	int exi = 0;
	Checkcin ccin;
	char ch;
	while (true) {
		int cxi = 0;
		cout << "�Ƿ�ԭ���Ǳ����ˣ�(y/n)"<<endl;
		char chh = ccin.Checkchmain();
		if (chh == 'y') {
			cout << "�Ƿ�ǵõǼ�ʱ�ĵǼ��룿(y/n):" << endl;
			char chh = ccin.Checkchmain();
			if (chh == 'y') {
				while (true) {
					cout << "������ԭ���Ǽ�ʱ�ĵǼ��룺" << endl;
					char code[7];
					cin >> code;
					fstream c1("Personlocal.dat", ios::in | ios::binary);
					fstream c2("drawboard.dat", ios::out | ios::binary);
					if (!c1 || !c2) {
						cout << "���ļ�ʧ�ܣ�����" << endl;
						Sleep(1000);
						exit(0);
					}
					c1.read((char*)&person, sizeof(person));
					while (!c1.eof()) {
						if (strcmp(person.Personcode , code)==0) {
							cout << "������" << person.name << endl;
							cout << "�Ա�" << person.age << endl;
							cout << "���룺";
							for (int nu = 0;person.telephone[nu] != '\0';nu++) {
								if (nu >= 3 && nu <= 7) {
									cout << "*";
								}
								else {
									cout << person.telephone[nu];
								}
							}
							cout << "�Ƿ��Ǹ���Ա��Ϣ��(y/n)" << endl;
							char cl = ccin.Checkchmain();
							if (cl == 'y') {
								person.outcheck = 'o';
								exi++;
								cxi = 1;
							}
							else {
								system("cls");
							}
						}
						c2.write((char*)&person, sizeof(person));
						c1.read((char*)&person, sizeof(person));
					}
					c1.close();
					c2.close();
					if (exi == 0) {
						const char* savePath = "drawboard.dat";
						if (remove(savePath) != 0)
						{
							cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
							cout << "�����������...";
							char chh = getchar();
							exit(0);
						}
						cout << "��δ�鵽����Ա���Ƿ��������룿(y/n):" << endl;
						char cll = ccin.Checkchmain();
						if (cll == 'y') {
							continue;
						}
						else {
							break;
						}
					}
					else {
						fstream c3("Personlocal.dat", ios::out | ios::binary);
						fstream c4("drawboard.dat", ios::in | ios::binary);
						if (!c3 || !c4) {
							cout << "���ļ�ʧ�ܣ�����" << endl;
							exit(0);
							Sleep(1000);
						}
						c4.read((char*)&person, sizeof(person));
						while (!c4.eof()) {
							c3.write((char*)&person, sizeof(person));
							c4.read((char*)&person, sizeof(person));
						}
						c3.close();
						c4.close();
						const char* savePath = "drawboard.dat";
						if (remove(savePath) != 0)
						{
							cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
							cout << "�����������...";
							char chh = getchar();
							cxi = 1;
							exit(0);
						}
						break;
					}
				}
			}
			else {
				while (true) {
					cout << "�Ƿ�Ǽǹ���(y/n)" << endl;
					char clll = ccin.Checkchmain();
					if (clll == 'y') {
						while (true) {
							char cename[10], cesex, cete[12];
							cout << "�������ȥ��Ա������" << endl;
							cin >> cename;
							cout << "�������ȥ��Ա�绰���룺" << endl;
							cin >> cete;
							cout << "�������ȥ��Ա�Ա�(F/M)��" << endl;
							cesex = ccin.Checksex();
							fstream c5("Personlocal.dat", ios::in | ios::binary);
							fstream c6("drawboard.dat", ios::out | ios::binary);
							if (!c5 || !c6) {
								cout << "���ļ�ʧ�ܣ�����" << endl;
								exit(0);
								Sleep(1000);
							}
							c5.read((char*)&person, sizeof(person));
							while (!c5.eof()) {
								if ((strcmp(person.name, cename) == 0) && (cesex == person.sex) && (strcmp(person.telephone, cete) == 0)) {
									person.outcheck = 'o';
									exi++;
								}
								c6.write((char*)&person, sizeof(person));
							}
							c5.close();
							c6.close();
							if (exi == 0) {
								const char* savePath = "drawboard.dat";
								if (remove(savePath) != 0)
								{
									cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
									cout << "�����������...";
									char chh = getchar();
									exit(0);
								}
								cout << "��δ�鵽����Ա���Ƿ��������룿(y/n):" << endl;
								char ccc = ccin.Checkchmain();
								if (ccc == 'y') {
									system("cls");
									continue;
								}
								else {
									system("cls");
									break;
								}
							}
							else {
								cxi = 1;
								break;
							}
						}
					}
					else {
						cout << "���ȵǼǸ�����Ϣ������" << endl;
						Personlocal p;
						p.creat();
						p.getdate();
						cxi = 1;
						break;
					}
					if (cxi == 1) {
						break;
					}
				}
			}

		}
		else {
			cout << "�Ƿ�ǵõǼ�ʱ�ĵǼ��룿(y/n):" << endl;
			char chhh = ccin.Checkchmain();
			if (chhh == 'y') {
				while (true) {
					cout << "������ԭ���Ǽ�ʱ�ĵǼ��룺" << endl;
					char code[7];
					cin >> code;
					fstream c1("personin.dat", ios::in | ios::binary);
					fstream c2("drawboard.dat", ios::out | ios::binary);
					if (!c1 || !c2) {
						cout << "���ļ�ʧ�ܣ�����" << endl;
						exit(0);
						Sleep(1000);
					}
					c1.read((char*)&person, sizeof(person));
					while (!c1.eof()) {
						if (strcmp(person.Personcode , code)==0) {
							cout << "������" << person.name << endl;
							cout << "�Ա�" << person.age << endl;
							cout << "���룺";
							for (int nu = 0;person.telephone[nu] != '\0';nu++) {
								if (nu >= 3 && nu <= 7) {
									cout << "*";
								}
								else {
									cout << person.telephone[nu];
								}
							}
							cout << "�Ƿ��Ǹ���Ա��Ϣ��(y/n)" << endl;
							char chhhh = ccin.Checkchmain();
							if (chhhh == 'y') {
								person.outcheck = 'o';
								exi++;
							}
							else {
								system("cls");
							}
						}
						c2.write((char*)&person, sizeof(person));
						c1.read((char*)&person, sizeof(person));
					}
					c1.close();
					c2.close();
					if (exi == 0) {
						const char* savePath = "drawboard.dat";
						if (remove(savePath) != 0)
						{
							cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
							cout << "�����������...";
							char chh = getchar();
							exit(0);
						}
						cout << "��δ�鵽����Ա���Ƿ��������룿(y/n):" << endl;
						char cn = ccin.Checkchmain();
						if (cn == 'y') {
							continue;
						}
						else {
							break;
						}
					}
					else {
						fstream c3("personin.dat", ios::out | ios::binary);
						fstream c4("drawboard.dat", ios::in | ios::binary);
						if (!c3 || !c4) {
							cout << "���ļ�ʧ�ܣ�����" << endl;
							exit(0);
							Sleep(1000);
						}
						c4.read((char*)&person, sizeof(person));
						while (!c4.eof()) {
							c3.write((char*)&person, sizeof(person));
							c4.read((char*)&person, sizeof(person));
						}
						c3.close();
						c4.close();
						const char* savePath = "drawboard.dat";
						if (remove(savePath) != 0)
						{
							cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
							cout << "�����������...";
							char chh = getchar();
							cxi = 1;
							exit(0);
						}
						break;
					}
				}
			}
			else {
				while (true) {
					cout << "�Ƿ�Ǽǹ���(y/n)" << endl;
					char cnn = ccin.Checkchmain();
					if (cnn == 'y') {
						while (true) {
							char cename[10], cesex, cete[12];
							cout << "�������ȥ��Ա������" << endl;
							cin >> cename;
							cout << "�������ȥ��Ա�绰���룺" << endl;
							cin >> cete;
							cout << "�������ȥ��Ա�Ա�(F/M)��" << endl;
							cesex = ccin.Checksex();
							fstream c5("personin.dat", ios::in | ios::binary);
							fstream c6("drawboard.dat", ios::out | ios::binary);
							if (!c5 || !c6) {
								cout << "���ļ�ʧ�ܣ�����" << endl;
								exit(0);
								Sleep(1000);
							}
							c5.read((char*)&person, sizeof(person));
							while (!c5.eof()) {
								if ((strcmp(person.name, cename) == 0) && (cesex == person.sex) && (strcmp(person.telephone, cete) == 0)) {
									person.outcheck = 'o';
									exi++;
								}
								c6.write((char*)&person, sizeof(person));
							}
							c5.close();
							c6.close();
							if (exi == 0) {
								const char* savePath = "drawboard.dat";
								if (remove(savePath) != 0)
								{
									cout << "ɾ��drawboard.dat�ļ�ʧ�ܣ�����" << endl;
									cout << "�����������...";
									char chh = getchar();
									exit(0);
								}
								cout << "��δ�鵽����Ա���Ƿ��������룿(y/n):" << endl;
								char cc = ccin.Checkchmain();
								if (cc == 'y') {
									system("cls");
									continue;
								}
								else {
									system("cls");
									break;
								}
							}
							else {
								cxi = 1;
								break;
							}
						}
					}
					else {
						cout << "���ȵǼǸ�����Ϣ������" << endl;
						Personin per;
						per.creat();
						per.getdate();
						per.savepersonin();
						++per;
						cxi = 1;
						break;
					}
					if (cxi == 1) {
						break;
					}
				}
			}
		}
		system("cls");
		if (cxi == 1) {
			break;
		}
		
	}
	system("cls");
	cout << "�������ȥ��Ա������" << endl;
	cin >> person.name;
	cout << "�������ȥ��Ա���䣺" << endl;
	cin >> person.age;
	cout << "�������ȥ��Ա�绰���룺" << endl;
	cin >> person.telephone;
	cout << "�������ȥ��Ա�Ա�(F/M)��" << endl;
	s=ccin.Checksex();
	cout << "�����������Ա��ְ��(W/C):" << endl;
	w=ccin.Checkwork();
	cout << "�����������Ա��Ŀ�ĵأ�" << endl;
	cin >> person.place;
	cout << "���������ԭ��(�������)��" << endl;
	cin >> person.reason;
	cout << "�Ƿ�;������������(�人)(y/n):" << endl;
	ch=ccin.Checkchmain();
	person.sex = s;
	person.work = w;
	if (ch == 'y') {
		fstream file("Apersonout.txt", ios::app);
		if (!file) {
			cout << "��Apersonout.txt�ļ�ʧ�ܣ���" << endl;
			exit(0);
		}
		file << person.name << endl;
		file.close();
	}
}

void Personout::getdate()
{
	date indate;
	indate.setdate();
	person.dat.year = indate.getdate()->year;
	person.dat.month = indate.getdate()->month;
	person.dat.day = indate.getdate()->day;
}

void Personout::savepersonout()
{
	fstream f("personout.dat", ios::app | ios::binary);
	if (!f) {
		cout << "���ļ�personout.datʧ�ܣ�" << endl;
		exit(0);
	}
	f.write((char*)&person, sizeof(person));
	f.close();
}
