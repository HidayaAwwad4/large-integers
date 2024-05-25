#include"LargeInteger.h"


/* 1-
	------------------------------------------------------------*/
LargeInteger::LargeInteger(int size = 10) {
	length = 0;
	maxSize = size;
	number = new short int[maxSize];
	for (int i = 0; i < maxSize; i++) {
		number[i] = 0;
	}
}
/* 2-
 ------------------------------------------------------------*/
LargeInteger::LargeInteger(const LargeInteger& L) {
	length = L.length;
	maxSize = L.maxSize;
	number = new short int[maxSize];
	for (int i = 0; i < length; i++) {
		number[i] = L.number[i];
	}
}
/* 3-
------------------------------------------------------------*/
LargeInteger::~LargeInteger() {
	if (number != NULL)
		delete[] number;
	number = NULL;
}
/* 4-
------------------------------------------------------------*/
bool LargeInteger::setNumber(string str) {
	if (str.empty()) {
		length = 0;
		return false;
	}
	if (str.length() > maxSize) {
		length = 0;
		return false;
	}
	length = str.length();
	for (int i = 0; i < length; i++) {
		if (!isdigit(str[i])) {
			length = 0;
			return false;
		}
		number[i] = str[i] - '0';
	}
	return true;
}
/* 5-
------------------------------------------------------------*/
void LargeInteger::read(istream& in) {
	string str;
	in >> str;
	if (!setNumber(str)) {
		cout << "Invalid input" << endl;
	}
}
/* 6-
------------------------------------------------------------*/
void LargeInteger::write(ostream& out)const {
	if (length == 0) {
		out << "0";
		return;
	}
	for (int i = 0; i < length; i++) {
		out << number[i];
	}

}
/* 7-
------------------------------------------------------------*/
LargeInteger LargeInteger:: operator+(const LargeInteger& L) {
	LargeInteger copy(*this);
	for (int i = 0; i < length; i++) {
		copy.number[i] = number[i];
	}
	//case 1
	if (length == L.length) {
		LargeInteger sum(length + 1);
		sum.length = this->length + 1;
		int i;
		for (i = length; i > 0; i--) {
			if ((number[i - 1] + L.number[i - 1]) >= 10 && i > 1) {
				sum.number[i] = (number[i - 1] + L.number[i - 1]) % 10;
				number[i - 2]++;
			}
			else {
				sum.number[i] = number[i - 1] + L.number[i - 1];
			}
		}
		if (i == 0) {
			if (sum.number[1] >= 10) {
				sum.number[1] %= 10;
				sum.number[0] = 1;
			}
			else {
				sum.number[0] = 0;
			}
		}
		for (int i = 0; i < length; i++) {
			number[i] = copy.number[i];
		}
		return sum;
	}
	//case 2
	if (length > L.length) {
		LargeInteger sum(length + 1);
		sum.length = this->length + 1;
		if (L.maxSize < length) {
			LargeInteger temp(L);
			int i, j;
			for (i = length - 1, j = L.length - 1; j >= 0; i--, j--) {
				temp.number[i] = temp.number[j];
			}
			for (i; i >= 0; i--) {
				temp.number[i] = 0;
			}
			int k;
			for (k = length; k > 0; k--) {
				if ((number[k - 1] + temp.number[k - 1]) >= 10 && k > 1) {
					sum.number[k] = (number[k - 1] + temp.number[k - 1]) % 10;
					number[k - 2]++;
				}
				else {
					sum.number[k] = number[k - 1] + temp.number[k - 1];
				}
			}
			if (k == 0) {
				if (sum.number[1] >= 10) {
					sum.number[1] %= 10;
					sum.number[0] = 1;
				}
				else {
					sum.number[0] = 0;
				}
			}
		}
		else {
			LargeInteger copyL(L);
			int i, j;
			for (i = length - 1, j = copyL.length - 1; j >= 0; i--, j--) {
				copyL.number[i] = copyL.number[j];
			}
			for (i; i >= 0; i--) {
				copyL.number[i] = 0;
			}
			int k;
			for (k = length; k > 0; k--) {
				if ((number[k - 1] + copyL.number[k - 1]) >= 10 && k > 1) {
					sum.number[k] = (number[k - 1] + copyL.number[k - 1]) % 10;
					number[k - 2]++;
				}
				else {
					sum.number[k] = number[k - 1] + copyL.number[k - 1];
				}
			}
			if (k == 0) {
				if (sum.number[1] >= 10) {
					sum.number[1] %= 10;
					sum.number[0] = 1;
				}
				else {
					sum.number[0] = 0;
				}
			}
		}
		for (int i = 0; i < length; i++) {
			number[i] = copy.number[i];
		}
		return sum;
	}
	//case 3
	if (length < L.length) {
		LargeInteger sum(L.length + 1);
		sum.length = L.length + 1;
		if (L.length > maxSize) {
			LargeInteger temp(L);
			int i, j;
			for (i = L.length - 1, j = length - 1; j >= 0; i--, j--) {
				temp.number[i] = temp.number[j];
			}
			for (i; i >= 0; i--) {
				temp.number[i] = 0;
			}
			int k;
			for (k = L.length; k > 0; k--) {
				if ((temp.number[k - 1] + L.number[k - 1]) >= 10 && k > 1) {
					sum.number[k] = (temp.number[k - 1] + L.number[k - 1]) % 10;
					temp.number[k - 2]++;
				}
				else {
					sum.number[k] = temp.number[k - 1] + L.number[k - 1];
				}
			}
			if (k == 0) {
				if (sum.number[1] >= 10) {
					sum.number[1] %= 10;
					sum.number[0] = 1;
				}
				else {
					sum.number[0] = 0;
				}
			}
		}
		else {
			int i, j;
			for (i = L.length - 1, j = length - 1; j >= 0; i--, j--) {
				number[i] = number[j];
			}
			for (i; i >= 0; i--) {
				number[i] = 0;
			}
			int k;
			for (k = L.length; k > 0; k--) {
				if ((number[k - 1] + L.number[k - 1]) >= 10 && k > 1) {
					sum.number[k] = (number[k - 1] + L.number[k - 1]) % 10;
					number[k - 2]++;
				}
				else {
					sum.number[k] = number[k - 1] + L.number[k - 1];
				}
			}
			if (k == 0) {
				if (sum.number[1] >= 10) {
					sum.number[1] %= 10;
					sum.number[0] = 1;
				}
				else {
					sum.number[0] = 0;
				}
			}
		}
		for (int i = 0; i < length; i++) {
			number[i] = copy.number[i];
		}
		return sum;
	}

}
/* 8-
------------------------------------------------------------*/
LargeInteger LargeInteger:: operator-(const LargeInteger& L) {
	LargeInteger copyThis(*this), copyL(L);
	for (int i = 0; i < length; i++) {
		copyThis.number[i] = number[i];
	}
	for (int i = 0; i < L.length; i++) {
		copyL.number[i] = L.number[i];
	}
	//case 1
	if (length == L.length) {
		LargeInteger sub(this->length);
		sub.length = this->length;
		LargeInteger copyThis(*this), copyL(L);
		for (int i = 0; i < length; i++) {
			copyThis.number[i] = number[i];
		}
		if (number[0] > L.number[0]) {
			for (int i = length - 1; i >= 0; i--) {
				if (number[i] < L.number[i]) {
					number[i - 1]--;
					number[i] += 10;
					sub.number[i] = number[i] - L.number[i];
				}
				else {
					sub.number[i] = number[i] - L.number[i];
				}
			}
		}
		else if (number[0] < L.number[0] || *this < L) {
			for (int i = length - 1; i >= 0; i--) {
				if (L.number[i] < number[i]) {
					L.number[i - 1]--;
					L.number[i] += 10;
					sub.number[i] = L.number[i] - number[i];
				}
				else {
					sub.number[i] = L.number[i] - number[i];
				}
			}
			sub.number[0] *= -1;
		}
		else {
			for (int i = length - 1; i >= 0; i--) {
				if (number[i] < L.number[i]) {
					number[i - 1]--;
					number[i] += 10;
					sub.number[i] = number[i] - L.number[i];
				}
				else {
					sub.number[i] = number[i] - L.number[i];
				}
			}
		}
		for (int i = 0; i < length; i++) {
			number[i] = copyThis.number[i];
		}
		for (int i = 0; i < L.length; i++) {
			L.number[i] = copyL.number[i];
		}
		return sub;
	}//end case 1

	//case 2
	if (length > L.length) {
		LargeInteger sub(this->length);
		sub.length = this->length;
		if (L.maxSize < length) {
			LargeInteger temp(length);
			temp.length = length;
			for (int i = 0; i < L.length; i++) {
				temp.number[i] = L.number[i];
			}
			int i, j;
			for (i = length - 1, j = L.length - 1; j >= 0; i--, j--) {
				temp.number[i] = temp.number[j];
			}
			for (i; i >= 0; i--) {
				temp.number[i] = 0;
			}
			for (int k = length - 1; k >= 0; k--) {
				if (number[k] < temp.number[k]) {
					number[k - 1]--;
					number[k] += 10;
					sub.number[k] = number[k] - temp.number[k];
				}
				else {
					sub.number[k] = number[k] - temp.number[k];
				}
			}
		}
		else {
			int i, j;
			for (i = length - 1, j = L.length - 1; j >= 0; i--, j--) {
				L.number[i] = L.number[j];
			}
			for (i; i >= 0; i--) {
				L.number[i] = 0;
			}
			for (int k = length - 1; k >= 0; k--) {
				if (number[k] < L.number[k]) {
					number[k - 1]--;
					number[k] += 10;
					sub.number[k] = number[k] - L.number[k];
				}
				else {
					sub.number[k] = number[k] - L.number[k];
				}
			}
		}
		for (int i = 0; i < length; i++) {
			number[i] = copyThis.number[i];
		}
		for (int i = 0; i < L.length; i++) {
			L.number[i] = copyL.number[i];
		}
		return sub;
	}//end case 2

	//case 3
	if (length < L.length) {
		LargeInteger sub(L.length);
		sub.length = L.length;
		if (L.length > maxSize) {
			LargeInteger temp(L.length);
			temp.length = L.length;
			for (int i = 0; i < length; i++) {
				temp.number[i] = number[i];
			}
			int i, j;
			for (i = L.length - 1, j = length - 1; j >= 0; i--, j--) {
				temp.number[i] = temp.number[j];
			}
			for (i; i >= 0; i--) {
				temp.number[i] = 0;
			}
			for (int k = L.length - 1; k >= 0; k--) {
				if (L.number[k] < temp.number[k]) {
					L.number[k - 1]--;
					L.number[k] += 10;
					sub.number[k] = L.number[k] - temp.number[k];
				}
				else {
					sub.number[k] = L.number[k] - temp.number[k];
				}
			}
		}
		else {
			int i, j;
			for (i = L.length - 1, j = length - 1; j >= 0; i--, j--) {
				number[i] = number[j];
			}
			for (i; i >= 0; i--) {
				number[i] = 0;
			}
			for (int k = L.length - 1; k >= 0; k--) {
				if (L.number[k] < number[k]) {
					L.number[k - 1]--;
					L.number[k] += 10;
					sub.number[k] = L.number[k] - number[k];
				}
				else {
					sub.number[k] = L.number[k] - number[k];
				}
			}
		}

		sub.number[0] *= (-1);
		for (int i = 0; i < length; i++) {
			number[i] = copyThis.number[i];
		}
		for (int i = 0; i < L.length; i++) {
			L.number[i] = copyL.number[i];
		}
		return sub;

	}//end case 3

}//end operator -
/* 9-
------------------------------------------------------------*/
LargeInteger LargeInteger:: operator*(const LargeInteger& L)const {
	LargeInteger ReverseThis(*this), ReverseL(L);
	short int temp;
	int a, z;
	// Reverse This
	for (a = 0, z = ReverseThis.length - 1; a <= z; a++, z--) {
		temp = ReverseThis.number[a];
		ReverseThis.number[a] = ReverseThis.number[z];
		ReverseThis.number[z] = temp;
	}//end for loop

	// Reverse L.
	for (a = 0, z = ReverseL.length - 1; a <= z; a++, z--) {
		temp = ReverseL.number[a];
		ReverseL.number[a] = ReverseL.number[z];
		ReverseL.number[z] = temp;
	}//end for loop

	int maxSizeMulti = length + L.length ; 
	LargeInteger multi(maxSizeMulti);

	for (int i = 0; i < ReverseThis.length; i++) {
		int carry = 0;

		for (int j = 0; j < ReverseL.length; j++) {
			int product = ReverseThis.number[i] * ReverseL.number[j] + multi.number[i + j] + carry;
			multi.number[i + j] = product % 10;
			carry = product / 10;
		}

		if (carry > 0) {
			multi.number[i + ReverseL.length] += carry;
		}
	}

	int i = maxSizeMulti - 1;
	while (i > 1 && multi.number[i] == 0) {
		i--;
	}

	multi.length = i + 1;

	// Reverse Multi .
	LargeInteger ReverseMulti(multi);
	for (a = 0, z = ReverseMulti.length - 1; a <= z; a++, z--) {
		temp = ReverseMulti.number[a];
		ReverseMulti.number[a] = ReverseMulti.number[z];
		ReverseMulti.number[z] = temp;

	}
	return ReverseMulti;


}//end operator *
/* 10-
------------------------------------------------------------*/
const LargeInteger& LargeInteger::operator=(const LargeInteger& L) {
	if (this == &L)return*this;
	if (number != NULL)delete[]number;
	length = L.length;
	maxSize = L.maxSize;
	number = new short int[maxSize];
	for (int i = 0; i < length; i++) {
		number[i] = L.number[i];
	}
	return *this;
}
/* 11-
------------------------------------------------------------*/
bool LargeInteger::operator==(const LargeInteger& L) {
	if (length != L.length)return false;
	for (int i = 0; i < length; i++) {
		if (number[i] != L.number[i])
			return false;
	}
	return true;
}
/* 12-
------------------------------------------------------------*/
bool LargeInteger::operator < (const LargeInteger& L) {
	if (length > L.length)return false;
	if (length < L.length)return true;

	if (length == L.length) {
		for (int i = 0; i < length; i++) {
			if (number[i] > L.number[i])return false;
			if (number[i] < L.number[i])return true;
		}
		return false;
	}
}
/* 13-
------------------------------------------------------------*/
bool LargeInteger::operator > (const LargeInteger& L) {
	if (length > L.length)return true;
	if (length == L.length) {
		for (int i = 0; i < length; i++) {
			if (number[i] > L.number[i])
				return true;
			if (number[i] < L.number[i])
				return false;
		}
		return false;
	}
	if (length < L.length)return false;
}
/* 14- bonus
------------------------------------------------------------*/
ostream& operator << (ostream& out, const LargeInteger& L) {
	L.write(out);
	return out;
}
/* 15-bonus
------------------------------------------------------------*/
istream& operator >> (istream& in, LargeInteger& L) {
	L.read(in);
	return in;
}
