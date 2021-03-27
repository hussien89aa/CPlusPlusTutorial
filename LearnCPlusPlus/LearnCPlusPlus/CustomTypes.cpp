#include <iostream>

using namespace std;

typedef struct{
	string name;
	int age;
	float GPA;
} Info;

int main3() {
	Info userInfo[3] ;
 
	// User info Hussein
	userInfo[0].name = "Hussein Alrubaye";
	userInfo[0].age = 31;
	userInfo[0].GPA = 3.8;
	cout <<"Name: "<< userInfo[0].name <<endl;
	cout << "Age: " << userInfo[0].age << endl;
	cout << "GPA: " << userInfo[0].GPA << endl;

	// User info Jena
	userInfo[1].name = "Jena Alrubaye";
	userInfo[1].age = 5;
	userInfo[1].GPA = 4.0;
	cout << "Name: " << userInfo[1].name << endl;
	cout << "Age: " << userInfo[1].age << endl;
	cout << "GPA: " << userInfo[1].GPA << endl;

	// User info Laya
	userInfo[2].name = "Laya Alrubaye";
	userInfo[2].age = 4;
	userInfo[2].GPA = 3.7;
	cout << "Name: " << userInfo[2].name << endl;
	cout << "Age: " << userInfo[2].age << endl;
	cout << "GPA: " << userInfo[2].GPA << endl;


	// Other ways to work with array

	int numbers[5];
	numbers[0] = 12;
	numbers[1] = 32;
	numbers[2] = 432;
	numbers[3] = 45;
	numbers[4] = 34;

	cout << numbers[0] << endl;

	cout << "sizeof(x): "<< sizeof(numbers)/sizeof(numbers[0]) << endl;

	system("pause");
	return 0;
}