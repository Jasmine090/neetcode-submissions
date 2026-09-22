class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        unordered_map<char, int> lastPost;
        int left = 0;
        lastPost[s[0]] = 0;
        int re = 0;
        for(int i=1;i<s.size();i++){
            if(lastPost.count(s[i]) && lastPost[s[i]]>= left){
                left = lastPost[s[i]]+1;
            }
            lastPost[s[i]] = i; 
            re = max(re, i-left+1);
        }
        re = max(re, 1);
        return re;
    }
};
