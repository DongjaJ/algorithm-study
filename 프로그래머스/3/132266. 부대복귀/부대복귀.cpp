#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int vis[100005];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    fill(vis, vis + n + 1, -1);
    
    for(auto v: roads){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    
    queue<int> q;
    
    vis[destination] = 0;
    q.push(destination);
    
    while(q.size()){
        int cur = q.front();
        q.pop();
        
        for(auto nxt: adj[cur]){
            if(vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            q.push(nxt);
        }
    }
    
    for(auto src : sources) {
        answer.push_back(vis[src]);
    }
    
    return answer;
}