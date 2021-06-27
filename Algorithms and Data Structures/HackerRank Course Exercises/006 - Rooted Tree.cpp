#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long int n;
    std::cin>>n;
    int num;
    
    std::vector<int> arr(n);
    std::vector<bool> arr2(n);
    for(unsigned long int i=0; i<n; i++){
        std::cin>>arr[i];
        if(arr[i]<1){
            arr2[i]=true;
            num=arr[i];
            std::cout<<i+1;
        }
    }
    std::cout<<"\n";
    
    for(unsigned long int i=0; i<n; i++){
        int tmp = arr[i];
        while(tmp!=num){
            if(arr2[tmp-1]==true){
                break;
            }
            arr2[tmp-1]=true;
            tmp=arr[tmp-1];
        }
    }
    for(unsigned long int i=0; i<n; i++){
        if(!arr2[i]){
            std::cout<<i+1<<' ';
        }
    }
}