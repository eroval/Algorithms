#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long int n;
    std::cin>>n;
    int max=0;
    int num;
    
    std::vector<int> arr(n);
    std::vector<int> arr2(n);
    for(unsigned long int i=0; i<n; i++){
        std::cin>>arr[i];
        if(arr[i]<1){
            num=arr[i];
        }
    }
    
    for(unsigned long int i=0; i<n; i++){
        int tmp = arr[i];
        while(tmp!=num){
            arr2[i]++;
            if(arr2[i]>max){
            max=arr2[i];
            }
            tmp=arr[tmp-1];
        }
    }
    
    std::cout<<max<<"\n";
    for(unsigned long int i=0; i<n; i++){
        std::cout<<arr2[i]<<" ";
    }
    
}