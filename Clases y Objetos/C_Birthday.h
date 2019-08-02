#pragma once
#include <string>
class C_Birthday
{
private:
	int Day, Month, Year;

public:
	C_Birthday();
	C_Birthday(int, int, int);
	C_Birthday(const C_Birthday &);
	~C_Birthday();

	std::string ToString();
};

