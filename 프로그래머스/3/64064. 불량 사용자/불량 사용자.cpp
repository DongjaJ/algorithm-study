#include <bits/stdc++.h>

using namespace std;

set<set<string>> s;
set<string> ss;
vector<vector<string>> v;

void backT(int cur, int mx){    
    if(cur == mx) {
        s.insert(ss);
        return;
    }
    
    for(auto i: v[cur]){
        int originSize = ss.size();
        ss.insert(i);
        if(ss.size() == originSize) continue;
        backT(cur + 1, mx);
        ss.erase(i);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    for(auto bId: banned_id){
        vector<string> tmp;
        
        for(auto uId:user_id) {
            if(uId.size() != bId.size()) continue;
            
            bool isValid = true;
            for(int i = 0;i<uId.size();i++){
                if(bId[i] == '*') continue;
                if(uId[i] != bId[i]) {
                    isValid = false;
                    break;
                }
            }
            
            if(isValid) {
                tmp.push_back(uId);
            }
        }
        
        v.push_back(tmp);
    }
    
    backT(0, v.size());
    
    return s.size();
}