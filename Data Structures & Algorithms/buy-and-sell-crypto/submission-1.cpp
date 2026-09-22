class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min_p = prices[0];
        for (int i=1; i<prices.size() ; i++){
            if(min_p > prices[i-1]) min_p = prices[i-1];
            if(max < (prices[i]-min_p)) max = prices[i]-min_p;
        }
        return max;
    }
};
