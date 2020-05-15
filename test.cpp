#include<iostream>
#include<fstream>
#include "test.h"
using namespace std;

void test::gettest()
{
	int i;
	char ch;
	while (true) {
		cout << "此为核酸检测结果的登记,请输入您的姓名：" << endl;
		cin >> tp.name;
		while (true) {
			cout << "请输入您的核酸检测结果 " << endl;
			cout << "如果检测结果为阴性请输入n,否则输入y:" << endl;
			cin >> ch;
			if (ch == 'y') {
				tp.result = ch;
				cout << "您的核酸检测结果为阳性，是否正确？" << endl;
				cout << "如若需要修改，请输入 1，若不需要请输入 2：" << endl;
				cin >> i;
				if (i == 1) {
					continue;
				}
				else {
					fstream tt("test.dat", ios::app | ios::binary);
					if (!tt) {
						cout << "打开test.dat文件失败！！！" << endl;
						exit(0);
					}
					tt.write((char*)&tp, sizeof(tp));
					tt.close();
					break;
				}
			}
			else if (ch == 'n') {
				tp.result = ch;
				cout << "您的核酸检测结果为阴性，是否正确？" << endl;
				cout << "如若需要修改，请输入 1，若不需要请输入 2：" << endl;
				cin >> i;
				if (i == 1) {
					continue;
				}
				else {
					fstream tt("test.dat", ios::app | ios::binary);
					if (!tt) {
						cout << "打开test.dat文件失败！！！" << endl;
						exit(0);
					}
					tt.write((char*)&tp, sizeof(tp));
					tt.close();
					break;
				}
			}
			else {
				cout << "请正确输入您的核酸检测结果！！！" << endl;
				continue;
			}
		}
		cout << "是否需要继续添加核酸检测结果(y/n)"<<endl;
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
