class Date
{
public:
	Date();
	Date(int m, int d, int y);
	void Show() const;
	void Input();
	bool Set(int m, int d, int y);
	int GetMonth() const;
	int GetDay() const;
	int GetYear() const;
	bool SetFormat(char f);
	void Increment(int numDays = 1);
	int Compare(const Date& d) const;
	void numMonth() const;
	bool CheckValidity() const;
private:
	int Month;
	int Day;
	int Year;
	char Format;
};
