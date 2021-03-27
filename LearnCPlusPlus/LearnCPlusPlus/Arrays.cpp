#include <iostream>

using namespace std;
 
#define SIZE 4

int main5() {
 
	// 1 D array
	//int numbers[SIZE] ;
	//for (int i = 0; i < SIZE; i++) {
	//	cout << "Enter Number[" << i << "]=";
	//	cin >> numbers[i];
	//}
	//for (int i = 0; i < SIZE; i++) {

	//	cout << "Number["<< i << "]="<< numbers[i] << endl;
	//}


	// 2 D array

	int numbers[3][3]; // = { {10,20,30}, {4,5,100},{10,20,40} };

	cout << " enter all array " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "enter numbers[" << i << "][" << j << "]=";
			cin >> numbers[i][j]  ;
		}
		cout << endl;
	}

	cout << " print all array " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			cout << numbers[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\nmain Dig\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				cout << numbers[i][j] << "\t";
			}
		}
	}

	cout << "\nUnder main Dig\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i > j) {
				cout << numbers[i][j] << "\t";
			}
		}
	}


	cout << "\nAbove main Dig\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i < j) {
				cout << numbers[i][j] << "\t";
			}
		}
	}

	system("pause");

	return 0;

}