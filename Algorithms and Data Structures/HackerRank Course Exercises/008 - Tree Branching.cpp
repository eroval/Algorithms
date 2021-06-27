
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long int n;
    std::cin>>n;
    std::vector<int> arr(n);
    std::vector<int> arr2(n);
    int max=0;
    for(long unsigned int i=0; i<n; i++){
        std::cin>>arr[i];
        if(arr[i]>=1){
            arr2[arr[i]-1]++;
            if(arr2[arr[i]-1]>max){
                max=arr2[arr[i]-1];
            }
        }
    }
    
    std::cout<<max<<"\n";
    for(long unsigned int  i=0; i<n; i++){
        std::cout<<arr2[i]<<" ";
    }
    
}