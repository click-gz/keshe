#include<iostream>
#include<fstream>
#include "test.h"
using namespace std;

void test::gettest()
{
	int i;
	char ch;
	while (true) {
		cout << "��Ϊ���������ĵǼ�,����������������" << endl;
		cin >> tp.name;
		while (true) {
			cout << "���������ĺ������� " << endl;
			cout << "��������Ϊ����������n,��������y:" << endl;
			cin >> ch;
			if (ch == 'y') {
				tp.result = ch;
				cout << "���ĺ�������Ϊ���ԣ��Ƿ���ȷ��" << endl;
				cout << "������Ҫ�޸ģ������� 1��������Ҫ������ 2��" << endl;
				cin >> i;
				if (i == 1) {
					continue;
				}
				else {
					fstream tt("test.dat", ios::app | ios::binary);
					if (!tt) {
						cout << "��test.dat�ļ�ʧ�ܣ�����" << endl;
						exit(0);
					}
					tt.write((char*)&tp, sizeof(tp));
					tt.close();
					break;
				}
			}
			else if (ch == 'n') {
				tp.result = ch;
				cout << "���ĺ�������Ϊ���ԣ��Ƿ���ȷ��" << endl;
				cout << "������Ҫ�޸ģ������� 1��������Ҫ������ 2��" << endl;
				cin >> i;
				if (i == 1) {
					continue;
				}
				else {
					fstream tt("test.dat", ios::app | ios::binary);
					if (!tt) {
						cout << "��test.dat�ļ�ʧ�ܣ�����" << endl;
						exit(0);
					}
					tt.write((char*)&tp, sizeof(tp));
					tt.close();
					break;
				}
			}
			else {
				cout << "����ȷ�������ĺ�������������" << endl;
				continue;
			}
		}
		cout << "�Ƿ���Ҫ������Ӻ�������(y/n)"<<endl;
		char l;
		cin >> l;
		if (l == 'y') {
			continue;
		}
		else {
			break;
		}
	}
}
