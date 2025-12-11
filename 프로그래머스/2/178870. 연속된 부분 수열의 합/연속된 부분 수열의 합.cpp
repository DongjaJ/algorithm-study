#include <bits/stdc++.h>

using namespace std;

int prefixSum[1000005];

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int l = 1, r = 1,total = 0;
    int st = -1, en = -1;
    
    for(int i = 0; i < sequence.size();i++){
        prefixSum[i+1] = prefixSum[i] + sequence[i];
    }
    cout<<'\n';
    
    while(r <= sequence.size()) {
        int total = prefixSum[r] - prefixSum[l - 1];
            
        if(total == k) {
            if(st == -1 && en == -1) {
                st = l;
                en = r;
            }
            
            if(en - st > r - l){
                st = l;
                en = r;
            }
            
            r++;
            continue;
        }
        
        if(total < k) {
            r++;
        } else {
            l++;
        }
    }
    
    answer.push_back(st - 1);
    answer.push_back(en - 1);
    
    return answer;
}