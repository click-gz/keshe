#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<windows.h>
#include <graphics.h>
#include <conio.h>
#include "load.h"
#include"Checkcin.h"
using namespace std;
char* hashcheck(char p[20]);
loadperson::loadperson()
{
	fstream L("load.dat", ios::in | ios::binary);
	if (!L) {
		fstream L("load.dat", ios::out | ios::binary);
		L.close();
	}
	else {
		L.read((char*)&exp, sizeof(exp));
		L.close();
	}
}
loadperson::loadperson(char n[20], char s[20])
{
	strcpy_s(exp.name, n);
	strcpy_s(exp.password, s);
}

int loadperson::check(char name[20],char pa[20])
{
	char* na = new char[strlen(name) + 1];
	char* ppa = new char[strlen(pa) + 1];
	strcpy_s(na, strlen(name) + 1, name);
	strcpy_s(ppa, strlen(pa) + 1, pa);
	fstream L("load.dat", ios::in | ios::binary);
	if (!L) {
		cout << "打开文件失败！！！" << endl;
		exit(0);
	}
	L.read((char*)&exp, sizeof(exp));
	L.close();
	while (true) {
		if (strcmp(na, exp.name) == 0 && strcmp(hashcheck(ppa) , exp.password)==0) {
			outtextxy(80, 130, "登 陆 成 功");
			Sleep(1000);
			closegraph();
			return 1;
			break;
		}
		else {
			cleardevice();
			loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
			char s[50];
			InputBox(s, 50, "抱歉，登录用户或密码错误！！\r 是否忘记密码?(y/n)");
			char cc;
			sscanf_s(s, "%c", &cc);
			if (cc == 'y') {
				char ss[50];
				InputBox(ss, 50, "请输入产品密钥，重新设置用户：");
				//密钥为**88**
				if (strcmp(ss, "**88**") == 0) {
					loadperson::changeload();
					loadperson::saveloadperson();
					cleardevice();
					loadimage(NULL, _T("F:\\bk.jpg"));
					RECT r = { 0, 0, 299, 299 };
					drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
					RECT p = { 44, 22, 299, 299 };
					drawtext(_T("用户名："), &p, DT_WORDBREAK);
					RECT pp = { 44, 55, 299, 299 };
					drawtext(_T("密码："), &pp, DT_WORDBREAK);
					string str1, str2;
					char c;
					while ((c = _getch()) != '\r')  //如果没按回车，接收一个c
					{  //getch()头文件 conio.h
						str2 = "";
						if (c == '\b')  //如果c是退格符，str1删掉一个
						{
							str1 = str1.substr(0, str1.size() - 1);
						}
						else {
							str1 += (int)c;
						}
						str2 = "用户名:" + str1;
						cleardevice();
						loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
						RECT r = { 0, 0, 299, 299 };
						drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
						outtextxy(44, 22, str2.c_str());
						RECT pp = { 44, 55, 299, 299 };
						drawtext(_T("密码："), &pp, DT_WORDBREAK);
					}
					char ch;
					string str3, str4;
					drawtext(_T("密码："), &pp, DT_WORDBREAK);
					while ((ch = _getch()) != '\r')  //如果没按回车，接收一个c
					{  //getch()头文件 conio.h
						str4 = "";
						if (ch == '\b')  //如果c是退格符，str1删掉一个
						{
							str3 = str3.substr(0, str3.size() - 1);

						}
						else {
							str3 += (int)ch;
						}
						str4 = "密码：" + str3;
						cleardevice();
						loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
						RECT r = { 0, 0, 299, 299 };
						drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
						outtextxy(44, 22, str2.c_str());
						outtextxy(44, 55, str4.c_str());
					}
					strcpy_s(na, strlen(str1.c_str()) + 1, (char*)str1.c_str());
					strcpy_s(ppa, strlen(str3.c_str()) + 1, (char*)str3.c_str());
					continue;
				}
				else {
					outtextxy(44, 22, "密钥错误！！即将退出登录系统！！");
					outtextxy(77, 44, "按任意键继续...");
					_getch();
					closegraph();
					system("cls");
					return 2;
					break;
				}
			}
			else {
				system("cls");
				char sss[50];
				InputBox(sss, 50, "是否重新登录？(y/n)");
				char chhhh;
				sscanf_s(sss, "%c", &chhhh);
				if (chhhh == 'y') {
					cleardevice();
					loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
					RECT r = { 0, 0, 299, 299 };
					drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
					RECT p = { 44, 22, 299, 299 };
					drawtext(_T("用户名："), &p, DT_WORDBREAK);
					RECT pp = { 44, 55, 299, 299 };
					drawtext(_T("密码："), &pp, DT_WORDBREAK);
					string str1, str2;
					char c;
					while ((c = _getch()) != '\r')  //如果没按回车，接收一个c
					{  //getch()头文件 conio.h
						str2 = "";
						if (c == '\b')  //如果c是退格符，str1删掉一个
						{
							str1 = str1.substr(0, str1.size() - 1);

						}
						else {
							str1 += (int)c;
						}
						str2 = "用户名:" + str1;
						cleardevice();
						loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
						RECT r = { 0, 0, 299, 299 };
						drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
						outtextxy(44, 22, str2.c_str());
						RECT pp = { 44, 55, 299, 299 };
						drawtext(_T("密码："), &pp, DT_WORDBREAK);
					}
					char ch;
					string str3, str4;
					drawtext(_T("密码："), &pp, DT_WORDBREAK);
					while ((ch = _getch()) != '\r')  //如果没按回车，接收一个c
					{  //getch()头文件 conio.h
						str4 = "";
						if (ch == '\b')  //如果c是退格符，str1删掉一个
						{
							str3 = str3.substr(0, str3.size() - 1);

						}
						else {
							str3 += (int)ch;
						}
						str4 = "密码：" + str3;
						cleardevice();
						loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
						RECT r = { 0, 0, 299, 299 };
						drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
						outtextxy(44, 22, str2.c_str());
						outtextxy(44, 55, str4.c_str());
					}
					for (int j = 80;j < 151;j++) {
						if (j == 90 || j == 105 || j == 120 || j == 135 || j == 150) {
							j = j + 5;
						}
						else {
							for (int i = 100;i < 110;i++) {
								putpixel(j, i, RGBtoGRAY(BLUE));
							}
						}
						Sleep(30);
					}
					for (int j = 80;j < 151;j++) {
						if (j == 90 || j == 105 || j == 120 || j == 135 || j == 150) {
							j = j + 5;
						}
						else {
							for (int i = 100;i < 110;i++) {
								putpixel(j, i, RGBtoGRAY(BLUE));
							}
						}
						Sleep(30);
					}
					/*na = (char*)str1.c_str();
					ppa = (char*)str3.c_str();*/
					strcpy_s(na, strlen(str1.c_str())+1, (char*)str1.c_str());
					strcpy_s(ppa, strlen(str3.c_str()) + 1, (char*)str3.c_str());
					continue;
				}
				else {
					return 2;
					break;
				}
			}
		}
	}
}

void loadperson::changeload(int i)
{
	if (i == 1) {
		initgraph(300, 300);
		setbkcolor(WHITE);// 设置背景色为白色
		setcolor(BLACK);//设置字体颜色为黑色
		LOGFONT f;
		gettextstyle(&f);						// 获取当前字体设置
		_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	}
	loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
	RECT r = { 0, 0, 299, 299 };
	drawtext(_T("修改界面"), &r, DT_WORDBREAK | DT_CENTER);
	RECT p = { 44, 22, 299, 299 };
	drawtext(_T("修改后用户名："), &p, DT_WORDBREAK);
	RECT pp = { 44, 55, 299, 299 };
	drawtext(_T("修改后密码："), &pp, DT_WORDBREAK);
	string str1, str2;
	char c;
	while ((c = _getch()) != '\r')  //如果没按回车，接收一个c
	{  //getch()头文件 conio.h
		str2 = "";
		if (c == '\b')  //如果c是退格符，str1删掉一个
		{
			str1 = str1.substr(0, str1.size() - 1);

		}
		else {
			str1 += (int)c;
		}
		str2 = "修改后用户名：" + str1;
		cleardevice();
		loadimage(NULL, _T("F:\\bk.jpg"));
		RECT r = { 0, 0, 299, 299 };
		drawtext(_T("修改界面"), &r, DT_WORDBREAK | DT_CENTER);
		outtextxy(44, 22, str2.c_str());
		RECT pp = { 44, 55, 299, 299 };
		drawtext(_T("修改后密码："), &pp, DT_WORDBREAK);
	}
	char ch;
	string str3, str4;
	drawtext(_T("修改后密码："), &pp, DT_WORDBREAK);
	while ((ch = _getch()) != '\r')  //如果没按回车，接收一个c
	{  //getch()头文件 conio.h
		str4 = "";
		if (ch == '\b')  //如果c是退格符，str1删掉一个
		{
			str3 = str3.substr(0, str3.size() - 1);

		}
		else {
			str3 += (int)ch;
		}
		str4 = "修改后密码：" + str3;
		cleardevice();
		loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
		RECT r = { 0, 0, 299, 299 };
		drawtext(_T("修改界面"), &r, DT_WORDBREAK | DT_CENTER);
		outtextxy(44, 22, str2.c_str());
		outtextxy(44, 55, str4.c_str());
	}
	strcpy_s(exp.name , (char*)str1.c_str());
	strcpy_s(exp.password, (char*)str3.c_str());
	if (i == 1) {
		RECT r = { 0, 0, 299, 299 };
		drawtext(_T("修改成功，按任意键继续..."), &r, DT_WORDBREAK | DT_SINGLELINE | DT_BOTTOM);
		_getch();
		closegraph();
	}
}

void loadperson::saveloadperson()
{
	fstream Load("load.dat", ios::out | ios::binary);
	if (!Load) {
		cout << "打开文件失败！！" << endl;
		exit(0);
	}
	strcpy_s(exp.password,20,hashcheck(exp.password));
	Load.write((char*)&exp,sizeof(exp));
	Load.close();
}

char* hashcheck(char p[20]){
	int len =strlen(p);
	int i = 0, s = 0;
	int itmp;
	char space[20]="****+++****----****";
	while (true) {
		itmp = space[s % 19] + p[i];
		if (itmp >= 65 && itmp <= 90) {
			space[s % 19] = (char)itmp;
		}
		else {
			while (true) {
				itmp -= 10;
				if (itmp >= 65 && itmp <= 90) {
					space[s % 19] = (char)itmp;
					break;
				}
			}
		}
		s++;
		i++;
		if (i == len) {
			return space;
			break;
		}
	}
}

int loadperson::loadfirst(int i)
{
	initgraph(300, 300);
	loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
	setbkcolor(WHITE);// 设置背景色为白色
	//cleardevice();// 用背景色清空屏幕
	setcolor(BLACK);//设置字体颜色为黑色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	// 在屏幕中央输出字符串
	RECT r = { 0, 0, 299, 299 };
	drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
	RECT p = { 44, 22, 299, 299 };
	drawtext(_T("用户名："), &p, DT_WORDBREAK);
	RECT pp = { 44, 55, 299, 299 };
	drawtext(_T("密码："), &pp, DT_WORDBREAK);
	string str1, str2;
	char c;
	while ((c = _getch()) != '\r')  //如果没按回车，接收一个c
	{  //getch()头文件 conio.h
		str2 = "";
		if (c == '\b')  //如果c是退格符，str1删掉一个
		{
			str1 = str1.substr(0, str1.size() - 1);

		}
		else {
			str1 += (int)c;
		}
		str2 = "用户名:" + str1;
		cleardevice();
		loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
		RECT r = { 0, 0, 299, 299 };
		drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
		outtextxy(44, 22, str2.c_str());
		RECT pp = { 44, 55, 299, 299 };
		drawtext(_T("密码："), &pp, DT_WORDBREAK);
	}
	char ch;
	string str3, str4;
	drawtext(_T("密码："), &pp, DT_WORDBREAK);
	while ((ch = _getch()) != '\r')  //如果没按回车，接收一个c
	{  //getch()头文件 conio.h
		str4 = "";
		if (ch == '\b')  //如果c是退格符，str1删掉一个
		{
			str3 = str3.substr(0, str3.size() - 1);

		}
		else {
			str3 += (int)ch;
		}
		str4 = "密码：" + str3;
		cleardevice();
		loadimage(NULL, _T("F:\\c++\\c++课设\\bk.jpg"));
		RECT r = { 0, 0, 299, 299 };
		drawtext(_T("登录界面"), &r, DT_WORDBREAK | DT_CENTER);
		outtextxy(44, 22, str2.c_str());
		outtextxy(44, 55, str4.c_str());
	}
	for (int j = 80;j < 151;j++) {
		if (j == 90 || j == 105 || j == 120 || j == 135 || j == 150) {
			j = j + 5;
		}
		else {
			for (int i = 100;i < 110;i++) {
				putpixel(j, i, RGBtoGRAY(BLUE));
			}
		}
		Sleep(30);
	}
	char* na = (char*)str1.c_str();
	char* pa = (char*)str3.c_str();
	if (i == 0) {
		loadperson first(na, pa);
		first.saveloadperson();
		return first.check(na, pa);
	}
	else {
		loadperson se;
		return se.check(na, pa);
	}
}