#ifndef G
#define G
#include<iostream>
#include"Tem.h"
using namespace std;
//��¼����������
class Allperson:public Tem {	//������
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