#include <bits/stdc++.h>

using namespace std;

bool isAlpha(char c){
    return c >= 'a' && c <= 'z';
}

int solution(string str1, string str2) {
    map<string, float> m1;
    map<string, float> m2;
    
    for(int i = 0;i<str1.size()-1;i++){
        string tmp = str1.substr(i, 2);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        if(!isAlpha(tmp[0]) || !isAlpha(tmp[1])) {
            continue;
        }
        
        m1[tmp]++;
    }
    
    for(int i = 0;i<str2.size()-1;i++){
        string tmp = str2.substr(i, 2);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        
        if(!isAlpha(tmp[0]) || !isAlpha(tmp[1])) {
            continue;
        }
        
        m2[tmp]++;
    }
    
    float a = 0; //교집합
    float b = 0; //합집합
    
    for(auto p: m1) {
        if(!m2[p.first]) {
            b += p.second;
            continue;
        }
        
        a += min(m2[p.first], p.second);
        b += max(m2[p.first], p.second);
    }
    
    for(auto p: m2) {
        if(m1[p.first]) {
            continue;
        }
        
        b += p.second;
    }
    
    if (a== 0 && b == 0) return 65536;
    
    return (int)a/b*65536;
}