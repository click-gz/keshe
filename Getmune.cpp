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
	cout << "  ===========��¼===========" << endl;
	showtd.todaydate();
	cout << "|	1. �鿴˵��		|" << endl;
	cout << "|	2. ����Ա��¼		|" << endl;
	cout << "|	3. �Ǽ�Ŀ¼		|" << endl;
	cout << "|	4. ����Ŀ¼		|" << endl;
	cout << "|	5. ����ʱ��		|" << endl;
	cout << "|	6. ������ʾ		|" << endl;
	cout << "|	7. �˳�ϵͳ		|" << endl;
	cout << "�������Ӧ�������֣�" << endl;
}

void mune::GetmuneRegister()
{
	date showtd;
	cout << "  =========�Ǽ�Ŀ¼========" << endl;
	showtd.todaydate();
	cout << "||	1. ������Ա�Ǽ�		||" << endl;
	cout << "||	2. �����Ա�Ǽ�		||" << endl;
	cout << "||	3. ������Ա�Ǽ�		||" << endl;
	cout << "||	4. �ճ����µǼ�		||" << endl;
	cout << "||	5. ������Ǽ�		||" << endl;
	cout << "||	6. �˳�			||" << endl;
	cout << "�������Ӧ�������֣�" << endl;
}

void mune::GetmuneManager()
{
	system("cls");
	date showtd;
	showtd.todaydate();
	cout << "**��ӭ����Ա��½�����¹��ܿ��Խ��в���**" << endl;
	cout << "	1. �鿴����������Ա����Ϣ " << endl;
	cout << "	2. �鿴���������Ա����Ϣ" << endl;
	cout << "	3. �鿴���б�����Ա����Ϣ" << endl;
	cout << "	4. �鿴�������µǼǼ�¼" << endl;
	cout << "	5. ��Ҫ�����ĳ�˵���Ϣ" << endl;
	cout << "	6. �鿴/ɾ�����в�������" << endl;
	cout << "	7. �鿴���زֿ��е���������" << endl;
	cout << "	8. �鿴��Ա��������" << endl;
	cout << "	9. �޸��û�/����" << endl;
	cout << "	10. �˳���¼" << endl;
	cout << "��ѡ������Ĺ������(1-10):" << endl;
}

void mune::GetmuneManagerP()
{
	cout << "��Ҫ�鿴���в��˵����¼���¼������: 1" << endl;
	cout << "��Ҫ����ĳ������������: 2" << endl;
	cout << "��Ҫɾ��ĳ�����˼�¼������: 3" << endl;
}

void mune::GetmuneExplain()
{
	initgraph(640, 480);
	setbkcolor(WHITE);// ���ñ���ɫΪ��ɫ
	cleardevice();// �ñ���ɫ�����Ļ
	setcolor(BLACK);//����������ɫΪ��ɫ
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	RECT r = { 0, 0, 639, 479 };
	fstream m("mune.txt", ios::in);
	char ch[200];
	if (!m) {
		cout << "�򿪲˵�ʧ�ܣ�����" << endl;
		exit(0);
	}
	while (!m.eof()) {
		m.getline(ch, 200);
		drawtext(_T(ch), &r, DT_WORDBREAK);
	}
	if (m.eof()) {
		drawtext(_T("��������˳�..."), &r, DT_WORDBREAK| DT_SINGLELINE| DT_BOTTOM);
	}
	_getch();
	closegraph();
	m.close();
}

void mune::GetmuneSearchi()
{
	cout << endl;
	cout << "***Ŀǰ��ѯ����Ϊ������Ա***" << endl;
	cout << "��ѡ���ѯ���" << endl;
	cout << "1. ���ս���ʱ���ѯ" << endl;
	cout << "2. ����������ѯ" << endl;
	cout << "3. ���յ绰�����ѯ" << endl;
	cout << "4. ������Դ�ؽ��в�ѯ" << endl;
}

void mune::GetmuneSearcho()
{
	cout << endl;
	cout << "***Ŀǰ��ѯ����Ϊ�����Ա***" << endl;
	cout << "��ѡ���ѯ���" << endl;
	cout << "1. �������ʱ���ѯ" << endl;
	cout << "2. ����������ѯ" << endl;
	cout << "3. ���յ绰�����ѯ" << endl;
	cout << "4. ����Ŀ�ĵؽ��в�ѯ" << endl;
}

void mune::GetmuneStore()
{
	Store ku;
	ku.del_Masknum();
	ku.check_Masknum();
}
