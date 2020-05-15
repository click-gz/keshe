#pragma once
//病人类，包括外来与本地，与仓库类挂钩，可从其他人员类中添加病人，也可自行添加
#include"Peosonin.h"
#include"test.h"
class patient:public Personin {
protected:
	int num_patient=0;
	double maxtem = 37.3;
public:
	patient();
	void getnum_patient();
	void printnum_patient();
	void savepatient();
	void show_patienttem();
	void check_patient();
	void delete_patient();
	void attention_patient();
};
