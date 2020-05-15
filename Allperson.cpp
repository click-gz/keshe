#ifndef C
#define C
#include<iostream>
#include<fstream>
#include "Allperson.h"
using namespace std;
Allperson::Allperson()
{
	fstream file("Allperson.txt", ios::in);
	if (!file) {
		fstream s("Allperson.txt", ios::out);
		s << num;
		s.close();
	}
	else {
		file >> num;
		file.close();
	}
}



Allperson::~Allperson()
{
	fstream file("Allperson.txt", ios::out);
	if (!file) {
		cout << "can not open this file!" << endl;
		exit(0);
	}
	file << num;
	file.close();
}
#endif

