#pragma once
#include"Peosonin.h"

class Code {
private:
	char pcode[7];
	allperson al;
public:
	char* getcode();
	int checkCodein(char c[7]);
	int checkCodelocal(char c[7]);
};