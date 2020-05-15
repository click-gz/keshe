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
			cout << "��Patient.txt�ļ�ʧ�ܣ�����" << endl;
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
		cout << "��Patient.txtʧ�ܣ�����" << endl;
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
				cout << "��ȡPatient.txt���󣡣���" << endl;
				exit(0);
			}
		}
	}
	T.close();
}

void patient::printnum_patient()
{
	cout << "***��¼���ߵĲ����У�" << num_patient << "λ***" << endl;
}

void patient::savepatient()
{
	int ck = 0;
	fstream T("temperature.dat", ios::in | ios::binary);
	Record_Tem ex;
	if (!T) {
		fstream TT("temperature.dat", ios::out | ios::binary);
		if(!TT){
			cout << "��temperature.dat�ļ�ʧ�ܣ�����" << endl;
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
					cout << "�޷���test.dat�ļ�������" << endl;
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
							cout << "��Patient.txt�ļ�ʧ�ܣ�����" << endl;
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
							cout << "������󣡣���" << endl;
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
		cout << "��Patient.txtʧ�ܣ�����" << endl;
		exit(0);
	}
	T.getline(n,10);
	while (!T.eof()) {
		cout << "������" << n << "  " << "��ʷ���¼�¼��" << endl;
		fstream M("temperature.dat", ios::in | ios::binary);
		Record_Tem ex;
		if (!M) {
			cout << "�޷���temperature.dat�ļ�������" << endl;
			exit(0);
		}
		M.read((char*)&ex, sizeof(ex));
		while (!M.eof()) {
			if (strcmp(ex.name, n) == 0) {
				i++;
				cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "��" << endl;
			}
			M.read((char*)&ex, sizeof(ex));
		}
		M.close();
		cout << "�����������...";
		char chh = getchar();
		system("cls");
		T.getline(n, 10);
	}
	T.close();
	if (i == 0) {
		cout << "���޲��˵Ǽ�" << endl;
	}
}

void patient::check_patient()
{
	int i = 0;
	char n[10],na[10];
	cout << "��ѡ��Ҫ���ҵĲ��˵�������" << endl;
	cin >> n;
	fstream T("Patient.txt", ios::in);
	if (!T) {
		cout << "��Patient.txtʧ�ܣ�����" << endl;
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
		cout << "û�д˲��ˣ�����" << endl;
	}
	else {
		int k = 0;
		fstream in("personin.dat", ios::in | ios::binary);
		struct allperson p;
		if (!in) {
			cout << "��ȡpersonin.dat�ļ�ʧ��!!!" << endl;
			exit(0);
		}
		in.read((char*)&p, sizeof(p));
		while (!in.eof()) {
			if (strcmp(n, p.name) == 0) {
				if (k == 0) {
					cout << "��Ϊ������Ա����Ϣ��" << endl;
					i++;
				}
				cout << "-------------------" << endl;
				cout << "������" << p.name << endl;
				cout << "�Ա�" << p.sex << endl;
				cout << "���䣺" << p.age << endl;
				cout << "�绰���룺" << p.telephone << endl;
				cout << "ְ��" << p.work << endl;
				cout << "��Դ�أ�" << p.place << endl;
				cout << "������" << n << "  " << "��ʷ���¼�¼��" << endl;
				fstream M("temperature.dat", ios::in | ios::binary);
				Record_Tem ex;
				if (!M) {
					cout << "�޷���temperature.dat�ļ�������" << endl;
					exit(0);
				}
				M.read((char*)&ex, sizeof(ex));
				while (!M.eof()) {
					if (strcmp(ex.name, n) == 0) {
						cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "��" << endl;
					}
					M.read((char*)&ex, sizeof(ex));
				}
				M.close();
				fstream file("Apersonin.txt",ios::in);
				if (!file) {
					cout << "��Apersonin.txt�ļ�ʧ�ܣ�����" << endl;
					exit(0);
				}
				char ch[10];
				file >> ch;
				while (!file.eof()) {
					if (strcmp(ch, p.name) == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//���ú�ɫ
						cout << "����;������������������ע�⣡����" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
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
			cout << "��ȡpersonout.dat�ļ�ʧ��!!!" << endl;
			exit(0);
		}
		out.read((char*)&p, sizeof(p));
		while (!out.eof()) {
			if (strcmp(n, p.name) == 0) {
				if (k == 0) {
					cout << "��Ϊ�����Ա����Ϣ��" << endl;
					i++;
				}
				cout << "-------------------" << endl;
				cout << "������" << p.name << endl;
				cout << "�Ա�" << p.sex << endl;
				cout << "���䣺" << p.age << endl;
				cout << "�绰���룺" << p.telephone << endl;
				cout << "ְ��" << p.work << endl;
				cout << "Ŀ�ĵأ�" << p.place << endl;
				cout << "���ԭ��" << p.reason << endl;
				cout << "���ʱ�䣺" << p.dat.year << "-" << p.dat.month << "-" << p.dat.day << endl;
				fstream M("temperature.dat", ios::in | ios::binary);
				Record_Tem ex;
				if (!M) {
					cout << "�޷���temperature.dat�ļ�������" << endl;
					exit(0);
				}
				M.read((char*)&ex, sizeof(ex));
				while (!M.eof()) {
					if (strcmp(ex.name, n) == 0) {
						cout << ex.Tdate.year << "-" << ex.Tdate.month << "-" << ex.Tdate.day << ": " << ex.temp << "��" << endl;
					}
					M.read((char*)&ex, sizeof(ex));
				}
				M.close();
				fstream file("Apersonout.txt", ios::in);
				if (!file) {
					cout << "��Apersonout.txt�ļ�ʧ�ܣ�����" << endl;
					exit(0);
				}
				char ch[10];
				file >> ch;
				while (!file.eof()) {
					if (strcmp(ch, p.name) == 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//���ú�ɫ
						cout << "����;������������������ע�⣡����" << endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
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
	cout << "�����������...";
	char chh = getchar();
	system("cls");
}

void patient::delete_patient()
{
	patient::getnum_patient();
	if (num_patient == 0) {
		cout << "���޲��˵Ǽ�" << endl;
	}
	else {
		int i = 0;
		char n[10], n1[10];
		fstream TT("Patient.txt", ios::in);
		if (!TT) {
			cout << "��Patient.txtʧ�ܣ�����" << endl;
			exit(0);
		}
		TT.getline(n1, 10);
		cout << "����Ϊ�ǼǵĲ���������" << endl;
		while (!TT.eof()) {
			cout << n1 << endl;
			TT.getline(n1, 10);
		}
		TT.close();
		fstream T("Patient.txt", ios::in);
		fstream T_1("Patient1.txt", ios::out);
		if (!T_1) {
			cout << "���ļ�ʧ��" << endl;
			exit(0);
		}
		if (!T) {
			cout << "��Patient.txtʧ�ܣ�����" << endl;
			exit(0);
		}
		cout << "��ѡ����Ҫɾ���Ĳ��˵�������";
		cin >> n;
		if (T.getline(n1, 10).good()) {
			int ckk = 0;
			while (!T.eof()) {
				if (i != 1 && strcmp(n1, n) == 0) {
					i = 1;
					if (IDYES == MessageBox(NULL, "�Ƿ�ɾ���ò���?", "Comfirm Message", MB_YESNO | MB_ICONQUESTION))
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
				cout << "������󣡣���" << endl;
				exit(0);
			}
		}
		T.close();
		T_1.close();
		fstream T3("Patient.txt", ios::out);
		fstream T2("Patient1.txt", ios::in);
		if (!T2) {
			cout << "���ļ�ʧ��" << endl;
			exit(0);
		}
		if (!T3) {
			cout << "��Patient.txtʧ�ܣ�����" << endl;
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
			cout << "ɾ���ļ�patient1ʧ�ܣ�����" << endl;
			cout << "�����������...";
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
		cout << "��temperature.dat�ļ�ʧ�ܣ�����" << endl;
		exit(0);
	}
	T.read((char*)&ex, sizeof(ex));
	while (!T.eof()) {
		ck = 0;
		if (ex.temp >= maxtem) {
			fstream tp("test.dat", ios::in | ios::binary);
			if (!tp) {
				cout << "�޷���test.dat�ļ�������" << endl;
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
				//���ú�ɫ
				cout << ex.name;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
				cout << " ���¹���";
				cout << "�Ҳ��޺�������" << endl;
				cout << "�뼰ʱ������к����⣡����" << endl;
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
						cout << "��Patient.txt�ļ�ʧ�ܣ�����" << endl;
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
						cout << "������󣡣���" << endl;
						exit(0);
					}
				}
				O.close();
				if (i == 1) {
					if (ckk == 7) {
						cout << "�����������...";
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
							cout << "�����������...";
							char chh = getchar();
							system("cls");
							ckk = 0;
						}
						continue;
					}
					else {
						ckk++;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
						//���ú�ɫ
						cout << ex.name;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);//�ָ�ԭɫ
						cout << "  ��ǰ���¹��ߣ��������½��к������������" << endl;
					}
				}
			}
		}
		if (ckk == 7) {
			cout << "�����������...";
			char chh = getchar();
			system("cls");
			ckk = 0;
		}
		T.read((char*)&ex, sizeof(ex));
	}
	cout << "�����������...";
	char chh = getchar();
	system("cls");
	system("mode con cols=40 lines=20  ");
}
