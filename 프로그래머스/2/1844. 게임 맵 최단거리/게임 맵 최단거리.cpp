#include <bits/stdc++.h>
using namespace std;

int vis[105][105];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;

bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}

int solution(vector<vector<int>> maps)
{   
    n = maps.size();
    m = maps[0].size();
    
    queue<pair<int,int>> q;
    
    vis[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(OOB(nx, ny) || !maps[nx][ny] ||vis[nx][ny]) continue;
            
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    return vis[n-1][m-1] ? vis[n-1][m-1] : -1;
}