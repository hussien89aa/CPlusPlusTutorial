#include <iostream>
namespace ds {

	template < class T>
	struct DNode {
		T val;
		DNode* left;
		DNode* right;
		DNode(T data) {
			val = data;
			left = nullptr;
			right = nullptr;
		}
	};


	template <class T2>
	class DLinkedList{
	public:
		~DLinkedList();
		void addFront(T2 value);
		void addRear(T2 value);
		DNode<T2>* getRear();
		DNode<T2>* getFront();

	protected:
		DNode<T2>* front = nullptr;
		DNode<T2>* rear = nullptr;
	};

	template <class T2>
	DLinkedList<T2>::~DLinkedList(){

		while (front != nullptr) {
			DNode<T2>* temp = front;
			front = front->left;
			if (front != nullptr) {
				front->right = nullptr;
			}
				
			std::cout << "Delete:" << temp->val << std::endl;
			delete temp;
		}
	}

	template <class T2>
	void DLinkedList<T2>::addFront(T2 value){

		DNode<T2>* newNode = new DNode<T2>(value);

		if (rear == nullptr && front == nullptr) {
			rear = newNode;
			front = newNode;
			return;
		}

		newNode->left = front;
		front->right = newNode;
		front = newNode;
	}

	template <class T2>
	void DLinkedList<T2>::addRear(T2 value){

		DNode<T2>* newNode = new DNode<T2>(value);

		if (rear == nullptr && front == nullptr) {
			rear = newNode;
			front = newNode;
			return;
		}

		newNode->right = rear;
		rear->left = newNode;
		rear = newNode;

	}

	template <class T2>
	DNode<T2>* DLinkedList<T2>::getRear(){
		return rear;
	}

	template <class T2>
	DNode<T2>* DLinkedList<T2>::getFront(){
		return front;
	}


}