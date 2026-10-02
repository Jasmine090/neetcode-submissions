class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i] = for ith as the last, the length of longest subsequence
        //2 0 3 0 1 2 3 4 5
        //1 1 2 1 
        int n = nums.size();
        int re = 1;
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            re = max(re, dp[i]);
        }
        return re;
    }
};
