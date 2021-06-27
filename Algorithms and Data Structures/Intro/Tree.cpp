#include <iostream>


typedef int DataT;
typedef struct Node* po;

int ln=1;
int mn=1;

struct Node {
	DataT data;
	po left;
	po right;
};

po ibd(int n) {
	po node = new Node;
	if (n > 0) {
		int nl = n / 2;
		int nd = n - nl - 1;
		std::cin >> node->data;
		node->left = ibd(nl);
		node->right = ibd(nd);
		return node;
	}
	else return nullptr;
}


po ibdL(int n) {
	po node = new Node;
	if (n > 0) {
		int nl = n / 2;
		int nd = n - nl - 1;
		node->data = ln;
		ln++;
		node->left = ibdL(nl);
		node->right = ibdL(nd);
		return node;
	}
	else return nullptr;
}


po ibdM(int n) {
	po node = new Node;
	if (n > 0) {
		int nl = n / 2;
		int nd = n - nl - 1;
		node->data = mn;
		mn++;
		node->left = ibdM(nl);
		node->right = ibdM(nd);
		return node;
	}
	else return nullptr;
}


void printInfix(po root) {
	if (root == nullptr) {
		return;
	}
	printInfix(root->left);
	std::cout << root->data << " ";
	printInfix(root->right);

}


void printPrefix(po root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data << " ";
	printPrefix(root->left);
	printPrefix(root->right);

}



void printPostfix(po root) {
	if (root == nullptr) {
		return;
	}
	printPostfix(root->left);
	printPostfix(root->right);
	std::cout << root->data<<" ";
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
	int n=9;
	po root;

	root=ibd(n);
	print(root, 2);

	std::cout << "\nInfix Print:\n";
	printInfix(root);

	po rootL;
	po rootM;

	int l = 80;
	int m = 15; 


	rootL = ibdL(l);
	rootM = ibdM(m);

	print(rootL, 1);
	std::cout << "\n\n\n\n\n\n";
	print(rootM, 1);


	std::cout << "\n\nL:\n";
	std::cout << "\nInfix Print:\n";
	printInfix(rootL);
	std::cout << "\n\nPrefix Print:\n";
	printPrefix(rootL);
	std::cout << "\n\nPostfix Print:\n";
	printPostfix(rootL);

	std::cout << "\n\n\nM:\n\n";
	std::cout << "Infix Print:\n";
	printInfix(rootM);
	std::cout << "\n\nPrefix Print:\n";
	printPrefix(rootM);
	std::cout << "\n\nPostfix Print:\n";
	printPostfix(rootM);
	std::cout << "\n\n";
	return 0;
}