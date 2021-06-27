#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int* arr, int n){
    for(int i=0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
}

void sort(int* arr1, int* arr2, int n, int m){
    int* arr=new int[n+m];
    int i=0; int j=0, k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    
    if(i<n){
        for(; i<n; i++){
            arr[k]=arr1[i];
            k++;
        }
    }
    else {
        for(; j<m; j++){
            arr[k]=arr2[j];
            k++;
        }
    }
    
    print(arr,k);
}

int main() {
    int m, n;
    std::cin>>m>>n;
    int* arr1 = new int[m];
    int* arr2 = new int[n];
    for(int i=0; i<m; i++){
        std::cin>>arr1[i];
    }
    for(int i=0; i<n; i++){
        std::cin>>arr2[i];
    }
    
    sort(arr1,arr2,m,n);
    
    return 0;
}