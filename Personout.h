#pragma once
#include"Peosonin.h"
#include"date.h"
class Personout :public Personin{
protected:
	struct allperson person;
	char w='0', s='0';
public:
	virtual Personout operator ++();
	virtual void creat();//����
	virtual void getdate();//��ó�ȥʱ��
	virtual void savepersonout();//����
};
