class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] = greatest benefit if sold at the day
        // dp[i] = max(prices[i]-prices[j]+dp[k]) for all j<i, k<j-2
        int n = prices.size();
        if(n==1) return 0;
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = prices[1]-prices[0];
        int re = 0;
        re = max({dp[0], dp[1], re});
        for(int i=2;i<n;i++){
            int tmp = 0;
            for(int j=0;j<i;j++){
                if(j>1) tmp = max(tmp, dp[j-2]);
                dp[i] = max(dp[i], prices[i]-prices[j]+tmp);
            }
            re = max(re, dp[i]);
            
        }
        return re;
    }
};
