class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==1) return (s[0]-'0')? 1:0;
        vector<int> dp(n);
        dp[0] = (s[0]-'0')? 1:0;
        int tmp = 10*(s[0]-'0') + s[1]-'0'; 
        if((s[0]-'0') && tmp>0 && tmp<27) dp[1] = dp[0]+1;
        else dp[1] = dp[0];
        dp[1] = ((s[1]-'0')?dp[0]:0) + (((s[0]-'0') && tmp>0 && tmp<27)?1:0);
        for(int i=2;i<n;i++){
            int tmp = 10*(s[i-1]-'0') + s[i]-'0'; 
            dp[i] = ((s[i]-'0')?dp[i-1]:0) + (((s[i-1]-'0') && tmp>0 && tmp<27)?dp[i-2]:0);
        }
        return dp[n-1];
    }
};
