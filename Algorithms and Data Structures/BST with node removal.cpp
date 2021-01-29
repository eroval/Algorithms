#include <iostream>

typedef int DataT;
typedef struct Node* po;

struct Node {
	DataT data;
	po left;
	po right;
};


po here;
int k = 0;

bool search(po root, DataT x) {
	if (root == nullptr) {
		k++;
		return false;
	}
	else if (root->data == x) {
		k += 2;
		return true;
	}
	else {
		k += 3;
		here = root;
		if (root->data > x) search(root->left, x);
		else search(root->right, x);
	}
}



po ddp(const po& root, DataT x) {
	k = 0;
	if (root != nullptr) {
		if (search(root, x)) {
			std::cout << "Found at position \"" << here << "\" after " << k << " searches.\n";
		}
		else {
			std::cout << "Not found after " << k << " searches. Inserting it now.\n";
			po node = new Node;
			node->data = x;
			node->left = nullptr;
			node->right = nullptr;
			k++;
			if (here->data > x) here->left = node;
			else here->right = node;
		}
		return root;
	}
	else {
		po node = new Node;
		node->data = x;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
}


po find(po el, DataT x) {
	if (el == nullptr || el->data == x) {
		return el;
	}
	else {
		here = el;
		if (el->data > x) find(el->left, x);
		else find(el->right, x);
	}
}

void removeElement(po& root, DataT x) {
	po element = find(root, x);
	if (element == nullptr){
		std::cout << "Such a node doesn't exist.\n";
		return;
	}
	else {
		if (element->left == nullptr) {
			if (element == root) { //root check
				po ptr = root;
				root = element->right;
				delete ptr;
				return;
			}
			else {
				if (element->data < here->data) {
					here->left = element->right;
				}
				else here->right = element->right;
				delete element;
				return;
			}
		}
		else if (element->right == nullptr) {
			if (element == root) { //rootcheck
				po ptr = root;
				root = element->left;
				delete ptr;
				return;
			}
			else {
				if (element->data < here->data) {
					here->left = element->left;
				}
				else here->right = element->left;
				delete element;
				return;
			}
		}
		else {
			po bottomlr = element->left;
			po bottomhelp = bottomlr;
			while (bottomlr->right != nullptr) {
				bottomhelp = bottomlr;
				bottomlr = bottomlr->right;
			}

			bottomhelp->right = nullptr;

			if (element == root) { //root check
				po ptr = root;
				bottomlr->left = root->left;
				bottomlr->right = root->right;
				delete ptr;
				root = bottomlr;
				return;
			}
			else {

				if (bottomlr != element->left) {		//check if it isn't pointing to itself
					bottomlr->left = element->left;		//in case of being just the first and last left element.
				}										//we could get a loop

				bottomlr->right = element->right;

				if (bottomlr->data < here->data) {
					here->left = bottomlr;
				}
				else {
					here->right = bottomlr;
				}

				delete element;
				return;
			}
		}
	}
}


void printInfix(po root) {
	if (root == nullptr) {
		return;
	}
	printInfix(root->left);
	std::cout << root->data << " ";
	printInfix(root->right);
}



void printPostfix(po root) {
	if (root == nullptr) {
		return;
	}
	printPostfix(root->left);
	printPostfix(root->right);
	std::cout << root->data << " ";
}




void print(po root, int space)
{
	if (root == NULL)
		return;
	int COUNT = 3;
	space += COUNT;
	print(root->right, space);
	std::cout << " ";
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";
	print(root->left, space);
}


int main() {
	int n;
	DataT x;
	std::cout << "Enter number of elements: ";
	std::cin >> n;
	po root = nullptr;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		root = ddp(root, x);
	}
	std::cout << "\n\n";
	print(root, 3);
	std::cout << "\n\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "Enter x to be removed: ";
		std::cin >> x;
		removeElement(root, x);
		std::cout << "\n\n";
		print(root, 3);
	}
}