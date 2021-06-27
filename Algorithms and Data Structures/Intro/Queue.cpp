
#include <iostream>
#include <string>

typedef struct Element* po;

struct Element {
	std::string data;
	po next;
};

void push(po& beg, po& end) {
	po el=new Element;
	std::cout << "Enter data for the new element: ";
	std::getline(std::cin, el->data);
	el->next = nullptr;
	if (beg != nullptr) {
		end->next = el;
	}
	else {
		beg = el;
	}
	end = el;
}

void print(po& beg) {
	po helper=beg;
	while (helper != nullptr) {
		std::cout << helper->data<<"\n";
		helper = helper->next;
	}
}


void popall(po& beg) {
	po helper=beg;
	while (beg != nullptr) {
		std::cout << helper->data << "\n";
		helper = helper->next;
		delete beg;
		beg = helper;
	}
}

void pop(po& beg) {
	po helper = beg;
		helper = helper->next;
		delete beg;
		beg = helper;
}

int main() {
	po beg = nullptr;
	po end = nullptr;
	push(beg, end);
	bool enter=false;
	std::cout << "Would you like to enter more elements? ";
	std::cin >> enter;
	while (enter) 
	{
		std::cin.get();
		push(beg, end);
		std::cout << "Would you like to enter more elements? ";
		std::cin >> enter;
	}
	std::cout << "\n";
	print(beg);
	std::cout << "\n";
	pop(beg);
	print(beg);
}
