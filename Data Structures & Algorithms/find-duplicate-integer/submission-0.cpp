class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tmp = nums[0];
        for(int i=1;i<nums.size();i++){
            if(tmp==nums[i]) return tmp;
            tmp = nums[i];
        }
        return 0;
    }
};
