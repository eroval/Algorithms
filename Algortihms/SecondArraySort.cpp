#include <iostream>
#include <time.h>


/*
//Method 1
int main() {
	int length = 50;
	char* arr;
	char* arr2;
	arr2 = new char[length];
	std::cin.getline(arr2, length);
	//begin of normalization
	for (int i = 0; i <= length; i++) {
		if (arr2[i] == '\0') {
			length = i;
			break;
		}
	}

	arr = new char[length];

	for (int i = 0; i < length; i++) {
		arr[i] = arr2[i];
	}

	delete[] arr2;

	//end of normalization
	std::cout << std::endl;
	int flag = arr[0];
	for (int i = 0; i < length-1; i++) {
		int k = 0;
		int min = arr[i];
		flag = i;
		std::cout << "Condition "<<i<<": " << std::endl;
		for (int j = i + 1; j < length; j++) {
			if (min > arr[j]) {
				k++;
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
				flag = j;
			}
		}
		std::cout << std::endl<<"Min=" << arr[i] << " Flag= " << flag << std::endl;
		for (int k = 0; k < length; k++) {
			std::cout << arr[k]<<" ";
		}
		std::cout << std::endl << "Numbers of checks " << k;
		std::cout << std::endl;
	}

	return 0;
}
*/


/*
//Method 2
int main() {
	int length = 50;
	char* arr;
	char* arr2;
	arr2 = new char[length];
	std::cin.getline(arr2, length);
	//begin of normalization
	for (int i = 0; i <= length; i++) {
		if (arr2[i] == '\0') {
			length = i;
			break;
		}
	}

	arr = new char[length];

	for (int i = 0; i < length; i++) {
		arr[i] = arr2[i];
	}

	delete[] arr2;

	//end of normalization
	int flag = arr[0];
	for (int i = 0; i < length-1; i++) {
		int k = 0;
		int min = arr[i];
		flag = i;
		std::cout << "Condition " << i << ": " << std::endl;
		for (int j = i + 1; j < length; j++) {
			if (min > arr[j]) {
				k++;
				min = arr[j];
				flag = j;
			}
		}
		arr[flag] = arr[i];
		arr[i] = min;
		std::cout << std::endl << "Min=" << arr[i] << " Flag= " << flag << std::endl;
		for (int k = 0; k < length; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl << "Numbers of checks " << k;
		std::cout << std::endl;
	}

	return 0;
}
*/