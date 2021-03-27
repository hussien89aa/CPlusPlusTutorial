#include <iostream>
#include "DLinkedList.h"
#include "Queue2.hh"

using namespace std;

int main17() {

	{
		ds::DLinkedList<int> dLinkedList;
		dLinkedList.addFront(12);
		dLinkedList.addFront(333);
		dLinkedList.addFront(22);
		dLinkedList.addRear(12);
		dLinkedList.addFront(132);

		ds::DNode<int>* temp = dLinkedList.getRear();

		while (temp != nullptr) {

			cout << temp->val << endl;
			temp = temp->right;
		}


	}

	ds::Queue2<int> queue;

	queue.push(3);
	queue.push(4);
	queue.push(6);
	cout <<"queue:"<< queue.pull() << endl;
	cout << "queue:" << queue.pull()<< endl;


	system("pause");

	return 0;
}