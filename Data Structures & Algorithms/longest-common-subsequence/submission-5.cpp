class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + ((text1[i]==text2[j])? 1:0);
        int m = text1.size();
        int n = text2.size();
        if(!m || !n) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (text1[0]==text2[0])? 1:0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i && !j) continue;
                int left = 0;
                int up = 0;
                int left_up = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                if(i>0 && j>0) left_up = dp[i-1][j-1];
                if(text1[i]==text2[j]){
                    dp[i][j] = left_up + 1;
                }
                else{
                    dp[i][j] = max(left, up);
                }
            }
        }
        return dp[m-1][n-1];
        
    }
    //        01234
    //  cbat, crabt
    //0:c     11111
    //1:cb    11122
    //2:cba   11222
    //3:cbat  11223

    //            012345678
    //  bsbininm, jmjkbkjkv
    //0:b         000011111
    //1:bs        000011111
    //2:bsb       0000

};
