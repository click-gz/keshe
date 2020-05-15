#ifndef G
#define G
#include<iostream>
#include"Tem.h"
using namespace std;
//记录进来总人数
class Allperson:public Tem {	//抽象类
protected:
	int num=0;
public:
	Allperson();
	~Allperson();
	virtual void creat() = 0;
	virtual void getdate() = 0;
	virtual void getTem() = 0;
};

#endif 