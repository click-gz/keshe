#pragma once
#include<string>
using namespace std;
struct load {
	char name[20];
	char password[20];
};

class loadperson {
protected:
	load exp;
public:
	loadperson();
	loadperson (char n[20], char s[20]);
	int loadfirst(int i);
	int check(char name[20], char p[20]);
	void changeload(int i=0);
	void saveloadperson();
};
