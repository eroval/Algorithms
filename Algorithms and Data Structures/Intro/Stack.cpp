
typedef struct Element* po;

struct Element {
	std::string data;
	po next;
};


void print(po el1) {
	po ptr = el1;
	while (ptr != nullptr) {
		std::cout << ptr->data << "\n";
		ptr = ptr->next;
	}
}

int main() {
	po el1 = new Element;
	std::cout << "Enter first element:\n";
	std::getline(std::cin, el1->data);
	el1->next = nullptr;
	bool enter;

	std::cout << "Would you like to insert more elements? (0/1) ";
	std::cin >> enter;
	std::cin.get();
	while (enter) {
		po el2 = new Element;
		std::cout << "Enter the element's data: ";
		std::getline(std::cin, el2->data);
		if (el2->data < el1->data) {
			el2->next = el1;
			el1 = el2;
		}
		else {
			po helper = el1;
			while (helper->next != nullptr && el2->data > helper->next->data) {
				helper = helper->next;
			}

			el2->next = helper->next;
			helper->next = el2;
		}

		std::cout << "Would you like to insert more elements? (0/1) ";
		std::cin >> enter;
		std::cin.get();
	}

	po helper = el1;
	while (helper != nullptr) {
		std::cout << helper->data << "\n";
		helper = helper->next;
	}
	return 0;
}