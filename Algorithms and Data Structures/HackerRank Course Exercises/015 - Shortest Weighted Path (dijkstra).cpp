#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void print(std::vector<std::vector<int>>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << i + 1 << ":";
        for (unsigned int j = 0; j < arr[i].size(); j++) {
            std::cout << " " << arr[i][j];
        }
        std::cout << "\n";
    }
}

void print(std::vector<int>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << i+1<<": "<<arr[i]<<"\n";
    }
}

void find(std::vector<std::vector<int>>& finarr, int target){
    std::stack<int> s;
    s.push(target);
    int Sum = finarr[target-1][1];
    while(s.top()!=1){
        target=finarr[target-1][0];
        s.push(target);
    }
    while(!s.empty()){
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<"\n"<<Sum<<"\n";
}

void fixVarNM(int& N, int& M){
    if(N<3){
        N=3;
    }
    if(N>1000){
        N=1000;
    }
    if(M<3){
        M=3;
    }
    if(M>50000){
        M=50000;
    }
}

void fixSum(int& Sum){
    if(Sum<1){
        Sum=1;
    }
    if(Sum>127){
        Sum=127;
    }
}

int main() {
    int n, m, target;
    std::cin >> n >> m >> target;
    std::vector<std::vector<int>> arr(n);
    std::vector<std::vector<int>> arrSum(n);
    int x, y, Sum;
    
    fixVarNM(n, m);
    
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> Sum;
        fixSum(Sum);
        arr[x - 1].push_back(y);
        arr[y - 1].push_back(x);
        arrSum[x-1].push_back(Sum);
        arrSum[y-1].push_back(Sum);
    }

    std::vector<std::vector<int>> finarr(n);
    for(int i=0; i<n; i++){
        finarr[i] = std::vector<int> (2);
        finarr[i][1]=INFINITY;
    }
    
    std::queue<int> q;
    bool* barr = new bool[arr.size()]{};
    q.push(1);
    finarr[0][0]=0;
    finarr[0][1]=0;
    
    while(!q.empty()){
        if(!barr[q.front()-1]){
            int number;
            int index;
            for(int i=0; i<arr[q.front()-1].size(); i++){    
                number = arr[q.front()-1][i];
                index = number-1;
                q.push(number);
                if(finarr[index][1]>finarr[q.front()-1][1]+arrSum[q.front()-1][i]){
                    finarr[index][1]=finarr[q.front()-1][1]+arrSum[q.front()-1][i];
                    finarr[index][0]=q.front();
                }
            }
        }
        barr[q.front()-1]=true;
        q.pop();
    }
    //print(finarr);
    find(finarr, target);
    
}