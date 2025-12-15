#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int,int> m;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(auto i: tangerine) m[i]++;
    for(auto p: m) pq.push({p.second, p.first});
    
    int len = tangerine.size() - k;
    
    while(len--) {
        auto top = pq.top();
        pq.pop();
        
        int cnt = top.first - 1;
        int idx = top.second;
        
        if(cnt > 0) {
            pq.push({cnt, idx});
        }
    }
    
    return pq.size();
}