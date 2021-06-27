#include <iostream>
#include <string>
#include <time.h>
#include <vector>


const int N = 10;
std::vector<int> C(N);

int rndint() {
	return rand() % 100;
}

void print(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void printInInterval(int* arr, int start, int end) {
	if (end == N) {
		end -= 1;
	}
	for (; start <= end; ++start) {
		std::cout << arr[start] << " ";
	}
	std::cout << "\n";
}

void Merge(int* arr, int start, int index, int end) {
	int i = start;
	int j = index;
	int l = start;
	std::cout << "\n\nMerging [" << start << "," << end << "] started.\n";
	printInInterval(arr, start, end);
	std::cout << "Newly merged C:\n";
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


	printInInterval(arr, start, end);
	std::cout << "Transfering to A...\n\n";
}

void MergeSort(int* arr, int start, int end) {
	int index = (start + end) / 2;
	
	if (start >= end) {
		return;
	}

	std::cout << "\nDescending into Left Partition ";
	std::cout << "(boundaries [" << start << "][" << index << "]):\n";
	printInInterval(arr, start, index);
	MergeSort(arr, start, index);
	std::cout << "\nDescending into Right Partition ";
	std::cout << "(boundaries [" << index+1 << "][" << end << "]):\n";
	printInInterval(arr, index + 1, end);
	MergeSort(arr, index + 1, end);
	//std::cout << "\n";
	Merge(arr, start, index+1, end);
}


int main() 
{
	srand(time(NULL));
	int* arr = new int[N];
	int* arrcpy = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rndint();
		arrcpy[i] = arr[i];
	}
	print(arr, N);
	MergeSort(arr, 0, N - 1);
	std::cout << "Starting Array:\n";
	print(arrcpy, N);
	std::cout << "\nFinished Array:\n";
	print(arr, N);
	return 0;
}