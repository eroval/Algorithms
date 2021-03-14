#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>


#define MAX 100
#define start 10
//File to save and use
#define Fname "generated.txt"

void generateFile() {
    int i, v;
    std::ofstream output(Fname);
    srand((unsigned)time(NULL));
    v = rand() % start + 1;
    output << v<<"\n";
    for (i = 1; i < MAX; i++)
    {
        v += rand() % start + 1;
        output << v<<"\n";
    }
    v = rand() % start + 1;
    output << v<<"\n";
    for (i = 1; i < MAX; i++)
    {
        v += rand() % start + 1;
        output << v<<"\n";
    }
    output.close();
}

void print(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i]<<" ";
    }
    std::cout << "\n";
}

void compare(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& result) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i != MAX && j != MAX) { 
        k++;
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        }
        else {
            j++;
        }
    }
    std::cout << "\nNumber of steps: " << k << "\n";
}

void launch() {
    std::vector<int> arr(MAX);
    std::vector<int> arr2(MAX);
    std::vector<int> result;

    std::ifstream t(Fname);
    for (int i = 0; i < MAX; i++) {
        t>>arr[i];
    }
    for (int i = 0; i < MAX; i++) {
        t >>arr2[i];
    }
    t.close();
    std::cout << "Arr1:\n";
    print(arr);
    std::cout << "\n\nArr2:\n";
    print(arr2);
    compare(arr, arr2, result);
    std::cout << "\n\nResult Arr:\n";
    print(result);
}

int main() {
    //generateFile();
    launch();
	return 0;
}