#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(std::vector<int> arr, int n){
    for(int i=0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
}

void compare(std::vector<int>& arr1, std::vector<int>& arr2) {
    long unsigned i = 0;
    long unsigned j = 0;
    long unsigned k = 0;
    std::vector<int> result;

    while (i != arr1.size() && j != arr2.size()) { 
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
    print(result, result.size());
}


int main() {
    int m, n;
    std::cin>>m>>n;
    std::vector<int> arr1(m);
    std::vector<int> arr2(n);
    for(int i=0; i<m; i++){
        std::cin>>arr1[i];
    }
    for(int i=0; i<n; i++){
        std::cin>>arr2[i];
    }
    
    compare(arr1,arr2);
    
    return 0;
}