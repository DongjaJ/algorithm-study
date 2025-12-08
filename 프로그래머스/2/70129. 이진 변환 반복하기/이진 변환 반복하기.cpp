#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeroCnt = 0;
    
    while(s != "1") {
        cnt++;
        int len = 0;
        for(auto c: s) {
            if (c == '0'){
                zeroCnt++;
            } else {
                len++;
            }
        }
        
        string tmp = "";
        
        while(len>0){
            tmp += len % 2 + '0';
            len /= 2;
        }
        s = tmp;
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    
    return answer;
}