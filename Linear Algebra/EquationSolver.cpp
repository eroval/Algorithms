#include <iostream>
#include <time.h>
#include <iomanip>  

//make zeroes on the diagonal non-zeroes
void makeNonZero(float**& arr, int sz, int fsz) {
	for (int i = 0; i < sz; i++) {
		if (arr[i][i] == 0) {
			for (int j = 0; j < i; j++) {
				if (arr[j][i] != 0 && arr[i][j] != 0) {
					for (int k = 0; k < fsz; k++) {
						float tmp = arr[i][k];
						arr[i][k] = arr[j][k];
						arr[j][k] = tmp;
					}
				}
			}
			for (int j = i + 1; j < sz; j++) {
				if (arr[j][i] != 0 && arr[i][j] != 0) {
					for (int k = 0; k < fsz; k++) {
						float tmp = arr[i][k];
						arr[i][k] = arr[j][k];
						arr[j][k] = tmp;
					}
				}
			}
		}
	}
}

int main() {
	//for (int p = 0; p < 100; p++) {
		srand(time(NULL));
		int sz;
		int fsz;
		//std::cout << "Enter Length: ";
		//std::cin >> sz;
		sz = 30;
		fsz = sz + 1;
		float** arr = new float* [sz];
		float** arrcpy = new float* [sz];
		float* results = new float[sz];
		for (int i = 0; i < sz; i++) {
			arr[i] = new float[fsz];
			arrcpy[i] = new float[fsz];
		}


		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < fsz; j++) {
				//std::cin >> arr[i][j];
				int num = rand() % 10;
				arr[i][j] = num;
				arrcpy[i][j] = num;
			}
		}

		std::cout << "\n";

		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < fsz - 1; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << "= " << arr[i][fsz - 1] << "\n";
		}

		std::cout << "\n";

		//TRY to make zeroes on the diagonal non zeroes
		makeNonZero(arr, sz, fsz);

		for (int i = 0; i < sz; i++) {
			float x = arr[i][i];
			for (int j = 0; j < fsz; j++) {
				arr[i][j] = (arr[i][j] / x);
			}

			for (int k = i + 1; k < sz; k++) {
				float y = arr[k][i];
				for (int j = i; j < fsz; j++) {
					arr[k][j] = arr[k][j] - (arr[i][j] * y);
				}
				makeNonZero(arr, sz, fsz);
				//there should be a different function for this check to save memory and time
			}

			for (int k = 0; k < sz; k++) {
				for (int j = 0; j < fsz - 1; j++) {
					std::cout << arr[k][j] << " ";
				}
				std::cout << "= " << arr[k][fsz - 1] << "\n";
			}
			std::cout << "\n";
		}

		results[sz - 1] = arr[sz - 1][fsz - 1];
		for (int i = sz - 2; i >= 0; i--) {
			float x = 0;
			for (int j = i + 1; j < fsz - 1; j++) {
				x = x + (arr[i][j] * results[j]);
			}
			results[i] = arr[i][fsz - 1] - x;
		}

		std::cout << "\nSalvations:\n";
		for (int i = 0; i < sz; i++) {
			std::cout << "x" << i + 1 << " = " << results[i] << "\n";
		}

		std::cout << "\nChecks:\n";
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < fsz - 2; j++) {
				std::cout << arrcpy[i][j] << "*" << results[j] << " + ";
			}
			std::cout << arrcpy[i][fsz - 2] << "*" << results[sz - 1] << " = ";
			float x = 0;
			for (int j = 0; j < fsz - 1; j++) {
				x += arrcpy[i][j] * results[j];
			}
			std::cout<<std::fixed<<std::setprecision(0)<< x << "\n";
		}
	//}
}
