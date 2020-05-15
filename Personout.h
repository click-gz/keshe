#pragma once
#include"Peosonin.h"
#include"date.h"
class Personout :public Personin{
protected:
	struct allperson person;
	char w='0', s='0';
public:
	virtual Personout operator ++();
	virtual void creat();//创造
	virtual void getdate();//获得出去时间
	virtual void savepersonout();//保存
};
