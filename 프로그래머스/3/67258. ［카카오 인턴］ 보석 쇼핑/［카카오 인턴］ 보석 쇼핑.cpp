#include <bits/stdc++.h>

using namespace std;

int st = -1,en = -1;
int r = 0;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    set<string> category(begin(gems), end(gems));
    int len = category.size();
    
    m[gems[r]]++;
    for(int l = 0; l < gems.size();l++){
        while(r < gems.size() && m.size() < len) {
            r++;
            if(r != gems.size()) {
                 m[gems[r]]++;
            }
        }
        
        if(r == gems.size()) break;
        if((st == -1 && en == -1) || en-st > r-l){
            st = l;
            en = r;
        }
         m[gems[l]]--;
        if(!m[gems[l]]) {
            m.erase(gems[l]);
        }
    }
    
    vector<int> answer;
    answer.push_back(st+1);
    answer.push_back(en+1);
    return answer;
}