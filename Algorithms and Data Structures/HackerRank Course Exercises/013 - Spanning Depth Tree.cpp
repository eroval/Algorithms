#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void DFS(std::vector<std::vector<int>>& arr, int root) {
    std::vector<int> finarr(arr.size());
    std::stack<int> s;
    std::stack<int> roots;
    bool* barr = new bool[arr.size()]{};
    barr[root - 1] = true;
    finarr[root - 1] = 0;

    roots.push(root);
    int index;
    while(!roots.empty()){
        for(int i=0; i<arr[roots.top()-1].size(); i++){
            index = arr[roots.top()-1][i]-1;
            if(!barr[index]){
                s.push(arr[roots.top()-1][i]);
            }
            //std::cout<<"\ntop = "<<s.top()<<"\n";
        }
        if(!barr[s.top()-1]){
            finarr[s.top()-1]=roots.top();
            barr[s.top()-1]=true;
            roots.push(s.top());
        }
        else roots.pop();
    }
    for (int i = 0; i < finarr.size(); i++) {
        std::cout << i + 1 << ": " << finarr[i] << "\n";
    }
}

void print(std::vector<std::vector<int>>& arr){
    for(unsigned int i=0; i<arr.size(); i++){
        std::cout<<i+1<<":";
        for(unsigned int j=0; j<arr[i].size(); j++){
            std::cout<<" "<<arr[i][j];
        }
        std::cout<<"\n";
    }
}

void normalize(std::vector<std::vector<int>>& arr){
    for(int i=0; i<arr.size(); i++){
        std::sort(arr[i].begin(), arr[i].end());
    }
}


int main(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> arr(n);
    int x, y;
    
    for(int i=0; i<m; i++){
        std::cin>>x>>y;
        arr[x-1].push_back(y);
        arr[y-1].push_back(x);
    }
    
    //print(arr);
    DFS(arr, 1);
    
}