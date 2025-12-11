#include <bits/stdc++.h>

using namespace std;

int arr[1002][1002];

int dx[] = {1,0,-1};
int dy[] = {0,1,-1};

vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1, x = 1, y = 1, dir = 0;
    
    for(int t = n; t > 0; t--){
       for(int i = 0;i< t;i++){
            arr[x][y] = num++;
           
            if(i == t - 1) dir = (dir + 1) % 3;
           
            x += dx[dir];
            y += dy[dir];
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i;j++)
            answer.push_back(arr[i][j]);
    
    return answer;
}