#include <iostream>
#include <time.h>
using namespace std;


void Hanoi(int n, char from, char to, char help) {
	//std::cout << n <<" "<< from << " " << to << " " << help << "\n";
	if (n == 1) {
		std::cout << "Move one disc from " << from << " to " << to << "\n";
	}
	else {
		Hanoi(n - 1, from, help, to);
		std::cout << "Move one disc from " << from << " to " << to << "\n";
		Hanoi(n - 1, help, to, from);
	}
}

int main() {
	for (int i = 5; i <= 30; i += 5) {
		time_t t0, t1;
		clock_t c0, c1;
		t0 = time(NULL);
		c0 = clock();

		Hanoi(i, 'A', 'B', 'C');
		c1 = clock();
		t1 = time(NULL);
		std::cout << "---Hanoi---\n";
		std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << "\n\n";
	}
}