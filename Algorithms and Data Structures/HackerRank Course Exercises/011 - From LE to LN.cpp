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
    std::vector<std::vector<int>> arr(n);
    int x,y;
    for(int i=0; i<m; i++){
        std::cin>>x>>y;
        arr[x-1].push_back(y);
        arr[y-1].push_back(x);
    }
    for(int i=0; i<arr.size(); i++){
        std::cout<<i+1<<":";
        for(int j=0; j<arr[i].size(); j++){
            std::cout<<" "<<arr[i][j];
        }
        std::cout<<"\n";
    }
    return 0;
}