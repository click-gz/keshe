#include<iostream>
#include<fstream>
#include "Code.h"
#include"Checkcin.h"
using namespace std;

char*  Code::getcode()
{
	Checkcin ccin;
	while (true) {
		cout << "��������˵����֤����λ����Ϊ�Ǽ��룺" << endl;
		for (int i = 0;i < 6;i++) {
			cin >> pcode[i];
		}
		pcode[6] = '\0';
		cout << "���ĵǼ���Ϊ��" << pcode << endl;
		cout << "����Ҫ�޸�������y,��������n:" << endl;
		char chh = ccin.Checkchmain();
		if (chh == 'y') {
			system("cls");
			continue;
		}
		else {
			break;
		}
	}
	return pcode;
}

int Code::checkCodein(char c[7])
{
	int ci = 0;
	allperson al;
	strcpy_s(pcode, c);
	fstream f("personin.dat", ios::in | ios::binary);
	if (!f) {
		cout << "���ļ�ʧ��" << endl;
		exit(0);
	}
	f.read((char*)&al, sizeof(al));
	while (!f.eof()) {
		if (strcmp(al.Personcode , pcode)==0) {
			ci++;
		}
		f.read((char*)&al, sizeof(al));
	}
	f.close();
	return ci;
}

int Code::checkCodelocal(char c[7])
{
	int ci = 0;
	allperson al;
	strcpy_s(pcode, c);
	fstream f("Personlocal.dat", ios::in | ios::binary);
	if (!f) {
		cout << "���ļ�ʧ��" << endl;
		exit(0);
	}
	f.read((char*)&al, sizeof(al));
	while (!f.eof()) {
		if (strcmp(al.Personcode, pcode) == 0) {
			ci++;
		}
	}
	f.close();
	return ci;
}
