class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        for (int i=0; i<s.size() ; i++){
            if(!st.empty() && mp[st.top()]==s[i]) st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) return true;
        else return false;
    }
};
