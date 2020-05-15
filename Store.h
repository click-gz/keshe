//仓库类，查看口罩剩余，发放口罩
#include"Patient.h"
struct Td {
	int Y, M, D;
};
class Store:public patient {
private:
	int Masknum=100000;//初始化口罩数量100000个
	int Respiratornum = 10000;//初始化呼吸机数量10000个
public:
	Store();
	~Store();
	void check_Masknum();//检查口罩/呼吸机数量是否足够
	void add_num();//添加口罩/呼吸机数量
	void del_Masknum();//减少数量
	void show();
};
