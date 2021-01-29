#include <iostream>
#include <string>
#include <time.h>
#include <vector>


const int N = 10000000;
std::vector<int> C(N);

int rndint() {
	return rand() % 100;
}

void Merge(int* arr, int start, int index, int end) {
	int i = start;
	int j = index;
	int l = start;

	while (i < index && j <= end) {
		if (arr[i] < arr[j]) {
			C[l] = arr[i];
			++i;
			++l;
		}
		else {
			C[l] = arr[j];
			++j;
			++l;
		}
	}

	for (int k = i; k < index; k++) {
		C[l] = arr[k];
		++l;
	}
	for (int k = j; k <= end; k++) {
		C[l] = arr[k];
		++l;
	}


	for (int k = start; k <= end; k++) {
		arr[k] = C[k];
	}
}

void MergeSort(int* arr, int start, int end) {
	int index = (start + end) / 2;

	if (start >= end) {
		return;
	}
	MergeSort(arr, start, index);
	MergeSort(arr, index + 1, end);
	Merge(arr, start, index + 1, end);
}




void quickSort(int* arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = arr[(start + end) / 2];
	int i = start;
	int j = end;
	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			int buff = arr[j];
			arr[j] = arr[i];
			arr[i] = buff;
			++i;
			--j;
		}
	}
	quickSort(arr, start, j);
	quickSort(arr, i, end);
}

void print(int* arr) {
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n";
}


void Method1(int* arr) {
	time_t t0, t1;
	clock_t c0, c1;
	t0 = time(NULL);
	c0 = clock();

	MergeSort(arr, 0, N - 1);

	c1 = clock();
	t1 = time(NULL);
	std::cout << "Merge Sort:\n";
	std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << "\n\n";
}



void Method2(int* arr) {
	time_t t0, t1;
	clock_t c0, c1;
	t0 = time(NULL);
	c0 = clock();

	quickSort(arr, 0, N - 1);

	c1 = clock();
	t1 = time(NULL);
	std::cout << "Quick Sort:\n";
	std::cout << "ellapsed wall clock time: " << (float)(c1 - c0) / CLOCKS_PER_SEC << "\n\n";
}

int main()
{
	srand(time(NULL));
	int* arr1 = new int[N];
	int* arr2 = new int[N];
	for (int i = 0; i < N; i++) {
		arr1[i] = rndint();
		arr2[i] = arr1[i];
	}

	Method1(arr1);
	Method2(arr2);

	return 0;
}