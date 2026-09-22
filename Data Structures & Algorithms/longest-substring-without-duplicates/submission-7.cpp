class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        unordered_map<char, int> mp;
        int left = 0;
        mp[s[0]] = 1;
        int re = 0;
        for(int i=1;i<s.size();i++){
            if(mp.count(s[i]) && mp[s[i]]==1){
                for(int j=left;j<i;j++){
                    if(s[j]==s[i]){
                        left = j+1;
                        break;
                    }
                    mp[s[j]] = 0;
                }
            }
            else mp[s[i]] = 1; 
            re = max(re, i-left+1);
        }
        re = max(re, 1);
        return re;
    }
};
