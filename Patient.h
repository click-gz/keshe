#pragma once
//�����࣬���������뱾�أ���ֿ���ҹ����ɴ�������Ա������Ӳ��ˣ�Ҳ���������
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
