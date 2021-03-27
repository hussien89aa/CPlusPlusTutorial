
#include "LinkedList.hh"

namespace ds {


	template <class T2>
	class  Stack2 : public Vector2<T2> {

	public:
		void push(T2 value);
		T2 pop();

		int getSize();

	private:
		int size = 0;

	};


	template <class T2>
	void Stack2<T2>::push(T2 value) {

		this->add(value);

		size = size + 1;
	}

	template <class T2>
	T2 Stack2<T2>::pop() {

		// check if stack is empty
		if (size == 0) {
			return NULL;
		}

		ds::Node<T2>* temp = this->root;
		this->root = this->root->next;

		T2 val = temp->val;
		delete temp;
		size = size - 1;

		return val;
	}

	template <class T2>
	int Stack2<T2>::getSize() {
		return size;
	}
}