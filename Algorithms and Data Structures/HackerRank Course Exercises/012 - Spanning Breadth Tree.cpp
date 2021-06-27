#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


void BFS(std::vector<std::vector<int>>& arr, int root){
    std::vector<int> finarr(arr.size());
    std::queue<int> q;
    bool * barr = new bool[arr.size()]{};
    barr[root-1]=true;
    finarr[root-1]=0;
    
    int index;
    q.push(root);
    
    while(!q.empty()){
        //std::cout<<"Visiting: "<<q.front()<<"\n";
        for(int i=0; i<arr[q.front()-1].size(); i++){
            index = arr[q.front()-1][i]-1;
            //std::cout<<"index = "<<index<<"\n";
            if(!barr[index]){
                finarr[index]=q.front();
                q.push(arr[q.front()-1][i]);
                barr[index]=true;
            }
        }
        q.pop();
    }
    
    for(int i=0; i<finarr.size(); i++){
        std::cout<<i+1<<": "<<finarr[i]<<"\n";
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


int main() {
    ///////FINAL SOLUTION///////////
    unsigned int n;
    unsigned int m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> arr(n);
    unsigned int x,y;
    
    for(unsigned int i=0; i<m; i++){
        std::cin>>x>>y;
        arr[x-1].push_back(y);
        arr[y-1].push_back(x);
    }
    
    //print(arr);
    
    //std::cout<<"\n";
    
    BFS(arr, 1);
}