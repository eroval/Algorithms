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

void normalize(std::vector<std::vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::sort(arr[i].begin(), arr[i].end());
    }
}

std::vector<int> BFS(std::vector<std::vector<int>>& arr, int root) {
    std::vector<int> finarr(arr.size());
    std::queue<int> q;
    bool* barr = new bool[arr.size()]{};
    barr[root - 1] = true;
    finarr[root - 1] = 0;

    int index;
    q.push(root);

    while (!q.empty()) {
        for (int i = 0; i < arr[q.front() - 1].size(); i++) {
            index = arr[q.front() - 1][i] - 1;
            if (!barr[index]) {
                finarr[index] = q.front();
                q.push(arr[q.front() - 1][i]);
                barr[index] = true;
            }
        }
        q.pop();
    }
    
    return finarr;
}

void findShortestPath(std::vector<int>& bfsarr, int target){
    std::stack<int> s;
    while(bfsarr[target-1]!=0){
        s.push(target);
        target=bfsarr[target-1];
    }
    s.push(target);
    
    while(!s.empty()){
        std::cout<<s.top()<<" ";
        s.pop();
    }
}


int main() {
    int n, m, target;
    std::cin >> n >> m >> target;
    std::vector<std::vector<int>> arr(n);
    int x, y;

    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        arr[x - 1].push_back(y);
        arr[y - 1].push_back(x);
    }

    //print(arr);
    std::vector<int> finarr = BFS(arr, 1);
    findShortestPath(finarr, target);

}