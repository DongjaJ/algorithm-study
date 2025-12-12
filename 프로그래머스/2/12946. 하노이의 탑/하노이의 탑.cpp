#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;

void hanoi(int st, int en, int cur){
    if(cur == 1){
        v.push_back({st, en});
        return;
    }

    hanoi(st, 6 - st - en, cur - 1);
    v.push_back({st, en});
    hanoi(6 - st - en, en , cur - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(1, 3, n);
    
    return v;
}