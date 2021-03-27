#include <iostream>

using namespace std;

int main4() {

	int number;
	for (int i = 0; i <= 100; i = i + 1) {


		cout << i << "- Enter number:";
		number = i;
		//cin >> number;

		if (number % 2 == 0) {
			// block of code 
			cout << " Number is even" << endl;
		}
		else if (number % 2 == 1) {

			cout << " Number is odd" << endl;
		}

	}

	system("pause");

	return 0;
}