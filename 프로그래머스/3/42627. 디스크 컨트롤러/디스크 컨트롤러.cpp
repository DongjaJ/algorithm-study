#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0;i<jobs.size();i++){
        auto job = jobs[i];
        vector<int> tmp;
                       
        pq.push({job[1], job[0], i });
    }
    
    int t = 0;
    int cnt = 0;
    
    while(pq.size()){
        vector<int> tmp;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq2;
        
        bool isDeleted = false;
        // t 이전에 시작하는 작업 있는 지 확인
        while(pq.size()){
            auto it = pq.top(); // 시간, 시작 시각, 작업 번호
            pq.pop();
            if(it[1] < t) {
                isDeleted = true;
                cnt += it[0] + (t-it[1]);
                t += it[0];
                while(pq2.size()){
                    auto v = pq2.top();
                    pq2.pop();
                    pq.push({v[1], v[0], v[2]});
                }
                
                break;
            }
            
            pq2.push({it[1], it[0], it[2]});
        }
        
        if(isDeleted) continue;
        
        auto v = pq2.top();
        pq2.pop();
        t = v[0] + v[1];
        cnt += v[1];
            
        while(pq2.size()){
            auto v = pq2.top();
            pq2.pop();
            pq.push({v[1], v[0], v[2]});
        }
    }
    
    
    
    return cnt / jobs.size();
}