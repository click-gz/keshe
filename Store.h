//�ֿ��࣬�鿴����ʣ�࣬���ſ���
#include"Patient.h"
struct Td {
	int Y, M, D;
};
class Store:public patient {
private:
	int Masknum=100000;//��ʼ����������100000��
	int Respiratornum = 10000;//��ʼ������������10000��
public:
	Store();
	~Store();
	void check_Masknum();//������/�����������Ƿ��㹻
	void add_num();//��ӿ���/����������
	void del_Masknum();//��������
	void show();
};
