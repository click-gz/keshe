#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include "Patient.h"
using namespace std;
patient::patient()
{
	fstream O("Patient.txt", ios::in);
	if (!O) {
		fstream P("Patient.txt", ios::out);
		if (!P) {
			cout << "打开Patient.txt文件失败！！！" << endl;
			exit(0);
		}
		else {
			P.close();
		}
	}
	else {
		O.close();
	}
}
void patient::getnum_patient()
{
	char name[10];
	fstream T("Patient.txt", ios::in);
	if (!T) {
		cout << "打开Patient.txt失败！！！" << endl;
		exit(0);
	}
	if (T.getline(name, 10).good()) {
		while (!T.eof()) {
			num_patient++;
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
}

void patient::printnum_patient()
{
	cout << "***记录在线的病人有：" << num_patient << "位***" << endl;
}

void patient::savepatient()
{
	int ck = 0;
	fstream T("temperature.dat", ios::in | ios::binary);
	Record_Tem ex;
	if (!T) {
		fstream TT("temperature.dat", ios::out | ios::binary);
		if(!TT){
			cout << "打开temperature.dat文件失败！！！" << endl;
			exit(0);
		}
		TT.close();
	}
	else {
		T.read((char*)&ex, sizeof(ex));
		while (!T.eof()) {
			ck = 0;
			if (ex.temp >= maxtem) {
				fstream tp("test.dat", ios::in | ios::binary);
				if (!tp) {
					cout << "无法打开test.dat文件！！！" << endl;
					exit(0);
				}
				testperson pp;
				tp.read((char*)&pp, sizeof(pp));
				while (!tp.eof()) {
					if (strcmp(pp.name, ex.name) == 0) {
						ck++;
						break;
					}
					else {
						tp.read((char*)&pp, sizeof(pp));
					}
				}
				if (ck != 0) {
					int i = 0;
					char n[10];
					fstream O("Patient.txt", ios::in);
					if (!O) {
						fstream P("Patient.txt", ios::out);
						if (!P) {
							cout << "打开Patient.txt文件失败！！！" << endl;
							exit(0);
						}
						else {
							P.close();
							fstream O("Patient.txt", ios::in);
						}
					}
					if (O.getline(n, 10).good()) {
						while (!O.eof()) {
							if (strcmp(ex.name, n) == 0) {
								i = 1;
								O.close();
								break;
							}
							if (O.getline(n, 10).good()) {
								continue;
							}
							if (O.eof()) {
								break;
							}
							cout << "读入错误！！！" << endl;
							exit(0);
						}
					}
					O.close();
					if (i == 1) {
						T.read((char*)&ex, sizeof(ex));
						continue;
					}
					else {
						if (pp.result == 'y') {
							fstream M("Patient.txt", ios::app);
							M << ex.name << endl;
							M.close();
						}
					}
				}
			}
			T.read((char*)&ex, sizeof(ex));
		}
		T.close();
	}
}

void patient::show_patienttem()
{
	int i = 0;
	char n[10];
	fstream T("Patient.txt", ios::in);
	if (!T) {
		cout << "打开Patient.txt失败！！！" << endl;
		exit(0);
	}
	T.getline(n,10);
	while (!T.eof()) {
		cout << "姓名：" << n << "  " << "历史体温记录：" << endl;
		fstream M("temperature.dat", ios::in | ios::binary);
		Record_Tem ex;
		if (!M) {
			cout << "无法打开temperature.dat文件！！！" << endl;
			exit(0);
		}
		M.read((char*)&ex, sizeof(ex));
		while (!M.eof()) {
			if (strcmp(ex.name, n) == 0) {
				i++;
				cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "度" << endl;
			}
			M.read((char*)&ex, sizeof(ex));
		}
		M.close();
		cout << "按任意键继续...";
		char chh = getchar();
		system("cls");
		T.getline(n, 10);
	}
	T.close();
	if (i == 0) {
		cout << "暂无病人登记" << endl;
	}
}

void patient::check_patient()
{
	int i = 0;
	char n[10],na[10];
	cout << "请选择要查找的病人的姓名：" << endl;
	cin >> n;
	fstream T("Patient.txt", ios::in);
	if (!T) {
		cout << "打开Patient.txt失败！！！" << endl;
		exit(0);
	}
	T.getline(na, 10);
	while (!T.eof()) {
		if (strcmp(na, n) == 0) {
			i = 1;
			break;
		}
		T.getline(na, 10);
	}
	T.close();
	if (i == 0) {
		cout << "没有此病人！！！" << endl;
	}
	else {
		int k = 0;
		fstream in("personin.dat", ios::in | ios::binary);
		struct allperson p;
		if (!in) {
			cout << "读取personin.dat文件失败!!!" << endl;
			exit(0);
		}
		in.read((char*)&p, sizeof(p));
		while (!in.eof()) {
			if (strcmp(n, p.name) == 0) {
				if (k == 0) {
					cout << "此为进来人员的信息：" << endl;
					i++;
				}
				cout << "-------------------" << endl;
				cout << "姓名：" << p.name << endl;
				cout << "性别：" << p.sex << endl;
				cout << "年龄：" << p.age << endl;
				cout << "电话号码：" << p.telephone << endl;
				cout << "职务：" << p.work << endl;
				cout << "来源地：" << p.place << endl;
				cout << "姓名：" << n << "  " << "历史体温记录：" << endl;
				fstream M("temperature.dat", ios::in | ios::binary);
				Record_Tem ex;
				if (!M) {
					cout << "无法打开temperature.dat文件！！！" << endl;
					exit(0);
				}
				M.read((char*)&ex, sizeof(ex));
				while (!M.eof()) {
					if (strcmp(ex.name, n) == 0) {
						cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "度" << endl;
					}
					M.read((char*)&ex, sizeof(ex));
				}
				M.close();
				fstream file("Apersonin.txt",ios::in);
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
			}
			in.read((char*)&p, sizeof(p));
		}
		in.close();
		k = 0;
		fstream out("personout.dat", ios::in | ios::binary);
		if (!out) {
			cout << "读取personout.dat文件失败!!!" << endl;
			exit(0);
		}
		out.read((char*)&p, sizeof(p));
		while (!out.eof()) {
			if (strcmp(n, p.name) == 0) {
				if (k == 0) {
					cout << "此为外出人员的信息：" << endl;
					i++;
				}
				cout << "-------------------" << endl;
				cout << "姓名：" << p.name << endl;
				cout << "性别：" << p.sex << endl;
				cout << "年龄：" << p.age << endl;
				cout << "电话号码：" << p.telephone << endl;
				cout << "职务：" << p.work << endl;
				cout << "目的地：" << p.place << endl;
				cout << "外出原因：" << p.reason << endl;
				cout << "外出时间：" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
				fstream M("temperature.dat", ios::in | ios::binary);
				Record_Tem ex;
				if (!M) {
					cout << "无法打开temperature.dat文件！！！" << endl;
					exit(0);
				}
				M.read((char*)&ex, sizeof(ex));
				while (!M.eof()) {
					if (strcmp(ex.name, n) == 0) {
						cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "度" << endl;
					}
					M.read((char*)&ex, sizeof(ex));
				}
				M.close();
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
			}
			out.read((char*)&p, sizeof(p));
		}
		out.close();

	}
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
}

void patient::delete_patient()
{
	patient::getnum_patient();
	if (num_patient == 0) {
		cout << "暂无病人登记" << endl;
	}
	else {
		int i = 0;
		char n[10], n1[10];
		fstream TT("Patient.txt", ios::in);
		if (!TT) {
			cout << "打开Patient.txt失败！！！" << endl;
			exit(0);
		}
		TT.getline(n1, 10);
		cout << "以下为登记的病人姓名：" << endl;
		while (!TT.eof()) {
			cout << n1 << endl;
			TT.getline(n1, 10);
		}
		TT.close();
		fstream T("Patient.txt", ios::in);
		fstream T_1("Patient1.txt", ios::out);
		if (!T_1) {
			cout << "打开文件失败" << endl;
			exit(0);
		}
		if (!T) {
			cout << "打开Patient.txt失败！！！" << endl;
			exit(0);
		}
		cout << "请选择你要删除的病人的姓名：";
		cin >> n;
		if (T.getline(n1, 10).good()) {
			int ckk = 0;
			while (!T.eof()) {
				if (i != 1 && strcmp(n1, n) == 0) {
					i = 1;
					if (IDYES == MessageBox(NULL, "是否删除该病人?", "Comfirm Message", MB_YESNO | MB_ICONQUESTION))
					{
						ckk++;
						T.getline(n, 10);
						if (T.eof()) {
							ckk++;
							break;
						}
					}

				}
				if (ckk == 0) {
					T_1 << n1 << endl;
				}
				if (T.getline(n, 10).good()) {
					continue;
				}
				if (T.eof()) {
					break;
				}
				cout << "读入错误！！！" << endl;
				exit(0);
			}
		}
		T.close();
		T_1.close();
		fstream T3("Patient.txt", ios::out);
		fstream T2("Patient1.txt", ios::in);
		if (!T2) {
			cout << "打开文件失败" << endl;
			exit(0);
		}
		if (!T3) {
			cout << "打开Patient.txt失败！！！" << endl;
			exit(0);
		}
		T2.getline(n1, 10);
		while (!T2.eof()) {
			T3 << n1;
			T2.getline(n1, 10);
		}
		T2.close();
		T3.close();
		const char* savePath = "Patient1.txt";
		if (remove(savePath) != 0)
		{
			cout << "删除文件patient1失败！！！" << endl;
			cout << "按任意键继续...";
			char chh = getchar();
			exit(0);
		}
	}
}

void patient::attention_patient()
{
	system("mode con cols=45 lines=25  ");
	int ck = 0 , ckk = 0;
	fstream T("temperature.dat", ios::in | ios::binary);
	Record_Tem ex;
	if (!T) {
		cout << "打开temperature.dat文件失败！！！" << endl;
		exit(0);
	}
	T.read((char*)&ex, sizeof(ex));
	while (!T.eof()) {
		ck = 0;
		if (ex.temp >= maxtem) {
			fstream tp("test.dat", ios::in | ios::binary);
			if (!tp) {
				cout << "无法打开test.dat文件！！！" << endl;
				exit(0);
			}
			testperson pp;
			tp.read((char*)&pp, sizeof(pp));
			while (!tp.eof()) {
				if (strcmp(pp.name, ex.name) == 0) {
					ck++;
					break;
				}
				else {
					tp.read((char*)&pp, sizeof(pp));
				}
			}
			if (ck == 0) {
				ckk++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				//设置红色
				cout << ex.name;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
				cout << " 体温过高";
				cout << "且查无核酸检测结果" << endl;
				cout << "请及时对其进行核酸检测！！！" << endl;
				cout << endl;
				T.read((char*)&ex, sizeof(ex));
				continue;
			}
			else {
				int i = 0;
				char n[10];
				fstream O("Patient.txt", ios::in);
				if (!O) {
					fstream P("Patient.txt", ios::out);
					if (!P) {
						cout << "打开Patient.txt文件失败！！！" << endl;
						exit(0);
					}
					else {
						P.close();
						fstream O("Patient.txt", ios::in);
					}
				}
				if (O.getline(n, 10).good()) {
					while (!O.eof()) {
						if (strcmp(ex.name, n) == 0) {
							i = 1;
							O.close();
							break;
						}
						if (O.getline(n, 10).good()) {
							continue;
						}
						if (O.eof()) {
							break;
						}
						cout << "读入错误！！！" << endl;
						exit(0);
					}
				}
				O.close();
				if (i == 1) {
					if (ckk == 7) {
						cout << "按任意键继续...";
						char chh = getchar();
						system("cls");
						ckk = 0;
					}
					T.read((char*)&ex, sizeof(ex));
					continue;
				}
				else {
					if (pp.result == 'y') {
						if (ckk == 7) {
							cout << "按任意键继续...";
							char chh = getchar();
							system("cls");
							ckk = 0;
						}
						continue;
					}
					else {
						ckk++;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//设置红色
						cout << ex.name;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//恢复原色
						cout << "  当前体温过高，建议重新进行核酸鉴定！！！" << endl;
					}
				}
			}
		}
		if (ckk == 7) {
			cout << "按任意键继续...";
			char chh = getchar();
			system("cls");
			ckk = 0;
		}
		T.read((char*)&ex, sizeof(ex));
	}
	cout << "按任意键继续...";
	char chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
