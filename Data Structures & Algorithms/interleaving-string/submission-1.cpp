class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != (m+n)) return false;
        if(!s3.size()) return true;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(!i && !j) continue;
                if((i-1>=0 && dp[i-1][j] && s1[i-1]==s3[i+j-1]) || 
                   (j-1>=0 && dp[i][j-1] && s2[j-1]==s3[i+j-1])){
                    dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};
