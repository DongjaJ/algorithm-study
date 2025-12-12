#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(auto i: works){
        pq.push(i);
    }
    
    while(n--){
        int tmp = pq.top();
        pq.pop();
        pq.push(--tmp);
    }
    
    while(!pq.empty()){
        int tmp = pq.top();
        pq.pop();
        
        if(tmp < 0){
            break;
        }
        
        answer += tmp * tmp;
    }
    
    return answer;
}