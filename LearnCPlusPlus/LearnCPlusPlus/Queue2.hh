 
namespace ds {

	template <class T2>
	class Queue2 : protected DLinkedList<T2> {

	public:
		void push(T2 value);
		T2 pull();
	};

	template <class T2>
	void Queue2<T2>::push(T2 value) {

		this->addFront(value);
	}

	template <class T2>
	T2 Queue2<T2>::pull() {

		DNode<T2>* node = this->getRear();

		if (node == nullptr) {
			return NULL;
		}

		T2 value = node->val;
		this->rear = this->rear->right;
		if (this->rear == nullptr) {
			this->rear = nullptr;
			this->front = nullptr;
		}else{
			 this->rear->left = nullptr;
		}
		
		delete node;

		return value;

	}
}