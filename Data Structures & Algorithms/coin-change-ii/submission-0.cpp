class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        sort(coins.begin(), coins.end(), greater());
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i]>=0 && dp[j-coins[i]]>0){
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    //   0 1 2 3 4
    //1: 0 1 
    //2: 
    //3: 
    }
};
