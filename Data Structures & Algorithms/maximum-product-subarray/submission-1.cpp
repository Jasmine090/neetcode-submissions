class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // dp[i] = max({dp[i-1], dp[i-1]*nums[i], nums[i]})
        int n = nums.size();
        vector<int> mmax(n, INT_MIN);
        vector<int> mmin(n, INT_MIN);
        mmax[0] = nums[0];
        mmin[0] = nums[0];
        int re = mmax[0];
        for(int i=1;i<n;i++){
            mmax[i] = max({mmin[i-1]*nums[i], mmax[i-1]*nums[i], nums[i]});
            mmin[i] = min({mmin[i-1]*nums[i], mmax[i-1]*nums[i], nums[i]});
            re = max(re, mmax[i]);
        }
        return re;
    }
};
