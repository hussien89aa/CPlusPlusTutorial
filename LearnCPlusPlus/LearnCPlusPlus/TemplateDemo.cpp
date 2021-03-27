#include <iostream>
#include "LinkedList.hh"
 
using namespace std;
 
int main12() {
	unsigned long x=0x11223344;
	long long xx=(long long)x;
	cout << std::hex<< (long long*)x << endl;
	{
		ds::Vector2<string> vec;
		vec.add("hussein");
		vec.add("jena");
		vec.add("laya");

		ds::Node<string>* currentNode = vec.getRoot();

		while (currentNode != nullptr) {
			cout << currentNode->val << endl;

			currentNode = currentNode->next;
		}

	}
	system("pause");

	return 0;
}