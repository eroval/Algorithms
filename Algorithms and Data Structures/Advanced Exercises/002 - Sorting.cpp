#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int* arr, int sz){
    for(int i=0; i<sz; i++){
        std::cout<<arr[i]<<" ";
    }
}

void bubbleSort(int* arr, int n){
    int* arrcpy = new int[n];
    for(int i=0; i<n; i++){
        arrcpy[i]=arr[i];        
    }
    bool inversion=true;
    
    while (inversion) {
        inversion = false;
        for (int i = 1; i < n; i++) {
            if (arrcpy[i - 1] > arrcpy[i]) {
            arrcpy[i] ^= arrcpy[i - 1];
            arrcpy[i - 1] ^= arrcpy[i];
            arrcpy[i] ^= arrcpy[i - 1];
            inversion = true;
            }
        }
    }
    print(arrcpy, n);
}



void Merge(int* arr, int start, int index, int end, int* C) {
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

void MergeSort(int* arr, int start, int end, int* C) {
    int index = (start + end) / 2;
    if (start >= end) {
        return;
    }
    MergeSort(arr, start, index,C);
    MergeSort(arr, index + 1, end,C);
    Merge(arr, start, index+1, end,C);
}

int main() {
    int n;
    int* arr;
    int* arrsort;
    std::cin>>n;
    arr = new int[n];
    arrsort=new int[n]{};
    for(int i=0; i<n; i++){
        std::cin>>arr[i];        
    }
    //bubbleSort(arr,n);
    MergeSort(arr,0,n-1,arrsort);
    print(arr,n);
    
    return 0;
}