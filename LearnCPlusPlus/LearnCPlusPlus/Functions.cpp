#include <iostream>

using namespace std;

double sum(double a, double b);

double sub(double a, double b ) {

	double result = a - b;
	return result;
}

int sub(int a, int b) {

	int result = a - b;
	return result;
}

double sub(double a, double b, double c) {

	double result = a - b-c;
	return result;
}


void print(int x, int y) {
	cout <<  "\tx=" << x << "\ty=" << y << endl;
}


typedef int (*SubPtr)(int, int) ;

void printME(SubPtr ptrFunction) {

	int r = ptrFunction(3, 4);

	cout << r << endl;


}

int main9() {
	//double a = 12.7;
	//double b = 10.3;
	//double r1 = sum(a, b);
	//cout << "r1= " << r1 << "\ta="<<a <<"\tb="<<b<< endl;
	//print(a, b);
 //
	//double r2 = sub(a,14.6);
	//cout << "r2= " << r2 << endl;

	//double r3 = sub(a, 14.6,1.5);
	//cout << "r3= " << r3 <<  endl;


	//double r4 = sub(3, 4);
	//cout << "r4= " << r2 << endl;


	//// lamda
 //
	//auto addFunction = [](int a, int b)-> int {
	//	a = a - 1;
	//	return a + b;
	//};

	//int r5 = addFunction(a, b);
	//cout << "r5= " << r5 << endl;

	//SubPtr ptrFunction = &sub;

	//int r = ptrFunction(10, 4);

	printME(&sub);

	printME([](int a, int b) {

		int r = a - b - 2;
		return r;
		}
		);

	system("pause");

	return 0;
}




double sum(double a, double b = 22) {

	double result = a + b;
	return result;
}