class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] = true if: 1. there is a dp[j](j<i) is true &&  the word of s[j+1]~s[i] exist in dict
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(!j){
                    if(dict.count(s.substr(0, i+1))) dp[i] = true;
                }
                else if(dp[j-1] && dict.count(s.substr(j, i-j+1))) dp[i] = true;
            }
        }
        // for(int i=0;i<n;i++){
        //     if(dp[i]) cout << '1' << ' ';
        //     else cout << '0' << ' ';
        // }
        cout << endl;
        return dp[n-1];
    }
};
