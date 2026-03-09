#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long st = 1;
    long long en = (long long)(n) * ((long long)times.back());
    
    while(st <= en) {
        long long mid = (st + en) / 2;
        long long sum = 0;
        for(auto time: times){
            if(sum >= n) {
                break;
            }
            sum += (mid / (long long)time);
        }
        if(sum >= n) {
            answer = mid;
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    
    return answer;
}