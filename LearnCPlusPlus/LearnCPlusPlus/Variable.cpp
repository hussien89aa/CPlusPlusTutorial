#include <iostream>
 
using namespace std;

typedef  unsigned int UINT;

int main2() {

	//UINT x =1000;

	//cout << x << endl;
	//cout << sizeof(x) << endl;
	//cout << &x << endl;

	//int a = 5;
	//int b(3);
	//decltype(b) c{ 22 };

	// 
	//auto result = (a + b) * c;
	//cout << result << endl<< typeid(result).name() << endl;

	//auto result2 = (a + b) * c + 1.3;
	//cout << result2 << endl << typeid(result2).name() << endl;


	//// binary
	//int data = 0b1010;
	//cout << data << endl;
	//cout << std::hex<< data << endl;

	//// hex
	//data = 0xABF19;
	//cout << data << endl;
	//cout << std::hex << data << endl;

	//// hex
	//data = 1234;
	//cout << data << endl;
	//cout << std::hex << data << endl;

	 //unsigned long long testNumbeer = 75ull;
	 //char16_t text = u'h';


	int number;
 
	// input from screen
	cout << "Enter number:";
	cin >> number;


	cout << "You enter:"<< number << endl;

	system("pause");

	return 0;
}