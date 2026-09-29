class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i]=min(dp[i-coins[j]]+1)
        vector<int> dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        //if(!amount) return 0;
        //if(amount < coins[0]) return -1;
        for(int i=0;i<coins.size();i++){
            if(coins[i]>amount) break;
            dp[coins[i]] = 1;
        }
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if((i-coins[j])<0){
                    //if(dp[i]==INT_MAX) dp[i] = -1;
                    break;
                }
                if(dp[i-coins[j]]==INT_MAX){
                    continue;
                }
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
            cout << dp[i] << endl;
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};
