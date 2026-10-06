class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        // 3 states (all means greates benefits at ith day)
        vector<int> hold(n, 0); // has a coin
        vector<int> sold(n, 0); // has no coin and just sold cannot buy
        vector<int> rest(n, 0); // has no coin and can buy "the next" day (may be the cooldown day)
        hold[0] = -prices[0]; //notice!
        sold[0] = 0;
        rest[0] = 0;
        for(int i=1;i<n;i++){
            hold[i] = max(hold[i-1], rest[i-1]-prices[i]); // hold today so hold yesterday or buy today
            sold[i] = hold[i-1] + prices[i]; // sold today so hold yesterday
            rest[i] = max(sold[i-1], rest[i-1]);//rest today so rest or sold yesterday
        }
        return max({sold[n-1], rest[n-1]});
    }
};
