class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P = positive numbers sum
        // N = negative number sum (perform negatively, N is positive here)
        // P - N = target------------(1)
        // P + N = sum of all nums---(2)
        // (1) + (2) => 2P = target + sum => P = (target + sum)/2 = number of split of PN
        int n = nums.size();
        int sum = 0;
        int tmp = 1;
        for(int i=0;i<n;i++){ 
            sum += nums[i];
            if(!nums[i]) tmp*=2;
        }
        if((sum + target)%2) return 0;
        if((sum + target)<0) return 0;
        int r_target = (sum + target)/2;
        vector<int> dp(r_target+1, 0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=r_target;j>0;j--){
                if(nums[i] && j-nums[i]>=0 && dp[j-nums[i]]>0) dp[j] += dp[j-nums[i]];
            }
        }
        return dp[r_target]*tmp;
    }
};
