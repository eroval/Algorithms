#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


void heapify(int* arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
  
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
  
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
  
        heapify(arr, n, smallest);
    }
}
  
void buildHeap(int* arr, int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printHeap(int* arr, int n){
    for (int i = 0; i < n; ++i){
        std::cout<< i+1<<":"<< arr[i] << "\n";
    }
}

void findElementIndex(int* arr,int size,int x){
    for(int i=0; i<size; i++){
        if(arr[i]==x){
            std::cout<<i+1<<"\n";
            break;
        }
    }
}

int main()
{
    int n;
    std::cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        std::cin>>arr[i];
    }
    buildHeap(arr, n);
    printHeap(arr, n);
    int* arrcpy = new int[n+1];
    for(int i=0; i<n; i++){
        arrcpy[i]=arr[i];
    }
    delete[] arr;
    int tmp;
    std::cin>>tmp;
    arrcpy[n]=tmp;
    n++;
    buildHeap(arrcpy,n);
    findElementIndex(arrcpy, n, tmp);
    
    return 0;
}