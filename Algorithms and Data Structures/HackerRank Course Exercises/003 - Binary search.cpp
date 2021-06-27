#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarysearch(int* arr, int n, int x){
    int low=0, up=n-1;
    int temp;
    while(low<=up){ 
        temp=(low+up)/2;
        if(arr[temp]==x) return temp;
        if(arr[temp]>x) up=temp-1;
        else low=temp+1;
    }
    return -1;
}


int main() {
    int n;
    std::cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        std::cin>>arr[i];
    }
    int x;
    int y;
    std::cin>>x;
    std::cin>>y;
    std::cout<<binarysearch(arr, n,x)<<" "<<binarysearch(arr, n,y);
    return 0;
}