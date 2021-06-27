#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {   
    int n;
    int m;
    std::cin>>n>>m;
    int** arr = new int *[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n]{};
    }
    int x,y;
    for(int i=0; i<m; i++){
        std::cin>>x>>y;
        arr[x-1][y-1]=1;
        arr[y-1][x-1]=1;
    }
        
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    return 0;
}