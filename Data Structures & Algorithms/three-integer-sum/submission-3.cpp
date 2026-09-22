class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            find_target(re, nums, nums[i], i);
        }
        return re;
    }
    void find_target(vector<vector<int>>& re, vector<int>& nums, int target, int start){
        int left = start+1;
        int right = nums.size()-1;
        while(left<right){

            if(nums[left]+nums[right]+target==0){
                re.push_back({nums[left], nums[right], target});
                left++;
                while(left<right && nums[left-1]==nums[left]) left++;
                right--;
                while(left<right && nums[right+1]==nums[right]) right--;
            }
            else if(nums[left]+nums[right]<-target){
                left++;
                while(left<right && nums[left-1]==nums[left]) left++;
            }
            else{
                right--;
                while(left<right && nums[right+1]==nums[right]) right--;
            }
        }
        return;
    }
};
