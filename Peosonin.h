//总体人的信息记录：姓名，性别(F/M)，年龄,手机号，职务(Wokers/Commoner|简W/C)
//进来人员日期，来源地,个人码
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
	Personin operator ++();//记录在案的总人数
	virtual void creat();//创造
	virtual void getdate();//记录时间
	virtual void savepersonin();//保存
	void getTem();//获得体温
	void limitday();
};
#endif