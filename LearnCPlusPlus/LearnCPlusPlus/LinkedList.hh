 

namespace ds {

	template < class T>
	struct Node {
		T val;
		Node* next;
	};


	template <class T2>
	class Vector2 {

	public:

		void add(T2 value);
		~Vector2();
		ds::Node<T2>* getRoot();


	protected:

		ds::Node<T2>* root = nullptr;

	};


	template <class T2>
	void Vector2<T2>::add(T2 value) {

		ds::Node<T2>* newNode = new ds::Node<T2>();
		newNode->val = value;

		if (root == nullptr) {
			newNode->next = nullptr;
			root = newNode;
			return;
		}

		newNode->next = root;
		root = newNode;

	}

	template <class T2>
	Vector2<T2>::~Vector2() {
		Node<T2>* temp2 = root;
		while (root != nullptr) {

			Node<T2>* temp = root;
			root = root->next;
			delete temp;
		}
 
	}

	template <class T2>
	ds::Node<T2>* Vector2<T2>::getRoot() {

		return root;
	}

}