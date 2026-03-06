#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int d[505][505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    d[0][1] = triangle[0][0];
    for(int i = 1;i < triangle.size();i++){
        for(int j = 1;j < i + 2;j++) {
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + triangle[i][j - 1];
            answer = max(d[i][j], answer);
        }
    }
    
    return answer;
}