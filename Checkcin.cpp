#include<iostream>
#include<Windows.h>
#include "Checkcin.h"
#include"Getmune.h"
using namespace std;

int Checkcin::Checkmaini()
{
	mune MU;
	char buf[1024];
	int i;
	while (true) {
		MU.GetmuneAll();
		cin >> i;
		cin.clear();
		fgets(buf, 1024, stdin);
		if (i < 1 || i > 7) {
			cout << "��������ȷ���빦����ţ�����" << endl;
			Sleep(1000);
		}
		else {
			break;
		}
		system("cls");
	}
	return i;
}

int Checkcin::Checkmainik()
{
	char buf[1024];
	int i;
	while (true) {
		cin >> i;
		cin.clear();
		fgets(buf, 1024, stdin);
		if (i < 1 || i>6) {
			cout << "��������ȷ���빦����ţ�����" << endl;
		}
		else {
			break;
		}
	}
	return i;
}

int Checkcin::Checkmanager()
{
	char buf[1024];
	int i;
	while (true) {
		cin >> i;
		cin.clear();
		fgets(buf, 1024, stdin);
		if (i < 1 || i>10) {
			cout << "��������ȷ���빦����ţ�����" << endl;
		}
		else {
			break;
		}
	}
	return i;
}

int Checkcin::Checkmanagerp()
{
	char buf[1024];
	int i;
	while (true) {
		cin >> i;
		cin.clear();
		fgets(buf, 1024, stdin);
		if (i < 1 || i>3) {
			cout << "��������ȷ���빦����ţ�����" << endl;
		}
		else {
			break;
		}
	}
	return i;
}

int Checkcin::Checksearchi(int ii)
{
	char buf[1024];
	int i;
	while (true) {
		cin >> i;
		cin.clear();
		fgets(buf, 1024, stdin);
		if (ii == 0) {
			if (i < 1 || i>4) {
				cout << "��������ȷ���빦����ţ�����" << endl;
			}
			else {
				break;
			}
		}
		else {
			if (i < 1 || i>3) {
				cout << "��������ȷ���빦����ţ�����" << endl;
			}
			else {
				break;
			}
		}
	}
	return i;
}

char Checkcin::Checkchmain()
{
	char ch;
	while (true) {
		cin >> ch;
		if (ch != 'n' && ch != 'y') {
			cout << "����ȷ�����ж�(y/n)!!!" << endl;
			system("cls");
			continue;
		}
		break;
	}
	return ch;
}

char Checkcin::Checkchsearch()
{
	char ch;
	while (true) {
		cin >> ch;
		if (ch != 'i' && ch != 'o'&&ch!='L') {
			cout << "����ȷ����Ҫ��Ѷ��Ա����𣡣���(i/o/L)" << endl;
			continue;
		}
		break;
	}
	return ch;
}

char Checkcin::CheckchStore()
{
	char ch;
	while (true) {
		cin >> ch;
		if (ch != 'M' && ch != 'R') {
			cout << "����ȷ����Ҫ��ӵ���Ʒ����𣡣���(M/R)" << endl;
			continue;
		}
		break;
	}
	return ch;
}

char Checkcin::Checksex()
{
	char ch;
	while (true) {
		cin >> ch;
		if (ch != 'F' && ch != 'M') {
			cout << "����ȷ�����Ա𣡣���(F/M)" << endl;
			continue;
		}
		break;
	}
	return ch;
}

char Checkcin::Checkwork()
{
	char ch;
	while (true) {
		cin >> ch;
		if (ch != 'C' && ch != 'W') {
			cout << "����ȷ�������ͣ�����(C/W)" << endl;
			continue;
		}
		break;
	}
	return ch;
}

