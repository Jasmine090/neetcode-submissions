class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum%2) return false;
        vector<bool> dp(sum/2, false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            for(int j=sum/2;j>=nums[i];j--){
                if(dp[j-nums[i]]) dp[j] = true;
            }
        }
        return dp[sum/2];
    }
};
