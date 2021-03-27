#include <iostream>

using namespace std;

int main6() {

	int number = 10;
	cout << "number="<< number <<"\t&number="<< &number << endl;

	int* ptrNumber = &number;
	cout << "ptrNumber=" << ptrNumber << "\t*ptrNumber=" << *ptrNumber << "\t&ptrNumber=" << &ptrNumber <<endl;

	int items[3] = { 10,14,9 };
	cout << "print ietms array\n";
	for (int i = 0; i < 3; i++) {
		cout << "&items[" << i << "]=" << &items[i] << "\t value="<< items[i] 
			<< "\tsize of="<< sizeof(items[i]) << endl;
	}
	int* ptrItems = &items[0];
	cout << "&ptrItems="<< ptrItems << "\t*ptrItems="<< *ptrItems << endl;
	cout << "&ptrItems=" << ptrItems+1 << "\t*ptrItems=" << *(ptrItems+1) << endl;
	cout << "&ptrItems=" << ptrItems + 2 << "\t*ptrItems=" << *(ptrItems + 2) << endl;


	int** pptrItems = &ptrItems;

	cout << "pptrItems=" << pptrItems << "\t**pptrItems=" << **pptrItems
		<< "\t*pptrItems=" << *pptrItems 
		<<"&pptrItems="<< &pptrItems << endl;
		 

	int* dNumber = new int[1];
	*dNumber = 34;
	cout << "dNumber=" << dNumber << "\t*dNumber=" << *dNumber << "\t&dNumber=" << &dNumber << endl;
	delete dNumber;

	int SIZE = 3;
	int* darray = new int[SIZE];
	darray[0] = 10;
	darray[1] = 13;
	darray[2] = 14;
	for (int i = 0; i < 3; i++) {
		cout <<"darray="<< darray[i] << endl;
	}

	delete[] darray;

	system("pause");

	return 0;
}