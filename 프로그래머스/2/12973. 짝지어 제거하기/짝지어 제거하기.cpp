#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for(auto c: s) {
        if (st.empty() || st.top() != c) {
            st.push(c);
            continue;
        }
        
        st.pop();
    }

    return st.empty() ? 1 : 0;
}