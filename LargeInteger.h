#pragma once

#include<iostream>
#include<string>
using namespace std;
class LargeInteger {
private:
	short int* number;
	int length;
	int maxSize;
public:
	LargeInteger(int size = 10);
	LargeInteger(const LargeInteger& L);
	~LargeInteger();
	bool setNumber(string str);
	void read(istream& in);
	void write(ostream& out)const;
	LargeInteger operator+(const LargeInteger& L);
	LargeInteger operator-(const LargeInteger& L);
	LargeInteger operator*(const LargeInteger& L)const;
	const LargeInteger& operator=(const LargeInteger& L);
	bool operator==(const LargeInteger& L);
	bool operator < (const LargeInteger& L);
	bool operator > (const LargeInteger& L);
	friend ostream& operator << (ostream& out, const LargeInteger& L);
	friend istream& operator >> (istream& in, LargeInteger& L);
};
