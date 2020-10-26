#include <iostream>
#include <time.h>

int randNum() {
	return rand() % 100;
}

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout <<"arr["<<i<<"] = "<< arr[i] << "\n";
	}
	std::cout << "\n";
}

void quicksort(int* arr, int n, int start, int end)
{

	int pivot = arr[(start + end) / 2];
	int i = start;
	int j = end;

	if (start >= end) {
		return;
	}

	while (i <= j)
	{
		while (arr[i] < pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i <= j) {
			int buff = arr[j];
			arr[j] = arr[i];
			arr[i] = buff;
			++i;
			--j;
		}
	}
	quicksort(arr, n, start, j);
	quicksort(arr, n, i, end);
}


int main() {
	srand(time(NULL));
	int n = 20;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = randNum();
	}
  
	print(arr, n);
	std::cout << "\n";
	quicksort(arr, n, 0, n - 1);
	print(arr, n);


	return 0;
}
