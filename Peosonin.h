//�����˵���Ϣ��¼���������Ա�(F/M)������,�ֻ��ţ�ְ��(Wokers/Commoner|��W/C)
//������Ա���ڣ���Դ��,������
#ifndef B
#define B
#include"Allperson.h"
#include"date.h"
struct allperson {
	char name[10], telephone[12],place[20],reason[100]="0";
	int age;
	char Personcode[7];
	char sex;
	char work;
	char outcheck='i';
	struct Date dat;
};
class Personin:public Allperson {
protected:
	struct allperson person;
	char w='0', s='0';
public:
	Personin operator ++();//��¼�ڰ���������
	virtual void creat();//����
	virtual void getdate();//��¼ʱ��
	virtual void savepersonin();//����
	void getTem();//�������
	void limitday();
};
#endif