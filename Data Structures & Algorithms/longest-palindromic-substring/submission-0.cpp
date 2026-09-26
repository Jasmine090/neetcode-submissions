class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int re_start = 0;
        int re_n = 1;
        for(int len=0;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                if(len==0) dp[i][j] = true;
                else if(len==1 && s[i]==s[j]) dp[i][j] = true;
                else if(len>1 && dp[i+1][j-1] && s[i]==s[j]) dp[i][j] = true;
                if(dp[i][j] && re_n<len+1){
                    re_start = i;
                    re_n = len+1;
                }
            }
        }
        return s.substr(re_start, re_n);;
    }
};
