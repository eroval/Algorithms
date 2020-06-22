
int main() {
	int n1;
	int n2;
	int m1;
	int m2;
	std::cout << "Enter number of rows for the first matrix: ";
	std::cin >> n1;
	std::cout << "Enter number of columns for the first matrix: ";
	std::cin >> m1;
	n2 = m1;
	std::cout << "Enter number of columns for the second matrix: ";
	std::cin >> m2;
	int** A = new int*[n1];
	int** B = new int* [n2];
	for (int i = 0; i < n1; i++) {
		A[i] = new int[m1];
	}

	for (int i = 0; i < n2; i++) {
		B[i] = new int[m2];
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			std::cout << "A[" << i << "][" << j << "] = ";
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			std::cout << "B[" << i << "][" << j << "] = ";
			std::cin >> B[i][j];
		}
	}
	std::cout << "\nA:\n";
	std::cout << "________" << 0;
	for (int i = 1; i < m1; i++) {
		std::cout << "_______"<<i;
	}
	std::cout << "\n";
	for (int i = 0; i < n1; i++) {
		std::cout << i<<"|";
		for (int j = 0; j < m1; j++) {
			std::cout <<"\t"<< A[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << "\nB:\n";
	std::cout << "________" << 0;
	for (int i = 1; i < m2; i++) {
		std::cout << "_______" << i;
	}
	std::cout << "\n";
	for (int i = 0; i < n2; i++) {
		std::cout << i << "|";
		for (int j = 0; j < m2; j++) {
			std::cout << "\t" << B[i][j];
		}
		std::cout << std::endl;
	}

	int** C = new int* [n1];
	for (int i = 0; i < n1; i++) {
		C[i] = new int[m2] {};
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < n2; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	std::cout << "\nC:\n";
	std::cout << "________" << 0;
	for (int i = 1; i < m2; i++) {
		std::cout << "_______" << i;
	}
	std::cout << "\n";
	for (int i = 0; i < n1; i++) {
		std::cout << i << "|";
		for (int j = 0; j < m2; j++) {
			std::cout << "\t" << C[i][j];
		}
		std::cout << std::endl;
	}

}
