#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/types.h>
#include <algorithm>
#include <time.h> 

//Selection Sort
void Method1(int arr2[], int n) {
	//COPY CREATION
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = arr2[i];
	}

	time_t t0, t1;
	clock_t c0, c1;
	int k = 0;
	int l = 0;

	t0 = time(NULL);
	c0 = clock();

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			l++;
			if (arr[i] > arr[j]) {
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
				k++;
			}
		}
	}

	std::std::cout << "Inversions: " << k << std::endl;
	std::std::cout << "Checks: " << l << std::endl;

	c1 = clock();
	t1 = time(NULL);
	std::cout << "ellapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;

	delete[] arr;
}

//Bubble Sort
void Method2(int arr2[], int n) {
	//COPY CREATION
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = arr2[i];
	}

	time_t t0, t1;
	clock_t c0, c1;
	bool inversion = true;
	int k = 0;
	int l = 0;

	t0 = time(NULL);
	c0 = clock();

	while (inversion) {
		inversion = false;
		for (int i = 1; i < n; i++) {
			l++;
			if (arr[i - 1] > arr[i]) {
				k++;
				arr[i] ^= arr[i - 1];
				arr[i - 1] ^= arr[i];
				arr[i] ^= arr[i - 1];
				inversion = true;
			}
		}
		n = n - 1; //it's slower even if we do the n-1
	}

	std::cout << "Inversions: " << k << std::endl;
	std::cout << "Checks: " << l << std::endl;

	c1 = clock();
	t1 = time(NULL);
	std::cout << "ellapsed wall clock time: " << ((long)(t1 - t0)) << std::endl;
	std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << std::endl;

	delete[] arr;
}



int main() {
	srand(time(NULL));
	int n = 10000;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	std::cout << "Method 1:\n";
	Method1(arr, n); //usually faster
	std::cout << std::endl << "\nMethod2:\n";
	Method2(arr, n); //superbly fast when no inversions

	return 0;
}