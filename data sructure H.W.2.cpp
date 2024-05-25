#include"LargeInteger.h"

void checkCopyConstructor(LargeInteger L) {
	L.write(cout);
}
int main()
{
	LargeInteger L1(10), L2(10), L3(15);
	cout << "enter the number 1 : ";
	L1.read(cin);
	cout << "enter the number 2 : ";
	L2.read(cin);

	L3 = L1 + L2;
	L1.write(cout);
	cout << " + ";
	L2.write(cout);
	cout << " = ";
	L3.write(cout);
	cout << endl;

	L3 = L1 - L2;
	L1.write(cout);
	cout << " - ";
	L2.write(cout);
	cout << " = ";
	L3.write(cout);
	cout << endl;

	L3 = L1 * L2;
	L1.write(cout);
	cout << " * ";
	L2.write(cout);
	cout << " = ";
	L3.write(cout);
	cout << endl;
	

	if (L1 == L2) cout << "L1 equal L2 " << endl;
	else if (L1 < L2) cout << "L1 less L2 " << endl;
	else cout << "L1 greater L2 " << endl;
	cout << "checkCopyConstructor : ";
	checkCopyConstructor(L1);
	cout << endl;

	cout << "L1 :";
	cin >> L1;
	cout << L1;


	return 0;
}
