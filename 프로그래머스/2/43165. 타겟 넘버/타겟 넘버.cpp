#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int t;

void dfs(vector<int> numbers, int curValue, int curIndex){
    if(numbers.size() == curIndex) {
        if(curValue == t) {
            answer++;
        }
        return;
    }
    dfs(numbers, curValue + numbers[curIndex], curIndex + 1);
    dfs(numbers, curValue - numbers[curIndex], curIndex + 1);
}

int solution(vector<int> numbers, int target) 
{
    t = target;
    dfs(numbers, 0, 0);
    
    return answer;
}