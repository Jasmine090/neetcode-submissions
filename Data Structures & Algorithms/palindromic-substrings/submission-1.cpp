class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for(int len=0;len<n;len++){
            for(int i=0;i+len<n;i++){
                int j=i+len;
                if(i==j) dp[i][j] = true;
                else if(len==1 && s[i]==s[j]) dp[i][j] = true;
                else if(len>1 && dp[i+1][j-1] && s[i]==s[j]) dp[i][j] = true;
                if(dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
