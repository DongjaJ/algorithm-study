#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeroCnt = 0;
    
    while(s != "1") {
        cnt++;
        string tmp = "";
        for(auto c: s) {
            if (c == '0'){
                zeroCnt++;
                continue;
            }
            tmp += c;
        }
        
        int l = tmp.size();
        
        tmp = "";
        while(l>0){
            tmp += l % 2 + '0';
            l /= 2;
        }
        s = tmp;
    }
    
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    
    return answer;
}