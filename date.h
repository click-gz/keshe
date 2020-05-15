#ifndef F
#define F


class Personin;
class Tem;
struct Date {
	int year, month, day;
};

class date {
	int year, month, day;
	struct Date d;
public:
	date();
	void setdate();
	void todaydate();
	struct Date* getdate();
};
#endif // !F