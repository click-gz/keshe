#include<iostream>
#include<fstream>
#include <graphics.h>
#include <conio.h>
#include"windows.h"
#include"date.h"
#include "Getmune.h"
#include"Store.h"

using namespace std;
void mune::GetmuneAll()
{
	system("mode con cols=40 lines=20  ");
	date showtd;
	cout << "  ===========登录===========" << endl;
	showtd.todaydate();
	cout << "|	1. 查看说明		|" << endl;
	cout << "|	2. 管理员登录		|" << endl;
	cout << "|	3. 登记目录		|" << endl;
	cout << "|	4. 警报目录		|" << endl;
	cout << "|	5. 限制时长		|" << endl;
	cout << "|	6. 体温提示		|" << endl;
	cout << "|	7. 退出系统		|" << endl;
	cout << "请输入对应功能数字：" << endl;
}

void mune::GetmuneRegister()
{
	date showtd;
	cout << "  =========登记目录========" << endl;
	showtd.todaydate();
	cout << "||	1. 外来人员登记		||" << endl;
	cout << "||	2. 外出人员登记		||" << endl;
	cout << "||	3. 本地人员登记		||" << endl;
	cout << "||	4. 日常体温登记		||" << endl;
	cout << "||	5. 核酸检测登记		||" << endl;
	cout << "||	6. 退出			||" << endl;
	cout << "请输入对应功能数字：" << endl;
}

void mune::GetmuneManager()
{
	system("cls");
	date showtd;
	showtd.todaydate();
	cout << "**欢迎管理员登陆，以下功能可以进行操作**" << endl;
	cout << "	1. 查看所有外来人员的信息 " << endl;
	cout << "	2. 查看所有外出人员的信息" << endl;
	cout << "	3. 查看所有本地人员的信息" << endl;
	cout << "	4. 查看所有体温登记记录" << endl;
	cout << "	5. 按要求查找某人的信息" << endl;
	cout << "	6. 查看/删除所有病人详情" << endl;
	cout << "	7. 查看本地仓库中的物资详情" << endl;
	cout << "	8. 查看人员比例详情" << endl;
	cout << "	9. 修改用户/密码" << endl;
	cout << "	10. 退出登录" << endl;
	cout << "请选择操作的功能序号(1-10):" << endl;
}

void mune::GetmuneManagerP()
{
	cout << "若要查看所有病人的体温检测记录请输入: 1" << endl;
	cout << "若要查找某个病人请输入: 2" << endl;
	cout << "若要删除某个病人记录请输入: 3" << endl;
}

void mune::GetmuneExplain()
{
	initgraph(640, 480);
	setbkcolor(WHITE);// 设置背景色为白色
	cleardevice();// 用背景色清空屏幕
	setcolor(BLACK);//设置字体颜色为黑色
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”
	RECT r = { 0, 0, 639, 479 };
	fstream m("mune.txt", ios::in);
	char ch[200];
	if (!m) {
		cout << "打开菜单失败！！！" << endl;
		exit(0);
	}
	while (!m.eof()) {
		m.getline(ch, 200);
		drawtext(_T(ch), &r, DT_WORDBREAK);
	}
	if (m.eof()) {
		drawtext(_T("按任意键退出..."), &r, DT_WORDBREAK| DT_SINGLELINE| DT_BOTTOM);
	}
	_getch();
	closegraph();
	m.close();
}

void mune::GetmuneSearchi()
{
	cout << endl;
	cout << "***目前查询对象为进入人员***" << endl;
	cout << "请选择查询类别：" << endl;
	cout << "1. 按照进入时间查询" << endl;
	cout << "2. 按照人名查询" << endl;
	cout << "3. 按照电话号码查询" << endl;
	cout << "4. 按照来源地进行查询" << endl;
}

void mune::GetmuneSearcho()
{
	cout << endl;
	cout << "***目前查询对象为外出人员***" << endl;
	cout << "请选择查询类别：" << endl;
	cout << "1. 按照外出时间查询" << endl;
	cout << "2. 按照人名查询" << endl;
	cout << "3. 按照电话号码查询" << endl;
	cout << "4. 按照目的地进行查询" << endl;
}

void mune::GetmuneStore()
{
	Store ku;
	ku.del_Masknum();
	ku.check_Masknum();
}
