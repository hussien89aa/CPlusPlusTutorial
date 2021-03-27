#include <iostream>

using namespace std;
 
struct Node {

	int val;
	struct Node* left;
	struct Node* right;

	Node(int data) {
		val = data;
		left = nullptr;
		right = nullptr;
	}



};
struct Node* root = nullptr;

#define newNode(val)( new Node(val))
#define getLelftChild( node) (node##->left)  //## node->left
#define getRightChild( node) (node##->right)  //## node->right
#define getValue( node) (node##->val)  //## node->val

void addNodeToTree(struct Node*  startNode, struct Node* newNode) {

	if (root == nullptr) {
		root = newNode;
		return;
	}

	if (newNode->val < startNode->val) {
		// add to right side of tree
		if (startNode->left == nullptr) {
			startNode->left = newNode;
			return;
		}
		addNodeToTree(startNode->left, newNode);
	}

	if (newNode->val > startNode->val) {
		// add to left side of tree

		if (startNode->right == nullptr) {
			startNode->right = newNode;
			return;
		}
		addNodeToTree(startNode->right, newNode);
	}

}

void printTree(struct Node* node) {

	if (node == nullptr) {
		return;
	}
	printTree(getLelftChild(node));
	cout << getValue(node)<< "\t";
	printTree(getRightChild(node));


}

void clearTree(struct Node* node) {

	if (node == nullptr) {
		return;
	}
	clearTree(node->left);
	clearTree(node->right);
	cout <<"delete:"<< node->val << endl;
	if (node == root) {
		root = nullptr;
	}
	delete node;
}

void buildTreeFromArray(int* arrayOfvalues, int size) {

	cout << "\nbuildTreeFromArray\n";
	for (int i = 0; i < size; i++) {
		addNodeToTree(root, newNode(arrayOfvalues[i]));
	}
}

int main10() {
 
 
	buildTreeFromArray(new int[] {5, 3, 2, 4, 9, 7, 10}, 7);
	
	cout << "\nprintTree\n";
	printTree(root);


	cout << "\nclearTree\n";
	clearTree(root);


	cout << "\nprintTree\n";
	printTree(root);

	system("pause");

	return 0;
}