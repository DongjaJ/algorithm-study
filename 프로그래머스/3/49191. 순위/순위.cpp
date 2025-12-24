#include <bits/stdc++.h>

using namespace std;

int arr[105][105];
int cnt[105];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(auto result: results) {
        arr[result[0]][result[1]] = 1;
    }
    
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(arr[i][k]&&arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(arr[i][j]) {
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
    
    for(int i = 1;i<=n;i++){
        if(cnt[i] == n-1){
            answer++;
        }
    }
    
    
    return answer;
}